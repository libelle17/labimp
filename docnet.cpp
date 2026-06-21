// docnet.cpp – Erweiterung von labimp für den doc.net-Labmessenger (LDT 3.x)
//
// Dieses Modul wird analog zu turbomed.cpp eingebunden.
// Es überschreibt bzw. ergänzt:
//   pvirtVorgbSpeziell() – Vorgaben für Verzeichnisse
//   virtinitopt()        – neue Kommandozeilenoptionen (qvz, zvz1..zvz4, pdfvz)
//   pvirtfuehraus()      – Hauptschleife mit Datei-Verschiebe-/Kopier-/PDF-Logik
//   dverarbeit()  wird NICHT überschrieben – stattdessen wird
//   docnet_dverarbeit()  als Präprozess-Schritt eingehängt, der
//                        LDT3-Hierarchie flach in LDT1/2-kompatible
//                        Felder auflöst und dann dverarbeit() aufruft.
//
// LDT 3 → LDT 1/2 Mapping (nur die für labimp relevanten Felder):
//   7278 → Datum (YYYYMMDD)  innerhalb Obj_0054 (Timestamp)
//   7279 → Uhrzeit (HHMMSS)  innerhalb Obj_0054
//   3101, 3102, 3103, 3110   Patientenname, Vorname, GebDat, Geschlecht  (gleich)
//   3000 → Patientennummer (Kassennummer, entspricht 3000 in LDT2)
//   3119 → Krankenversicherungsnummer (neu in LDT3)
//   8310, 8311               Auftragsnummer/-schlüssel (gleich)
//   8401                     Befundart (gleich)
//   8410, 8411               Test-Ident, Langtext (gleich)
//   8420, 8421, 8422         Wert, Einheit, Grenzwertindikator (gleich)
//   8460                     Normbereich (gleich, einzeilig in LDT3)
//   8428, 8430               Probenmaterial-Ident, -Bezeichnung (gleich)
//   8480 / 3564              Ergebnistext/Kommentar → wie 8480
//   8242 / 6329              Base64-Anlage (PDF) – wie bisher
//   0105                     Auftrags-ID (LDT3-Dateikennung, ersetzt 8000/8220 + 0101)
//   Timestamp_Erstellung_Datensatz (7278/7279 im Kopf-Obj_0054) → Dateiumbenennung
//
// Dateiumbenennung:
//   Quelldatei  →  ldatvz/Labor<YYYYMMDD>_<HHMMSS>_<lfdnr>.ldt
//   Laufende Nummer wird hochgezählt, falls gleichnamige Datei in ldatvz existiert.
//
// PDF-Extraktion:
//   Base64-Blöcke (Feldkennung 8242 + 6329) werden je Auftrag
//   in pdfvz/<auftragsschluessel>_<YYYYMMDD>.pdf gespeichert.
//
// Kompilierung: wie turbomed.cpp, z. B.:
//   $(CXX) … docnet.cpp labimp.o kons.o DB.o -o labimp_docnet

// ===========================================================================
// ABHAENGIGKEITEN
// ===========================================================================
// kons.h  - Konsolhilfsfunktionen (fLog, caus, Farbcodes rot/blau/schwarz)
// DB.h    - Datenbankabstraktion (RS, insv, DB)
// labimp.h - hhcl-Klasse (Hauptprogramm-Klasse)
// docnet.h - Enums (TDN_*) und Deklaration hhcl_docnet_verarbeitqvz()
// filesystem - C++17 fuer Verzeichnisoperationen


#include "kons.h"
#include "DB.h"
#include "labimp.h"
#include "docnet.h"
#include <filesystem>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cerrno>
#include <ctime>
#include <sys/stat.h>

namespace fs = std::filesystem;

// ── Hilfstexte (zweisprachig wie im Rest des Projekts) ──────────────────────
// (TDN_-Enum ist in docnet.h definiert)

// ===========================================================================
// HILFSTEXTE (zweisprachig Deutsch/Englisch)
// ===========================================================================
// Jeder Eintrag entspricht einem TDN_*-Enum-Wert aus docnet.h.
// Reihenfolge muss exakt mit der Enum-Reihenfolge uebereinstimmen.
// Erscheinen in Kommandozeilenhilfe und Logmeldungen.


const char *dn_T[TDN_MAX + 1][SprachZahl] = {
	// TDN_qvz_k
	{"qvz", "qdir"},
	// TDN_qvz_l
	{"quelldatenvz", "sourcedir"},
	// TDN_zvz1_k
	{"zvz1", "cdir1"},
	// TDN_zvz1_l
	{"zielverzeichnis1", "copydir1"},
	// TDN_zvz2_k
	{"zvz2", "cdir2"},
	// TDN_zvz2_l
	{"zielverzeichnis2", "copydir2"},
	// TDN_zvz3_k
	{"zvz3", "cdir3"},
	// TDN_zvz3_l
	{"zielverzeichnis3", "copydir3"},
	// TDN_zvz4_k
	{"zvz4", "cdir4"},
	// TDN_zvz4_l
	{"zielverzeichnis4", "copydir4"},
	// TDN_pdfvz_k
	{"pdfvz", "pdfdir"},
	// TDN_pdfvz_l
	{"pdfverzeichnis", "pdfdirectory"},
	// TDN_Quelldateiverzeichnis_doc_net
	{"Quelldateiverzeichnis (doc.net)", "source directory (doc.net)"},
	// TDN_Kopierziel_1
	{"Kopierziel 1", "copy target 1"},
	// TDN_Kopierziel_2
	{"Kopierziel 2", "copy target 2"},
	// TDN_Kopierziel_3
	{"Kopierziel 3", "copy target 3"},
	// TDN_Kopierziel_4
	{"Kopierziel 4", "copy target 4"},
	// TDN_PDF_Ausgabeverzeichnis
	{"PDF-Ausgabeverzeichnis", "PDF output directory"},
	// TDN_Verschiebe_von
	{"Verschiebe: ", "Moving: "},
	// TDN_nach
	{" nach ", " to "},
	// TDN_Kopiere_nach
	{"Kopiere nach ", "Copying to "},
	// TDN_Fehler_beim_Kopieren
	{"Fehler beim Kopieren: ", "Error while copying: "},
	// TDN_Fehler_beim_Verschieben
	{"Fehler beim Verschieben: ", "Error while moving: "},
	// TDN_Fehler_beim_PDF_Schreiben
	{"Fehler beim Schreiben der PDF: ", "Error writing PDF: "},
	// TDN_PDF_gespeichert
	{"PDF gespeichert: ", "PDF saved: "},
	// TDN_kein_Timestamp_gefunden
	{"Kein Timestamp_Erstellung_Datensatz in Datei, nutze Dateidatum: ",
	 "No Timestamp_Erstellung_Datensatz in file, using file date: "},
	// TDN_pvirtVorgbSpeziell
	{"pvirtVorgbSpeziell() (doc.net)", "pvirtVorgbSpeziell() (doc.net)"},
	{"", ""}
};

