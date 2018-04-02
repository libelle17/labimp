// '//α' oder '//ω' als Kommentar sind nur fuer die Verwendung dieses Programms als Programmvorlage wichtig
// sed -n '/\/\/α/,/\/\/ω/p;/\/\/ω/a\\' test
// sed -n '/\/\/α/,/\/\/ω/p' test
#include "kons.h" //α
#include "DB.h" 
#include <tiffio.h>
#define VOMHAUPTCODE // um Funktionsdefinition manchmal mit "__attribute__((weak)) " versehen zu können //ω
#include "labimp.h"
// fuer verschiedene Sprachen //α
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
	// T_prueflaboryeingel
	{"prueflaboryeingel()","testlaboratoryyimported()"},
	// 	T_prueflaboryleist,
	{"prueflaboryleist()","testlaboratoryyservice()"},
	// T_prueflaborypgl,
	{"prueflaborypgl()","testlaboratoryparameterequities()"},
	// T_prueflaboryplab,
	{"prueflaboryplab()","testlaboratoryplab()"},
	// T_prueflaborypnb,
	{"prueflaborypnb()","testlaboratorypnb()"},
	// T_prueflaborypneu,
	{"prueflaborypneu()","testlaboratorypneu()"},
	// T_prueflaborysaetze,
	{"prueflaborysaetze()","testlaboratorysets()"},
	// T_prueflaboryus,
	{"prueflaboryus()","testlaboratoryus"},
	// T_prueflaborywert,
	{"prueflaborywert()","testlaboratoryvalue()"},
	// T_prueflaborybakt,
	{"prueflaborybakt","testlaboratorybact()"},
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
	{"Laboreinlesungen","laboratory imports"},
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
	{"Laborbakt","Laborbak"},
	// T_laborxpneu
	{"laborxpneu","laborxpneu"},
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
	// T_Bezug_zu_LaborEingelesen
	{"Bezug zu LaborEingelesen","reference to LaborEingelesen"},
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
	{"",""} //α
}; // char const *DPROG_T[T_MAX+1][SprachZahl]=

class TxB Tx((const char* const* const* const*)DPROG_T);
const char *logdt="/var/log/" DPROG "vorgabe.log";//darauf wird in kons.h verwiesen;

using namespace std; //ω
hhcl::hhcl(const int argc, const char *const *const argv):dhcl(argc,argv,DPROG) //α
{
	// mitcron=0; //ω
} // hhcl::hhcl //α
// Hier neue Funktionen speichern: //ω

// wird aufgerufen in: virtpruefweiteres
void hhcl::prueflaboryeingel(DB *My, const string& tlaboryeingel, const int obverb, const int oblog, const uchar direkt/*=0*/)
{
	hLog(violetts+Tx[T_prueflaboryeingel]+schwarz);
	const size_t aktc=0;
	if (!direkt) {
		Feld felder[] = {
			Feld("DatID","int","10","",Tx[T_eindeutige_Identifikation],1,1,0,"",1),
			Feld("Pfad","varchar","1","",Tx[T_Pfadname],0,0,1),
			Feld("Name","varchar","1","",Tx[T_Name_der_eingelesenen_Labordatei_ohne_Endung],0,0,1),
			Feld("Zp","datetime","0","0",Tx[T_Einlesezeitpunkt],0,0,1),
			Feld("fertig","bit","1","",Tx[T_ob_Einlesen_fertig],0,0,1),
		};
		Feld ifelder0[] = {Feld("Name"),Feld("Pfad")};   Index i0("NamePfad",ifelder0,sizeof ifelder0/sizeof* ifelder0);
		Index indices[]={i0};
		// auf jeden Fall ginge "binary" statt "utf8" und "" statt "utf8_general_ci"
		Tabelle taba(My,tlaboryeingel,felder,sizeof felder/sizeof* felder,indices,sizeof indices/sizeof *indices,0,0,Tx[T_LaborEinlesungen]/*//,"InnoDB","utf8","utf8_general_ci","DYNAMIC"*/);
		if (taba.prueftab(aktc,obverb)) {
			fLog(rots+Tx[T_Fehler_beim_Pruefen_von]+schwarz+tlaboryeingel,1,1);
			exit(11);
		}
	} // if (!direkt)
} // int pruefouttab(DB *My, string touta, int obverb, int oblog, uchar direkt=0)

