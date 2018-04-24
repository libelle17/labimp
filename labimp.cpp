// '//α' oder '//ω' als Kommentar sind nur fuer die Verwendung dieses Programms als Programmvorlage wichtig
// sed -n '/\/\/α/,/\/\/ω/p;/\/\/ω/a\\' test
// sed -n '/\/\/α/,/\/\/ω/p' test
#include "kons.h" //α
#include "DB.h" 
#include <tiffio.h>
#define VOMHAUPTCODE // um Funktionsdefinition manchmal mit "__attribute__((weak)) " versehen zu können //ω
#include "labimp.h"
// fuer verschiedene Sprachen //α
#define vorsilbe "labory"
const string hhcl::vorsil=vorsilbe;
const string hhcl::tlydat=vorsil+"dat";
const string hhcl::tlyleist=vorsil+"leist";
const string hhcl::tlypgl=vorsil+"pgl";
const string hhcl::tlyplab=vorsil+"plab";
const string hhcl::tlypnb=vorsil+"pnb";
const string hhcl::tlypneu=vorsil+"pneu";
const string hhcl::tlyaerzte=vorsil+"aerzte";
const string hhcl::tlysaetze=vorsil+"saetze";
const string hhcl::tlyus=vorsil+"us";
const string hhcl::tlywert=vorsil+"wert";
const string hhcl::tlybakt=vorsil+"bakt";
const string hhcl::tlyfehlt=vorsil+"fehlt";
const string hhcl::tlyparameter=vorsil+"parameter";
const string hhcl::tlyhinw=vorsil+"hinw";
char const *DPROG_T[T_MAX+1][SprachZahl]={
	// T_virtVorgbAllg
	{"virtVorgbAllg()","virtgeneralprefs()"},
	// T_pvirtVorgbSpeziell
	{"pvirtVorgbSpeziell()","pvirtspecialprefs()"},
	// T_virtMusterVorgb
	{"virtMusterVorgb()","virtsampleprefs"},
	// T_pvirtvorrueckfragen
	{"pvirtvorrueckfragen()","pvirtbeforecallbacks()"},
	// T_virtrueckfragen
	{"virtrueckfragen()","virtcallbacks()"},
	//	T_Fehler_beim_Pruefen_von
	{"Fehler beim Pruefen von: ","Error while examining: "},
	// T_Fuege_ein
	{"Fuege ein: ","Inserting: "}, //ω
	// T_prueflydat
	{"prueflydat()","testlyfiles()"},
	// 	T_prueflyleist,
	{"prueflyleist()","testlyservice()"},
	// T_prueflypgl,
	{"prueflypgl()","testlyparameterequities()"},
	// T_prueflyplab,
	{"prueflyplab()","testlyplab()"},
	// T_prueflypnb,
	{"prueflypnb()","testlypnb()"},
	// T_prueflypneu,
	{"prueflypneu()","testlypneu()"},
	// T_prueflysaetze,
	{"prueflysaetze()","testlysets()"},
	// T_prueflyus,
	{"prueflyus()","testlyus"},
	// T_prueflywert,
	{"prueflywert()","testlyvalue()"},
	// T_prueflybakt,
	{"prueflybakt","testlybact()"},
	// T_eindeutige_Identifikation
	{"eindeutige Identifikation","unique identifier"},
	// T_Pfadname
	{"Pfadname","path name"},
	// T_Name_der_eingelesenen_Labordatei_ohne_Endung
	{"Name der eingelesenen Labordatei ohne Endung","name of the imported laboratory file without suffix"},
	// T_Einlesezeitpunkt
	{"Einlesezeitpunkt","time of import"},
	// T_ob_Einlesen_fertig
	{"ob Einlesen fertig","if import finished"},
	// T_LaborEinlesungen
	{"LaborDateien","laboratory files"},
	// T_Bezug_auf_LaborUS
	{"Bezug auf LaborUS","Reference to LaborUS"},
	// T_8410_Test_Ident_Turbomed
	{"8410 Test-Ident (Turbomed)","8410 Test-Ident (Turbomed)"},
	// T_8434
	{"8434","8434"},
	// T_5001_GNR_Turbomed
	{"5001 GNR (Turbomed)", "5001 GNR (Turbomed)"},
	// T_8406
	{"8406","8406"},
	// T_5005
	{"5005","5005"},
	// T_8614_Abrechnung_durch_1_Labor_2_Einweiser
	{"8614 Abrechnung durch: 1 Labor, 2 Einweiser","billing by: 1 laboratory, 2 admitter"},
	// T_LaborLeistungen
	{"LaborLeistungen","Laboratory services"},
	// T_Laborpgl
	{"Parametergleichheiten","parameter equities"},
	// T_Laborbakt
	{"lybakt","lybact"},
	// T_Laborfehlt
	{"Lyfehlt","lymissing"},
	// T_laborxpneu
	{"lypneu","lypneu"},
	// T_laborparameter
	{"laborparameter","laborparameter"},
	// T_ist_identisch_mit_laborxpneu
	{"ist identisch mit laborxpneu","is identical to laborxpneu"},
	// T_Zeitpunkt_der_Ergaenzung
	{"Zeitpunkt der Ergänzung","Time of addition"},
	// T_8428_Probenmaterial_Ident_Turbomed
	{"8428 Probenmaterial-Ident (Turbomed)","8428 Probenmaterial-Ident (Turbomed)"},
	// T_8430_Probenmaterial_Bezeichnung_Turbomed
	{"8430 Probenmaterial-Bezeichnung (Turbomed)","8430 Probenmaterial-Bezeichnung (Turbomed)"},
	// T_8431_Probenmaterial_Spezifikation_Turbomed
	{"8431 Probenmaterial-Spezifikation (Turbomed)","8431 Probenmaterial-Spezifikation (Turbomed)"},
	// T_8432_Abnahmedatum_Turbomed
	{"8432 Abnahmedatum (Turbomed)","8432 Abnahmedatum (Turbomed)"},
	// T_8480_Ergebnistest_Turbomed
	{"8480 Ergebnistest (Turbomed)","8480 Ergebnistest (Turbomed)"},
	// T_8300_maximale_Laenge_36
	{"8300 (maximale Länge: 36)","8300 (maximale Länge: 36)"},
	// T_Laborplab
	{"Labor","laboratory"},
	// T_Labornb
	{"Normbereiche","normal ranges"},
	// T_Bezug_auf_laborxpneu
	{"Bezug auf laborxpneu","reference to laborxpneu"},
	// T_1_Mann_2_Frau_3_unbek_4_Knabe_5_Maedchen_0_Name_fehlt_9_beide
	{"1=Mann, 2=Frau, 3=unbek, 4=Knabe, 5=Mädchen, 0=Name fehlt, 9=beide","1=man, 2=woman, 3=unknown, 4=boy, 5=girl, 0=name is missing, 9=both"},
	// T_Eingangsdatum_im_Labor
	{"Eingangsdatum im Labor","entry date in the laboratory"},
	// T_untere_Normgrenze
	{"untere Normgrenze","lower border"},
	// T_obere_Normgrenze
	{"obere Normgrenze","upper border"},
	// T_Normbereich
	{"Normbereich","normal range"},
	// T_Haeufigkeit_eines_Laborparameters
	{"Häufigkeit eines Laborparameters","frequency of the laboratory parameter"},
	// T_laborxus_id_des_ersten_Eintrags
	{"laborxus.id des ersten Eintrags","laborxus.id of the first entry"},
	// T_Laborneu
	{"Langtexte, Einheiten und Gruppen zu den Verfahren","long texts, units and groups to the methods"},
	// T_8410_maximale_Laenge_8
	{"8410 maximale Länge: 8","8410 (maximal length: 8)"},
	// T_8411_maximale_Laenge_40
	{"8411 (maximale Länge: 40)","8411 (maximal length: 40)"},
	// T_8421_maximale_Laenge_12
	{"8421 (maximale Länge: 12)","8421 (maximal length: 12)"},
	// T_Bezug_auf_laborxplab_id
	{"Bezug auf laborxplab.id","reference to laborxplab.id"},
	// T_Bezug_auf_laborgruppen_laborgruppe
	{"Bezug auf laborgruppen.laborgruppe","reference to laborgruppen.laborgruppe"},
	// T_Laborsaetze
	{"Laborsaetze","laboratory sets"},
	// T_zum_Bezug_fuer_LaborUS
	{"zum Bezug für LaborUS","for reference of LaborUS"},
	// T_Bezug_zu_LaborDat
	{"Bezug zu LaborDat","reference to LaborDat"},
	// T_8000_Satzart_Turbomed
	{"8000 Satzart (Turbomed)","8000 set category (turbomed)"},
	// T_8100_Satzlaenge_Turbomed
	{"8100 Satzlänge (Turbomed)","8100 set length (turbomed)"},
	// T_8100_Satzlaenge_Turbomed_nach_8221_in_Feld_8000
	{"8100 Satzlänge (Turbomed), nach 8221 in Feld 8000","8100 set length (turbomed), after 8221 in field 8000"},
	// T_9212_Version_der_Satzbeschreibung_Turbomed
	{"9212 Version der Satzbeschreibung (Turbomed)","9212 version of the set description (turbomed)"},
	// T_201_Arztnummer_Turbomed
	{"201 Arztnummer (Turbomed)","201 physician no (turbomed)"},
	// T_203_Arztname_Turbomed
	{"203 Arztname (Turbomed)","203 physician name (turbomed)"},
	// T_205_Strasse_der_Praxis_Turbomed
	{"205 Straße der Praxis (Turbomed)","205 street of the practice (turbomed)"},
	// T_211_Ausfuehrender_Arzt
	{"211 Ausführender Arzt","211 executing physician"},
	// T_212_LANR
	{"212 LANR","212 LANR"},
	// T_215_PLZ_der_Praxis_Turbomed
	{"215 PLZ der Praxis (Turbomed)","215 zip code of the practice (turbomed)"},
	// T_216_Ort_der_Praxis_Turbomed
	{"216 Ort der Praxis (Turbomed)","216 location of the practice (turbomed)"},
	// T_8320_Labor
	{"8320 Labor","8320 laboratory"},
	// T_8321_Strasse_der_Laboradresse_Turbomed
	{"8321 Straße der Laboradresse (Turbomed)","8321 street of the laboratory (turbomed)"},
	// T_8322_PLZ_der_Laboradresse_Turbomed
  {"8322 PLZ der Laboradresse (Turbomed)","8322 zip code of the laboratory (turbomed)"},
	// T_8323_Ort_der_Laboradresse_Turbomed
	{"8323 Ort der Laboradresse (Turbomed)","8323 location of the laboratory (turbomed)"},
	// T_101_KBV_Pruefnummer_Turbomed
	{"101 KBV-Prüfnummer (Turbomed)","101 KBV-check number (turbomed)"},
	// T_9106_verwendeter_Zeichensatz_Turbomed
	{"9106 verwendeter Zeichensatz (Turbomed)","9106 used character set (turbomed)"},
	// T_8312_Kundenarztnummer_Turbomed
	{"8312 Kundenarztnummer (Turbomed)","8312 customer's physicion no (turbomed)"},
	// T_9103_Erstellungsdatum_Turbomed
	{"9103 Erstellungsdatum (Turbomed)","9103 creation date (turbomed)"},
	// T_9202_Gesamtlaenge_des_Datenpaketes_Turbomed
	{"9202 Gesamtlänge des Datenpaketes (Turbomed)","9202 total length of the data set (turbomed)"},
	// T_Laborus
	{"Untersuchungen","examinations"},
	// T_Bezug_auf_LaborWert
	{"Bezug auf LaborWert","reference to laboratory value"},
	// T_Bezug_auf_LaborXSaetze
	{"Bezug auf LaborXSätze","reference to LaborXSätze"},
	// T_8310_Anforderungsident_Turbomed
	{"8310 Anforderungsident (Turbomed)","8310 Anforderungsident (Turbomed)"},
	// T_8311_Anforderungsnr_d_Labors_Turbomed
	{"8311 Anforderungsnr d Labors (Turbomed)","8311 Anforderungsnr d Labors (Turbomed)"},
	// T_8302_Berichtsdatum
	{"8302 Berichtsdatum","8302 reporting date"},
	// T_8401_Befundart_Turbomed__Fertigstellungsgrad_EEndbefund_T__Teilbefund
	{"8401 Befundart (Turbomed) / Fertigstellungsgrad (\"E\"=Endbefund, \"T\" = Teilbefund)","8401 Befundart (Turbomed) / Fertigstellungsgrad (\"E\"=Endbefund, \"T\" = Teilbefund)"},
	// T_8609_Abrechnungstyp_Kasse_Privat_X_anderer_RE_Einsender_Turbomed
	{"8609 Abrechnungstyp (Kasse/Privat/X=anderer RE/Einsender) (Turbomed)","8609 Abrechnungstyp (Kasse/Privat/X=anderer RE/Einsender) (Turbomed)"},
	// T_8403_Gebuehrenordnung_Turbomed
	{"8403 Gebührenordnung (Turbomed)","8403 Gebührenordnung (Turbomed)"},
	// T_8615_Auftraggeber_LANR
	{"8615 Auftraggeber (LANR)","8615 Auftraggeber (LANR)"},
	// T_8405_Patienteninformation_Turbomed
	{"8405 Patienteninformation (Turbomed)","8405 Patienteninformation (Turbomed)"},
	// T_8407_Geschlecht_Turbomed
	{"8407 Geschlecht (Turbomed)","8407 Geschlecht (Turbomed)"},
	// T_8490_Auftragsbezogene_Hinweise_Turbomed
	{"8490 Auftragsbezogene Hinweise (Turbomed)","8490 Auftragsbezogene Hinweise (Turbomed)"},
	// T_Ursprung_der_Pat_id_E__erwogene_Pat_id_su_L__vergleich_mit_ueber_Turbomed_eingelesenem_Labor
	{"Ursprung der Pat_id: E = erwogene Pat_id s.u., L = vergleich mit über Turbomed eingelesenem Labor","Ursprung der Pat_id: E = erwogene Pat_id s.u., L = vergleich mit über Turbomed eingelesenem Labor"},
	// T_erwogene_Pat_id_mit_gleichem_Vornamen_Nachnamen_und_Geburtstag
	{"erwogene Pat_id mit gleichem Vornamen, Nachnamen und Geburtstag","erwogene Pat_id mit gleichem Vornamen, Nachnamen und Geburtstag"},
	// T_erwogene_Pat_id_mit_gleichem_Vornamen_und_Nachnamen
	{"erwogene Pat_id mit gleichem Vornamen und Nachnamen","erwogene Pat_id mit gleichem Vornamen und Nachnamen"},
	// T_erwogene_Pat_id_mit_gleichem_Geburtstag
	{"erwogene Pat_id mit gleichem Geburtstag","erwogene Pat_id mit gleichem Geburtstag"},
	// T_erwogene_Pat_id_mit_gleichem_Geburtstag_und_zeitlich_passender_Behandlung
	{"erwogene Pat_id mit gleichem Geburtstag und zeitlich passender Behandlung","erwogene Pat_id mit gleichem Geburtstag und zeitlich passender Behandlung"},
	// T_erwogene_Pat_id_mit_gleichem_Geburtstag_und_zeitlich_passendem_Labor
	{"erwogene Pat_id mit gleichem Geburtstag und zeitlich passendem Labor","erwogene Pat_id mit gleichem Geburtstag und zeitlich passendem Labor"},
	// T_Pat_ids_von_in_Laborneu_zuordnbaren_Patienten
	{"Pat_ids von in Laborneu zuordnbaren Patienten","Pat_ids von in Laborneu zuordnbaren Patienten"},
	// T_Zeitpunkt_der_Untersuchung_die_in_Laborneu_zugeordnet_wurde
	{"Zeitpunkt der Untersuchung, die in Laborneu zugeordnet wurde","Zeitpunkt der Untersuchung, die in Laborneu zugeordnet wurde"},
	// T_Zahl_der_verglichenen_Parameter
	{"Zahl der verglichenen Parameter","No of compared parameters"},
	// T_Zahl_der_infragekommenden_Patienten
	{"Zahl der infragekommenden Patienten","No of the patients considered"},
	// T_Laborwerte_die_zur_Zuordnung_gefuehrt_haben
	{"Laborwerte, die zur Zuordnung geführt haben","Laborwerte, die zur Zuordnung geführt haben"},
	// T_Datum_zu_dem_Datensatz_zuletzt_verglichen_wurde
	{"Datum, zu dem Datensatz zuletzt verglichen wurde","Datum, zu dem Datensatz zuletzt verglichen wurde"},
	// T_Affected_Number_Zahl_der_zugehoerigen_Datensaetze_in_Laborneu
	{"Affected Number: Zahl der zugehörigen Datensätze in Laborneu","Affected Number: no of corresponding sets in Laborneu"},
	// T_Laborwert
	{"Laborwerte","laboratory values"},
	// T_8420_Ergebniswert_Turbomed
	{"8420 Ergebniswert (Turbomed)","8420 result value (Turbomed)"},
	// T_8422_Grenzwertindikator_Turbomed
	{"8422 Grenzwertindikator (Turbomed)","8422 Grenzwertindikator (Turbomed)"},
	// T_8418_Teststatus_Turbomed
	{"8418 Teststatus (Turbomed)","8418 Teststatus (Turbomed)"},
	// T_Bezug_zu_laborxplab_id
	{"Bezug zu laborxplab.id","reference to laborxplab.id"},
	// T_8411_Testbezeichnung_Turbomed
	{"8411 Testbezeichnung Turbomed","8411 Testbezeichnung Turbomed"},
	// T_ldvz_k
	{"ldvz","lddir"},
	// T_ldvz_l
	{"labordatenvz","laboratoryfiledir"},
	// T_Verzeichnis_der_Faxdateien
	{"Verzeichnis der Faxdateien","directory of the fax files"},
	// T_vv_k
	{"vonvorne","fromscratch"},
	// T_vv_l
	{"vonvorne","fromscratch"},
	// T_tr_k
	{"entleer","trunc"},
	// T_tr_l
	{"entleer","truncate"},
	// T_la_k
	{"loeschalle","deleteall"},
	// T_la_l
	{"loeschalle","deleteall"},
	// T_loescht_alle_Tabellen
	{"loescht alle Tabellen","deletes all tables"},
	// T_Loesche_alle_Tabellen_und_fange_von_vorne_an
	{"Loesche alle Tabellen und fange von vorne an","Deleting all tables and starting from scatch"},
  //T_Entleert_alle_Tabellen_und_faengt_von_vorne_an,
	{"Entleere alle Tabellen und fange von vorne an","Truncating all tables and starting from scatch"},
	// T_Kennung
	{"Kennung","identifier"},
	// T_Inhalt
	{"Inhalt","content"},
	// T_prueflyfehlt
	{"prueflyfehlt()","testlaboratoymissing()"},
	// T_Bezug_auf_lyplab
	{"Bezug zu " vorsilbe"plab","reference to " vorsilbe"plab"},
	// T_Abkuerzung_mit_gleicher_Bedeutung_gleicher_Einheit_und_gleichem_Normbereich
	{"Abkürzung mit gleicher Bedeutung, gleicher Einheit und gleichem Normbereich",
	 "abbreviation with same meaning, same unit and same normal range"},
	// T_8421
	{"8421","8421"},
	// T_LaborParameter
	{"Laborparameter","laborory parameters"},
	// T_prueflyparameter
	{"prueflyparameter()","testlyparameters()"},
	// T_Reihenfolge_innerhalb_der_Gruppe
	{"Reihenfolge innerhalb der Gruppe","order within the group"},
	// T_unterer_Normwert_maennlich
	{"unterer Normwert maennlich","lower border male"},
	// T_oberer_Normwert_maennlich,
	{"oberer Normwert maennlich","upper border male"},
	// T_unterer_Normwert_weiblich,
	{"unterer Normwert weiblich","lower border female"},
	// T_oberer_Normwert_weiblich,
	{"oberer Normwert weiblich","upper border female"},
	// T_Normbereich_aus_lywert
	{"Normbereich aus " vorsilbe"wert","normal range from " vorsilbe"wert"},
	// T_Aktualisierungszeitpunt
	{"Aktualisierungszeitpunkt","actualization time"},
	// T_Ordnungsnummer_der_Dateiuebertragung
	{"Ordnungsnummer der Dateiuebertragung","ordinal number of the file import"},
	// T_fehlend
	{"fehlend","missing"},
	// T_Bezug_auf_LaborBakt
	{"Bezug auf lybakt","reference to lybact"},
	// T_pruefPatID_Standardfunktion
	{"pruefPatID() (Stanardfunktion)","checkPatID() (standard function)"},
	// T_ergpql_leere_Funktion
	{"ergpql() (leere Funktion)","checkpql() (empty function)"},
	// T_Bezug_zu_laborynb
	{"Bezug auf Laborynb","reference to lynb"},
	// T_prueflyaerzte
	{"prueflysaetze()","checklysets()"},
	// T_zum_Bezug_fuer_Laborsaetze
	{"zum Bezug fuer lysaetze","for reference of lysets"},
	// T_Bezug_auf_lyaerzte
	{"Bezug auf lyaerzte","reference to lyaerzte"},
	// T_prueflyhinw
	{"prueflyhinw()","checklynote()"},
	// T_Auftragshinweis_Kommentar_oder_Erklaerung
	{"Auftragshinweis, Kommentar oder Erklärung","order note, comment or explanation"},
	// T_Hinweise
	{"Hinweise","notes"},
	// T_codepage_0_utf8_1_iso88591_2_cp850
	{"Zeichensatz: 0=utf-8, 1=iso8859-15, 2=cp850","code page: 0=utf-8, 1=iso8859-15, 2=cp850"},
	// T_Auftragshinweis_Bezug_auf_lyhinw
	{"Auftragshinweis, Bezug auf lyhinw","order note, reference to lyhinw"},
	// T_Erklaerung_Bezug_auf_lyhinw
	{"Erklärung, Bezug auf lyhinw","explanation, reference to lyhinw"},
	// T_Kommentar_Bezug_auf_lyhinw	
	{"Kommentar, Bezug auf lyhinw","comment, reference to lyhinw"},
	// T_letzte_Aenderung
	{"letzte Änderung","last modification"},
	// T_Groesse
	{"Größe","size"},
	{"",""} //α
}; // char const *DPROG_T[T_MAX+1][SprachZahl]=