class TxB TxtDN((const char * const * const * const *)dn_T);

// ── Zusätzliche Member-Variablen ─────────────────────────────────────────────
// Da wir kein Erbrecht auf hhcl haben, nutzen wir file-scope Variablen.
// (Alternative: Patch in labimp.h – hier bewusst non-invasiv gehalten.)

// ===========================================================================
// NAMESPACE docnet - Konfigurationsvariablen und Hilfsfunktionen
// ===========================================================================
// Alle doc.net-spezifischen Funktionen und Variablen leben in diesem
// Namespace um Namenskonflikte mit dem Rest von labimp zu vermeiden.
//
// Verzeichniskonfiguration (aus ~/.config/labimp.conf):
//   qvz    - Quelldateiverz.: doc.net legt LDT3-Dateien hier ab
//   zvz[4] - bis zu 4 optionale Kopierziele (z.B. Turbomed-Einleseverz.)
//   pdfvz  - Ausgabeverzeichnis fuer extrahierte PDF-Befunde


namespace docnet {
	string qvz;           // Quelldateiverzeichnis (doc.net legt hier ab)
	string zvz[4];        // bis zu 4 Kopierziele
	string pdfvz;         // PDF-Ausgabeverzeichnis

	// ── Basis64-Dekodierungstabelle ──────────────────────────────────────────
	static const string b64chars =
		"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";


// -- Base64-Dekodierung ------------------------------------------------------
// Standard RFC 4648 Dekodierung. LDT3-Anhaenge (FK 6329) enthalten den
// PDF-Befund als Base64-kodierte Zeichenkette, die hier in Bytes
// umgewandelt wird, um die PDF-Datei zu schreiben.

	// Dekodiert einen Base64-String in Bytes
	static vector<unsigned char> b64decode(const string &encoded) {
		vector<unsigned char> out;
		int val = 0, bits = -8;
		for (unsigned char c : encoded) {
			if (c == '=' || c == '\n' || c == '\r' || c == ' ')
				continue;
			size_t pos = b64chars.find(c);
			if (pos == string::npos)
				continue;
			val = (val << 6) + (int)pos;
			bits += 6;
			if (bits >= 0) {
				out.push_back((unsigned char)((val >> bits) & 0xFF));
				bits -= 8;
			}
		}
		return out;
	}

	// ── Zeitstempel-Parser für LDT3 (Felder 7278=Datum, 7279=Uhrzeit) ───────

// -- LDT3-Zeitstempel-Parser -------------------------------------------------
// LDT3 kodiert Zeitstempel in separaten Feldern:
//   FK 7278 = Datum im Format YYYYMMDD
//   FK 7279 = Uhrzeit im Format HHMMSS
// Beide Felder stehen innerhalb eines Obj_0054-Blocks.
// Gibt true zurueck wenn ein gueltiger Zeitstempel rekonstruiert wurde.

	// Gibt true zurück und befüllt *tm, wenn beide Felder gültig sind.
	static bool parseLDT3Timestamp(const string &dat8, const string &tim6, struct tm *out) {
		if (dat8.size() < 8 || tim6.size() < 6)
			return false;
		memset(out, 0, sizeof(*out));
		// Datum: YYYYMMDD
		out->tm_year = atoi(dat8.substr(0, 4).c_str()) - 1900;
		out->tm_mon  = atoi(dat8.substr(4, 2).c_str()) - 1;
		out->tm_mday = atoi(dat8.substr(6, 2).c_str());
		// Uhrzeit: HHMMSS
		out->tm_hour = atoi(tim6.substr(0, 2).c_str());
		out->tm_min  = atoi(tim6.substr(2, 2).c_str());
		out->tm_sec  = atoi(tim6.substr(4, 2).c_str());
		out->tm_isdst = -1;
		return (out->tm_year > 100 && out->tm_mday >= 1 && out->tm_mday <= 31);
	}

	// ── Zieldateiname aus Zeitstempel + laufender Nummer ─────────────────────
	// Muster: Labor<YYYYMMDD>_<HHMMSS>_<lfdnr>.ldt

// -- Zieldateiname berechnen -------------------------------------------------
// Erzeugt eindeutigen Dateinamen: Labor<YYYYMMDD>_<HHMMSS>_<lfdnr>.ldt
// Die laufende Nummer wird hochgezaehlt bis der Name im Zielverzeichnis
// noch nicht existiert. Verhindert Ueberschreibungen wenn mehrere Dateien
// im selben Sekundentakt ankommen.