// wird aufgerufen in: virtpruefweiteres
void hhcl::prueflaboryleist(DB *My, const string& tlaboryleist, const int obverb, const int oblog, const uchar direkt/*=0*/)
{
	hLog(violetts+Tx[T_prueflaboryleist]+schwarz);
	const size_t aktc=0;
	if (!direkt) {
		Feld felder[] = {
			Feld("ID","int","10","",Tx[T_eindeutige_Identifikation],1,1,0,"",1),
			Feld("RefNr","int","10","",Tx[T_Bezug_auf_LaborUS],/*obind*/1,/*obauto*/0,0,"",/*unsigned*/1),
			Feld("Abkü","varchar","1","",Tx[T_8410_Test_Ident_Turbomed],0,0,1),
			Feld("Verf","varchar","1","",Tx[T_8434],0,0,1),
			Feld("EBM","varchar","1","",Tx[T_5001_GNR_Turbomed],0,0,1),
			Feld("goä","varchar","1","",Tx[T_8406],0,0,1),
			Feld("Anzahl","varchar","1","",Tx[T_5005],0,0,1),
			Feld("abrd","varchar","1","",Tx[T_8614_Abrechnung_durch_1_Labor_2_Einweiser],0,0,1),
		};
////		Feld ifelder0[] = {Feld("RefNr")};   Index i0("RefNr",ifelder0,sizeof ifelder0/sizeof* ifelder0);
////		Index indices[]={i0};
////		Feld ifelder0[] = {};
////		Index indices[]={};
		  Feld ifd0[]{Feld("RefNr")};
			Constraint c0("LaborXUSLaborXLeist",ifd0,1,"laboryus",ifd0,1,cascade,cascade);
			Constraint csts[]{c0};
		// auf jeden Fall ginge "binary" statt "utf8" und "" statt "utf8_general_ci"
		Tabelle taba(My,tlaboryleist,felder,sizeof felder/sizeof* felder,0,0,csts,sizeof csts/sizeof *csts, Tx[T_LaborLeistungen]/*//,"InnoDB","utf8","utf8_general_ci","DYNAMIC"*/);
		if (taba.prueftab(aktc,obverb)) {
			fLog(rots+Tx[T_Fehler_beim_Pruefen_von]+schwarz+tlaboryleist,1,1);
			exit(11);
		}
	} // if (!direkt)
} // int pruefouttab(DB *My, string touta, int obverb, int oblog, uchar direkt=0)