class TxB Tx((const char* const* const* const*)DPROG_T);
const char *logdt="/var/log/" DPROG "vorgabe.log";//darauf wird in kons.h verwiesen;

using namespace std; //ω
hhcl::hhcl(const int argc, const char *const *const argv):dhcl(argc,argv,DPROG) //α
{
	// mitcron=0; //ω
	icp[0]=new ic_cl("UTF8","ISO-8859-15");
	icp[1]=new ic_cl("UTF8","CP850");
} // hhcl::hhcl //α
// Hier neue Funktionen speichern: //ω

// schwache Funktion, kann ueberdeckt werden
void hhcl::ergpql()
{
	hLog(violetts+Tx[T_ergpql_leere_Funktion]+schwarz);
}

// wird aufgerufen in: virtpruefweiteres
void hhcl::prueflyhinw(DB *My, const int obverb, const int oblog, const uchar direkt/*=0*/)
{
	hLog(violetts+Tx[T_prueflyhinw]+schwarz);
	const size_t aktc=0;
	if (!direkt) {
		Feld felder[] = {
			Feld(/*name*/"ID",/*typ*/"int",/*lenge*/"10",/*prec*/string(),/*comment*/Tx[T_eindeutige_Identifikation],/*obind*/1,/*obaut*/1,/*nnull*/0,/*defa*/string(),/*unsig*/1),
			Feld("Text","LONGTEXT","","",Tx[T_Auftragshinweis_Kommentar_oder_Erklaerung],0,0,1,string()),
		};
		Index indices[]{
			Index("Text",new Feld[1]{Feld("Text",string(),"767")},1,/*unique*/0)
		};
		Tabelle taba(My,tlyhinw,felder,sizeof felder/sizeof* felder,indices,sizeof indices/sizeof *indices,0,0, Tx[T_Hinweise]/*//,"InnoDB","utf8","utf8_general_ci","DYNAMIC"*/);
		if (taba.prueftab(aktc,obverb)) {
			fLog(rots+Tx[T_Fehler_beim_Pruefen_von]+schwarz+tlyhinw,1,1);
			exit(11);
		}
		// "Labor 20051127 224528.dat": kein Labor angegeben
		svec eindfeld; eindfeld<<"ID";
		insv rhinw(My,/*itab*/tlyhinw,aktc,/*eindeutig*/1,eindfeld,/*asy*/0,/*csets*/0);
		rhinw.hz("Text",string());
		rhinw.schreib(/*sammeln*/0,/*obverb*/1,/*idp*/&hinwind);
	} // if (!direkt)
} // int prueflyhinw

