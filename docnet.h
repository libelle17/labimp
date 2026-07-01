#pragma once
// docnet.h – Vorwärtsdeklarationen für docnet.cpp
// Einbinden in labimp.cpp (nach den anderen #includes)

#include <string>

// ── Enum und TxB-Instanz aus docnet.cpp ─────────────────────────────────────
// Da TxB kein Standard-Header-Typ ist, deklarieren wir nur die Enum-Werte
// und die externen Variablen, die labimp.cpp braucht.

enum TDN_ {
	TDN_qvz_k,
	TDN_qvz_l,
	TDN_zvz1_k,
	TDN_zvz1_l,
	TDN_zvz2_k,
	TDN_zvz2_l,
	TDN_zvz3_k,
	TDN_zvz3_l,
	TDN_zvz4_k,
	TDN_zvz4_l,
	TDN_pdfvz_k,
	TDN_pdfvz_l,
	TDN_Quelldateiverzeichnis_doc_net,
	TDN_Kopierziel_1,
	TDN_Kopierziel_2,
	TDN_Kopierziel_3,
	TDN_Kopierziel_4,
	TDN_PDF_Ausgabeverzeichnis,
	TDN_Verschiebe_von,
	TDN_nach,
	TDN_Kopiere_nach,
	TDN_Fehler_beim_Kopieren,
	TDN_Fehler_beim_Verschieben,
	TDN_Fehler_beim_PDF_Schreiben,
	TDN_PDF_gespeichert,
	TDN_kein_Timestamp_gefunden,
	TDN_pvirtVorgbSpeziell,
	TDN_dokvz_k,
	TDN_dokvz_l,
	TDN_dokdb_host_k,
	TDN_dokdb_host_l,
	TDN_dokdb_user_k,
	TDN_dokdb_user_l,
	TDN_dokdb_pass_k,
	TDN_dokdb_pass_l,
	TDN_dokdb_name_k,
	TDN_dokdb_name_l,
	TDN_dokdb_port_k,
	TDN_dokdb_port_l,
	TDN_Dokumentenverzeichnis,
	TDN_Dokument_DB_Host,
	TDN_Dokument_DB_Benutzer,
	TDN_Dokument_DB_Passwort,
	TDN_Dokument_DB_Name,
	TDN_Dokument_DB_Port,
	TDN_doksubvz_k,
	TDN_doksubvz_l,
	TDN_Dokument_Unterverzeichnis,
	TDN_dok_user_k,
	TDN_dok_user_l,
	TDN_dok_group_k,
	TDN_dok_group_l,
	TDN_Dokument_Owner_User,
	TDN_Dokument_Owner_Gruppe,
	TDN_Fehler_beim_Setzen_Rechte,
	TDN_MAX
};

// TxB-Instanz (definiert in docnet.cpp)
extern class TxB TxtDN;

// ── Namespace docnet – externe Variablen ────────────────────────────────────
namespace docnet {
	extern std::string qvz;
	extern std::string zvz[4];
	extern std::string pdfvz;
	extern std::string dokvz;       // Dokumentenverzeichnis
	extern std::string dokdb_host;  // DB-Host fuer Patientennummer-Suche
	extern std::string dokdb_user;  // DB-Benutzer
	extern std::string dokdb_pass;  // DB-Passwort
	extern std::string dokdb_name;  // DB-Name
	extern std::string dokdb_port;  // DB-Port (Default: 3306)
	extern std::string doksubvz;    // Unterverzeichnis unter dok/<nr>/
	extern std::string dok_user;    // Besitzer (Benutzer) neu angelegter Verzeichnisse
	extern std::string dok_group;   // Besitzer (Gruppe) neu angelegter Verzeichnisse
} // namespace docnet

// ── Freie Funktion (definiert in docnet.cpp) ─────────────────────────────────
class hhcl;
extern int hhcl_docnet_verarbeitqvz(hhcl *h, const int obverb, const int oblog);
// Oeffentliche LDT3-Funktionen (definiert in docnet.cpp)
std::string docnet_ldt3ToTmp(const std::string &pfad);
bool docnet_isLDT3(const std::string &pfad);
void docnet_extrahierePDF(const std::string &ldtpfad, const std::string &zielname_ohne_endung, const int obverb, const int oblog);