// wird aufgerufen in: virtpruefweiteres
void hhcl::prueflaborypgl(DB *My, const string& tlaborypgl, const int obverb, const int oblog, const uchar direkt/*=0*/)
{
	hLog(violetts+Tx[T_prueflaborypgl]+schwarz);
	const size_t aktc=0;
	if (!direkt) {
		Feld felder[] = {
			Feld("ID","int","10","",Tx[T_eindeutige_Identifikation],1,1,0,"",1),
			Feld("idxpneu","int","10","",Tx[T_laborxpneu],1,0,1,"",1),
			Feld("idpara","int","10","",Tx[T_laborparameter],1,0,1,"",1),
			Feld("idxpbez","int","10","",Tx[T_ist_identisch_mit_laborxpneu],1,0,1,"",1),
			Feld("ergänzt","datetime","0","0",Tx[T_Zeitpunkt_der_Ergaenzung],0,0,1),
		};
		  Feld ifd0[]{Feld("idxpneu")};
		  Feld ifd0a[]{Feld("id")};
		  Feld ifd1[]{Feld("idpara")};
		  Feld ifd1a[]{Feld("id")};
		  Feld ifd2[]{Feld("idxpbez")};
		  Feld ifd2a[]{Feld("id")};
			Constraint c0("laborxpgl_1",ifd0,1,"laborypneu",ifd0a,1);
			Constraint c1("laborxpgl_2",ifd1,1,"laborparameter",ifd1a,1);
			Constraint c2("laborxpgl_3",ifd2,1,"laborypneu",ifd2a,1,cascade,cascade);
			Constraint csts[]{c0,c1,c2};
		// auf jeden Fall ginge "binary" statt "utf8" und "" statt "utf8_general_ci"
		Tabelle taba(My,tlaborypgl,felder,sizeof felder/sizeof* felder,0,0,csts,sizeof csts/sizeof *csts, Tx[T_Laborpgl]/*//,"InnoDB","utf8","utf8_general_ci","DYNAMIC"*/);
		if (taba.prueftab(aktc,obverb)) {
			fLog(rots+Tx[T_Fehler_beim_Pruefen_von]+schwarz+tlaborypgl,1,1);
			exit(11);
		}
	} // if (!direkt)
} // int pruefouttab(DB *My, string touta, int obverb, int oblog, uchar direkt=0)

// wird aufgerufen in: virtpruefweiteres
void hhcl::prueflaboryplab(DB *My, const string& tlaboryplab, const int obverb, const int oblog, const uchar direkt/*=0*/)
{
	hLog(violetts+Tx[T_prueflaboryplab]+schwarz);
	const size_t aktc=0;
	if (!direkt) {
		Feld felder[] = {
			Feld("ID","int","10","",Tx[T_eindeutige_Identifikation],1,1,0,"",1),
			Feld("Labor","varchar","1","",Tx[T_8300_maximale_Laenge_36],0,0,1),
		};
		Feld ifelder0[] = {Feld("Labor")};   Index i0("Labor",ifelder0,sizeof ifelder0/sizeof* ifelder0,/*unique*/1);
		Index indices[]={i0};
		// auf jeden Fall ginge "binary" statt "utf8" und "" statt "utf8_general_ci"
		Tabelle taba(My,tlaboryplab,felder,sizeof felder/sizeof* felder,indices,sizeof indices/sizeof *indices,0,0, Tx[T_Laborplab]/*//,"InnoDB","utf8","utf8_general_ci","DYNAMIC"*/);
		if (taba.prueftab(aktc,obverb)) {
			fLog(rots+Tx[T_Fehler_beim_Pruefen_von]+schwarz+tlaboryplab,1,1);
			exit(11);
		}
	} // if (!direkt)
} // int pruefouttab(DB *My, string touta, int obverb, int oblog, uchar direkt=0)