// wird aufgerufen in: virtpruefweiteres
void hhcl::prueflyparameter(DB *My, const int obverb, const int oblog, const uchar direkt/*=0*/)
{
	hLog(violetts+Tx[T_prueflyparameter]+schwarz);
	const size_t aktc=0;
	if (!direkt) {
		Feld felder[] = {
			Feld(/*name*/"Abkü",/*typ*/"varchar",/*lenge*/"31",/*prec*/"",/*comment*/Tx[T_8410_maximale_Laenge_8],/*obind*/0,/*obaut*/0,/*nnull*/1),
			Feld("AbküN","varchar","1","",Tx[T_Abkuerzung_mit_gleicher_Bedeutung_gleicher_Einheit_und_gleichem_Normbereich],0,0,1),
			Feld("LabID","int","10","",Tx[T_Bezug_auf_lyplab],0,0,1,string(),1),
			Feld("Langtext","varchar","41","",Tx[T_8411_maximale_Laenge_40],0,0,1),
			Feld("Einheit","varchar","12","",Tx[T_8421],0,0,1,"kA"),
			Feld("Gruppe","int","10","",Tx[T_Bezug_auf_laborgruppen_laborgruppe],/*obind*/1,/*obauto*/0,/*nnull*/1,/*vdefa*/string(),/*unsig*/1),
			Feld("Reihe","int","10","",Tx[T_Reihenfolge_innerhalb_der_Gruppe],/*obind*/1,/*obauto*/0,/*nnull*/1,/*vdefa*/string(),/*unsig*/0),
			Feld("uNm","varchar","11","",Tx[T_unterer_Normwert_maennlich],0,0,1),
			Feld("oNm","varchar","11","",Tx[T_oberer_Normwert_maennlich],0,0,1),
			Feld("uNw","varchar","11","",Tx[T_unterer_Normwert_weiblich],0,0,1),
			Feld("oNw","varchar","11","",Tx[T_oberer_Normwert_weiblich],0,0,1),
			Feld("NB","varchar","650","",Tx[T_Normbereich_aus_lywert],0,0,1),
			Feld("Aktzeit","datetime","0","0",Tx[T_Aktualisierungszeitpunt],1,0,1),
			Feld("StByte","int","10","",Tx[T_Ordnungsnummer_der_Dateiuebertragung],/*obind*/1,/*obauto*/0,/*nnull*/1,/*vdefa*/string(),/*unsig*/0),
			Feld("ID","int","10","",Tx[T_eindeutige_Identifikation],1,1,0,string(),1),
		};
		Index indices[]{
			Index("Abkü",new Feld[2]{Feld("Abkü"),Feld("Einheit")},2),
			Index("eindeutig",new Feld[3]{Feld("Abkü"),Feld("Einheit"),Feld("NB")},3,/*unique*/1),
		};
		Constraint csts[]{
			Constraint(tlyparameter+tlyplab,new Feld{Feld("labid")},1,tlyplab,new Feld{Feld("ID")},1,cascade,cascade),
		};
			// auf jeden Fall ginge "binary" statt "utf8" und "" statt "utf8_general_ci"
		Tabelle taba(My,tlyparameter,felder,sizeof felder/sizeof* felder,indices,sizeof indices/sizeof *indices,csts,sizeof csts/sizeof *csts,Tx[T_LaborParameter]/*//,"InnoDB","utf8","utf8_general_ci","DYNAMIC"*/);
		if (taba.prueftab(aktc,obverb)) {
			fLog(rots+Tx[T_Fehler_beim_Pruefen_von]+schwarz+tlyparameter,1,1);
			exit(11);
		}
	} // if (!direkt)
} // int pruefouttab(DB *My, string touta, int obverb, int oblog, uchar direkt=0)

// wird aufgerufen in: virtpruefweiteres
void hhcl::prueflydat(DB *My, const int obverb, const int oblog, const uchar direkt/*=0*/)
{
	hLog(violetts+Tx[T_prueflydat]+schwarz);
	const size_t aktc=0;
	if (!direkt) {
		Feld felder[] = {
			Feld("DatID","int","10","",Tx[T_eindeutige_Identifikation],1,1,0,string(),1),
			Feld("Pfad","varchar","60","",Tx[T_Pfadname],1,0,1),
			Feld("Name","varchar","31","",Tx[T_Name_der_eingelesenen_Labordatei_ohne_Endung],1,0,1),
			Feld("geändert","datetime","","",Tx[T_letzte_Aenderung],1,0,1),
			Feld("Größe","int","10","",Tx[T_Groesse],0,0,1),
			Feld("Zp","datetime","0","0",Tx[T_Einlesezeitpunkt],0,0,1),
			Feld("codepage","integer","1","",Tx[T_codepage_0_utf8_1_iso88591_2_cp850],1,0,1),
			Feld("fertig","bit","1","",Tx[T_ob_Einlesen_fertig],0,0,1),
		};
		Index indices[]{
//			Index("NamePfad",new Feld[2]{Feld("Name"),Feld("Pfad")},2),
//				Index("DatID",new Feld[1]{Feld("DatID")},1),
		};
		// auf jeden Fall ginge "binary" statt "utf8" und "" statt "utf8_general_ci"
		Tabelle taba(My,tlydat,felder,sizeof felder/sizeof* felder,indices,sizeof indices/sizeof *indices,0,0,Tx[T_LaborEinlesungen]/*//,"InnoDB","utf8","utf8_general_ci","DYNAMIC"*/);
		if (taba.prueftab(aktc,obverb)) {
			fLog(rots+Tx[T_Fehler_beim_Pruefen_von]+schwarz+tlydat,1,1);
			exit(11);
		}
	} // if (!direkt)
} // int pruefouttab(DB *My, string touta, int obverb, int oblog, uchar direkt=0)

// wird aufgerufen in: virtpruefweiteres
void hhcl::prueflyplab(DB *My, const int obverb, const int oblog, const uchar direkt/*=0*/)
{
	hLog(violetts+Tx[T_prueflyplab]+schwarz);
	const size_t aktc=0;
	if (!direkt) {
		Feld felder[] = {
			Feld(/*name*/"ID",/*typ*/"int",/*lenge*/"10",/*prec*/string(),/*comment*/Tx[T_eindeutige_Identifikation],/*obind*/1,/*obaut*/1,/*nnull*/0,/*defa*/string(),/*unsig*/1),
			Feld("Labor","varchar","21","",Tx[T_8300_maximale_Laenge_36],0,0,1),
			Feld("StraßeLabor","varchar","1","",Tx[T_8321_Strasse_der_Laboradresse_Turbomed],0,0,1),
			Feld("PLZLabor","varchar","1","",Tx[T_8322_PLZ_der_Laboradresse_Turbomed],0,0,1),
			Feld("OrtLabor","varchar","1","",Tx[T_8323_Ort_der_Laboradresse_Turbomed],0,0,1),
		};
		Index indices[]{Index("Labor",new Feld[4]{Feld("Labor"),Feld("StraßeLabor"),Feld("PLZLabor"),Feld("OrtLabor")},4,/*unique*/1)};
		// auf jeden Fall ginge "binary" statt "utf8" und "" statt "utf8_general_ci"
		Tabelle taba(My,tlyplab,felder,sizeof felder/sizeof* felder,indices,sizeof indices/sizeof *indices,0,0, Tx[T_Laborplab]/*//,"InnoDB","utf8","utf8_general_ci","DYNAMIC"*/);
		if (taba.prueftab(aktc,obverb)) {
			fLog(rots+Tx[T_Fehler_beim_Pruefen_von]+schwarz+tlyplab,1,1);
			exit(11);
		}
		// "Labor 20051127 224528.dat": kein Labor angegeben
		svec eindfeld; eindfeld<<"ID";
		insv rlab(My,/*itab*/tlyplab,aktc,/*eindeutig*/1,eindfeld,/*asy*/0,/*csets*/0);
		rlab.hz("Labor",Tx[T_fehlend]);
		rlab.schreib(/*sammeln*/0,/*obverb*/1,/*idp*/&labind);
	} // if (!direkt)
} // int pruefouttab(DB *My, string touta, int obverb, int oblog, uchar direkt=0)

// wird aufgerufen in: virtpruefweiteres
void hhcl::prueflypneu(DB *My, const int obverb, const int oblog, const uchar direkt/*=0*/)
{
	hLog(violetts+Tx[T_prueflypneu]+schwarz);
	const size_t aktc=0;
	if (!direkt) {
		Feld felder[] = {
			Feld("ID","int","10","",Tx[T_eindeutige_Identifikation],1,1,0,string(),1),
			Feld("Abkü","varchar","31","",Tx[T_8410_maximale_Laenge_8],1,0,1),
			Feld("AbküN","varchar","1","",Tx[T_Abkuerzung_mit_gleicher_Bedeutung_gleicher_Einheit_und_gleichem_Normbereich],0,0,1),
			Feld("LabID","int","10","",Tx[T_Bezug_auf_lyplab],/*obind*/1,/*obauto*/0,/*nnull*/1,/*vdefa,NULL*/string(),/*unsig*/1),
			Feld("Langtext","varchar","50","",Tx[T_8411_maximale_Laenge_40],0,0,1),
			Feld("Einheit","varchar","12","",Tx[T_8421_maximale_Laenge_12],0,0,1,"kA"),
			Feld("Gruppe","int","10","",Tx[T_Bezug_auf_laborgruppen_laborgruppe],/*obind*/1,/*obauto*/0,/*nnull*/1,/*vdefa*/string(),/*unsig*/1),
			Feld("Reihe","int","10","",Tx[T_Reihenfolge_innerhalb_der_Gruppe],/*obind*/1,/*obauto*/0,/*nnull*/1,/*vdefa*/string(),/*unsig*/0),
		};
		/*
			 Feld ifelder0[] = {Feld("Abkü"),Feld("Einheit"),Feld("LabID")};   Index i0("Abkü",ifelder0,sizeof ifelder0/sizeof* ifelder0);
			 Index indices[]={i0};
		 */
		Index indices[]{
			Index("Abkü",new Feld[3]{Feld("Abkü"),Feld("Einheit"),Feld("LabID")},3),
			Index("eindeutig",new Feld[4]{Feld("Abkü"),Feld("Einheit"),Feld("Langtext"),Feld("LabID")},4,/*unique*/1),
		};
		Constraint csts[]{
			Constraint(tlypneu+"laborGruppen",new Feld{Feld("Gruppe")},1,"laborgruppen",new Feld{Feld("laborgruppe")},1,cascade,cascade),
				// geht beides!:
				//			  								Constraint("Labore",new Feld[1]{Feld("LabID")},1,tlyplab,new Feld[1]{Feld("id")},1)};
			Constraint(tlypneu+tlyplab,new Feld{Feld("LabID")},1,tlyplab,new Feld{Feld("id")},1,cascade,cascade)
	};
	// auf jeden Fall ginge "binary" statt "utf8" und "" statt "utf8_general_ci"
		Tabelle taba(My,tlypneu,felder,sizeof felder/sizeof* felder,indices,sizeof indices/sizeof *indices,csts,sizeof csts/sizeof *csts, Tx[T_Laborneu]/*//,"InnoDB","utf8","utf8_general_ci","DYNAMIC"*/);
		if (taba.prueftab(aktc,obverb)) {
			fLog(rots+Tx[T_Fehler_beim_Pruefen_von]+schwarz+tlypneu,1,1);
			exit(11);
		}
	} // if (!direkt)
} // int pruefouttab(DB *My, string touta, int obverb, int oblog, uchar direkt=0)

// wird aufgerufen in: virtpruefweiteres
void hhcl::prueflypnb(DB *My, const int obverb, const int oblog, const uchar direkt/*=0*/)
{
	hLog(violetts+Tx[T_prueflypnb]+schwarz);
	const size_t aktc=0;
	if (!direkt) {
		Feld felder[] = {
			Feld("ID","int","10","",Tx[T_eindeutige_Identifikation],1,1,0,string(),1),
			Feld("PNEUID","int","10","",Tx[T_Bezug_auf_laborxpneu],/*obind*/0,/*obauto*/0,/*nnull*/1,/*vdefa*/string(),/*unsig*/1),
//			Feld("Geschlecht","int","10","",Tx[T_1_Mann_2_Frau_3_unbek_4_Knabe_5_Maedchen_0_Name_fehlt_9_beide],/*obind*/0,/*obauto*/0,/*nnull*/1,/*vdefa*/string(),/*unsig*/1),
//			Feld("Eingang","datetime","0","0",Tx[T_Eingangsdatum_im_Labor],0,0,1),
			Feld("uNg","varchar","11","",Tx[T_untere_Normgrenze],0,0,1),
			Feld("oNg","varchar","11","",Tx[T_obere_Normgrenze],0,0,1),
			Feld("NB","varchar","650","",Tx[T_Normbereich],0,0,1),
			Feld("zahl","int","10","",Tx[T_Haeufigkeit_eines_Laborparameters],/*obind*/0,/*obauto*/0,/*nnull*/1,/*vdefa*/string(),/*unsig*/1),
			Feld("uid","int","10","",Tx[T_laborxus_id_des_ersten_Eintrags],/*obind*/0,/*obauto*/0,/*nnull*/1,/*vdefa*/string(),/*unsig*/1),
		};
		Feld ifd0[]{Feld("PNEUID")};
		Feld ifd0a[]{Feld("id")};
		Constraint c0(tlypnb+tlypneu,ifd0,1,tlypneu,ifd0a,1,cascade,cascade);
		Constraint csts[]{c0};
		// auf jeden Fall ginge "binary" statt "utf8" und "" statt "utf8_general_ci"
		Tabelle taba(My,tlypnb,felder,sizeof felder/sizeof* felder,0,0,csts,sizeof csts/sizeof *csts, Tx[T_Labornb]/*//,"InnoDB","utf8","utf8_general_ci","DYNAMIC"*/);
		if (taba.prueftab(aktc,obverb)) {
			fLog(rots+Tx[T_Fehler_beim_Pruefen_von]+schwarz+tlypnb,1,1);
			exit(11);
		}
	} // if (!direkt)
} // int pruefouttab(DB *My, string touta, int obverb, int oblog, uchar direkt=0)