	// Erhöht lfdnr so lange, bis kein gleichnamiges File in zieldir existiert.
	static string zieldateiname(const string &zieldir, const struct tm &ts) {
		char buf[64];
		for (unsigned lfd = 1; lfd <= 9999; ++lfd) {
			snprintf(buf, sizeof(buf),
			         "Labor%04d%02d%02d_%02d%02d%02d_%04u.ldt",
			         ts.tm_year + 1900, ts.tm_mon + 1, ts.tm_mday,
			         ts.tm_hour, ts.tm_min, ts.tm_sec, lfd);
			if (!fs::exists(fs::path(zieldir) / buf))
				return string(buf);
		}
		// Fallback (sollte nie auftreten)
		snprintf(buf, sizeof(buf),
		         "Labor%04d%02d%02d_%02d%02d%02d_XXXX.ldt",
		         ts.tm_year + 1900, ts.tm_mon + 1, ts.tm_mday,
		         ts.tm_hour, ts.tm_min, ts.tm_sec);
		return string(buf);
	}

	// ── Timestamp aus LDT3-Datei lesen (Kopfbereich) ─────────────────────────
	// Sucht nach Feldkennung 8218 = "Timestamp_Erstellung_Datensatz"

// -- Timestamp aus LDT3-Datei lesen (Vorabledurchlauf) ----------------------
// Sucht im Dateikopf nach:
//   FK 8218 = "Timestamp_Erstellung_Datensatz" (Label)
//   -> FK 8002 Obj_0054 (Beginn Timestamp-Objekt)
//      FK 7278 = Datum, FK 7279 = Uhrzeit
//   -> FK 8003 Obj_0054 (Ende Timestamp-Objekt)
// Fallback: Dateidatum (st_mtime) falls kein Timestamp in Datei.
// Dieser Timestamp wird fuer die Umbenennung der Datei verwendet.

	// und liest die unmittelbar folgenden 7278/7279 innerhalb des nächsten Obj_0054.
	static bool leseTimestamp(const string &pfad, struct tm *ts) {
		// Zeichensatzerkennung wie in dverarbeit
		string zeilen_text;
		{
			ifstream f(pfad);
			if (!f.is_open()) return false;
			ostringstream ss;
			ss << f.rdbuf();
			zeilen_text = ss.str();
		}
		if (zeilen_text.empty()) return false;

		istringstream iss(zeilen_text);
		string zeile;
		bool in_timestamp_obj = false;
		bool found8218 = false;
		string dat8, tim6;

		while (getline(iss, zeile)) {
			if (zeile.size() < 7) continue;
			// Zeilenende-CR entfernen
			if (!zeile.empty() && zeile.back() == '\r')
				zeile.pop_back();
			string fid = zeile.substr(3, 4);
			string inh = zeile.substr(7);

			if (fid == "8218" && inh.find("Timestamp_Erstellung_Datensatz") != string::npos) {
				found8218 = true;
				in_timestamp_obj = false;
				dat8.clear();
				tim6.clear();
				continue;
			}
			if (found8218) {
				// Nächstes Obj_0054 beginnt: 8001 Obj_0054
				if (fid == "8001" && inh.find("Obj_0054") != string::npos) {
					in_timestamp_obj = true;
					continue;
				}
				// Obj endet: 8003 Obj_0054
				if (fid == "8003" && inh.find("Obj_0054") != string::npos) {
					if (in_timestamp_obj && !dat8.empty()) {
						return parseLDT3Timestamp(dat8, tim6, ts);
					}
					in_timestamp_obj = false;
					found8218 = false;
				}
				if (in_timestamp_obj) {
					if (fid == "7278") dat8 = inh;
					else if (fid == "7279") tim6 = inh;
				}
			}
		}
		// Fallback: Dateidatum
		struct stat st{};
		if (!lstat(pfad.c_str(), &st)) {
			struct tm *lt = localtime(&st.st_mtime);
			if (lt) {
				*ts = *lt;
				return true;
			}
		}
		return false;
	}

	// ── PDF aus LDT3-Datei extrahieren ───────────────────────────────────────
	// Sucht 8242 = "base64-kodierte_Anlage" gefolgt von 6329-Blöcken.

// -- PDF-Extraktion aus LDT3-Datei -------------------------------------------
// LDT3 kann Anhaenge (PDF-Befunde) Base64-kodiert enthalten.
// Struktur:
//   FK 8242 = "base64-kodierte_Anlage" (Ankuendigung des Anhangs)
//   FK 6329 = <chunk>  (ein Stueck des Base64-Textes, beliebig viele Zeilen)
//   naechste andere FK = Ende des Anhangs
//
// Alle Chunks werden zusammengefuegt, Base64-dekodiert und als .pdf
// in pdfvz gespeichert. Bei Namenskollision wird _1, _2, ... angehaengt.
// FK 6329 wird in ldt3ToTmp() ignoriert (wird nur hier extrahiert).