// wird aufgerufen in: virtpruefweiteres
void hhcl::prueflaborypnb(DB *My, const string& tlaborypnb, const int obverb, const int oblog, const uchar direkt/*=0*/)
{
	hLog(violetts+Tx[T_prueflaborypnb]+schwarz);
	const size_t aktc=0;
	if (!direkt) {
		Feld felder[] = {
			Feld("ID","int","10","",Tx[T_eindeutige_Identifikation],1,1,0,"",1),
			Feld("pid","int","10","",Tx[T_Bezug_auf_laborxpneu],/*obind*/0,/*obauto*/0,/*nnull*/1,/*vdefa*/"",/*unsig*/1),
			Feld("Geschlecht","int","10","",Tx[T_1_Mann_2_Frau_3_unbek_4_Knabe_5_Maedchen_0_Name_fehlt_9_beide],/*obind*/0,/*obauto*/0,/*nnull*/1,/*vdefa*/"",/*unsig*/1),
			Feld("Eingang","datetime","0","0",Tx[T_Eingangsdatum_im_Labor],0,0,1),
			Feld("uNg","varchar","1","",Tx[T_untere_Normgrenze],0,0,1),
			Feld("oNg","varchar","1","",Tx[T_obere_Normgrenze],0,0,1),
			Feld("NB","varchar","1","",Tx[T_Normbereich],0,0,1),
			Feld("zahl","int","10","",Tx[T_Haeufigkeit_eines_Laborparameters],/*obind*/0,/*obauto*/0,/*nnull*/1,/*vdefa*/"",/*unsig*/1),
			Feld("uid","int","10","",Tx[T_laborxus_id_des_ersten_Eintrags],/*obind*/0,/*obauto*/0,/*nnull*/1,/*vdefa*/"",/*unsig*/1),
		};
		Feld ifd0[]{Feld("pid")};
		Feld ifd0a[]{Feld("id")};
		Constraint c0("laborxpneu_xpnb",ifd0,1,"laborypneu",ifd0a,1,cascade,cascade);
		Constraint csts[]{c0};
		// auf jeden Fall ginge "binary" statt "utf8" und "" statt "utf8_general_ci"
		Tabelle taba(My,tlaborypnb,felder,sizeof felder/sizeof* felder,0,0,csts,sizeof csts/sizeof *csts, Tx[T_Labornb]/*//,"InnoDB","utf8","utf8_general_ci","DYNAMIC"*/);
		if (taba.prueftab(aktc,obverb)) {
			fLog(rots+Tx[T_Fehler_beim_Pruefen_von]+schwarz+tlaborypnb,1,1);
			exit(11);
		}
	} // if (!direkt)
} // int pruefouttab(DB *My, string touta, int obverb, int oblog, uchar direkt=0)

// wird aufgerufen in: virtpruefweiteres
void hhcl::prueflaborypneu(DB *My, const string& tlaborypnb, const int obverb, const int oblog, const uchar direkt/*=0*/)
{
	hLog(violetts+Tx[T_prueflaborypneu]+schwarz);
	const size_t aktc=0;
	if (!direkt) {
		Feld felder[] = {
			Feld("ID","int","10","",Tx[T_eindeutige_Identifikation],1,1,0,"",1),
			Feld("Abkü","varchar","1","",Tx[T_8410_maximale_Laenge_8],1,0,1),
			Feld("Langtext","varchar","1","",Tx[T_8411_maximale_Laenge_40],0,0,1),
			Feld("Einheit","varchar","1","",Tx[T_8421_maximale_Laenge_12],0,0,1),
			Feld("lid","int","10","",Tx[T_Bezug_auf_laborxplab_id],/*obind*/1,/*obauto*/0,/*nnull*/1,/*vdefa*/"",/*unsig*/1),
			Feld("Gruppe","int","10","",Tx[T_Bezug_auf_laborgruppen_laborgruppe],/*obind*/1,/*obauto*/0,/*nnull*/1,/*vdefa*/"",/*unsig*/1),
		};
		Feld ifelder0[] = {Feld("Abkü"),Feld("Einheit"),Feld("lid")};   Index i0("Abkü",ifelder0,sizeof ifelder0/sizeof* ifelder0);
		Index indices[]={i0};
		  Feld ifd0[]{Feld("Gruppe")};
		  Feld ifd0a[]{Feld("Laborgruppe")};
		  Feld ifd1[]{Feld("lid")};
		  Feld ifd1a[]{Feld("id")};
			Constraint csts[]{Constraint("Gruppe",new Feld{Feld("Gruppe")},1,"laborgruppen",new Feld{Feld("Laborgruppe")},1),
				// geht beides!:
//			  								Constraint("Labore",new Feld[1]{Feld("lid")},1,"laboryplab",new Feld[1]{Feld("id")},1)};
			  								Constraint("Labore",new Feld{Feld("lid")},1,"laboryplab",new Feld{Feld("id")},1)};
		// auf jeden Fall ginge "binary" statt "utf8" und "" statt "utf8_general_ci"
		Tabelle taba(My,tlaborypneu,felder,sizeof felder/sizeof* felder,indices,sizeof indices/sizeof *indices,csts,sizeof csts/sizeof *csts, Tx[T_Laborneu]/*//,"InnoDB","utf8","utf8_general_ci","DYNAMIC"*/);
		if (taba.prueftab(aktc,obverb)) {
			fLog(rots+Tx[T_Fehler_beim_Pruefen_von]+schwarz+tlaborypneu,1,1);
			exit(11);
		}
	} // if (!direkt)
} // int pruefouttab(DB *My, string touta, int obverb, int oblog, uchar direkt=0)