// wird aufgerufen in: virtpruefweiteres
void hhcl::prueflyaerzte(DB *My, const int obverb, const int oblog, const uchar direkt/*=0*/)
{
	hLog(violetts+Tx[T_prueflyaerzte]+schwarz);
	const size_t aktc=0;
	if (!direkt) {
		Feld felder[] = {
			Feld("ID","int","10","",Tx[T_zum_Bezug_fuer_Laborsaetze],1,1,0,string(),1),
			Feld("Arztnr","varchar","1","",Tx[T_201_Arztnummer_Turbomed],1,0,1),
			Feld("Arztname","varchar","41","",Tx[T_203_Arztname_Turbomed],1,0,1),
			Feld("StraßePraxis","varchar","41","",Tx[T_205_Strasse_der_Praxis_Turbomed],0,0,1),
			Feld("Arzt","varchar","41","",Tx[T_211_Ausfuehrender_Arzt],1,0,1),
			Feld("LANR","varchar","11","",Tx[T_212_LANR],1,0,1),
			Feld("PLZPraxis","varchar","11","",Tx[T_215_PLZ_der_Praxis_Turbomed],0,0,1),
			Feld("OrtPraxis","varchar","11","",Tx[T_216_Ort_der_Praxis_Turbomed],0,0,1),
		};
		Index indices[]{
			Index("eindeutig",new Feld[7]{Feld("Arztnr"),Feld("Arztname"),Feld("StraßePraxis"),Feld("Arzt"),Feld("LANR"),Feld("PLZPraxis"),Feld("OrtPraxis")},7,/*unique*/1),
		};
		Constraint csts[]{
		};
			// auf jeden Fall ginge "binary" statt "utf8" und "" statt "utf8_general_ci"
		Tabelle taba(My,tlyaerzte,felder,sizeof felder/sizeof* felder,indices,sizeof indices/sizeof *indices,csts,sizeof csts/sizeof *csts,Tx[T_Laborsaetze]/*//,"InnoDB","utf8","utf8_general_ci","DYNAMIC"*/);
		if (taba.prueftab(aktc,obverb)) {
			fLog(rots+Tx[T_Fehler_beim_Pruefen_von]+schwarz+tlyaerzte,1,1);
			exit(11);
		}
	} // if (!direkt)
} // int pruefouttab(DB *My, string touta, int obverb, int oblog, uchar direkt=0)
// wird aufgerufen in: virtpruefweiteres
void hhcl::prueflysaetze(DB *My, const int obverb, const int oblog, const uchar direkt/*=0*/)
{
	hLog(violetts+Tx[T_prueflysaetze]+schwarz);
	const size_t aktc=0;
	if (!direkt) {
		Feld felder[] = {
			Feld("SatzID","int","10","",Tx[T_zum_Bezug_fuer_LaborUS],1,1,0,string(),1),
			Feld("DatID","int","10","",Tx[T_Bezug_zu_LaborDat],1,0,0,string(),1),
			Feld("Satzart","varchar","11","",Tx[T_8000_Satzart_Turbomed],0,0,1),
			Feld("Satzlänge","varchar","11","",Tx[T_8100_Satzlaenge_Turbomed],0,0,1),
			Feld("SatzlängeSchluss","varchar","11","",Tx[T_8100_Satzlaenge_Turbomed_nach_8221_in_Feld_8000],0,0,1),
			Feld("VersionSatzb","varchar","11","",Tx[T_9212_Version_der_Satzbeschreibung_Turbomed],0,0,1),
			Feld("ArztID","int","10","",Tx[T_Bezug_auf_lyaerzte],0,0,1,string(),1),
			Feld("LabID","int","10","",Tx[T_Bezug_auf_lyplab],0,0,1,string(),1),
			Feld("KBVPrüfnr","varchar","21","",Tx[T_101_KBV_Pruefnummer_Turbomed],0,0,1),
			Feld("Zeichensatz","varchar","1","",Tx[T_9106_verwendeter_Zeichensatz_Turbomed],0,0,1),
			Feld("Kundenarztnr","varchar","11","",Tx[T_8312_Kundenarztnummer_Turbomed],0,0,1),
			Feld("Erstellungsdatum","date","","",Tx[T_9103_Erstellungsdatum_Turbomed],0,0,1),
			Feld("Gesamtlänge","varchar","1","",Tx[T_9202_Gesamtlaenge_des_Datenpaketes_Turbomed],0,0,1),
		};
		Constraint csts[]{
			Constraint(tlysaetze+tlydat,new Feld{Feld("datid")},1,tlydat,new Feld{Feld("DatID")},1,cascade,cascade),
			Constraint(tlysaetze+tlyaerzte,new Feld{Feld("arztid")},1,tlyaerzte,new Feld{Feld("ID")},1,cascade,cascade),
			Constraint(tlysaetze+tlyplab,new Feld{Feld("labid")},1,tlyplab,new Feld{Feld("ID")},1,cascade,cascade),
		};
			// auf jeden Fall ginge "binary" statt "utf8" und "" statt "utf8_general_ci"
		Tabelle taba(My,tlysaetze,felder,sizeof felder/sizeof* felder,0,0,csts,sizeof csts/sizeof *csts,Tx[T_Laborsaetze]/*//,"InnoDB","utf8","utf8_general_ci","DYNAMIC"*/);
		if (taba.prueftab(aktc,obverb)) {
			fLog(rots+Tx[T_Fehler_beim_Pruefen_von]+schwarz+tlysaetze,1,1);
			exit(11);
		}
	} // if (!direkt)
} // int pruefouttab(DB *My, string touta, int obverb, int oblog, uchar direkt=0)


// wird aufgerufen in: virtpruefweiteres
void hhcl::prueflyus(DB *My, const int obverb, const int oblog, const uchar direkt/*=0*/)
{
	hLog(violetts+Tx[T_prueflyus]+schwarz);
	const size_t aktc=0;
	if (!direkt) {
		Feld felder[] = {
			Feld("ID","int","10","",Tx[T_eindeutige_Identifikation],1,1,0,string(),1),
			Feld("UsLfd","int","10","",Tx[T_Bezug_auf_LaborWert],1,0,0,string(),1),
			Feld("DatID","int","10","",Tx[T_Bezug_zu_LaborDat],1,0,1,string(),1),
			Feld("SatzID","int","10","",Tx[T_Bezug_auf_LaborXSaetze],1,0,1,string(),1),
			Feld("Satzart","varchar","11","",Tx[T_8000_Satzart_Turbomed],0,0,0),
			Feld("Satzlänge","varchar","11","",Tx[T_8100_Satzlaenge_Turbomed],0,0,0),
			Feld("Auftragsnummer","varchar","11","",Tx[T_8310_Anforderungsident_Turbomed],0,0,0),
			Feld("Auftragsschlüssel","varchar","11","",Tx[T_8311_Anforderungsnr_d_Labors_Turbomed],/*obind*/1,0,0),
			Feld("Eingang","datetime","0","0",Tx[T_Eingangsdatum_im_Labor],1,0,0),
			Feld("Berichtsdatum","varchar","21","",Tx[T_8302_Berichtsdatum],0,0,0),
			Feld("Pat_id","int","10","","",1,0,1,string(),1),
			Feld("Nachname","varchar","31","","3101",0,0,0),
			Feld("Vorname","varchar","31","","3102",0,0,0),
			Feld("GebDat","date","","","3103",0,0,0),
			Feld("Titel","varchar","1","","3104",0,0,0),
			Feld("NVorsatz","varchar","1","","3105",0,0,0),
			Feld("BefArt","varchar","1","",Tx[T_8401_Befundart_Turbomed__Fertigstellungsgrad_EEndbefund_T__Teilbefund],0,0,0),
			Feld("Abrechnungstyp","varchar","1","",Tx[T_8609_Abrechnungstyp_Kasse_Privat_X_anderer_RE_Einsender_Turbomed],0,0,0),
			Feld("GebüOrd","varchar","1","",Tx[T_8403_Gebuehrenordnung_Turbomed],0,0,0),
			Feld("Auftraggeber","varchar","1","",Tx[T_8615_Auftraggeber_LANR],0,0,0),
			Feld("Patienteninformation","varchar","1","",Tx[T_8405_Patienteninformation_Turbomed],0,0,0),
			Feld("Geschlecht","varchar","1","",Tx[T_8407_Geschlecht_Turbomed],/*obind*/0,/*obauto*/0,/*nnull*/1),
//			Feld("AuftrHinw","LONGTEXT","","",Tx[T_8490_Auftragsbezogene_Hinweise_Turbomed],/*obind*/0,/*obauto*/0,/*nnull*/0),
			fuellpql();
			for(auto i=0;i<pql.size();i++) {
				Feld("Pat_id_"+ltoan(i),"varchar","1","",pql[i],/*obind*/1,/*obauto*/0,/*nnull*/0)

			}
			Feld("Pat_idUrsp","varchar","1","",Tx[T_Ursprung_der_Pat_id_E__erwogene_Pat_id_su_L__vergleich_mit_ueber_Turbomed_eingelesenem_Labor],/*obind*/0,/*obauto*/0,/*nnull*/0),
			Feld("Pat_idErwVNG","varchar","1","",Tx[T_erwogene_Pat_id_mit_gleichem_Vornamen_Nachnamen_und_Geburtstag],/*obind*/0,/*obauto*/0,/*nnull*/0),
			Feld("Pat_idErwVN","varchar","1","",Tx[T_erwogene_Pat_id_mit_gleichem_Vornamen_und_Nachnamen],/*obind*/0,/*obauto*/0,/*nnull*/0),
			Feld("Pat_idErwG","varchar","1","",Tx[T_erwogene_Pat_id_mit_gleichem_Geburtstag],/*obind*/0,/*obauto*/0,/*nnull*/0),
			Feld("Pat_idErwGB","varchar","1","",Tx[T_erwogene_Pat_id_mit_gleichem_Geburtstag_und_zeitlich_passender_Behandlung],/*obind*/0,/*obauto*/0,/*nnull*/0),
			Feld("Pat_idErwGL","varchar","1","",Tx[T_erwogene_Pat_id_mit_gleichem_Geburtstag_und_zeitlich_passendem_Labor],/*obind*/0,/*obauto*/0,/*nnull*/0),
			Feld("Pat_idLaborNeu","varchar","1","",Tx[T_Pat_ids_von_in_Laborneu_zuordnbaren_Patienten],/*obind*/0,/*obauto*/0,/*nnull*/0),
			Feld("ZeitpunktLaborneu","datetime","0","0",Tx[T_Zeitpunkt_der_Untersuchung_die_in_Laborneu_zugeordnet_wurde],0,0,0),
			Feld("ZdüP","smallint","6","0",Tx[T_Zahl_der_verglichenen_Parameter],0,0,0),
			Feld("ZdiP","int","10","0",Tx[T_Zahl_der_infragekommenden_Patienten],0,0,0),
			Feld("LWerte","LONGTEXT","","0",Tx[T_Laborwerte_die_zur_Zuordnung_gefuehrt_haben],0,0,0),
			Feld("verglichen","datetime","0","0",Tx[T_Datum_zu_dem_Datensatz_zuletzt_verglichen_wurde],0,0,0),
			Feld("AfN","smallint","6","0",Tx[T_Affected_Number_Zahl_der_zugehoerigen_Datensaetze_in_Laborneu],0,0,0),
		};
		Feld ifelder0[] = {Feld("Nachname"),Feld("Vorname")};   Index i0("Name",ifelder0,sizeof ifelder0/sizeof* ifelder0);
		Index indices[]={i0};
		Constraint csts[]{Constraint(tlydat+tlyus,new Feld{Feld("DatID")},1,tlydat,new Feld{Feld("DatID")},1,cascade,cascade),
		                	Constraint(tlysaetze+tlyus,new Feld{Feld("satzid")},1,tlysaetze,new Feld{Feld("satzid")},1,cascade,cascade)};
		// auf jeden Fall ginge "binary" statt "utf8" und "" statt "utf8_general_ci"
		Tabelle taba(My,tlyus,felder,sizeof felder/sizeof* felder,indices,sizeof indices/sizeof *indices,csts,sizeof csts/sizeof *csts, Tx[T_Laborus]/*//,"InnoDB","utf8","utf8_general_ci","DYNAMIC"*/);
		if (taba.prueftab(aktc,obverb)) {
			fLog(rots+Tx[T_Fehler_beim_Pruefen_von]+schwarz+tlyus,1,1);
			exit(11);
		}
	} // if (!direkt)
} // int pruefouttab(DB *My, string touta, int obverb, int oblog, uchar direkt=0)