	// Speichert in pdfvz/<zieldatname_ohne_ldt>.pdf
	static void extrahierePDF(const string &ldtpfad,
	                           const string &zielname_ohne_endung,
	                           const string &zielverz,
	                           const TxB &TxtDN_ref,
	                           const int obverb, const int oblog)
	{
		if (zielverz.empty()) return;

		ifstream f(ldtpfad);
		if (!f.is_open()) return;

		vector<string> b64chunks;
		bool in_attachment = false;
		string zeile;

		while (getline(f, zeile)) {
			if (zeile.size() < 7) continue;
			if (!zeile.empty() && zeile.back() == '\r')
				zeile.pop_back();
			string fid = zeile.substr(3, 4);
			string inh = zeile.substr(7);

			if (fid == "8242") {
				// "base64-kodierte_Anlage"
				string inh_low = inh;
				transform(inh_low.begin(), inh_low.end(), inh_low.begin(), ::tolower);
				if (inh_low.find("base64") != string::npos) {
					in_attachment = true;
				}
			} else if (fid == "6329" && in_attachment) {
				b64chunks.push_back(inh);
			} else if (in_attachment && fid != "6329") {
				// Ende des Anhangs
				in_attachment = false;
			}
		}
		f.close();

		if (b64chunks.empty()) return;

		// Zusammenführen und dekodieren
		string raw_b64;
		for (const auto &chunk : b64chunks)
			raw_b64 += chunk;

		// Whitespace entfernen
		raw_b64.erase(remove_if(raw_b64.begin(), raw_b64.end(),
		                        [](char c){ return c == '\n' || c == '\r' || c == ' '; }),
		              raw_b64.end());

		auto pdf_bytes = b64decode(raw_b64);
		if (pdf_bytes.empty()) return;

		// Sicherstellen, dass Zielverzeichnis existiert
		try {
			fs::create_directories(zielverz);
		} catch (const exception &e) {
			fLog(rots + string(TxtDN_ref[TDN_Fehler_beim_PDF_Schreiben]) +
			     zielverz + ": " + e.what() + schwarz, 1, oblog);
			return;
		}

		string pdfpfad = zielverz + "/" + zielname_ohne_endung + ".pdf";
		// Falls Datei schon existiert: nummerieren
		if (fs::exists(pdfpfad)) {
			unsigned n = 1;
			do {
				pdfpfad = zielverz + "/" + zielname_ohne_endung +
				          "_" + to_string(n++) + ".pdf";
			} while (fs::exists(pdfpfad) && n < 9999);
		}

		ofstream pf(pdfpfad, ios::binary);
		if (!pf.is_open()) {
			fLog(rots + string(TxtDN_ref[TDN_Fehler_beim_PDF_Schreiben]) +
			     pdfpfad + schwarz, 1, oblog);
			return;
		}
		pf.write(reinterpret_cast<const char *>(pdf_bytes.data()), pdf_bytes.size());
		pf.close();

		fLog(gruens + string(TxtDN_ref[TDN_PDF_gespeichert]) + blau + pdfpfad + schwarz,
		     obverb, oblog);
	}

	// ── LDT3 → LDT2 Konvertierung (flaches Mapping) ─────────────────────────
	// Liest eine LDT3-Datei und schreibt eine temporäre LDT1/2-kompatible Datei,
	// die dverarbeit() direkt lesen kann.
	//
	// Strategie: Wir laufen durch die LDT3-Datei und sammeln die Hierarchie
	// in einem einfachen Zustand. Für jeden Patienten-Satz (Obj_8205 o.ä.)
	// schreiben wir einen LDT2-kompatiblen Block mit 8000/8100 … 8221.
	//
	// Felder die 1:1 übernommen werden (gleiche Kennung in LDT2 und LDT3):
	//   3101, 3102, 3103, 3110, 3000, 3119,
	//   8310, 8311, 8401, 8403, 8405, 8407, 8609,
	//   8410, 8411, 8418, 8420, 8421, 8422, 8460, 8461, 8462,
	//   8428, 8430, 8431, 8432,
	//   8320, 8321, 8322, 8323,
	//   8480, 8490,
	//   8242, 6329,     ← PDF-Anhang
	//   0201, 0203, 0205, 0211, 0212, 0215, 0216,
	//   9212
	//
	// Neu gemappte Felder (LDT3 → LDT2):
	//   7278 (Datum YYYYMMDD) + 7279 (Zeit HHMMSS) im Kontext:
	//     Timestamp_Auftragseingang   → 8301 (Eingangsdatum, YYYYMMDD) + 8302/8303
	//     Timestamp_Befunderstellung  → 8302/8303
	//     Timestamp_Materialabnahme   → 8432/8433
	//   3564 (Ergebnistext in BAK-Block) → 8480
	//   7306 (Ergebniscode)         → 8418 (Teststatus)
	//   7302 (Normbereich-Code kA)  → ignorieren (Normbereich kommt via 8460)
	//   7301 (Keimzahl)             → 8480 als Text

// ===========================================================================
// LDT3 -> LDT2-KONVERTIERUNG  (Kernfunktion des Moduls)
// ===========================================================================
// Liest eine LDT3-Datei und schreibt eine temporaere LDT1/2-kompatible
// Datei nach /tmp/, die dverarbeit() in labimp.cpp direkt lesen kann.
//
// HINTERGRUND: LDT3 ist hierarchisch (Objekte mit Unterobjekten),
// LDT2 ist flat (einfache Feldliste). dverarbeit() kennt nur LDT2.
//
// ZWEISTUFIGER ANSATZ:
//
// Stufe 1 - Vorabledurchlauf:
//   Liest die Datei einmal durch um Metadaten zu sammeln:
//   - Arztdaten (Name, Nr, LANR, Adresse) aus dem Patientenblock
//     (vor dem ersten Geburtstagsdatum FK 3103)
//   - Laborname aus dem ersten 1250-Feld nach FK 8239
//     (auch wenn 8002/8003-Strukturfelder dazwischen liegen)
//
// Stufe 2 - Konvertierung:
//   Zweiter Lesedurchlauf. Ausgabe in tmp-Datei.
//   Zustandsvariablen:
//   - in_header: wir sind im 8220-Datenpaket-Header
//   - header_emitted: LDT2-Header wurde schon geschrieben
//   - in_ts_obj: wir sind in einem Obj_0054-Timestamp-Block
//   - objstack: Stack der geoeffneten Objekte
//   - emit8302/emit8311/emit8418: Flags gegen Mehrfachausgabe
//     (werden bei jedem neuen Patientenblock zurueckgesetzt)
//
// WICHTIGE FELDMAPPINGS (LDT3 -> LDT2):
//   8000 8220 -> emit Header (8000 8220 + Arztdaten + Labor 8320/8323)
//   8000 8205 -> emit 8000 8205 (Patient), Flags zuruecksetzen
//   8002/8003 -> Objekt-Start/Ende, Timestamp-Tracking
//   7278+7279 in Obj_0054 -> 8301 (Eingang) oder 8302 (Befund) + 8303
//   7305 -> 8311 (Auftragsschluessel, nur einmal pro Patient)
//   7306 -> 8418 (Teststatus: 01=E, 04=T, nur einmal pro Wert)
//   3564 -> 8480 (Ergebnistext/Kommentar)
//   7301 -> 8480 "Keimzahl: <n>"
//   0105 -> ignoriert (Auftragsnr kommt direkt als 8310 im Patientenblock)
//   8239 -> ignoriert (Laborname kommt aus pre_labor via 8320/8323)
//   8418 direkt -> ignoriert (nur 7306-Mapping verwenden)
//   8428/8430/8431 -> nur im Patientenblock ausgeben (Probenmaterial)
//   6329 -> ignoriert (PDF-Base64, wird nur in extrahierePDF() verarbeitet)
//   8401 -> ignoriert (Befundart-Code, Teststatus kommt via 7306)
//   Viele LDT3-Strukturfelder -> ignoriert (8110, 8114, 8117, ...)