// wird aufgerufen in: virtpruefweiteres
void hhcl::prueflaborysaetze(DB *My, const string& tlaborypnb, const int obverb, const int oblog, const uchar direkt/*=0*/)
{
	hLog(violetts+Tx[T_prueflaborysaetze]+schwarz);
	const size_t aktc=0;
	if (!direkt) {
		Feld felder[] = {
			Feld("SatzID","int","10","",Tx[T_zum_Bezug_fuer_LaborUS],1,1,0,"",1),
			Feld("DatID","int","10","",Tx[T_Bezug_zu_LaborEingelesen],1,0,0,"",1),
			Feld("Satzart","varchar","1","",Tx[T_8000_Satzart_Turbomed],0,0,1),
			Feld("Satzlänge","varchar","1","",Tx[T_8100_Satzlaenge_Turbomed],0,0,1),
			Feld("SatzlängeSchluss","varchar","1","",Tx[T_8100_Satzlaenge_Turbomed_nach_8221_in_Feld_8000],0,0,1),
			Feld("VersionSatzb","varchar","1","",Tx[T_9212_Version_der_Satzbeschreibung_Turbomed],0,0,1),
			Feld("Arztnr","varchar","1","",Tx[T_201_Arztnummer_Turbomed],0,0,1),
			Feld("Arztname","varchar","1","",Tx[T_203_Arztname_Turbomed],0,0,1),
			Feld("StraßePraxis","varchar","1","",Tx[T_205_Strasse_der_Praxis_Turbomed],0,0,1),
			Feld("Arzt","varchar","1","",Tx[T_211_Ausfuehrender_Arzt],0,0,1),
			Feld("LANR","varchar","1","",Tx[T_212_LANR],0,0,1),
			Feld("PLZPraxis","varchar","1","",Tx[T_215_PLZ_der_Praxis_Turbomed],0,0,1),
			Feld("OrtPraxis","varchar","1","",Tx[T_216_Ort_der_Praxis_Turbomed],0,0,1),
			Feld("Labor","varchar","1","",Tx[T_8320_Labor],0,0,1),
			Feld("StraßeLabor","varchar","1","",Tx[T_8321_Strasse_der_Laboradresse_Turbomed],0,0,1),
			Feld("PLZLabor","varchar","1","",Tx[T_8322_PLZ_der_Laboradresse_Turbomed],0,0,1),
			Feld("OrtLabor","varchar","1","",Tx[T_8323_Ort_der_Laboradresse_Turbomed],0,0,1),
			Feld("KBVPrüfnr","varchar","1","",Tx[T_101_KBV_Pruefnummer_Turbomed],0,0,1),
			Feld("Zeichensatz","varchar","1","",Tx[T_9106_verwendeter_Zeichensatz_Turbomed],0,0,1),
			Feld("Kundenarztnr","varchar","1","",Tx[T_8312_Kundenarztnummer_Turbomed],0,0,1),
			Feld("Erstellungsdatum","varchar","1","",Tx[T_9103_Erstellungsdatum_Turbomed],0,0,1),
			Feld("Gesamtlänge","varchar","1","",Tx[T_9202_Gesamtlaenge_des_Datenpaketes_Turbomed],0,0,1),
		};
		Feld ifelder0[] = {Feld("PLZLabor"),Feld("OrtLabor")};   Index i0("Name",ifelder0,sizeof ifelder0/sizeof* ifelder0);
		Index indices[]={i0};
		// auf jeden Fall ginge "binary" statt "utf8" und "" statt "utf8_general_ci"
		Tabelle taba(My,tlaborysaetze,felder,sizeof felder/sizeof* felder,indices,sizeof indices/sizeof *indices, 0,0,Tx[T_Laborsaetze]/*//,"InnoDB","utf8","utf8_general_ci","DYNAMIC"*/);
		if (taba.prueftab(aktc,obverb)) {
			fLog(rots+Tx[T_Fehler_beim_Pruefen_von]+schwarz+tlaborysaetze,1,1);
			exit(11);
		}
	} // if (!direkt)
} // int pruefouttab(DB *My, string touta, int obverb, int oblog, uchar direkt=0)