// wird aufgerufen in: virtpruefweiteres
void hhcl::prueflybakt(DB *My, const int obverb, const int oblog, const uchar direkt/*=0*/)
{
	hLog(violetts+Tx[T_prueflybakt]+schwarz);
	const size_t aktc=0;
	if (!direkt) {
		Feld felder[] = {
			Feld("ID","int","10","",Tx[T_eindeutige_Identifikation],1,1,1,string(),1),
			Feld("UsID","int","10","",Tx[T_Bezug_auf_LaborUS],/*obind*/1,/*obauto*/0,/*nnull*/1,/*vdefa*/string(),/*unsig*/1),
			Feld("NBID","int","10","",Tx[T_Bezug_zu_laborynb],/*obind*/1,/*obauto*/0,/*nnull*/0),
			Feld("Verf","varchar","31","",Tx[T_8410_Test_Ident_Turbomed],0,0,1),
			Feld("KuQu","varchar","1","",Tx[T_8428_Probenmaterial_Ident_Turbomed],0,0,1),
			Feld("Quelle","varchar","1","",Tx[T_8430_Probenmaterial_Bezeichnung_Turbomed],0,0,1),
			Feld("QSpez","varchar","1","",Tx[T_8431_Probenmaterial_Spezifikation_Turbomed],0,0,1),
			Feld("AbnDat","datetime","0","0",Tx[T_8432_Abnahmedatum_Turbomed],0,0,1),
//			Feld("Kommentar","LONGTEXT","","",Tx[T_8480_Ergebnistest_Turbomed],0,0),
			Feld("KommID","int","10","",Tx[T_Kommentar_Bezug_auf_lyhinw],1,0,0,"0",1),
//			Feld("Erklärung","LONGTEXT","","","",0,0,0),
			Feld("ErklID","int","10","",Tx[T_Erklaerung_Bezug_auf_lyhinw],1,0,0,"0",1),
//			Feld("AuftrHinw","LONGTEXT","","",Tx[T_8490_Auftragsbezogene_Hinweise_Turbomed],/*obind*/0,/*obauto*/0,/*nnull*/0),
			Feld("HinwID","int","10","",Tx[T_Auftragshinweis_Bezug_auf_lyhinw],1,0,0,"0",1),
			Feld("Keimzahl","varchar","1","","",0,0,1),
			Feld("abrd","varchar","1","",Tx[T_8614_Abrechnung_durch_1_Labor_2_Einweiser],0,0,1),
		};
		Constraint csts[]{Constraint(tlyus+tlybakt,new Feld{Feld("UsID")},1,tlyus,new Feld{Feld("id")},1,cascade,cascade)};
		// auf jeden Fall ginge "binary" statt "utf8" und "" statt "utf8_general_ci"
		Tabelle taba(My,tlybakt,felder,sizeof felder/sizeof* felder,0,0,csts,sizeof csts/sizeof *csts,Tx[T_Laborbakt]/*//,"InnoDB","utf8","utf8_general_ci","DYNAMIC"*/);
		if (taba.prueftab(aktc,obverb)) {
			fLog(rots+Tx[T_Fehler_beim_Pruefen_von]+schwarz+tlybakt,1,1);
			exit(11);
		}
	} // if (!direkt)
} // int pruefouttab(DB *My, string touta, int obverb, int oblog, uchar direkt=0)

// wird aufgerufen in: virtpruefweiteres
void hhcl::prueflyleist(DB *My, const int obverb, const int oblog, const uchar direkt/*=0*/)
{
	hLog(violetts+Tx[T_prueflyleist]+schwarz);
	const size_t aktc=0;
	if (!direkt) {
		Feld felder[] = {
			Feld("ID","int","10","",Tx[T_eindeutige_Identifikation],1,1,0,string(),1),
			Feld("UsID","int","10","",Tx[T_Bezug_auf_LaborUS],/*obind*/1,/*obauto*/0,0,string(),/*unsigned*/1),
			Feld("Abkü","varchar","11","",Tx[T_8410_Test_Ident_Turbomed],0,0,1),
			Feld("Verf","varchar","1","",Tx[T_8434],0,0,1),
			Feld("EBM","varchar","11","",Tx[T_5001_GNR_Turbomed],0,0,1),
			Feld("goä","varchar","11","",Tx[T_8406],0,0,1),
			Feld("Anzahl","varchar","1","",Tx[T_5005],0,0,1),
		};
////		Feld ifelder0[] = {Feld("UsID")};   Index i0("UsID",ifelder0,sizeof ifelder0/sizeof* ifelder0);
////		Index indices[]={i0};
////		Feld ifelder0[] = {};
////		Index indices[]={};
		Constraint csts[]{
			Constraint(tlyus+tlyleist,new Feld{Feld("UsID")},1,tlyus,new Feld{Feld("ID")},1,cascade,cascade),
		};
		// auf jeden Fall ginge "binary" statt "utf8" und "" statt "utf8_general_ci"
		Tabelle taba(My,tlyleist,felder,sizeof felder/sizeof* felder,0,0,csts,sizeof csts/sizeof *csts, Tx[T_LaborLeistungen]/*//,"InnoDB","utf8","utf8_general_ci","DYNAMIC"*/);
		if (taba.prueftab(aktc,obverb)) {
			fLog(rots+Tx[T_Fehler_beim_Pruefen_von]+schwarz+tlyleist,1,1);
			exit(11);
		}
	} // if (!direkt)
} // int pruefouttab(DB *My, string touta, int obverb, int oblog, uchar direkt=0)

// wird aufgerufen in: virtpruefweiteres
void hhcl::prueflywert(DB *My, const int obverb, const int oblog, const uchar direkt/*=0*/)
{
	hLog(violetts+Tx[T_prueflywert]+schwarz);
	const size_t aktc=0;
	if (!direkt) {
		Feld felder[] = {
			Feld("ID","int","10","",Tx[T_eindeutige_Identifikation],1,1,0,string(),1),
			Feld("UsID","int","10","",Tx[T_Bezug_auf_LaborUS],1,0,0,string(),1),
			Feld("BaktID","int","10","",Tx[T_Bezug_auf_LaborBakt],1,0,0,"0",1),
			Feld("NBID","int","10","",Tx[T_Bezug_zu_laborynb],/*obind*/1,/*obauto*/0,/*nnull*/0),
			Feld("Abkü","varchar","11","",Tx[T_8410_maximale_Laenge_8],0,0,1),
			Feld("Langtext","varchar","41","",Tx[T_8411_Testbezeichnung_Turbomed],0,0,1),
			Feld("KuQu","varchar","11","",Tx[T_8428_Probenmaterial_Ident_Turbomed],0,0,1),
			Feld("Quelle","varchar","21","",Tx[T_8430_Probenmaterial_Bezeichnung_Turbomed],0,0,1),
			Feld("QSpez","varchar","1","",Tx[T_8431_Probenmaterial_Spezifikation_Turbomed],0,0,1),
			Feld("AbnDat","datetime","0","0",Tx[T_8432_Abnahmedatum_Turbomed],0,0,1),
			Feld("Wert","varchar","11","0",Tx[T_8420_Ergebniswert_Turbomed],0,0,1),
			Feld("Einheit","varchar","12","",Tx[T_8421_maximale_Laenge_12],0,0,1,"kA"),
			Feld("Grenzwerti","varchar","1","",Tx[T_8422_Grenzwertindikator_Turbomed],0,0,1),
			//Feld("Kommentar","LONGTEXT","","",Tx[T_8480_Ergebnistest_Turbomed],0,0),
			Feld("KommID","int","10","",Tx[T_Kommentar_Bezug_auf_lyhinw],1,0,0,"0",1),
			Feld("Teststatus","varchar","1","",Tx[T_8418_Teststatus_Turbomed],0,0,1),
			//Feld("Erklärung","LONGTEXT","","","",0,0,0),
			Feld("ErklID","int","10","",Tx[T_Erklaerung_Bezug_auf_lyhinw],1,0,0,"0",1),
//			Feld("AuftrHinw","LONGTEXT","","",Tx[T_8490_Auftragsbezogene_Hinweise_Turbomed],/*obind*/0,/*obauto*/0,/*nnull*/0),
			Feld("HinwID","int","10","",Tx[T_Auftragshinweis_Bezug_auf_lyhinw],1,0,0,"0",1),
			Feld("abrd","varchar","1","",Tx[T_8614_Abrechnung_durch_1_Labor_2_Einweiser],0,0,1),
		};
		Feld ifelder0[] = {Feld("Abkü"),Feld("Einheit")};   Index i0("LaborXWertAbkü",ifelder0,sizeof ifelder0/sizeof* ifelder0);
		Feld ifelder1[] = {Feld("UsID"),Feld("BaktID"),Feld("Abkü"),Feld("Langtext"),Feld("Quelle"),Feld("QSpez"),Feld("AbnDat"),Feld("Wert"),Feld("Einheit"),Feld("Grenzwerti"),Feld("Teststatus"),Feld("nbid"),Feld("HinwID"),Feld("KommID"),Feld("ErklID")};   
				Index i1("doppelte",ifelder1,sizeof ifelder1/sizeof* ifelder1,/*unique*/1);
		Index indices[]={i0,i1};
		Constraint csts[]{Constraint(tlyus+tlywert,new Feld{Feld("UsID")},1,tlyus,new Feld{Feld("id")},1,cascade,cascade)};
		// auf jeden Fall ginge "binary" statt "utf8" und "" statt "utf8_general_ci"
		Tabelle taba(My,tlywert,felder,sizeof felder/sizeof* felder,indices,sizeof indices/sizeof *indices,csts,sizeof csts/sizeof *csts, Tx[T_Laborwert]/*//,"InnoDB","utf8","utf8_general_ci","DYNAMIC"*/);
		if (taba.prueftab(aktc,obverb)) {
			fLog(rots+Tx[T_Fehler_beim_Pruefen_von]+schwarz+tlywert,1,1);
			exit(11);
		}
	} // if (!direkt)
} // int pruefouttab(DB *My, string touta, int obverb, int oblog, uchar direkt=0)

void hhcl::prueflyfehlt(DB *My, const int obverb, const int oblog, const uchar direkt/*=0*/)
{
	hLog(violetts+Tx[T_prueflyfehlt]+schwarz);
	const size_t aktc=0;
	if (!direkt) {
		Feld felder[] = {
			Feld("ID","int","10","",Tx[T_eindeutige_Identifikation],1,1,1,string(),1),
			Feld("DatID","int","10","",Tx[T_eindeutige_Identifikation],1,0,0,string(),1),
			Feld("Kennung","varchar","4","",Tx[T_Kennung],0,0,1),
			Feld("Inhalt","varchar","1","",Tx[T_Inhalt],0,0,1),
		};
		Constraint csts[]{
			Constraint(tlydat+tlyfehlt,new Feld{Feld("DatID")},1,tlydat,new Feld{Feld("DatID")},1,cascade,cascade)
		};
		// auf jeden Fall ginge "binary" statt "utf8" und "" statt "utf8_general_ci"
		Tabelle taba(My,tlyfehlt,felder,sizeof felder/sizeof* felder,0,0,csts,sizeof csts/sizeof *csts,Tx[T_Laborfehlt]/*//,"InnoDB","utf8","utf8_general_ci","DYNAMIC"*/);
		if (taba.prueftab(aktc,obverb)) {
			fLog(rots+Tx[T_Fehler_beim_Pruefen_von]+schwarz+tlyfehlt,1,1);
			exit(11);
		}
	} // if (!direkt)
} // int pruefouttab(DB *My, string touta, int obverb, int oblog, uchar direkt=0)


// wird aufgerufen in: virtpruefweiteres
void hhcl::prueflypgl(DB *My, const int obverb, const int oblog, const uchar direkt/*=0*/)
{
	hLog(violetts+Tx[T_prueflypgl]+schwarz);
	const size_t aktc=0;
	if (!direkt) {
		Feld felder[] = {
			Feld("ID","int","10","",Tx[T_eindeutige_Identifikation],1,1,0,string(),1),
			Feld("idxpneu","int","10","",Tx[T_laborxpneu],1,0,1,string(),1),
			Feld("idpara","int","10","",Tx[T_laborparameter],1,0,1,string(),1),
			Feld("idxpbez","int","10","",Tx[T_ist_identisch_mit_laborxpneu],1,0,1,string(),1),
			Feld("ergaenzt","datetime","0","0",Tx[T_Zeitpunkt_der_Ergaenzung],0,0,1),
		};
		Index indices[]{
		};
		/*//
		Feld ifd0[]{Feld("idxpneu")};
		Feld ifd0a[]{Feld("id")};
		Feld ifd1[]{Feld("idpara")};
		Feld ifd1a[]{Feld("id")};
		Feld ifd2[]{Feld("idxpbez")};
		Feld ifd2a[]{Feld("id")};
		Constraint c0(vorsil+"pgl_1",ifd0,1,tlypneu,ifd0a,1);
		Constraint c1(vorsil+"pgl_2",ifd1,1,tlyparameter,ifd1a,1); // bzw. laborparameter
		Constraint c2(vorsil+"pgl_3",ifd2,1,tlypneu,ifd2a,1,cascade,cascade);
		Constraint csts[]{c0,c1,c2};
		*/
		Constraint csts[]{
			Constraint(vorsil+"pgl_1",new Feld{Feld("idxpneu")},1,tlypneu,new Feld{Feld("id")},1),
			Constraint(vorsil+"pgl_2",new Feld{Feld("idpara")},1,tlyparameter,new Feld{Feld("id")},1),
			Constraint(vorsil+"pgl_3",new Feld{Feld("idxpbez")},1,tlypneu,new Feld{Feld("id")},1,cascade,cascade),
		};
		// auf jeden Fall ginge "binary" statt "utf8" und "" statt "utf8_general_ci"
		Tabelle taba(My,tlypgl,felder,sizeof felder/sizeof* felder,indices,sizeof indices/sizeof *indices,csts,sizeof csts/sizeof *csts, Tx[T_Laborpgl]/*//,"InnoDB","utf8","utf8_general_ci","DYNAMIC"*/);
		if (taba.prueftab(aktc,obverb)) {
			fLog(rots+Tx[T_Fehler_beim_Pruefen_von]+schwarz+tlypgl,1,1);
			exit(11);
		}
	} // if (!direkt)
} // int pruefouttab(DB *My, string touta, int obverb, int oblog, uchar direkt=0)