	static string ldt3ToTmp(const string &ldtpfad)
	{
		string tmp = "/tmp/" + fs::path(ldtpfad).filename().string();
		// LDT3: 8000=Satzstart, 8001=Satzende, 8002=Obj-Start, 8003=Obj-Ende
		// Zweistufig: erst Arztdaten sammeln, dann konvertieren
		// Stufe 1: Arztdaten der Praxis aus Patientenblock vorab lesen
		string pre203, pre201, pre212, pre205, pre215, pre216;
		string pre_labor, pre_ort;
		{
			ifstream f1(ldtpfad);
			string z; bool in_pat=false, after8239=false;
			while(getline(f1,z)) {
				if (z.size()<7) continue;
				if (!z.empty()&&z.back()=='\r') z.pop_back();
				string fid=z.substr(3,4), inh=z.substr(7);
				// Laborname aus Header sammeln (vor in_pat)
				if (fid=="8239") { after8239=true; continue; }
				if (fid=="1250"&&after8239&&pre_labor.empty()) { pre_labor=inh; after8239=false; continue; }
				if (fid!="1250"&&fid!="8239"&&fid!="8002"&&fid!="8003") after8239=false;
				if (fid=="8000") { in_pat=(inh!="8220"&&inh.substr(0,4)!="8220"&&inh!="8221"&&inh.substr(0,4)!="8221"); continue; }
				if (fid=="8001") { in_pat=false; continue; }
				if (!in_pat) continue;
				if (fid=="3103") break;
				if (fid=="0203") pre203=inh;
				if (fid=="0201") pre201=inh;
				if (fid=="0212") pre212=inh;
				if (fid=="0205") pre205=inh;
				if (fid=="0215") pre215=inh;
				if (fid=="0216") pre216=inh;
			}
		}
		// Stufe 2: Konvertierung
		ifstream fin(ldtpfad);
		if (!fin.is_open()) return "";
		ofstream fout(tmp);
		if (!fout.is_open()) return "";
		auto emit = [&](const string &fid, const string &inh) {
			size_t len = 3 + 4 + inh.size() + 2;
			if (len > 999) len = 999;
			char buf[8];
			snprintf(buf, sizeof(buf), "%03zu", len);
			fout << buf << fid << inh << "\r\n";
		};
		vector<string> objstack;
		string cur_ts_dat, cur_ts_tim, cur_ts_label, pending_label;
		bool in_header=false, header_emitted=false, in_ts_obj=false;
		bool emit8302=false, emit8311=false, emit8418=false; // nur einmal ausgeben
		string ldt_version;
		auto emitHeader = [&]() {
			if (header_emitted) return;
			emit("8000","8220"); emit("8100","0000");
			if (!ldt_version.empty()) emit("9212",ldt_version);
			// Arztdaten in den 8220-Header einfuegen (wie LDT2)
			if (!pre201.empty()) emit("0201",pre201);
			if (!pre203.empty()) emit("0203",pre203);
			if (!pre205.empty()) emit("0205",pre205);
			if (!pre212.empty()) emit("0212",pre212);
			if (!pre215.empty()) emit("0215",pre215);
			if (!pre216.empty()) emit("0216",pre216);
			// Labor: 8320=Name triggert rlab.schreib() in dverarbeit via 8323
			if (!pre_labor.empty()) { emit("8320",pre_labor); emit("8323","."); }
			header_emitted=true;
		};
		string zeile;
		while (getline(fin,zeile)) {
			if (zeile.size()<7) continue;
			if (!zeile.empty()&&zeile.back()=='\r') zeile.pop_back();
			string fid=zeile.substr(3,4), inh=zeile.substr(7);
			if (fid=="8002") {
				objstack.push_back(inh);
				if (inh.find("Obj_0054")!=string::npos) {
					in_ts_obj=true; cur_ts_dat.clear(); cur_ts_tim.clear();
					cur_ts_label=pending_label; pending_label.clear();
				} else { pending_label.clear(); }
				continue;
			}
			if (fid=="8003") {
				if (in_ts_obj&&inh.find("Obj_0054")!=string::npos&&!cur_ts_dat.empty()) {
					string t4=cur_ts_tim.size()>=4?cur_ts_tim.substr(0,4):cur_ts_tim;
					if (cur_ts_label=="ts_eingang") { emit("8301",cur_ts_dat); if (!t4.empty()) emit("8303",t4); }
					else if (cur_ts_label=="ts_befund") { if (!emit8302) { emit("8302",cur_ts_dat); if (!t4.empty()) emit("8303",t4); emit8302=true; } }
					else if (cur_ts_label=="ts_abnahme") { emit("8432",cur_ts_dat); if (!t4.empty()) emit("8433",t4); }
					in_ts_obj=false; cur_ts_dat.clear(); cur_ts_tim.clear(); cur_ts_label.clear();
				} else if (inh.find("Obj_0054")!=string::npos) { in_ts_obj=false; }
				if (!objstack.empty()) objstack.pop_back();
				continue;
			}
			if (fid=="8001") continue;
			if (fid=="8000") {
				if (inh=="8220"||(!inh.empty()&&inh.substr(0,4)=="8220")) {
					in_header=true; emitHeader();
				} else if (inh=="8221"||(!inh.empty()&&inh.substr(0,4)=="8221")) {
					in_header=false; emit("8000","8221"); emit("8100","0000");
				} else {
					in_header=false; emitHeader();
					emit8302=false; emit8311=false; emit8418=false;
					emit("8000",inh); emit("8100","0000");
				}
				continue;
			}
			if (in_ts_obj&&fid=="7278") { cur_ts_dat=inh; continue; }
			if (in_ts_obj&&fid=="7279") { cur_ts_tim=inh; continue; }
			if (fid=="7273"||fid=="7278"||fid=="7279") continue;
			if (fid=="8218") {
				if (inh.find("Timestamp_Auftragseingang")!=string::npos) pending_label="ts_eingang";
				else if (inh.find("Timestamp_Befunderstellung")!=string::npos) pending_label="ts_befund";
				else if (inh.find("Timestamp_Materialabnahme")!=string::npos||inh.find("Timestamp_Materialentnahme")!=string::npos) pending_label="ts_abnahme";
				else if (inh.find("Timestamp_Eingangserfassung")!=string::npos) pending_label="ts_eingang_material";
				else if (inh.find("Timestamp_Erstellung_Datensatz")!=string::npos) pending_label="ts_erstellung";
				else pending_label.clear();
				continue;
			}
			if (fid=="8110"||fid=="6303"||fid=="9300"||fid=="7302"||fid=="7304"||fid=="8401"||fid=="6329") continue; // 6329=PDF-Base64
			if (fid=="8114"||fid=="8122"||fid=="8136"||fid=="8147"||fid=="8145"||fid=="8117") continue;
			if (fid=="8119"||fid=="8131"||fid=="8132"||fid=="8143"||fid=="8151"||fid=="8160") continue;
			if (fid=="8161"||fid=="8212"||fid=="8225"||fid=="8228"||fid=="8229") continue;
			if (fid=="0001") { ldt_version=inh; emit("9212","LDT"+(inh.size()>4?inh.substr(4):inh)); continue; }
			// Arztfelder werden bereits im Header ausgegeben - hier ignorieren
			if (fid=="0201"||fid=="0203"||fid=="0212"||fid=="0205"||fid=="0215"||fid=="0216") continue;
			if (fid=="3564") { emit("8480",inh); continue; }
			if (fid=="7301") { if (!inh.empty()&&inh!="0") emit("8480","Keimzahl: "+inh); continue; }
			if (fid=="7305") { if (!emit8311) { emit("8311",inh); emit8311=true; } else (void)0; continue; }
			if (fid=="7306") { if (!emit8418) { emit("8418",(inh=="01"?"E":inh=="04"?"T":inh=="99"?"E":inh)); emit8418=true; } else (void)0; continue; }
			if (fid=="8239") continue; // Laborname kommt aus pre_labor in emitHeader
			if (fid=="3119") { emit("3119",inh); continue; }
			if (fid=="3000") { emit("3000",inh); continue; }
			if (fid=="0105") continue; // 8310-Auftragsnummer kommt direkt aus Patientenblock
			if (fid=="8219") { pending_label="ts_befund"; continue; }
			if (fid=="8215") { pending_label="ts_eingang"; continue; }
			// 8401 bereits in ignore-Liste
			if (fid=="8418") continue; // nur 7306-Mapping verwenden
			if ((fid=="3101"||fid=="3102"||fid=="3115"||fid=="3107"||fid=="3109"||fid=="3112"||fid=="3113"||fid=="3114")&&in_header) continue; // Arztfelder im Header ignorieren
			if (fid=="8311") { if (!emit8311) { emit("8311",inh); emit8311=true; } continue; }
			if (fid=="8216") continue;
			// Probenmaterial: nur im Patientenblock ausgeben, nicht im Header
			if (fid=="8428"||fid=="8430"||fid=="8431") { if (!in_header) emit(fid,inh); continue; }
			emit(fid,inh);
		}
		if (header_emitted) fout << "01380008221\r\n";
		fin.close(); fout.close();
		return tmp;
	}



} // namespace docnet