// wird aufgerufen in: virtpruefweiteres
void hhcl::prueflaboryus(DB *My, const string& tlaborypnb, const int obverb, const int oblog, const uchar direkt/*=0*/)
{
	hLog(violetts+Tx[T_prueflaboryus]+schwarz);
	const size_t aktc=0;
	if (!direkt) {
		Feld felder[] = {
			Feld("ID","int","10","",Tx[T_eindeutige_Identifikation],1,1,0,"",1),
			Feld("RefNr","int","10","",Tx[T_Bezug_auf_LaborWert],1,0,0,"",1),
			Feld("DatID","int","10","",Tx[T_Bezug_zu_LaborEingelesen],1,0,1,"",1),
			Feld("SatzID","int","10","",Tx[T_Bezug_auf_LaborXSaetze],1,0,1,"",1),
			Feld("Satzart","varchar","1","",Tx[T_8000_Satzart_Turbomed],0,0,0),
			Feld("Satzlänge","varchar","1","",Tx[T_8100_Satzlaenge_Turbomed],0,0,0),
			Feld("Auftragsnummer","varchar","1","",Tx[T_8310_Anforderungsident_Turbomed],0,0,0),
			Feld("Auftragsschlüssel","varchar","1","",Tx[T_8311_Anforderungsnr_d_Labors_Turbomed],0,0,0),
			Feld("Eingang","datetime","0","0",Tx[T_Eingangsdatum_im_Labor],0,0,0),
			Feld("Berichtsdatum","varchar","1","",Tx[T_8302_Berichtsdatum],0,0,0),
			Feld("Pat_id","int","10","","",1,0,1,"",1),
			Feld("Nachname","varchar","1","","3101",0,0,0),
			Feld("Vorname","varchar","1","","3102",0,0,0),
			Feld("GebDat","varchar","1","","3103",0,0,0),
			Feld("Titel","varchar","1","","3104",0,0,0),
			Feld("NVorsatz","varchar","1","","3105",0,0,0),
			Feld("BefArt","varchar","1","",Tx[T_8401_Befundart_Turbomed__Fertigstellungsgrad_EEndbefund_T__Teilbefund],0,0,0),
			Feld("Abrechnungstyp","varchar","1","",Tx[T_8609_Abrechnungstyp_Kasse_Privat_X_anderer_RE_Einsender_Turbomed],0,0,0),
			Feld("GebüOrd","varchar","1","",Tx[T_8403_Gebuehrenordnung_Turbomed],0,0,0),
			Feld("Auftraggeber","varchar","1","",Tx[T_8615_Auftraggeber_LANR],0,0,0),
			Feld("Patienteninformation","varchar","1","",Tx[T_8405_Patienteninformation_Turbomed],0,0,0),
			Feld("Geschlecht","varchar","1","",Tx[T_8407_Geschlecht_Turbomed],/*obind*/0,/*obauto*/0,/*nnull*/0),
			Feld("AuftrHinw","varchar","1","",Tx[T_8490_Auftragsbezogene_Hinweise_Turbomed],/*obind*/0,/*obauto*/0,/*nnull*/0),
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
		// auf jeden Fall ginge "binary" statt "utf8" und "" statt "utf8_general_ci"
		Tabelle taba(My,tlaboryus,felder,sizeof felder/sizeof* felder,indices,sizeof indices/sizeof *indices,0,0, Tx[T_Laborus]/*//,"InnoDB","utf8","utf8_general_ci","DYNAMIC"*/);
		if (taba.prueftab(aktc,obverb)) {
			fLog(rots+Tx[T_Fehler_beim_Pruefen_von]+schwarz+tlaboryus,1,1);
			exit(11);
		}
	} // if (!direkt)
} // int pruefouttab(DB *My, string touta, int obverb, int oblog, uchar direkt=0)


// wird aufgerufen in: virtpruefweiteres
void hhcl::prueflaborywert(DB *My, const string& tlaborywert, const int obverb, const int oblog, const uchar direkt/*=0*/)
{
	hLog(violetts+Tx[T_prueflaborywert]+schwarz);
	const size_t aktc=0;
	if (!direkt) {
		Feld felder[] = {
			Feld("ID","int","10","",Tx[T_eindeutige_Identifikation],1,1,0,"",1),
			Feld("RefNr","int","10","",Tx[T_Bezug_auf_LaborUS],1,0,0,"",1),
			Feld("Abkü","varchar","1","",Tx[T_8410_maximale_Laenge_8],0,0,1),
			Feld("Langname","varchar","1","",Tx[T_8411_Testbezeichnung_Turbomed],0,0,1),
			Feld("Quelle","varchar","1","",Tx[T_8430_Probenmaterial_Bezeichnung_Turbomed],0,0,1),
			Feld("QSpez","varchar","1","",Tx[T_8431_Probenmaterial_Spezifikation_Turbomed],0,0,1),
			Feld("AbnDat","datetime","0","0",Tx[T_8432_Abnahmedatum_Turbomed],0,0,1),
			Feld("Wert","varchar","1","0",Tx[T_8420_Ergebniswert_Turbomed],0,0,1),
			Feld("Einheit","varchar","1","",Tx[T_8421_maximale_Laenge_12],0,0,1),
			Feld("Grenzwerti","varchar","1","",Tx[T_8422_Grenzwertindikator_Turbomed],0,0,1),
			Feld("Kommentar","varchar","1","",Tx[T_8480_Ergebnistest_Turbomed],0,0,1),
			Feld("Teststatus","varchar","1","",Tx[T_8418_Teststatus_Turbomed],0,0,1),
			Feld("Erklärung","varchar","1","","",0,0,1),
			Feld("AuftrHinw","varchar","1","",Tx[T_8490_Auftragsbezogene_Hinweise_Turbomed],/*obind*/0,/*obauto*/0,/*nnull*/0),
			Feld("nbid","int","10","",Tx[T_Bezug_zu_laborxplab_id],/*obind*/1,/*obauto*/0,/*nnull*/0),
		};
		Feld ifelder0[] = {Feld("Abkü"),Feld("Einheit")};   Index i0("LaborXWertAbkü",ifelder0,sizeof ifelder0/sizeof* ifelder0);
		Feld ifelder1[] = {Feld("RefNr"),Feld("Abkü"),Feld("Langname"),Feld("Quelle"),Feld("QSpez"),Feld("AbnDat"),Feld("Wert"),Feld("Einheit"),Feld("Grenzwerti"),Feld("Teststatus"),Feld("nbid")};   
				Index i1("doppelte",ifelder1,sizeof ifelder1/sizeof* ifelder1,/*unique*/1);
		Index indices[]={i0,i1};
		// auf jeden Fall ginge "binary" statt "utf8" und "" statt "utf8_general_ci"
		Tabelle taba(My,tlaborywert,felder,sizeof felder/sizeof* felder,indices,sizeof indices/sizeof *indices,0,0, Tx[T_Laborwert]/*//,"InnoDB","utf8","utf8_general_ci","DYNAMIC"*/);
		if (taba.prueftab(aktc,obverb)) {
			fLog(rots+Tx[T_Fehler_beim_Pruefen_von]+schwarz+tlaborywert,1,1);
			exit(11);
		}
	} // if (!direkt)
} // int pruefouttab(DB *My, string touta, int obverb, int oblog, uchar direkt=0)



// wird aufgerufen in: virtpruefweiteres
void hhcl::prueflaborybakt(DB *My, const string& tlaborybakt, const int obverb, const int oblog, const uchar direkt/*=0*/)
{
	hLog(violetts+Tx[T_prueflaborybakt]+schwarz);
	const size_t aktc=0;
	if (!direkt) {
		Feld felder[] = {
			Feld("ID","int","10","",Tx[T_eindeutige_Identifikation],1,1,0,"",1),
			Feld("RefNr","int","10","",Tx[T_Bezug_auf_LaborUS],/*obind*/1,/*obauto*/0,0,"",1),
			Feld("Verf","varchar","1","",Tx[T_8410_Test_Ident_Turbomed],0,0,1),
			Feld("KuQu","varchar","1","",Tx[T_8428_Probenmaterial_Ident_Turbomed],0,0,1),
			Feld("Quelle","varchar","1","",Tx[T_8430_Probenmaterial_Bezeichnung_Turbomed],0,0,1),
			Feld("QSpez","varchar","1","",Tx[T_8431_Probenmaterial_Spezifikation_Turbomed],0,0,1),
			Feld("AbnDat","datetime","0","0",Tx[T_8432_Abnahmedatum_Turbomed],0,0,1),
			Feld("Kommentar","LONGTEXT","","",Tx[T_8480_Ergebnistest_Turbomed],0,0),
			Feld("Erklärung","LONGTEXT","","","",0,0,1),
			Feld("Keimzahl","varchar","1","","",0,0,1),
		};
		// auf jeden Fall ginge "binary" statt "utf8" und "" statt "utf8_general_ci"
		Tabelle taba(My,tlaborybakt,felder,sizeof felder/sizeof* felder,0,0,0,0,Tx[T_Laborbakt]/*//,"InnoDB","utf8","utf8_general_ci","DYNAMIC"*/);
		if (taba.prueftab(aktc,obverb)) {
			fLog(rots+Tx[T_Fehler_beim_Pruefen_von]+schwarz+tlaborybakt,1,1);
			exit(11);
		}
	} // if (!direkt)
} // int pruefouttab(DB *My, string touta, int obverb, int oblog, uchar direkt=0)


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
	} //α
	dhcl::virtrueckfragen();
} // void hhcl::virtrueckfragen()