void hhcl::fuellpql()
{
	pql.clear();
	pql<<"SELECT pat_id FROM `"+tlyus+"` u WHERE gebdat="+sqlft(My->DBS,&gebdat)+" AND auftragsschlüssel = '"+auftrschl+"' AND pat_id<>0 GROUP BY pat_id";
	ergpql();
}

void hhcl::pruefPatID(const int aktc)
{
	hLog(violetts+Tx[T_pruefPatID_Standardfunktion]+schwarz);
	fuellpql();
	for(string const& aktsql:pql) {
		RS rspat(My,aktsql,aktc,ZDB);
		if (!rspat.obfehl) {
			caus<<gruen<<"Zahl: "<<blau<<rspat.result->row_count<<gruen<<" bei: "<<blau<<aktsql<<schwarz<<endl;
			if (rspat.result->row_count==1){
				char ***cerg;
				if ((cerg=rspat.HolZeile())) {
					if (*cerg) {
						caus<<"Pat_id fuer "<<nname<<", "<<vname<<": "<<**cerg<<endl;
						pat_id=**cerg;
						break;
					}
				}
			}
		} else {
			caus<<rot<<"Fehler bei sql: "<<violett<<aktsql<<schwarz<<endl;
		}
	}
//	if (pat_id=="0") exit(97);
} // void hhcl::virtVorgbAllg

//α
// wird aufgerufen in lauf
void hhcl::virtVorgbAllg()
{
	hLog(violetts+Tx[T_virtVorgbAllg]+schwarz); //ω
	dhcl::virtVorgbAllg(); //α
} // void hhcl::virtVorgbAllg

// wird aufgerufen in lauf
void hhcl::pvirtVorgbSpeziell()
{
	hLog(violetts+Tx[T_pvirtVorgbSpeziell]+schwarz); //ω
	dbq="quelle";
	dhcl::pvirtVorgbSpeziell(); //α
	virtMusterVorgb();
} // void hhcl::pvirtVorgbSpeziell

// wird aufgerufen in lauf
void hhcl::virtinitopt()
{ //ω
	opn<<new optcl(/*pname*/"ldatvz",/*pptr*/&ldatvz,/*art*/pverz,T_ldvz_k,T_ldvz_l,/*TxBp*/&Tx,/*Txi*/T_Verzeichnis_der_Faxdateien,/*wi*/0,/*Txi2*/-1,/*rottxt*/string(),/*wert*/-1,/*woher*/!ldatvz.empty());
	opn<<new optcl(/*pname*/string(),/*pptr*/&vonvorne,/*art*/puchar,T_vv_k,T_vv_l,/*TxBp*/&Tx,/*Txi*/T_Loesche_alle_Tabellen_und_fange_von_vorne_an,/*wi*/0,/*Txi2*/-1,/*rottxt*/string(),/*wert*/1,/*woher*/1);
	opn<<new optcl(/*pname*/string(),/*pptr*/&entleer,/*art*/puchar,T_tr_k,T_tr_l,/*TxBp*/&Tx,/*Txi*/T_Entleert_alle_Tabellen_und_faengt_von_vorne_an,/*wi*/0,/*Txi2*/-1,/*rottxt*/string(),/*wert*/1,/*woher*/1);
	opn<<new optcl(/*pname*/string(),/*pptr*/&loeschalle,/*art*/puchar,T_la_k,T_la_l,/*TxBp*/&Tx,/*Txi*/T_loescht_alle_Tabellen,/*wi*/0,/*Txi2*/-1,/*rottxt*/string(),/*wert*/1,/*woher*/1);
	dhcl::virtinitopt(); //α
} // void hhcl::virtinitopt

// wird aufgerufen in lauf
void hhcl::pvirtmacherkl()
{
	erkl<<blau<<Txk[T_Program]<<violett<<DPROG //ω
		<<blau<<" ist etwas ganz Spezielles"<<schwarz; //α
} // void hhcl::pvirtmacherkl

// wird aufgerufen in lauf
void hhcl::virtMusterVorgb()
{
	hLog(violetts+Tx[T_virtMusterVorgb]+schwarz); //ω
	dhcl::virtMusterVorgb(); //α
} // void hhcl::MusterVorgb

// wird aufgerufen in lauf
void hhcl::virtzeigversion(const string& ltiffv/*=nix*/)
{ //ω
	dhcl::virtzeigversion(ltiffv); //α
} // void hhcl::virtzeigversion

// wird aufgerufen in lauf
void hhcl::pvirtvorrueckfragen()
{
	hLog(violetts+Tx[T_pvirtvorrueckfragen]+schwarz);
	if (rzf) { //ω
  } //α
} // void hhcl::pvirtvorrueckfragen


// wird aufgerufen in lauf
void hhcl::virtrueckfragen()
{
	hLog(violetts+Tx[T_virtrueckfragen]+schwarz);
	if (rzf) { //ω
		ldatvz=Tippverz(Tx[T_Verzeichnis_der_Faxdateien],&ldatvz);
	} //α
	dhcl::virtrueckfragen();
} // void hhcl::virtrueckfragen()

// wird aufgerufen in lauf
void hhcl::virtpruefweiteres()
{ //ω
	initDB();
	const size_t aktc=0;
	if (vonvorne||loeschalle) {
		RS d0(My,"DROP TABLE IF EXISTS "+tlypgl,aktc,ZDB);
		RS d1(My,"DROP TABLE IF EXISTS "+tlywert,aktc,ZDB);
		RS d2(My,"DROP TABLE IF EXISTS "+tlyleist,aktc,ZDB);
		RS d3(My,"DROP TABLE IF EXISTS "+tlybakt,aktc,ZDB);
		RS d6(My,"DROP TABLE IF EXISTS "+tlypnb,aktc,ZDB);
		RS d7(My,"DROP TABLE IF EXISTS "+tlypneu,aktc,ZDB);
		RS d4(My,"DROP TABLE IF EXISTS "+tlyus,aktc,ZDB);
		RS d5(My,"DROP TABLE IF EXISTS "+tlysaetze,aktc,ZDB);
		RS d12(My,"DROP TABLE IF EXISTS "+tlyaerzte,aktc,ZDB);
		RS d11(My,"DROP TABLE IF EXISTS "+tlyparameter,aktc,ZDB);
		// aber: laborparameter nicht loeschen!
		RS d8(My,"DROP TABLE IF EXISTS "+tlyplab,aktc,ZDB);
		RS d10(My,"DROP TABLE IF EXISTS "+tlyfehlt,aktc,ZDB);
		RS d9(My,"DROP TABLE IF EXISTS "+tlydat,aktc,ZDB);
		fLog(blaus+Tx[vonvorne?T_Loesche_alle_Tabellen_und_fange_von_vorne_an:T_loescht_alle_Tabellen]+schwarz,1,1);
	} else if (entleer) {
		RS da(My,"SET FOREIGN_KEY_CHECKS=0",aktc,ZDB);
		RS d0(My,"TRUNCATE "+tlypgl,aktc,ZDB);
		RS d1(My,"TRUNCATE "+tlywert,aktc,ZDB);
		RS d2(My,"TRUNCATE "+tlyleist,aktc,ZDB);
		RS d3(My,"TRUNCATE "+tlybakt,aktc,ZDB);
		RS d6(My,"TRUNCATE "+tlypnb,aktc,ZDB);
		RS d7(My,"TRUNCATE "+tlypneu,aktc,ZDB);
		RS d4(My,"TRUNCATE "+tlyus,aktc,ZDB);
		RS d5(My,"TRUNCATE "+tlysaetze,aktc,ZDB);
		RS d12(My,"TRUNCATE "+tlyaerzte,aktc,ZDB);
		RS d11(My,"TRUNCATE "+tlyparameter,aktc,ZDB);
		// aber: laborparameter nicht loeschen!
		RS d8(My,"DELETE FROM `"+tlyplab+"` where id>1",aktc,ZDB);
		RS d10(My,"TRUNCATE "+tlyfehlt,aktc,ZDB);
		RS d9(My,"TRUNCATE "+tlydat,aktc,ZDB);
		RS de(My,"SET FOREIGN_KEY_CHECKS=1",aktc,ZDB);
		fLog(blaus+Tx[T_Entleert_alle_Tabellen_und_faengt_von_vorne_an]+schwarz,1,1);
	}
	if (!loeschalle) {
		prueflyhinw(My, obverb, oblog, /*direkt*/0);
		prueflyplab(My, obverb, oblog, /*direkt*/0);
		prueflyparameter(My, obverb, oblog, /*direkt*/0);
		prueflypneu(My, obverb, oblog, /*direkt*/0);
		prueflypnb(My, obverb, oblog, /*direkt*/0);
		prueflydat(My, obverb, oblog, /*direkt*/0);
		prueflyfehlt(My, obverb, oblog, /*direkt*/0);
		prueflyaerzte(My, obverb, oblog, /*direkt*/0);
		prueflysaetze(My, obverb, oblog, /*direkt*/0);
		prueflyus(My, obverb, oblog, /*direkt*/0);
		prueflybakt(My, obverb, oblog, /*direkt*/0);
		prueflyleist(My, obverb, oblog, /*direkt*/0);
		prueflywert(My, obverb, oblog, /*direkt*/0);
		prueflypgl(My, obverb, oblog, /*direkt*/0);
	}
	hcl::virtpruefweiteres(); // z.Zt. leer //α
} // void hhcl::virtpruefweiteres

// wird aufgerufen in lauf
void hhcl::virtzeigueberschrift()
{ //ω
  // hier ggf. noch etwas an 'uebers' anhaengen //α
	uebers<<" (Laborimport) ";
	hcl::virtzeigueberschrift();
} // void hhcl::virtzeigueberschrift

void BDTtoDate(string& inh,struct tm *tm)
{
	memset(tm,0,sizeof *tm);
//	const char* const mu[]{"%d%m%Y","%Y%m%d"};
	const char* const mu[]{"%Y%m%d","%d%m%Y"};
	for(auto const& aktmu:mu) {
		strptime(inh.c_str(),aktmu,tm);
		if (tm->tm_year && tm->tm_year<200 && tm->tm_mon<12 && tm->tm_mday && tm->tm_mday<32)
			break;
	} // 	for(auto& aktmu:mu)
} // void BDTtoDate

void hhcl::russchreib(insv &rus,const int aktc,string *usidp)
{
	rus.ausgeb();
	pruefPatID(aktc);
	rus.hz("Nachname",nname);
	rus.hz("Vorname",vname);
	rus.hz("Titel",titel);
	rus.hz("NVorsatz",nvorsatz);
	rus.hz("GebDat",&gebdat);
	rus.hz("Geschlecht",sgschl);
	rus.hz("Pat_id",pat_id);
	rus.schreib(/*sammeln*/0,/*obverb*/1,/*idp*/usidp);
	usreset();
} // void hhcl::russchreib

// ins russchreib und dverarbeit
void hhcl::usreset()
{
	nname.clear();
	vname.clear();
	titel.clear();
	nvorsatz.clear();
	memset(&gebdat,0,sizeof gebdat);
	memset(&eingtm,0,sizeof eingtm);
	sgschl.clear();
	auftrschl.clear();
	pat_id="0";
	baktid="0";
	hinwid="0";
	erklid="0";
	kommid="0";
} // void hhcl::usreset

void hhcl::wertschreib(const int aktc,insv *rpar, insv *rpneu, insv *rpnb, insv *rwe, insv *rbawep,insv *rhinwp)
{
	if (!normbereich.empty()) {
		rpar->hz("NB",normbereich);
		rpnb->hz("NB",normbereich);
	}
	if (!uNm.empty()) {
		rpar->hz("uNm",uNm);
	}
	if (!oNm.empty()) {
		rpar->hz("oNm",oNm);
	}
	if (!uNw.empty()) {
		rpar->hz("uNw",uNw);
	}
	if (!oNw.empty()) {
		rpar->hz("oNw",oNw);
	}
	if (rpar->size()) {
		/*auto*/chrono::system_clock::time_point aktzp=chrono::system_clock::now();
		rpar->hz("Aktzeit",&aktzp);
		// z.B. "Labor 20101201 044232.dat"
		rpar->schreib(/*sammeln*/0,/*obverb*/1,/*idp*/0,/*mitupd=*/1);
	}
	if (rpneu->size()) {
		rpneu->ausgeb();
		rpneu->schreib(/*sammeln*/0,/*obverb*/1,/*idp*/&pneuind);
		if (!pneuind.empty()) {
			rpnb->hz("PNEUID",pneuind);
			if (sgschl=="2") {
				rpnb->hz("uNg",uNw);
				rpnb->hz("oNg",oNw);
			} else {
				rpnb->hz("uNg",uNm);
				rpnb->hz("oNg",oNm);
			}
			rpnb->schreib(/*sammeln*/0,/*obverb*/1,/*idp*/&pnbid);
		}
	}

	if (rbawep) {
		rbawep->hz("NBID",pnbid);
		// z.B. "Labor 20101201 004634.dat"
		if (!qspez.empty()) {
			rbawep->hz("QSpez",qspez);
		}
		// Field Erklärung doesn't have a default value
			rhinwp->hz("Text",erklaerung);
			rhinwp->schreib(/*sammeln*/0,/*obverb*/1,/*idp*/&erklid,/*mitupd=*/0);
			rbawep->hz("ErklID",erklid);
//		rbawep->hz("Erklärung",erklaerung);
		if (!kommentar.empty()) {
			rhinwp->hz("Text",kommentar);
			rhinwp->schreib(/*sammeln*/0,/*obverb*/1,/*idp*/&kommid,/*mitupd=*/0);
			rbawep->hz("KommID",kommid);
//			rbawep->hz("Kommentar",kommentar);
		}
		if (!auftrhinw.empty()) {
			rhinwp->hz("Text",auftrhinw);
			rhinwp->schreib(/*sammeln*/0,/*obverb*/1,/*idp*/&hinwid,/*mitupd=*/0);
			rbawep->hz("HinwID",hinwid);
//			rbawep->hz("AuftrHinw",auftrhinw);
		} // 						if (!auftrhinw.empty())
		rbawep->hz("AbnDat",&abndat);
		if (rbawep==rwe) {
			rbawep->hz("BaktID",baktid);
		}
		rbawep->schreib(/*sammeln*/0,/*obverb*/1,/*idp*/rbawep==rwe?0:&baktid,/*mitupd=*/1);
		rbawep=0;
		keimz=0; // "Labor 20101204 195050.dat"
		keimzda=0; // "Labor 20101210 034422.dat"
	} // 					if (rbawep)
	normbereich.clear();
	uNm.clear();
	oNm.clear();
	uNw.clear();
	oNw.clear();
	qspez.clear();
	erklaerung.clear();
	kommentar.clear();
	auftrhinw.clear();
	memset(&abndat,0,sizeof abndat);
	pnbid.clear();
} // void hhcl::wertschreib