// pvirtVorgbSpeziell() ist in turbomed.cpp definiert und dort um den
// docnet.h-Include erweitert. Keine zweite Definition hier (ODR).

// ── Zusätzliche Kommandozeilenoptionen eintragen ─────────────────────────────
// virtinitopt() wird in labimp.cpp definiert und ruft dhcl::virtinitopt() auf.
// Wir können hier keine zweite Definition von virtinitopt() haben.
// Stattdessen: die neuen Optionen werden direkt in virtinitopt() eingefügt.
// → Patch-Anleitung: In labimp.cpp virtinitopt() VOR dem Aufruf von
//   dhcl::virtinitopt() folgende Zeilen einfügen:
//
//   // doc.net-Erweiterungsoptionen
//   opn<<new optcl("qvz",&docnet::qvz,pverz,TDN_qvz_k,TDN_qvz_l,...);
//   opn<<new optcl("zvz1",&docnet::zvz[0],pverz,TDN_zvz1_k,TDN_zvz1_l,...);
//   … usw.
//
// Da wir virtinitopt() nicht überschreiben dürfen (ODR), werden die neuen
// Optionen über eine separate Initialisierungsfunktion registriert, die
// pvirtVorgbSpeziell() aufruft:

// ── doc.net-Hauptschleife: Quelldatei-Polling, Verschieben, Konvertieren ─────
// Diese Funktion wird AUS pvirtfuehraus() aufgerufen (Patch, s.u.).
// Sie kann auch standalone als Testfunktion genutzt werden.