// wird aufgerufen in lauf
void hhcl::virtpruefweiteres()
{ //ω
	initDB();
	prueflaboryeingel(My, tlaboryeingel, obverb, oblog, /*direkt*/0);
	prueflaboryleist(My, tlaboryleist, obverb, oblog, /*direkt*/0);
	prueflaborypgl(My, tlaborypgl, obverb, oblog, /*direkt*/0);
	prueflaboryplab(My, tlaboryplab, obverb, oblog, /*direkt*/0);
	prueflaborypnb(My, tlaborypnb, obverb, oblog, /*direkt*/0);
	prueflaborypneu(My, tlaborypnb, obverb, oblog, /*direkt*/0);
	prueflaborybakt(My, tlaborybakt, obverb, oblog, /*direkt*/0);
	prueflaborysaetze(My, tlaborysaetze, obverb, oblog, /*direkt*/0);
	prueflaboryus(My, tlaboryus, obverb, oblog, /*direkt*/0);
	prueflaborywert(My, tlaborywert, obverb, oblog, /*direkt*/0);
	hcl::virtpruefweiteres(); // z.Zt. leer //α
} // void hhcl::virtpruefweiteres

// wird aufgerufen in lauf
void hhcl::virtzeigueberschrift()
{ //ω
  // hier ggf. noch etwas an 'uebers' anhaengen //α
	hcl::virtzeigueberschrift();
} // void hhcl::virtzeigueberschrift

// wird aufgerufen in lauf
void hhcl::pvirtfuehraus()
{ //ω
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