void hhcl::dverarbeit(const string& datei)
{
#define speichern
#ifdef speichern
	const size_t aktc=0;
#endif 
	string datid,satzid,arztid,satzart;
	unsigned UsLfd;
	uchar lsatzart=0; // für Bedeutung von nachfolgendem 8100 (Satzlaenge): 1=8220 (Datenpaket-Header), 2=8221 (Datenpaketheader-Ende), 3=8201,8202 oder 8203 (Labor)
	uchar saetzeoffen, usoffen=0;
	usreset();
	string usid;
	// Zahl der unbekannten Geschlechter aus Namen reduzieren
	RS unbekgschl(My,"update namen n set geschlecht = if((SELECT COUNT(DISTINCT i.geschlecht) FROM (SELECT * FROM namen) i WHERE vorname=n.vorname AND geschlecht<>' ')=1,(SELECT MAX(i.geschlecht) FROM (SELECT * FROM namen) i WHERE vorname=n.vorname AND geschlecht<>' '),n.geschlecht) WHERE geschlecht= ' '",aktc,ZDB);
	svec eindfeld; eindfeld<<"id";
	insv reing(My,/*itab*/tlydat,aktc,/*eindeutig*/0,eindfeld,/*asy*/0,/*csets*/0);
	/*auto*/chrono::system_clock::time_point jetzt=chrono::system_clock::now();
	reing.hz("Name",base_name(datei));
	reing.hz("Pfad",datei);
	struct stat pfst{0};
	if (!lstat(datei.c_str(),&pfst)) {
		reing.hz("geändert",&pfst.st_mtime);
		reing.hz("Größe",pfst.st_size);
	}
	reing.hz("Zp",&jetzt);
#ifdef speichern
	reing.schreib(/*sammeln*/0,/*obverb*/1,/*idp*/&datid);
#endif 
	insv raerzte(My,/*itab*/tlyaerzte,aktc,/*eindeutig*/1,eindfeld,/*asy*/0,/*csets*/0);
	insv rsaetze(My,/*itab*/tlysaetze,aktc,/*eindeutig*/0,eindfeld,/*asy*/0,/*csets*/0);
	insv rpar(My,/*itab*/tlyparameter,aktc,/*eindeutig*/0,eindfeld,/*asy*/0,/*csets*/0);
	insv rpneu(My,/*itab*/tlypneu,aktc,/*eindeutig*/1,eindfeld,/*asy*/0,/*csets*/0);
	insv rpnb(My,/*itab*/tlypnb,aktc,/*eindeutig*/1,eindfeld,/*asy*/0,/*csets*/0);
	insv rlab(My,/*itab*/tlyplab,aktc,/*eindeutig*/1,eindfeld,/*asy*/0,/*csets*/0);
	insv rus(My,/*itab*/tlyus,aktc,/*eindeutig*/0,eindfeld,/*asy*/0,/*csets*/0);
	insv rfe(My,/*itab*/tlyfehlt,aktc,/*eindeutig*/0,eindfeld,/*asy*/0,/*csets*/0);
	insv rba(My,/*itab*/tlybakt,aktc,/*eindeutig*/0,eindfeld,/*asy*/0,/*csets*/0);
	insv rwe(My,/*itab*/tlywert,aktc,/*eindeutig*/0,eindfeld,/*asy*/0,/*csets*/0);
	insv *rbawep=0; // Zeiger auf rba oder rwe
	insv rhinw(My,/*itab*/tlyhinw,aktc,/*eindeutig*/1,eindfeld,/*asy*/0,/*csets*/0);
	insv rle(My,/*itab*/tlyleist,aktc,/*eindeutig*/0,eindfeld,/*asy*/0,/*csets*/0);

	caus<<rot<<datei<<schwarz<<endl;
	
	mdatei mdat(datei,ios::in);
	if (mdat.is_open()) {
		// Zeichensatz ermitteln und verwenden
		uchar cp=0; // 0=utf-8, 1=iso-8859-15, 2=cp850
		// ä,ö,ü,Ä,Ö,Ü,ß,µ, iso8859-15, cp850
		const char* const sonder[2]={"\xE4\xF6\xFC\xC4\xD6\xDC\xDF\xB5","\x84\x94\x81\x8E\x99\x9A\xE1\xE6"};
		string zeile,altz;
		struct tm berdat={0};
		uchar oblaborda=0, arztnameda=0, /*in (Vor)zeile kommt Wort Keimzahl vor*/keimz=0,/*die Keimzahl wurde schon eingesetzt*/keimzda=0;
		string verf,abkue,lanr;
		while(getline(mdat,zeile)) {
			string bzahl=zeile.substr(0,3);
			string cd,inh;
			if (zeile.size()>3) cd=zeile.substr(3,4);
			if (zeile.size()>7) {
				if (!cp) {
					for(unsigned p=0;p<2;p++) {
//					for(unsigned const& p: {0,1}) {
						if (zeile.find_first_of(sonder[p],7)!=string::npos) {
							cp=p+1;
							break;
						}
					}
				}
				if (cp) {
					inh=icp[cp-1]->convert(zeile,7);
				} else {
					inh=zeile.substr(7);
				}
				sersetze(&inh,"\r","");
			}
			if (cd.empty()||!cd[0]) continue;
			// sonst keinen Fall von Zeilenumbruch gefunden
			caus<<blau<<bzahl<<" "<<cd<<" "<<schwarz<<inh<<endl;
			//			for(uchar i=0;i<inh.length();i++) { caus<<(int)(uchar)inh[i]<<" "; } caus<<endl;
#ifdef speichern
			if (cd=="8000") {
				if (inh.substr(0,4)=="8220") { // Datenpaket-Header
					lsatzart=1;
					saetzeoffen=1;
					rsaetze.hz("Satzart",inh);
					rsaetze.hz("DatID",datid);
					UsLfd=0;
				} else if (inh.substr(0,4)=="8221") { // Datenpaket-Abschluss
//					if (inh.length()>4) ... // trat nicht auf
					lsatzart=2;
					if (usoffen) {
						// caus<<rus.size()<<endl;
						// z.B. "Labor 20120223 020708.dat"
						russchreib(rus,aktc,&usid);
						usoffen=0;
					}
					wertschreib(aktc,&rpar,&rpneu,&rpnb,&rwe,rbawep,&rhinw);
					// z.B. "Labor 20101201 004634.dat"
					rle.schreib(/*sammeln*/0,/*obverb*/1,/*idp*/0);
					//					satzid="0";
				} else { // 8201 FA-Bericht, 8202 LG-Bericht, 8203 Mikrobiologiebericht
					lsatzart=3;
					if (saetzeoffen) {
						if (!oblaborda) {
							rsaetze.hz("LabID",1);
						} else
							oblaborda=0;
						if (!lanr.empty()) {
							raerzte.hz("Lanr",lanr);
							lanr.clear();
						}
						// z.B. "Labor 20101201 044232.dat"
						raerzte.schreib(/*sammeln*/0,/*obverb*/1,/*idp*/&arztid);
						rsaetze.hz("ArztID",arztid);
						rsaetze.schreib(/*sammeln*/0,/*obverb*/1,/*idp*/&satzid);
						arztnameda=0;
						saetzeoffen=0;
					}
					//					rus.zeig("0");
					if (usoffen) {
						// caus<<rus.size()<<endl;
						// z.B. "Labor 20091126 162200.dat"
						russchreib(rus,aktc,&usid);
						usoffen=0;
					}
					satzart=inh;
					rus.hz("DatID",datid);
					rus.hz("SatzID",satzid);
					rus.hz("SatzArt",satzart);
					rus.hz("UsLfd",++UsLfd);
					usoffen=1;
				}
			} else if (cd=="8100") {
				switch (lsatzart) {
					case 1:
						rsaetze.hz("Satzlänge",inh);
						break;
					case 2:
						rsaetze.hz("SatzlängeSchluss",inh);
						// speichern unter 9202
						break;
					case 3:
						rus.hz("Satzlänge",inh);
						break;
					default:
						break;
				}
			} else if (cd=="8410" || cd=="8434") { // 8410=Test-Ident, 8434=Verfahren
				// z.B. "Labor 20101202 002036.dat"
					wertschreib(aktc,&rpar,&rpneu,&rpnb,&rwe,rbawep,&rhinw);
				// z.B. "Labor 20101202 011636.dat"
				rle.schreib(/*sammeln*/0,/*obverb*/1,/*idp*/0);
				if (usoffen) {
					// caus<<rus.size()<<endl;
					// z.B. "Labor 20091126 162829.dat"
					russchreib(rus,aktc,&usid);
					usoffen=0;
				}
				if (cd=="8434") {
					if (rba.size()) {
						caus<<"rba.size(): "<<rba.size()<<endl;
						rba.schreib(/*sammeln*/0,/*obverb*/1,/*idp*/&baktid,/*mitupd=*/1);
						keimz=0; // "Labor 20101204 195050.dat"
						keimzda=0; // "Labor 20101210 034422.dat"
						exit(59);
					}
					rbawep=&rba;
				} else /*if (cd=="8410")*/ {
//					if (rwe.size()) ... trat nicht auf
					rbawep=&rwe;
				} // 					if (cd=="8434") else if (cd=="8410")
				rbawep->hz("UsID",usid);
				if (cd=="8434") {
					verf=inh;
					rba.hz("Verf",inh);
				} else /*if (cd=="8410")*/ {
					abkue=inh;
					rwe.hz("Abkü",inh);
				} // 					if (cd=="8434") else if (cd=="8410")
				rpar.hz("Abkü",inh);
				rpneu.hz("Abkü",inh);
				rpar.hz("LabID",labind);
				rpneu.hz("LabID",labind);
			} else if (cd=="5001") {
				// z.B. 1b01042005.ld0
				rle.schreib(/*sammeln*/0,/*obverb*/1,/*idp*/0);
				//				rle.clear();
				rle.hz("UsID",usid);
				if (rbawep==&rba) {
					rle.hz("Verf",verf);
				} else {
					rle.hz("Abkü",abkue);
				}
				rle.hz("EBM",inh);
			} else if (cd=="5005") {
				rle.hz("Anzahl",inh);
			} else if (cd=="8406") { // zwingende Abfolge mit 5001 wurde 2/05 geprueft
				rle.hz("GOÄ",inh);
			} else if (cd=="8614") { 
				rbawep->hz("Abrd",inh);
			} else if (cd=="8411") {
				rbawep->hz("Langtext",inh);
				rpar.hz("Langtext",inh);
				rpneu.hz("Langtext",inh);
			} else if (cd=="8428") {
				if (!rbawep) caus<<rot<<"4 Fehler rbawep 0"<<schwarz<<endl;
				rbawep->hz("KuQu",inh);
			} else if (cd=="8430") {
				if (!rbawep) caus<<rot<<"3 Fehler rbawep 0"<<schwarz<<endl;
				rbawep->hz("Quelle",inh);
			} else if (cd=="8431") {
				if (!rbawep) caus<<rot<<"2 Fehler rbawep 0"<<schwarz<<endl;
				if (qspez.empty()) qspez=inh;
				else {
					qspez+="\r\n";
					qspez+=inh;
				}
			} else if (cd=="8432") { // Abnahmedatum
				BDTtoDate(inh,&abndat);
			} else if (cd=="8433") {
				strptime(inh.c_str(),"%H%M",&abndat);
			} else if (cd=="8470") {
				if (erklaerung.empty()) erklaerung=inh;
				else {
					erklaerung+="\r\n";
					erklaerung+=inh;
				}
			} else if (cd=="8310") {
				rus.hz("Auftragsnummer",inh);
			} else if (cd=="8311") {
				auftrschl=inh;
				rus.hz("Auftragsschlüssel",auftrschl);
			} else if (cd=="8418") {
					rwe.hz("Teststatus",inh);
			} else if (cd=="8420") {
					rwe.hz("Wert",inh);
			} else if (cd=="8421") {
				if (rbawep) {
					rbawep->hz("Einheit",inh);
				}
				rpar.hz("Einheit",inh);
				rpneu.hz("Einheit",inh);
			} else if (cd=="8422") {
					rwe.hz("Grenzwerti",inh);
			} else if (cd=="8301") {
				BDTtoDate(inh,&eingtm);
				rus.hz("Eingang",&eingtm);
			} else if (cd=="8302") {
				BDTtoDate(inh,&berdat);
			} else if (cd=="8303") {
				strptime(inh.c_str(),"%H%M",&berdat);
				rus.hz("Berichtsdatum",&berdat);
				//// <<"3 berdat: "<<ztacl(&berdat,"%F %T")<<endl;
			} else if (cd=="8609") {
				rus.hz("Abrechnungstyp",inh);
			} else if (cd=="8401") { // Befundart
				rus.hz("Befart",inh); // Fertigstellungsgrad
			} else if (cd=="8615") {
				rus.hz("Auftraggeber",inh);
			} else if (cd=="8403") {
				rus.hz("GebüOrd",inh);
			} else if (cd=="8405") {
				rus.hz("Patienteninformation",inh);
			} else if (cd=="8407") { // ' 1=Mann, 2=Frau, 3=unbek, 4=Knabe, 5=Mädchen, 0=Name fehlt, 9=beide;
				sgschl=inh;
			} else if (cd=="3101") {
				nname=(inh.substr(0,3)=="zzz"?inh.substr(4):inh);
				if (!usoffen) {
					rus.hz("DatID",datid);
					rus.hz("SatzID",satzid);
					rus.hz("SatzArt",satzart);
					rus.hz("UsLfd",++UsLfd);
					usoffen=1; // verkuerzte Information z.B. in "Labor 20051127 224528.dat"
				} // 				if (!usoffen)
			} else if (cd=="3102") {
				vname=inh;
			} else if (cd=="3103") {
				BDTtoDate(inh,&gebdat);
			} else if (cd=="3110") {
				sgschl=(inh=="W"?"2":inh=="M"?"1":inh=="X"?"3":inh);
			} else if (cd=="3104") {
				titel=inh;
			} else if (cd=="3100") {
				nvorsatz=inh;
			} else if (cd=="9212") {
				rsaetze.hz("VersionSatzb",inh);
      } else if (cd=="0201") {
					raerzte.hz("ArztNr",inh);
      } else if (cd=="0203") {
					raerzte.hz("ArztName",inh);
      } else if (cd=="0205") {
					raerzte.hz("StraßePraxis",inh);
      } else if (cd=="0211") {
				if (!arztnameda) {
					raerzte.hz("Arzt",inh);
					arztnameda=1;
				}
			} else if (cd=="0212") {
				lanr=inh;
      } else if (cd=="0215") {
					raerzte.hz("PLZPraxis",inh);
      } else if (cd=="0216") {
					raerzte.hz("OrtPraxis",inh);
			} else if (cd=="8300") {
				svec labv;
				aufSplit(&labv, inh,';');
				if (labv.size()>0) {
					rlab.hz("Labor",labv[0]);
					if (labv.size()>1) {
						rlab.hz("StraßeLabor",labv[1]);
						if (labv.size()>2) {
							rlab.hz("PLZLabor",labv[2].substr(0,5));
							if (labv[2].size()>5) {
								rlab.hz("OrtLabor",labv[2].substr(6));
							}
						}
					}
				} else {
					rlab.hz("Labor",inh);
				}
				// 1. Moeglichkeit
				// z.B. "Labor 20101201 004634.dat"
				rlab.schreib(/*sammeln*/0,/*obverb*/1,/*idp*/&labind);
				oblaborda=1;
				rsaetze.hz("labid",labind);
			} else if (cd=="8320") {
				rlab.hz("Labor",inh);
			} else if (cd=="8321") {
				rlab.hz("StraßeLabor",inh);
			} else if (cd=="8322") {
				rlab.hz("PLZLabor",inh);
			} else if (cd=="8323") {
				// 2. Moeglichkeit
				rlab.hz("OrtLabor",inh);
				// z.B. 1b01042005.ldt
				rlab.schreib(/*sammeln*/0,/*obverb*/1,/*idp*/&labind);
				oblaborda=1;
				rsaetze.hz("labid",labind);
			} else if (cd=="0101") {
				rsaetze.hz("KBVPrüfnr",inh);
			} else if (cd=="8480") {
				if (kommentar.empty()) 
					kommentar=inh;
				else {
					kommentar+="\r\n";
					kommentar+=inh;
				}
				if (keimz && !keimzda) {
					if (inh.find("00")!=string::npos) {
						rba.hz("Keimzahl",inh);
					}
					keimzda=1; // "Labor 20101210 034422.dat"
					keimz=0;
				}
				if (!keimz && inh.find("Keimzahl")!=string::npos) {
					keimz=1;
				}
			} else if (cd=="8490") {
				if (auftrhinw.empty()) 
					auftrhinw=inh;
				else {
					auftrhinw+="\r\n";
					auftrhinw+=inh;
				}
			} else if (cd=="8460") { 
				// Normbereich
				uNm.clear();
				oNm.clear();
				oNw.clear();
				uNw.clear();
				if (normbereich.empty()) {
					normbereich=inh;
					string nbn=ersetze(inh.c_str(),"bis","0-");
					size_t pos;
					if ((pos=nbn.find("ab "))!=string::npos) {
						nbn.erase(0,pos+3);
						nbn+='-';
					} else if ((pos=nbn.find(">"))!=string::npos) {
						nbn.erase(0,pos+1);
						nbn+='-';
					} else if ((pos=nbn.find(":"))!=string::npos) {
						nbn.erase(0,pos+1);
						nbn.insert(0,1,'-');
					} else if ((pos=nbn.find("<"))!=string::npos) {
						if (nbn.find("chwere")>pos) { // Schwere Pankreasinsuffizienz:        < 100 µg/g Stuhl
							nbn.erase(0,pos+1);
							nbn.insert(0,1,'-');
						} else {
							nbn.erase(0,pos+1);
							nbn+='-';
						}
					}
					svec nbv;
					aufSplit(&nbv, nbn,'-');
					if (nbv.size()) {
						if (sgschl=="2") {
							uNw=zuzahl(nbv[0]);
						} else {
							uNm=zuzahl(nbv[0]);
						}
						if (nbv.size()>1) {
							if (sgschl=="2") {
								oNw=zuzahl(nbv[1]);
							} else {
								oNm=zuzahl(nbv[1]);
							}
						}
					} else {
						caus<<rot<<"Normbereich ohne '-': "<<violett<<nbn<<schwarz<<endl;
						exit(47);
					}
				} else {
					normbereich+="\r\n";
					normbereich+=inh;
				}
			} else if (cd=="8461") {
				// in der Annhame, dass 8461 vor 8462 kommt
				uNm.clear();
				oNm.clear();
				oNw.clear();
				uNw.clear();
				if (sgschl=="2") {
					uNw=zuzahl(inh);
				} else {
					uNm=zuzahl(inh);
				}
			} else if (cd=="8462") {
				if (sgschl=="2") {
					oNw=zuzahl(inh);
				} else {
					oNm=zuzahl(inh);
				}
			} else if (cd=="9106") {
				rsaetze.hz("Zeichensatz",inh);
			} else if (cd=="8312") {
				rsaetze.hz("Kundenarztnr",inh);
			} else if (cd=="9103") {
				tm erstd;
				BDTtoDate(inh,&erstd);
				rsaetze.hz("Erstellungsdatum",&erstd);
			} else if (cd=="9202") {
				rsaetze.hz("Gesamtlänge",inh);
				// update rsaetze.schreib(/*sammeln*/0,/*obverb*/1,/*idp*/0);
				rsaetze.ergaenz(satzid,/*sammeln*/0,/*obverb*/1,/*idp*/0);
			} else {
				rfe.hz("DatID",datid);
				rfe.hz("Kennung",cd);
				rfe.hz("Inhalt",inh);
				// z.B. "Labor 20120724 072122.dat"
				rfe.schreib(/*sammeln*/0,/*obverb*/1,/*idp*/0);
			}
			altz=zeile;
#endif 
		}
		reing.hz("codepage",cp);
		reing.hz("fertig",1);
		reing.ergaenz(datid,/*sammeln*/0,/*obverb*/1,/*idp*/0);
	} // 	if (mdat.is_open())
//	exit(0);
} // void hhcl::dverarbeit(const string& datei)