// ===========================================================================
// HAUPTSCHLEIFE: Quelldatei-Polling, Verschieben, Konvertieren
// ===========================================================================
// Diese Funktion wird von pvirtfuehraus() in labimp.cpp aufgerufen,
// bevor die normale find()-Schleife die Dateien aus ldatvz verarbeitet.
//
// ABLAUF fuer jede .ldt-Datei in qvz:
//   1. Timestamp aus Dateiinhalt lesen (oder Dateidatum als Fallback)
//   2. Umbenennen nach ldatvz/Labor<YYYYMMDD>_<HHMMSS>_<lfdnr>.ldt
//   3. Kopieren in bis zu 4 Zielverzeichnisse (zvz1..zvz4)
//   4. PDF-Anhang extrahieren und in pdfvz speichern
//   5. LDT3 -> LDT2-Konvertierung (ldt3ToTmp) nach /tmp/
//   6. dverarbeit_public() mit der Tmp-Datei aufrufen
//   7. Tmp-Datei loeschen
//   8. Original-LDT3-Datei nach fertigvz verschieben (verhindert
//      Doppelverarbeitung durch die normale find()-Schleife)
//
// AM ANFANG: Cleanup alter _tmp.ldt-Dateien in ldatvz und
//            Labor*.ldt-Dateien in /tmp/ aus abgebrochenen Laeufen.

void hhcl_docnet_verarbeitqvz(hhcl *h, const int obverb, const int oblog)
{
	const string &qvz    = docnet::qvz;
	const string &ldatvz = h->getLdatvz();   // Accessor nötig – s.u.
	// Aufr�umen: veraltete Tmp-Dateien in /tmp/ und ldatvz l�schen
	{
		error_code ec_cl;
		// _tmp.ldt-Dateien in ldatvz l�schen
		if (!ldatvz.empty()) {
			for (auto& e : fs::directory_iterator(ldatvz, ec_cl)) {
				string fn = e.path().filename().string();
				if (fn.size()>8 && fn.substr(fn.size()-8)=="_tmp.ldt")
					try { fs::remove(e.path()); } catch(...) {}
			}
		}
		// Labor*-Dateien in /tmp/ l�schen
		for (auto& e : fs::directory_iterator("/tmp", ec_cl)) {
			string fn = e.path().filename().string();
			if (fn.size()>4 && fn.substr(0,5)=="Labor" && fn.substr(fn.size()-4)==".ldt")
				try { fs::remove(e.path()); } catch(...) {}
		}
	}
	const string &pdfvz  = docnet::pdfvz;

	if (qvz.empty() || !fs::exists(qvz)) return;

	// Alle *.ldt-Dateien im qvz sammeln
	vector<fs::path> dateien;
	try {
		for (const auto &entry : fs::directory_iterator(qvz)) {
			if (!entry.is_regular_file()) continue;
			string ext = entry.path().extension().string();
			// case-insensitive Vergleich
			transform(ext.begin(), ext.end(), ext.begin(), ::tolower);
			if (ext == ".ldt")
				dateien.push_back(entry.path());
		}
	} catch (const exception &e) {
		fLog(rots + "docnet: Fehler beim Lesen von " + qvz + ": " + e.what() + schwarz,
		     1, oblog);
		return;
	}

	for (const auto &qpfad : dateien) {
		// 1. Zeitstempel aus Datei lesen
		struct tm ts{};
		bool ts_ok = docnet::leseTimestamp(qpfad.string(), &ts);
		if (!ts_ok) {
			fLog(rots + string(TxtDN[TDN_kein_Timestamp_gefunden]) +
			     qpfad.string() + schwarz, 1, oblog);
			// trotzdem weitermachen mit Dateidatum (leseTimestamp hat Fallback)
		}

		// Zieldateiname berechnen
		string zname = docnet::zieldateiname(ldatvz, ts);
		string zpfad = ldatvz + "/" + zname;

		// 2. Verschieben nach ldatvz
		fLog(blaus + string(TxtDN[TDN_Verschiebe_von]) + qpfad.string() +
		     string(TxtDN[TDN_nach]) + zpfad + schwarz, obverb, oblog);

		error_code ec;
		fs::rename(qpfad, zpfad, ec);
		if (ec) {
			// rename über Dateisystemgrenzen: kopieren + löschen
			try {
				fs::copy_file(qpfad, zpfad, fs::copy_options::overwrite_existing);
				fs::remove(qpfad);
			} catch (const exception &e2) {
				fLog(rots + string(TxtDN[TDN_Fehler_beim_Verschieben]) +
				     qpfad.string() + ": " + e2.what() + schwarz, 1, oblog);
				continue;
			}
		}

		// 3. Kopieren in Zielverzeichnisse zvz1..zvz4
		for (int i = 0; i < 4; ++i) {
			const string &z = docnet::zvz[i];
			// leer oder "-" bedeutet: Kopierziel nicht gesetzt → überspringen
			if (z.empty() || z == "-") continue;
			string cpfad = z + "/" + zname;
			fLog(blaus + string(TxtDN[TDN_Kopiere_nach]) +
			     cpfad + schwarz, obverb, oblog);
			try {
				fs::create_directories(z);
				fs::copy_file(zpfad, cpfad, fs::copy_options::overwrite_existing);
			} catch (const exception &e) {
				fLog(rots + string(TxtDN[TDN_Fehler_beim_Kopieren]) +
				     cpfad + ": " + e.what() + schwarz, 1, oblog);
			}
		}

		// 4. PDF extrahieren
		string zname_ohne_endung = zname.substr(0, zname.rfind('.'));
		docnet::extrahierePDF(zpfad, zname_ohne_endung, pdfvz,
		                      TxtDN, obverb, oblog);

		// 5. LDT3 → LDT2-Konvertierung in Temp-Datei, dann dverarbeit()
		string tmppfad = docnet::ldt3ToTmp(zpfad);
		if (tmppfad.empty()) {
			fLog(rots + "docnet: Konvertierung fehlgeschlagen: " + zpfad + schwarz,
			     1, oblog);
			continue;
		}

		// dverarbeit() über den normalen Mechanismus aufrufen:
		// Da pvirtfuehraus() die Dateien aus ldatvz einliest und dverarbeit()
		// selbst aufruft, müssen wir hier NICHT erneut dverarbeit() rufen –
		// die temporäre Datei wird beim nächsten Durchlauf der Hauptschleife
		// von find() nicht gefunden (sie endet auf .docnet_tmp, nicht .ldt).
		// Stattdessen: direkt aufrufen.
		string datid, patelid;

		// Dateidat aus Originaldateinamen parsen (LaborYYYYMMDD_HHMMSS)
		{
			string bn = zname; // z.B. Labor20260620_221857_0001.ldt
			string dateidat_str;
			if (bn.substr(0,5)=="Labor" && bn.size()>13) {
				string dt = bn.substr(5,15);
				struct tm dtm{}; char buf[15];
				if (strptime(dt.c_str(),"%Y%m%d_%H%M%S",&dtm)) { strftime(buf,sizeof(buf),"%Y%m%d%H%M%S",&dtm); dateidat_str=buf; }
				else { dt=bn.substr(5,13); if (strptime(dt.c_str(),"%Y%m%d_%H%M",&dtm)) { strftime(buf,sizeof(buf),"%Y%m%d%H%M00",&dtm); dateidat_str=buf; } }
			}
			h->setDateidat(dateidat_str);
		}
		h->initDB_public();
		h->dverarbeit_public(tmppfad, &datid, &patelid);

		// Temp-Datei aufräumen
		try { fs::remove(tmppfad); } catch (...) {}

		// Original-LDT3-Datei nach fertigvz verschieben damit
		// die normale find-Schleife sie nicht nochmal verarbeitet
		const string &fertigvz = h->getFertigvz();
		if (!fertigvz.empty() && fertigvz != ldatvz) {
			string ziel = fertigvz + "/" + zname;
			error_code ec2;
			fs::rename(zpfad, ziel, ec2);
			if (ec2) {
				try {
					fs::copy_file(zpfad, ziel, fs::copy_options::overwrite_existing);
					fs::remove(zpfad);
				} catch (...) {}
			}
		}
	}
}