// wird aufgerufen in lauf
void hhcl::pvirtfuehraus()
{ //ω
	const size_t aktc=0;
	const string fertigvz=ldatvz+"/"+fertiguvz;
	if (!loeschalle) {
		pruefverz(fertigvz,obverb,oblog);
		systemrueck("chmod --reference '"+ldatvz+"' '"+fertigvz+"'");
		systemrueck("chown --reference '"+ldatvz+"' '"+fertigvz+"'");
		svec lrue;
		systemrueck("find "+ldatvz+" -maxdepth 1 -type f \\( -iname '1b*.ld*' -or -iname '*.ldt' -or -iname 'x*.ld*' -or -iname 'labor*.dat' \\) -printf '%TY%Tm%Td%TH%TM%TS\t%p\n' "+string(obverb?"":"2>/dev/null")+"|sort|cut -f2", obverb,oblog,&lrue,/*obsudc=*/0);
		//	systemrueck("find "+ldatvz+" -type f -iname '*' "+string(obverb?"":" 2>/dev/null")+"| sort -r", obverb,oblog,&lrue,/*obsudc=*/0);
		caus<<"Dateien gefunden: "<<lrue.size()<<endl;
		for(size_t i=0;i<lrue.size();i++) {
			//		caus<<i<<": "<<blau<<lrue[i]<<schwarz<<endl;
			RS loeschvor(My,"DELETE FROM `"+tlydat+"` where pfad='"+lrue[i]+"' and fertig<>1",aktc,ZDB);
			char ***cerg;
			RS rsfertig(My,"SELECT fertig,name FROM `"+tlydat+"` l WHERE name ='"+base_name(lrue[i])+"' AND pfad = '"+lrue[i]+"'",aktc,ZDB);
			if (rsfertig.obfehl||!(cerg=rsfertig.HolZeile())||cerg?!*cerg:1) {
				// caus<<i<<": "<<blau<<lrue[i]<<schwarz<<endl;
				dverarbeit(lrue[i]);
			}
		}
	} // 	if (!loeschalle)
	caus<<"fertig!"<<endl;
} // void hhcl::pvirtfuehraus  //α

// wird aufgerufen in lauf
void hhcl::virtschlussanzeige()
{   //ω
	dhcl::virtschlussanzeige(); //α
} // void hhcl::virtschlussanzeige

// wird aufgerufen in: main
void hhcl::virtautokonfschreib()
{
	// int altobverb=obverb;
	// obverb=1;
	hLog(violetts+Txk[T_autokonfschreib]+schwarz+", "+Txk[T_zu_schreiben]+((rzf||hccd.obzuschreib)?Txk[T_ja]:Txk[T_nein]));
	/*//
		capizukonf und hylazukonf hier immer 0
		char buf[200];
		sprintf(buf,"rzf: %d, capizukonf: %d, hylazukonf: %d, obkschreib: %d",(int)rzf, (int)capizukonf, (int)hylazukonf, (int)obkschreib);
		hLog(blaus+buf+schwarz);
	 */
	struct stat kstat={0};
	if (lstat(akonfdt.c_str(),&kstat))
		hccd.obzuschreib=1;
	if (rzf||hccd.obzuschreib) {
		hLog(gruens+Tx[T_schreibe_Konfiguration]+schwarz,/*oberr*/obverb);
		// restliche Erklaerungen festlegen
		////    agcnfA.setzbem("language",sprachstr);
		hcl::virtautokonfschreib(); //ω
	} // if (rzf||obkschreib) //α
	// obverb=altobverb;
} // void hhcl::virtautokonfschreib

hhcl::~hhcl() 
{ //ω
} //α

void hhcl::virtlieskonfein()
{
	const int altobverb=obverb;
	//	obverb=1;
	hLog(violetts+Txk[T_virtlieskonfein]+schwarz);
	hcl::virtlieskonfein(); //ω
	hLog(violetts+Txk[T_Ende]+Txk[T_virtlieskonfein]+schwarz); //α
	obverb=altobverb;
} // void hhcl::virtlieskonfein()

int main(int argc,char** argv)
{
	if (argc>1) { //ω
	} //α
	hhcl hhi(argc,argv); // hiesige Hauptinstanz, mit lngzuw, setzlog und pruefplatte
	hhi.lauf(); // Einleitungsteil mit virtuellen Funktionen, 
	// mit virtVorgbAllg,pvirtVorgbSpeziell,initopt,parsecl,pvirtmacherkl,zeighilfe,virtlieskonfein,verarbeitkonf,lieszaehlerein,MusterVorgb,dovi,dovs,virtzeigversion
	// virtautokonfschreib,update,
} // int main 

void hhcl::virttesterg()
{
} //ω