// ── Hinweis für virtinitopt-Patch ────────────────────────────────────────────
//
// In labimp.cpp::hhcl::virtinitopt() VOR dhcl::virtinitopt() einfügen:
//
//   // ── doc.net-Optionen (docnet.cpp) ──
//   opn<<new optcl("qvz",&docnet::qvz,pverz,
//                  TDN_qvz_k,TDN_qvz_l,&TxtDN,TDN_Quelldateiverzeichnis_doc_net,
//                  0,-1,string(),-1,!docnet::qvz.empty(),
//                  TxtDN[TDN_Quelldateiverzeichnis_doc_net]);
//   opn<<new optcl("zvz1",&docnet::zvz[0],pverz,
//                  TDN_zvz1_k,TDN_zvz1_l,&TxtDN,TDN_Kopierziel_1,
//                  0,-1,string(),-1,!docnet::zvz[0].empty(),
//                  TxtDN[TDN_Kopierziel_1]);
//   opn<<new optcl("zvz2",&docnet::zvz[1],pverz,
//                  TDN_zvz2_k,TDN_zvz2_l,&TxtDN,TDN_Kopierziel_2,
//                  0,-1,string(),-1,!docnet::zvz[1].empty(),
//                  TxtDN[TDN_Kopierziel_2]);
//   opn<<new optcl("zvz3",&docnet::zvz[2],pverz,
//                  TDN_zvz3_k,TDN_zvz3_l,&TxtDN,TDN_Kopierziel_3,
//                  0,-1,string(),-1,!docnet::zvz[2].empty(),
//                  TxtDN[TDN_Kopierziel_3]);
//   opn<<new optcl("zvz4",&docnet::zvz[3],pverz,
//                  TDN_zvz4_k,TDN_zvz4_l,&TxtDN,TDN_Kopierziel_4,
//                  0,-1,string(),-1,!docnet::zvz[3].empty(),
//                  TxtDN[TDN_Kopierziel_4]);
//   opn<<new optcl("pdfvz",&docnet::pdfvz,pverz,
//                  TDN_pdfvz_k,TDN_pdfvz_l,&TxtDN,TDN_PDF_Ausgabeverzeichnis,
//                  0,-1,string(),-1,!docnet::pdfvz.empty(),
//                  TxtDN[TDN_PDF_Ausgabeverzeichnis]);
//
// In labimp.cpp::hhcl::pvirtfuehraus() AM ANFANG des normalen
// find()-Datei-Verarbeitungsblocks einfügen (vor systemrueck("find …")):
//
//   hhcl_docnet_verarbeitqvz(this, obverb, oblog);
//
// In labimp.h in class hhcl public: hinzufügen:
//   int dverarbeit_public(const string& datei,string *datidp,string *patelidp)
//     { return dverarbeit(datei, datidp, patelidp); }
//   const string& getLdatvz() const { return ldatvz; }
