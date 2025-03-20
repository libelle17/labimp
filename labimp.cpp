// '//α' oder '//ω' als Kommentar sind nur fuer die Verwendung dieses Programms als Programmvorlage wichtig
// sed -n '/\/\/α/,/\/\/ω/p;/\/\/ω/a\\' test
// sed -n '/\/\/α/,/\/\/ω/p' test
const double& versnr= //α
#include "versdt"
;
#include "kons.h" //α
#include "DB.h" 
#include <tiffio.h>
#define VOMHAUPTCODE // um Funktionsdefinition manchmal mit "__attribute__((weak)) " versehen zu können //ω
#include "labimp.h"
// fuer verschiedene Sprachen //α
#define vorsilbe "labory"
const tm hhcl::tmnull{0};
const tm hhcl::tmmax{0,0,0,1,0,200,0,0,0};
char const *DPROG_T[T_MAX+1][SprachZahl]=
{
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
	{"Eingangsdatum im Labor (Feld 8301)","entry date in the laboratory (field 8301)"},
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
#ifdef altfelder
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
#endif
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
	// T_vors_k
	{"vors","pref"},
	// T_vors_l
	{"vorsilbe","prefix"},
	// T_fgvz_k
	{"fgvz","fddir"},
	// T_fgvz_l
	{"fertigvz","processeddir"},
	// T_Verzeichnis_der_Labordateien
	{"Verzeichnis der Labordateien","directory of the laboratory files"},
	// T_Verzeichnis_der_Fertigen
	{"Verzeichnis der Fertigen","directory of the finished"},
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
	// T_Bezug_auf_
	{"Bezug auf ","reference to "},
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
	// T_Normbereich_aus_
	{"Normbereich aus ","normal range from "},
	// T_Aktualisierungszeitpunt
	{"Aktualisierungszeitpunkt","actualization time"},
	// T_Ordnungsnummer_der_Dateiuebertragung
	{"Ordnungsnummer der Dateiuebertragung","ordinal number of the file import"},
	// T_fehlend
	{"fehlend","missing"},
	// T_Bezug_auf_LaborBakt
	{"Bezug auf lybakt","reference to lybact"},
	// T_pruefPatID_Standardfunktion
	// {"pruefPatID() (Standardfunktion)","checkPatID() (standard function)"},
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
	// T_auswertpql
//	{"auswertpql()","evaluatepql()"},
	// T_PatID_aus_Laborneu
	{"Pat_ID aus Laborneu","Pat_id from laborneu"},
	// T_nachbearbeit_leere_Funktion
	{"nachbearbeit() (leere Funktion)","afterwork() (empty function)"},
	// T_vordverarb_leere_Funktion
	{"vordverarb() (leere Funktion)","beforefilework() (empty function)"},
	// T_loescht_Datensaetze_aus_unvollstaendig_eingelesenen_Dateien
	{"loescht Datensaetze aus unvollstaendig eingelesenen Dateien","deletes entries from incompletely read files"},
	// T_lu_k
	{"loeunv","delincomp"},
	// T_la_l
	{"loeschunvollstaendige","deleteincomplete"},
	// T_Pat_id_fuer
	{"Pat_id fuer ","Pat_id for"},
	// T_Zahl
	{"Zahl: ","no: "},
	// T_nurnachb_k
	{"nurnachb","onlyafterw"},
	// T_nurnachb_l
	{"nurnachbearbeitung","onlyafterwork"},
	// T_nachbneu_k
	{"nachbneu","afterwnew"},
	// T_nachbneu_l
	{"nachbearbeitungneu","afterworknew"},
	// T_nurusmod_k
	{"nurusmod","onlyusmod"},
	// T_nurnachb_l
	{"nurusmod","onlyusmod"},
	// T_pruefauft_k,
	{"pruefauft","checkord"},
	// T_pruefauft_l,
	{"pruefauftraege","checkorders"},
	// T_pruefe_alle_Auftraege,
	{"pruefe alle Auftraege","check all orders"},
	// T_nur_Nachbearbeitung
	{"nur Nachbearbeitung","only afterwork"},
	// T_nur_usmod
	{"nur usmod","only usmod"},
	// T_fertig
	{"fertig!","finished!"},
	// T_Dateien_gefunden
	{"Dateien gefunden: ","Files found: "},
	// 	T_lab_k,
	{"loeab","delfrom"},
	//	T_lab_l,
	{"loescheab","deletefrom"},
	// T_loescht_alle_Datensaetze_ab
	{"loescht alle Datensaetze ab DatID: ","deletes all data sets beginning at dat ID: "},
	// T_Loescheab
	{"Loesche ab DatID: ","Deleting from dat ID: "},
	// T_pidnachw_k,
	{"pidnw","pidpf"},
	// T_pidnachw_l,
	{"pidnachweis","pidproof"},
	// T_listet_Eintraege_zu_pid,
	{"listet Eintraege zu pid","lists entries to pid"},
	// T_lid_k,
	{"loeid","delid"},
	// T_lid_l,
	{"loeschid","deleteid"},
	// T_loescht_Datensatz_id,
	{"loescht Datensatz mit DATID ","deletes data set with DATID "},
	// T_Loescheid,
	{"Loesche DatID: ","Deleting datID: "},
	// T_Datensaetze_geloescht
	{"Datensaetze geloescht","entries deleted"},
	// T_fertig_mit_datid
	{"fertig mit datid","finished with datid"},
	// T_Fehler_bei_sql
	{"Fehler bei sql: ","Error at sql: "},
	// T_labor
	{"labor","laboratory"},
	// T_fertige
	{"fertige","processed"},
	// T_Verzeichnis_der_fertig_Verarbeiteten
	{"Verzeichnis der fertig Verarbeiteten","directory of the processed files"},
	// T_Fehler_beim_Verschieben_von
	{"Fehler beim Verschieben von: ","Error moving: "},
	// T_nach_
	{" nach: "," to: "},
	// T_listdat_k
	{"listdat","listfil"},
	// T_listdat_l
	{"listdateien","listfiles"},
	// T_pruefdb_k,
	{"pruefdb","checkdb"},
	// T_pruefdb_l,
	{"pruefdb","checkdb"},
	// T_umben_k,
	{"umben","ren"},
	// T_umben_l,
	{"umbenenn","rename"},
	// T_listet_alle_eingelesenen_Dateien_auf,
	{"listet alle eingelesenen Dateien auf","lists all processed files"},
	// T_Pfad_
	{"Pfad","Path"},
	// T_Eingang
	{"Eingang","Entry"},
	// T_eingelesen
	{"eingelesen","processed"},
	// T_Zeichensatz
	{"Zeichensatz","code page"},
	// T_fertig_
	{"fertig","finished"},
	// T_n_k
	{"n","n"},
	// T_dszahl_l
	{"dszahl","reccount"},
	// T_Zahl_der_aufzulistenden_Datensaetze_ist_zahl_statt
	{"Zahl der aufzulistenden Datensaetze = <zahl> statt","No. of listed entries = <no> instead of"},
	// T_Normbereich_ohne_bis
	{"Normbereich ohne '-': ","normal range without '-': "},
	//T_Soll_ich_wirklich_alle_Tabellen_mit
	{"Soll ich wirklich alle Tabellen mit ","Shall I in fact delete all tables with "},
	//T_Soll_ich_wirklich_alle_Tabellen_mit_
	{"Soll ich wirklich alle Tabellen mit ","Shall I in fact truncate all tables with "},
	//T_Soll_ich_wirklich_alle_Tabellen_mit__
	{"Soll ich wirklich alle Tabellen mit ","Shall I in fact delete in all tables with "},
	// T_Soll_ich_wirklich_alle_Tabellen_mit___
	{"Soll ich wirklich alle Tabellen mit ","Shall I in fact rename in all tables with "},
	// T_loeschen_und_von_vorne_anfangen
	{" loeschen und von vorne anfangen?"," and start from scratch?"},
	// T_Aktion_abgebrochen
	{"Aktion abgebrochen","action stopped"},
	// T_loeschen
	{" loeschen?","?"},
	// T_ab_DATID
	{" ab DATID "," from DATID "},
	// T_mit_DATID
	{" mit DATID "," with DATID "},
	// T_entleeren_und_von_vorne_anfangen
	{" entleeren und von vorne anfangen? "," and start from scratch?"},
	// T_um_Datensaetze_aus_nicht_fertig_eingelesenen_Dateien_bereinigt_werden
	{" um Datensaetze aus nicht fertig eingelesenen Dateien bereinigt werden?"," all data sets from incompletely read files?"},
	// T_Nachbearbeitung_von_vorne
	{"Nachbearbeitung von vorne","afterwork new"},
	// T_Soll_ich_wirklich_alle_Nachbearbeitungen_von_vorne_angefangen_werden
	{"Sollen wirklich alle Nachbearbeitungen von vorne angefangen werden?","Shall all after work really be done from scratch?"},
	// T_Eintraege_aus
	{" Eintraege aus "," entries from "},
	// T_saetze
	{"Saetze","Sets"},
	// T_unters
	{"unters","examin"},
	// T_werte
	{"werte","values"},
	// T_bakt
	{"bakt","bact"},
	// T_initialisiert_nur_die_Tabellen
	{"initialisiert nur die Tabellen","initializes only the tables"},
	// T_benennt_die_Tabellen_um
	{"benennt die Tabellen um","renames the tables"},
	// T_fuer_PatID_gewaehlte_SQL_Abfrage,
	{"für Pat_ID gewählte SQL-Abfrage","sql-query chosen for pat_id"},
	// T_russchreib_usid,
	{"russchreib(), usid: ","writerus(), usid: "},
	// 	T_SQL_Abfrage_zur_direkten_Pat_id_Ermittlung_aus_laborneu,
	{"SQL-Abfrage zur direkten Pat_id-Ermittlung aus laborneu","sql-query for directly questioning pat_id from laborneu"},
	// T_Zahl_der_Antworten_aus_laborneu,
	{"Zahl der Antworten aus laborneu","No of answers from laborneu"},
	// T_Vorsilbe_fuer_Datenbanktabellen,
	{"Vorsilbe für Datenbanktabellen","prefix for database tables"},
	// T_nach___
	{"' nach '","' to '"},
	// T_umbenennen
	{"' umbenennen?","'?"},
	// 	T_Namensanfang_aller_Einlesetabellen,
	{"Namensanfang aller Einlesetabellen: ","Beginning of the name of all storage tables: "},
	// T_Tabellenzahl_mit
	{"Tabellenzahl mit ","no.of tables with "},
	// T_Eingelesene_Labordateien
	{"Eingelesene Labordateien: ","Processed laboratory files: "},
	// T_war_schon_in
	{" war schon in `"," was already entered in `"},
	// T_eingetragen_
	{"` eingetragen! (","`! ("},
	// T_pvirtfueraus,
	{"pvirtfueraus()","pvirtexecute()"},
	{"",""} //α
}; // char const *DPROG_T[T_MAX+1][SprachZahl]=

class TxB Tx((const char* const* const* const*)DPROG_T);
const char *logdt="/var/log/" DPROG "vorgabe.log";//darauf wird in kons.h verwiesen;

using namespace std; //ω
hhcl::hhcl(const int argc, const char *const *const argv):dhcl(argc,argv,DPROG,/*mitcron*/1) //α
{
	//ω
	icp[0]=new ic_cl("UTF8","ISO-8859-15");
	icp[1]=new ic_cl("UTF8","CP850");
	icp[2]=new ic_cl("UTF8","ISO-8859-1");
} // hhcl::hhcl //α
// Hier neue Funktionen speichern: //ω

// schwache Funktion, kann ueberdeckt werden
// aufgerufen in fuellpql
void hhcl::ergpql()
{
	hLog(violetts+Tx[T_ergpql_leere_Funktion]+schwarz);
}

/*
// schwache Funktion, kann ueberdeckt werden, wird es aber nicht
// aufgerufen in pruefPatID
void hhcl::auswertpql(const size_t i,insv& rus)
{
	hLog(violetts+Tx[T_auswertpql]+schwarz);
}
*/

// aufgerufen in dverarbeit
void hhcl::vordverarb(const size_t aktc)
{
	hLog(violetts+Tx[T_vordverarb_leere_Funktion]+schwarz);
}
// schwache Funktion, kann ueberdeckt werden
// aufgerufen in pvirtfuehraus
void hhcl::nachbearbeit(const size_t aktc,const uchar obusmod/*=0*/)
{
	hLog(violetts+Tx[T_nachbearbeit_leere_Funktion]+schwarz);
}

// wird aufgerufen in: virtpruefweiteres
void hhcl::prueflyhinw(DB *My, const size_t aktc, const int obverb, const int oblog, const uchar direkt/*=0*/)
{
	hLog(violetts+Tx[T_prueflyhinw]+schwarz);
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
		if (taba.tbneu) {
			// "Labor 20051127 224528.dat": kein Labor angegeben
			svec eindfeld; eindfeld<<"ID";
			insv rhinw(My,/*itab*/tlyhinw,aktc,/*eindeutig*/1,eindfeld,/*asy*/0,/*csets*/0);
			rhinw.hz("Text",string());
			rhinw.schreib(/*sammeln*/0,/*obverb*/obverb,/*idp*/&hinwind);
		}
	} // if (!direkt)
} // int prueflyhinw

// wird aufgerufen in: virtpruefweiteres
void hhcl::prueflyparameter(DB *My, const size_t aktc, const int obverb, const int oblog, const uchar direkt/*=0*/)
{
	hLog(violetts+Tx[T_prueflyparameter]+schwarz);
	if (!direkt) {
		Feld felder[] = {
			Feld(/*name*/"Abkü",/*typ*/"varchar",/*lenge*/"42",/*prec*/"",/*comment*/Tx[T_8410_maximale_Laenge_8],/*obind*/0,/*obaut*/0,/*nnull*/1),
			Feld("AbküN","varchar","8","",Tx[T_Abkuerzung_mit_gleicher_Bedeutung_gleicher_Einheit_und_gleichem_Normbereich],0,0,1),
			Feld("LabID","int","10","",(Tx[T_Bezug_auf_]+tlyplab).c_str(),0,0,1,string(),1),
			Feld("Langtext","varchar","41","",Tx[T_8411_maximale_Laenge_40],0,0,1),
			Feld("Einheit","varchar","12","",Tx[T_8421],0,0,1,"kA"),
			Feld("Gruppe","int","10","",Tx[T_Bezug_auf_laborgruppen_laborgruppe],/*obind*/1,/*obauto*/0,/*nnull*/1,/*vdefa*/string(),/*unsig*/1),
			Feld("Reihe","int","10","",Tx[T_Reihenfolge_innerhalb_der_Gruppe],/*obind*/1,/*obauto*/0,/*nnull*/1,/*vdefa*/string(),/*unsig*/0),
			Feld("uNm","varchar","5","",Tx[T_unterer_Normwert_maennlich],0,0,1),
			Feld("oNm","varchar","6","",Tx[T_oberer_Normwert_maennlich],0,0,1),
			Feld("uNw","varchar","5","",Tx[T_unterer_Normwert_weiblich],0,0,1),
			Feld("oNw","varchar","6","",Tx[T_oberer_Normwert_weiblich],0,0,1),
			Feld("NB","varchar","1342","",Tx[T_Normbereich_aus_]+tlywert,0,0,1),
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
void hhcl::prueflydat(DB *My, const size_t aktc, const int obverb, const int oblog, const uchar direkt/*=0*/)
{
	hLog(violetts+Tx[T_prueflydat]+schwarz);
	if (!direkt) {
		Feld felder[] = {
			Feld("DatID","int","10","",Tx[T_eindeutige_Identifikation],1,1,0,string(),1),
			Feld("Pfad","varchar","78","",Tx[T_Pfadname],1,0,1),
			Feld("Name","varchar","51","",Tx[T_Name_der_eingelesenen_Labordatei_ohne_Endung],1,0,1),
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
void hhcl::prueflyplab(DB *My, const size_t aktc, const int obverb, const int oblog, const uchar direkt/*=0*/)
{
	hLog(violetts+Tx[T_prueflyplab]+schwarz);
	if (!direkt) {
		Feld felder[] = {
			Feld(/*name*/"ID",/*typ*/"int",/*lenge*/"10",/*prec*/string(),/*comment*/Tx[T_eindeutige_Identifikation],/*obind*/1,/*obaut*/1,/*nnull*/0,/*defa*/string(),/*unsig*/1),
			Feld("Labor","varchar","43","",Tx[T_8300_maximale_Laenge_36],0,0,1),
			Feld("StraßeLabor","varchar","22","",Tx[T_8321_Strasse_der_Laboradresse_Turbomed],0,0,1),
			Feld("PLZLabor","varchar","5","",Tx[T_8322_PLZ_der_Laboradresse_Turbomed],0,0,1),
			Feld("OrtLabor","varchar","16","",Tx[T_8323_Ort_der_Laboradresse_Turbomed],0,0,1),
		};
		Index indices[]{Index("Labor",new Feld[4]{Feld("Labor"),Feld("StraßeLabor"),Feld("PLZLabor"),Feld("OrtLabor")},4,/*unique*/1)};
		// auf jeden Fall ginge "binary" statt "utf8" und "" statt "utf8_general_ci"
		Tabelle taba(My,tlyplab,felder,sizeof felder/sizeof* felder,indices,sizeof indices/sizeof *indices,0,0, Tx[T_Laborplab]/*//,"InnoDB","utf8","utf8_general_ci","DYNAMIC"*/);
		if (taba.prueftab(aktc,obverb)) {
			fLog(rots+Tx[T_Fehler_beim_Pruefen_von]+schwarz+tlyplab,1,1);
			exit(11);
		}
		if (taba.tbneu) {
			// "Labor 20051127 224528.dat": kein Labor angegeben
			svec eindfeld; eindfeld<<"ID";
			insv rlab(My,/*itab*/tlyplab,aktc,/*eindeutig*/1,eindfeld,/*asy*/0,/*csets*/0);
			rlab.hz("Labor",Tx[T_fehlend]);
			rlab.schreib(/*sammeln*/0,/*obverb*/obverb,/*idp*/&labind);
		}
	} // if (!direkt)
} // int pruefouttab(DB *My, string touta, int obverb, int oblog, uchar direkt=0)

// wird aufgerufen in: virtpruefweiteres
void hhcl::prueflypneu(DB *My, const size_t aktc, const int obverb, const int oblog, const uchar direkt/*=0*/)
{
	hLog(violetts+Tx[T_prueflypneu]+schwarz);
	if (!direkt) {
		Feld felder[] = {
			Feld("ID","int","10","",Tx[T_eindeutige_Identifikation],1,1,0,string(),1),
			Feld("Abkü","varchar","42","",Tx[T_8410_maximale_Laenge_8],1,0,1),
			Feld("AbküN","varchar","8","",Tx[T_Abkuerzung_mit_gleicher_Bedeutung_gleicher_Einheit_und_gleichem_Normbereich],0,0,1),
			Feld("LabID","int","10","",Tx[T_Bezug_auf_],/*obind*/1,/*obauto*/0,/*nnull*/1,/*vdefa,NULL*/string(),/*unsig*/1),
			Feld("Langtext","varchar","41","",Tx[T_8411_maximale_Laenge_40],0,0,1),
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
void hhcl::prueflypnb(DB *My, const size_t aktc, const int obverb, const int oblog, const uchar direkt/*=0*/)
{
	hLog(violetts+Tx[T_prueflypnb]+schwarz);
	if (!direkt) {
		Feld felder[] = {
			Feld("ID","int","10","",Tx[T_eindeutige_Identifikation],1,1,0,string(),1),
			Feld("PNEUID","int","10","",Tx[T_Bezug_auf_laborxpneu],/*obind*/0,/*obauto*/0,/*nnull*/1,/*vdefa*/string(),/*unsig*/1),
//			Feld("Geschlecht","int","10","",Tx[T_1_Mann_2_Frau_3_unbek_4_Knabe_5_Maedchen_0_Name_fehlt_9_beide],/*obind*/0,/*obauto*/0,/*nnull*/1,/*vdefa*/string(),/*unsig*/1),
//			Feld("Eingang","datetime","0","0",Tx[T_Eingangsdatum_im_Labor],0,0,1),
			Feld("uNg","varchar","5","",Tx[T_untere_Normgrenze],0,0,1),
			Feld("oNg","varchar","6","",Tx[T_obere_Normgrenze],0,0,1),
			Feld("NB","varchar","1342","",Tx[T_Normbereich],0,0,1),
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
void hhcl::prueflyaerzte(DB *My, const size_t aktc, const int obverb, const int oblog, const uchar direkt/*=0*/)
{
	hLog(violetts+Tx[T_prueflyaerzte]+schwarz);
	if (!direkt) {
		Feld felder[] = {
			Feld("ID","int","10","",Tx[T_zum_Bezug_fuer_Laborsaetze],1,1,0,string(),1),
			Feld("Arztnr","varchar","9","",Tx[T_201_Arztnummer_Turbomed],1,0,1),
			Feld("Arztname","varchar","50","",Tx[T_203_Arztname_Turbomed],1,0,1),
			Feld("StraßePraxis","varchar","18","",Tx[T_205_Strasse_der_Praxis_Turbomed],0,0,1),
			Feld("Arzt","varchar","50","",Tx[T_211_Ausfuehrender_Arzt],1,0,1),
			Feld("LANR","varchar","9","",Tx[T_212_LANR],1,0,1),
			Feld("PLZPraxis","varchar","5","",Tx[T_215_PLZ_der_Praxis_Turbomed],0,0,1),
			Feld("OrtPraxis","varchar","8","",Tx[T_216_Ort_der_Praxis_Turbomed],0,0,1),
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
void hhcl::prueflysaetze(DB *My, const size_t aktc, const int obverb, const int oblog, const uchar direkt/*=0*/)
{
	hLog(violetts+Tx[T_prueflysaetze]+schwarz);
	if (!direkt) {
		Feld felder[] = {
			Feld("SatzID","int","10","",Tx[T_zum_Bezug_fuer_LaborUS],1,1,0,string(),1),
			Feld("DatID","int","10","",Tx[T_Bezug_zu_LaborDat],1,0,0,string(),1),
			Feld("Satzart","varchar","4","",Tx[T_8000_Satzart_Turbomed],0,0,1),
			Feld("Satzlänge","varchar","5","",Tx[T_8100_Satzlaenge_Turbomed],0,0,1),
			Feld("SatzlängeSchluss","varchar","5","",Tx[T_8100_Satzlaenge_Turbomed_nach_8221_in_Feld_8000],0,0,1),
			Feld("VersionSatzb","varchar","11","",Tx[T_9212_Version_der_Satzbeschreibung_Turbomed],0,0,1),
			Feld("ArztID","int","10","",Tx[T_Bezug_auf_lyaerzte],0,0,1,string(),1),
			Feld("LabID","int","10","",Tx[T_Bezug_auf_],0,0,1,string(),1),
			Feld("KBVPrüfnr","varchar","16","",Tx[T_101_KBV_Pruefnummer_Turbomed],0,0,1),
			Feld("Zeichensatz","varchar","1","",Tx[T_9106_verwendeter_Zeichensatz_Turbomed],0,0,1),
			Feld("Kundenarztnr","varchar","8","",Tx[T_8312_Kundenarztnummer_Turbomed],0,0,1),
			Feld("Erstellungsdatum","date","","",Tx[T_9103_Erstellungsdatum_Turbomed],0,0,1),
			Feld("Gesamtlänge","varchar","8","",Tx[T_9202_Gesamtlaenge_des_Datenpaketes_Turbomed],0,0,1),
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
void hhcl::prueflyus(DB *My, const size_t aktc, const int obverb, const int oblog, const uchar direkt/*=0*/)
{
	hLog(violetts+Tx[T_prueflyus]+schwarz);
	if (!direkt) {
		sfeld fdr;
		fdr<<new Feld("ID","int","10","",Tx[T_eindeutige_Identifikation],1,1,0,string(),1);
		fdr<<new Feld("UsLfd","int","10","",Tx[T_Bezug_auf_LaborWert],1,0,0,string(),1);
		fdr<<new Feld("DatID","int","10","",Tx[T_Bezug_zu_LaborDat],1,0,1,string(),1);
		fdr<<new Feld("SatzID","int","10","",Tx[T_Bezug_auf_LaborXSaetze],1,0,1,string(),1);
		fdr<<new Feld("Satzart","varchar","4","",Tx[T_8000_Satzart_Turbomed],0,0,0);
		fdr<<new Feld("Satzlänge","varchar","5","",Tx[T_8100_Satzlaenge_Turbomed],0,0,0);
		fdr<<new Feld("Auftragsnummer","varchar","10","",Tx[T_8310_Anforderungsident_Turbomed],0,0,0);
		fdr<<new Feld("Auftragsschlüssel","varchar","15","",Tx[T_8311_Anforderungsnr_d_Labors_Turbomed],/*obind*/1,0,0);
		fdr<<new Feld("Eingang","date","0","0",Tx[T_Eingangsdatum_im_Labor],1,0,0);
		fdr<<new Feld("Berichtsdatum","datetime","0","0",Tx[T_8302_Berichtsdatum],0,0,0);
		fdr<<new Feld("Pat_id","int","5","","",1,0,1,string(),1);
		fdr<<new Feld("Nachname","varchar","25","","3101",0,0,0);
		fdr<<new Feld("Vorname","varchar","25","","3102",0,0,0);
		fdr<<new Feld("GebDat","date","","","3103",0,0,0);
		fdr<<new Feld("Titel","varchar","1","","3104",0,0,0);
		fdr<<new Feld("NVorsatz","varchar","7","","3105",0,0,0);
		fdr<<new Feld("NVors2","varchar","3","","3120",0,0,0);
		fdr<<new Feld("BefArt","varchar","1","",Tx[T_8401_Befundart_Turbomed__Fertigstellungsgrad_EEndbefund_T__Teilbefund],0,0,0);
		fdr<<new Feld("Abrechnungstyp","varchar","1","",Tx[T_8609_Abrechnungstyp_Kasse_Privat_X_anderer_RE_Einsender_Turbomed],0,0,0);
		fdr<<new Feld("GebüOrd","varchar","1","",Tx[T_8403_Gebuehrenordnung_Turbomed],0,0,0);
		fdr<<new Feld("Auftraggeber","varchar","9","",Tx[T_8615_Auftraggeber_LANR],0,0,0);
		fdr<<new Feld("Patienteninformation","varchar","10","",Tx[T_8405_Patienteninformation_Turbomed],0,0,0);
		fdr<<new Feld("Geschlecht","varchar","1","",Tx[T_8407_Geschlecht_Turbomed],/*obind*/0,/*obauto*/0,/*nnull*/1);
		fuellpql();
		for(size_t i=0;i<pql.size();i++) {
			fdr<<new Feld("Pat_id_"+ltoan(i),"varchar","11","",ersetze(pql[i].c_str(),"'",""),/*obind*/1,/*obauto*/0,/*nnull*/0);
		}
		fdr<<new Feld("ZeitpunktLaborneu","datetime","0","0",Tx[T_Zeitpunkt_der_Untersuchung_die_in_Laborneu_zugeordnet_wurde],0,0,0);
		fdr<<new Feld("Pat_id_Laborneu","varchar","5","",Tx[T_PatID_aus_Laborneu],0,0,0);
		/*
		fdr<<new Feld("ZdüP","smallint","6","0",Tx[T_Zahl_der_verglichenen_Parameter],0,0,0);
		fdr<<new Feld("ZdiP","int","10","0",Tx[T_Zahl_der_infragekommenden_Patienten],0,0,0);
		fdr<<new Feld("LWerte","LONGTEXT","","0",Tx[T_Laborwerte_die_zur_Zuordnung_gefuehrt_haben],0,0,0);
		*/
		fdr<<new Feld("verglichen","datetime","0","0",Tx[T_Datum_zu_dem_Datensatz_zuletzt_verglichen_wurde],0,0,0);
		fdr<<new Feld("AfN","smallint","6","0",Tx[T_Affected_Number_Zahl_der_zugehoerigen_Datensaetze_in_Laborneu],0,0,0);
#ifdef mitsqlnachweis
		fdr<<new Feld("SQL","varchar","220","",Tx[T_fuer_PatID_gewaehlte_SQL_Abfrage],0,0,0);
#endif
		fdr<<new Feld("z7","int","10","",Tx[T_Zahl_der_Antworten_aus_laborneu],0,0,0);
		fdr<<new Feld("SQL7","text","","",Tx[T_SQL_Abfrage_zur_direkten_Pat_id_Ermittlung_aus_laborneu],0,0,0);
		Feld ifelder0[] = {Feld("Nachname"),Feld("Vorname")};   Index i0("Name",ifelder0,sizeof ifelder0/sizeof* ifelder0);
		Feld ifelder1[]{Feld("Pat_Id_Laborneu"),Feld("ZeitpunktLaborneu")};   Index i1("Laborneu",ifelder1,sizeof ifelder1/sizeof* ifelder1);
		Index indices[]={i0,i1};
		Constraint csts[]{Constraint(tlydat+tlyus,new Feld{Feld("DatID")},1,tlydat,new Feld{Feld("DatID")},1,cascade,cascade),
		                	Constraint(tlysaetze+tlyus,new Feld{Feld("satzid")},1,tlysaetze,new Feld{Feld("satzid")},1,cascade,cascade)};
		// auf jeden Fall ginge "binary" statt "utf8" und "" statt "utf8_general_ci"
		Tabelle taba(My,tlyus,fdr,indices,sizeof indices/sizeof *indices,csts,sizeof csts/sizeof *csts, Tx[T_Laborus]/*//,"InnoDB","utf8","utf8_general_ci","DYNAMIC"*/);
#ifdef altfelder
		Feld felder[] = {
			Feld("ID","int","10","",Tx[T_eindeutige_Identifikation],1,1,0,string(),1),
			Feld("UsLfd","int","10","",Tx[T_Bezug_auf_LaborWert],1,0,0,string(),1),
			Feld("DatID","int","10","",Tx[T_Bezug_zu_LaborDat],1,0,1,string(),1),
			Feld("SatzID","int","10","",Tx[T_Bezug_auf_LaborXSaetze],1,0,1,string(),1),
			Feld("Satzart","varchar","11","",Tx[T_8000_Satzart_Turbomed],0,0,0),
			Feld("Satzlänge","varchar","11","",Tx[T_8100_Satzlaenge_Turbomed],0,0,0),
			Feld("Auftragsnummer","varchar","11","",Tx[T_8310_Anforderungsident_Turbomed],0,0,0),
			Feld("Auftragsschlüssel","varchar","11","",Tx[T_8311_Anforderungsnr_d_Labors_Turbomed],/*obind*/1,0,0),
			Feld("Eingang","date","0","0",Tx[T_Eingangsdatum_im_Labor],1,0,0),
			Feld("Berichtsdatum","datetime","0","0",Tx[T_8302_Berichtsdatum],0,0,0),
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
		Feld ifelder0[]{Feld("Nachname"),Feld("Vorname")};   Index i0("Name",ifelder0,sizeof ifelder0/sizeof* ifelder0);
		Index indices[]{i0};
		Constraint csts[]{Constraint(tlydat+tlyus,new Feld{Feld("DatID")},1,tlydat,new Feld{Feld("DatID")},1,cascade,cascade),
		                	Constraint(tlysaetze+tlyus,new Feld{Feld("satzid")},1,tlysaetze,new Feld{Feld("satzid")},1,cascade,cascade)};
		// auf jeden Fall ginge "binary" statt "utf8" und "" statt "utf8_general_ci"
		Tabelle taba(My,tlyus,felder,sizeof felder/sizeof* felder,indices,sizeof indices/sizeof *indices,csts,sizeof csts/sizeof *csts, Tx[T_Laborus]/*//,"InnoDB","utf8","utf8_general_ci","DYNAMIC"*/);
#endif
		if (taba.prueftab(aktc,obverb)) {
			fLog(rots+Tx[T_Fehler_beim_Pruefen_von]+schwarz+tlyus,1,1);
			exit(11);
		}
	} // if (!direkt)
} // int pruefouttab(DB *My, string touta, int obverb, int oblog, uchar direkt=0)

// wird aufgerufen in: virtpruefweiteres
void hhcl::prueflybakt(DB *My, const size_t aktc, const int obverb, const int oblog, const uchar direkt/*=0*/)
{
	hLog(violetts+Tx[T_prueflybakt]+schwarz);
	if (!direkt) {
		Feld felder[] = {
			Feld("ID","int","10","",Tx[T_eindeutige_Identifikation],1,1,1,string(),1),
			Feld("UsID","int","10","",Tx[T_Bezug_auf_LaborUS],/*obind*/1,/*obauto*/0,/*nnull*/1,/*vdefa*/string(),/*unsig*/1),
			Feld("NBID","int","10","",Tx[T_Bezug_zu_laborynb],/*obind*/1,/*obauto*/0,/*nnull*/0),
			Feld("Verf","varchar","42","",Tx[T_8410_Test_Ident_Turbomed],0,0,1),
			Feld("KuQu","varchar","6","",Tx[T_8428_Probenmaterial_Ident_Turbomed],0,0,1),
			Feld("Quelle","varchar","22","",Tx[T_8430_Probenmaterial_Bezeichnung_Turbomed],0,0,1),
			Feld("QSpez","varchar","29","",Tx[T_8431_Probenmaterial_Spezifikation_Turbomed],0,0,1),
			Feld("AbnDat","datetime","0","0",Tx[T_8432_Abnahmedatum_Turbomed],0,0,1),
//			Feld("Kommentar","LONGTEXT","","",Tx[T_8480_Ergebnistest_Turbomed],0,0),
			Feld("KommID","int","10","",Tx[T_Kommentar_Bezug_auf_lyhinw],1,0,0,"0",1),
//			Feld("Erklärung","LONGTEXT","","","",0,0,0),
			Feld("ErklID","int","10","",Tx[T_Erklaerung_Bezug_auf_lyhinw],1,0,0,"0",1),
//			Feld("AuftrHinw","LONGTEXT","","",Tx[T_8490_Auftragsbezogene_Hinweise_Turbomed],/*obind*/0,/*obauto*/0,/*nnull*/0),
			Feld("HinwID","int","10","",Tx[T_Auftragshinweis_Bezug_auf_lyhinw],1,0,0,"0",1),
			Feld("Keimzahl","varchar","16","","",0,0,1),
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
void hhcl::prueflyleist(DB *My, const size_t aktc, const int obverb, const int oblog, const uchar direkt/*=0*/)
{
	hLog(violetts+Tx[T_prueflyleist]+schwarz);
	if (!direkt) {
		Feld felder[] = {
			Feld("ID","int","10","",Tx[T_eindeutige_Identifikation],1,1,0,string(),1),
			Feld("UsID","int","10","",Tx[T_Bezug_auf_LaborUS],/*obind*/1,/*obauto*/0,0,string(),/*unsigned*/1),
			Feld("Abkü","varchar","8","",Tx[T_8410_Test_Ident_Turbomed],0,0,1),
			Feld("Verf","varchar","42","",Tx[T_8434],0,0,1),
			Feld("EBM","varchar","6","",Tx[T_5001_GNR_Turbomed],0,0,1),
			Feld("goä","varchar","4","",Tx[T_8406],0,0,1),
			Feld("Anzahl","varchar","2","",Tx[T_5005],0,0,1),
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
void hhcl::prueflywert(DB *My, const size_t aktc, const int obverb, const int oblog, const uchar direkt/*=0*/)
{
	hLog(violetts+Tx[T_prueflywert]+schwarz);
	if (!direkt) {
		Feld felder[] = {
			Feld("ID","int","10","",Tx[T_eindeutige_Identifikation],1,1,0,string(),1),
			Feld("UsID","int","10","",Tx[T_Bezug_auf_LaborUS],1,0,0,string(),1),
			Feld("BaktID","int","10","",Tx[T_Bezug_auf_LaborBakt],1,0,0,"0",1),
			Feld("NBID","int","10","",Tx[T_Bezug_zu_laborynb],/*obind*/1,/*obauto*/0,/*nnull*/0),
			Feld("Abkü","varchar","8","",Tx[T_8410_maximale_Laenge_8],0,0,1),
			Feld("Langtext","varchar","41","",Tx[T_8411_Testbezeichnung_Turbomed],0,0,1),
			Feld("KuQu","varchar","4","",Tx[T_8428_Probenmaterial_Ident_Turbomed],0,0,1),
			Feld("Quelle","varchar","22","",Tx[T_8430_Probenmaterial_Bezeichnung_Turbomed],0,0,1),
			Feld("QSpez","varchar","158","",Tx[T_8431_Probenmaterial_Spezifikation_Turbomed],0,0,1),
			Feld("AbnDat","datetime","0","0",Tx[T_8432_Abnahmedatum_Turbomed],0,0,1),
			Feld("Wert","varchar","8","0",Tx[T_8420_Ergebniswert_Turbomed],0,0,1),
			Feld("Einheit","varchar","12","",Tx[T_8421_maximale_Laenge_12],0,0,1,"kA"),
			Feld("Grenzwerti","varchar","2","",Tx[T_8422_Grenzwertindikator_Turbomed],0,0,1),
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
		Feld ifelder2[] = {Feld("Wert")};   Index i2("Wert",ifelder2,sizeof ifelder2/sizeof* ifelder2);
		Index indices[]={i0,i1,i2};
		Constraint csts[]{Constraint(tlyus+tlywert,new Feld{Feld("UsID")},1,tlyus,new Feld{Feld("id")},1,cascade,cascade)};
		// auf jeden Fall ginge "binary" statt "utf8" und "" statt "utf8_general_ci"
		Tabelle taba(My,tlywert,felder,sizeof felder/sizeof* felder,indices,sizeof indices/sizeof *indices,csts,sizeof csts/sizeof *csts, Tx[T_Laborwert]/*//,"InnoDB","utf8","utf8_general_ci","DYNAMIC"*/);
		if (taba.prueftab(aktc,obverb)) {
			fLog(rots+Tx[T_Fehler_beim_Pruefen_von]+schwarz+tlywert,1,1);
			exit(11);
		}
	} // if (!direkt)
} // int pruefouttab(DB *My, string touta, int obverb, int oblog, uchar direkt=0)

void hhcl::prueflyfehlt(DB *My, const size_t aktc, const int obverb, const int oblog, const uchar direkt/*=0*/)
{
	hLog(violetts+Tx[T_prueflyfehlt]+schwarz);
	if (!direkt) {
		Feld felder[] = {
			Feld("ID","int","10","",Tx[T_eindeutige_Identifikation],1,1,1,string(),1),
			Feld("DatID","int","10","",Tx[T_eindeutige_Identifikation],1,0,0,string(),1),
			Feld("Kennung","varchar","4","",Tx[T_Kennung],0,0,1),
			Feld("Inhalt","varchar","3","",Tx[T_Inhalt],0,0,1),
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
void hhcl::prueflypgl(DB *My, const size_t aktc, const int obverb, const int oblog, const uchar direkt/*=0*/)
{
	hLog(violetts+Tx[T_prueflypgl]+schwarz);
	if (!direkt) {
		const string idypneu{"id"+tlypneu.substr(tlypneu.length()-5)},
					idypbez{"id"+tlypneu.substr(tlypneu.length()-5,2)+"bez"};
		Feld felder[] = {
			Feld("ID","int","10","",Tx[T_eindeutige_Identifikation],/*obind*/1,/*obauto*/1,/*nnull*/0,string(),1),
			Feld(idypneu,"int","10","",Tx[T_laborxpneu],1,/*obauto*/0,/*nnull*/0,string(),1), // idypneu
			Feld("idpara","int","10","",Tx[T_laborparameter],1,/*obauto*/0,/*nnull*/0,string(),1),
			Feld(idypbez,"int","10","",Tx[T_ist_identisch_mit_laborxpneu],1,/*obauto*/0,/*nnull*/1,string(),1), // idypbez
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
		Constraint c0(vorsl+"pgl_1",ifd0,1,tlypneu,ifd0a,1);
		Constraint c1(vorsl+"pgl_2",ifd1,1,tlyparameter,ifd1a,1); // bzw. laborparameter
		Constraint c2(vorsl+"pgl_3",ifd2,1,tlypneu,ifd2a,1,cascade,cascade);
		Constraint csts[]{c0,c1,c2};
		*/
		Constraint csts[]{
			Constraint(vorsl+"pgl_1",new Feld{Feld(idypneu)},1,tlypneu,new Feld{Feld("id")},1),
			Constraint(vorsl+"pgl_2",new Feld{Feld("idpara")},1,"laborparameter",new Feld{Feld("id")},1),
			Constraint(vorsl+"pgl_3",new Feld{Feld(idypbez)},1,tlypneu,new Feld{Feld("id")},1,cascade,cascade),
		};
		// auf jeden Fall ginge "binary" statt "utf8" und "" statt "utf8_general_ci"
		Tabelle taba(My,tlypgl,felder,sizeof felder/sizeof* felder,indices,sizeof indices/sizeof *indices,csts,sizeof csts/sizeof *csts, Tx[T_Laborpgl]/*//,"InnoDB","utf8","utf8_general_ci","DYNAMIC"*/);
		if (taba.prueftab(aktc,obverb)) {
			fLog(rots+Tx[T_Fehler_beim_Pruefen_von]+schwarz+tlypgl,1,1);
			exit(11);
		}
	} // if (!direkt)
} // int pruefouttab(DB *My, string touta, int obverb, int oblog, uchar direkt=0)

// aufgerufen in /*pruefPatID*/ russchreib und prueflyus
void hhcl::fuellpql()
{
	pql.clear();
	pql<<"SELECT pat_id FROM `"+tlyus+"` u WHERE gebdat="+sqlft(My->DBS,&gebtm)+" AND auftragsschlüssel = "+sqlft(My->DBS,auftrschl)+" AND eingang = "+sqlft(My->DBS,&eingtm)+" AND pat_id<>0 GROUP BY pat_id";
	ergpql();
}

/*
// aufgerufen in russchreib
void hhcl::pruefPatID(const int aktc,insv& rus)
{
//	if (pid=="0") exit(97);
} // void hhcl::virtVorgbAllg
*/

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
	dhcl::pvirtVorgbSpeziell(); //α
	virtMusterVorgb();
} // void hhcl::pvirtVorgbSpeziell

int hhcl::fui0(){return !vorsl.empty();};

// wird aufgerufen in lauf
void hhcl::virtinitopt()
{ //ω
	// Kopiervorlage:
	// opn<<new optcl(/*pname*/"pname",/*pptr*/pptr,/*art*/pstri,/*kurzi*/T_kurz_k,/*langi*/T_lang_l,/*TxBp*/&Tx,/*Txi*/T_Option_erklaert,/*wi*/1,/*Txi2*/T_Option_Nachtext,/*rottxt*/nix,/*wert*/1,/*woher*/!pname.empty(),/*Txtrf*/{},/*obno*/1,/*refstr*/0,/*obfragz*/0,/*fnobfragz*/0,/*fnnachhz*/&hcl::fu1,/*fnvorhz*/0,/*sonderrf*/0,/*fngueltigz*/0)
	opn<<new optcl(/*pname*/"vorsil",/*pptr*/&vorsl,/*art*/pstri,T_vors_k,T_vors_l,/*TxBp*/&Tx,/*Txi*/T_Vorsilbe_fuer_Datenbanktabellen,/*wi*/0,/*Txi2*/-1,/*rottxt*/string(),/*wert*/-1,/*woher*/!vorsl.empty(),Tx[T_Vorsilbe_fuer_Datenbanktabellen],/*obno*/0,/*refstr*/0,/*obfragz*/0,/*fnobfragz*/0,/*fnnachhz*/0,/*fnvorhz*/0,/*sonderrf*/0,/*fngueltigz*/&hcl::fui0);
	opn<<new optcl(/*pname*/"ldatvz",/*pptr*/&ldatvz,/*art*/pverz,T_ldvz_k,T_ldvz_l,/*TxBp*/&Tx,/*Txi*/T_Verzeichnis_der_Labordateien,/*wi*/0,/*Txi2*/-1,/*rottxt*/string(),/*wert*/-1,/*woher*/!ldatvz.empty(),Tx[T_Verzeichnis_der_Labordateien]);
	opn<<new optcl(/*pname*/"fertigvz",/*pptr*/&fertigvz,/*art*/pverz,T_fgvz_k,T_fgvz_l,/*TxBp*/&Tx,/*Txi*/T_Verzeichnis_der_Fertigen,/*wi*/0,/*Txi2*/-1,/*rottxt*/string(),/*wert*/-1,/*woher*/!fertigvz.empty(),Tx[T_Verzeichnis_der_fertig_Verarbeiteten]);
	opn<<new optcl(/*pptr*/&vonvorne,/*art*/puchar,T_vv_k,T_vv_l,/*TxBp*/&Tx,/*Txi*/T_Loesche_alle_Tabellen_und_fange_von_vorne_an,/*wi*/0,/*Txi2*/-1,/*rottxt*/string(),/*wert*/1,/*woher*/1);
	opn<<new optcl(/*pptr*/&entleer,/*art*/puchar,T_tr_k,T_tr_l,/*TxBp*/&Tx,/*Txi*/T_Entleert_alle_Tabellen_und_faengt_von_vorne_an,/*wi*/0,/*Txi2*/-1,/*rottxt*/string(),/*wert*/1,/*woher*/1);
	opn<<new optcl(/*pptr*/&loeschalle,/*art*/puchar,T_la_k,T_la_l,/*TxBp*/&Tx,/*Txi*/T_loescht_alle_Tabellen,/*wi*/0,/*Txi2*/-1,/*rottxt*/string(),/*wert*/1,/*woher*/1);
	opn<<new optcl(/*pptr*/&umben,/*art*/pstri,T_umben_k,T_umben_l,/*TxBp*/&Tx,/*Txi*/T_benennt_die_Tabellen_um,/*wi*/0,/*Txi2*/-1,/*rottxt*/string(),/*wert*/-1,/*woher*/1);
	opn<<new optcl(/*pptr*/&loeschab,/*art*/pdez,T_lab_k,T_lab_l,/*TxBp*/&Tx,/*Txi*/T_loescht_alle_Datensaetze_ab,/*wi*/0,/*Txi2*/-1,/*rottxt*/string(),/*wert*/-1,/*woher*/!loeschab.empty());
	opn<<new optcl(/*pptr*/&loeschid,/*art*/pdez,T_lid_k,T_lid_l,/*TxBp*/&Tx,/*Txi*/T_loescht_Datensatz_id,/*wi*/0,/*Txi2*/-1,/*rottxt*/string(),/*wert*/-1,/*woher*/!loeschid.empty());
	opn<<new optcl(/*pptr*/&pidnachw,/*art*/pdez,T_pidnachw_k,T_pidnachw_l,/*TxBp*/&Tx,/*Txi*/T_listet_Eintraege_zu_pid,/*wi*/0,/*Txi2*/-1,/*rottxt*/string(),/*wert*/-1,/*woher*/!pidnachw.empty());
	opn<<new optcl(/*pptr*/&listdat,/*art*/puchar,T_listdat_k,T_listdat_l,/*TxBp*/&Tx,/*Txi*/T_listet_alle_eingelesenen_Dateien_auf,/*wi*/0,/*Txi2*/-1,/*rottxt*/string(),/*wert*/1,/*woher*/1);

	opn<<new optcl(/*pptr*/&loeschunvollst,/*art*/puchar,T_lu_k,T_lu_l,/*TxBp*/&Tx,/*Txi*/T_loescht_Datensaetze_aus_unvollstaendig_eingelesenen_Dateien,/*wi*/0,/*Txi2*/-1,/*rottxt*/string(),/*wert*/1,/*woher*/1);
	opn<<new optcl(/*pptr*/&nurpruefdb,/*art*/puchar,T_pruefdb_k,T_pruefdb_l,/*TxBp*/&Tx,/*Txi*/T_initialisiert_nur_die_Tabellen,/*wi*/0,/*Txi2*/-1,/*rottxt*/string(),/*wert*/1,/*woher*/1);
	opn<<new optcl(/*pptr*/&nurnachb,/*art*/puchar,T_nurnachb_k,T_nurnachb_l,/*TxBp*/&Tx,/*Txi*/T_nur_Nachbearbeitung,/*wi*/1,/*Txi2*/-1,/*rottxt*/string(),/*wert*/-2,/*woher*/1);
	opn<<new optcl(/*pptr*/&nachbneu,/*art*/puchar,T_nachbneu_k,T_nachbneu_l,/*TxBp*/&Tx,/*Txi*/T_Nachbearbeitung_von_vorne,/*wi*/1,/*Txi2*/-1,/*rottxt*/string(),/*wert*/1,/*woher*/1);
	opn<<new optcl(/*pptr*/&nurusmod,/*art*/puchar,T_nurusmod_k,T_nurusmod_l,/*TxBp*/&Tx,/*Txi*/T_nur_usmod,/*wi*/1,/*Txi2*/-1,/*rottxt*/string(),/*wert*/-2,/*woher*/1);
	opn<<new optcl(/*pptr*/&pruefauft,/*art*/puchar,T_pruefauft_k,T_pruefauft_l,/*TxBp*/&Tx,/*Txi*/T_pruefe_alle_Auftraege,/*wi*/1,/*Txi2*/-1,/*rottxt*/string(),/*wert*/-2,/*woher*/1);
	opn<<new optcl(/*pptr*/&dszahl,/*art*/plong,T_n_k,T_dszahl_l,/*TxBp*/&Tx,/*Txi*/T_Zahl_der_aufzulistenden_Datensaetze_ist_zahl_statt,/*wi*/1,/*Txi2*/-1,/*rottxt*/string(),/*wert*/-1,/*woher*/1);
	dhcl::virtinitopt(); //α
//	vorclvors=vorsl;
} // void hhcl::virtinitopt

// wird aufgerufen in lauf
void hhcl::pvirtmacherkl()
{
	erkl<<blau<<Txk[T_Program]<<violett<<DPROG //ω
		<<blau<<" ist etwas ganz Spezielles"<<schwarz; //α
	tabnamen();
} // void hhcl::pvirtmacherkl

void hhcl::tabnamen()
{
	tlydat=vorsl+"dat";
	tlyleist=vorsl+"leist";
	tlypgl=vorsl+"pgl";
	tlyplab=vorsl+"plab";
	tlypnb=vorsl+"pnb";
	tlypneu=vorsl+"pneu";
	tlyaerzte=vorsl+"aerzte";
	tlysaetze=vorsl+"saetze";
	tlyus=vorsl+"us";
	tlywert=vorsl+"wert";
	tlybakt=vorsl+"bakt";
	tlyfehlt=vorsl+"fehlt";
	tlyparameter=vorsl+"parameter";
	tlyhinw=vorsl+"hinw";
} // void hhcl::tabnamen

// wird aufgerufen in lauf
void hhcl::virtMusterVorgb()
{
	hLog(violetts+Tx[T_virtMusterVorgb]+schwarz); //ω
	dhcl::virtMusterVorgb(); //α
	dbq=DPROG;
	vorsl=vorsilbe;
	ldatvz=gethome()+vtz+Tx[T_labor];
	fertigvz=ldatvz+vtz+Tx[T_fertige];
} // void hhcl::MusterVorgb

// wird aufgerufen in lauf
void hhcl::pvirtvorzaehler()
{ //ω
} // void hhcl::virtvorzaehler() //α
//ω

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
	}
	if (listdat||!pidnachw.empty()) {
#ifndef sqlos
		char*** cerg{0};
		const size_t aktc{0};
		if (!My) initDB();
#endif
		if (listdat) {
			// schon vor pruefggfdoppelt
#ifdef sqlos
			svec datr;
			systemrueck("mysql -u"+muser+" -p"+mpwd+" "+dbq+" -e'SELECT datid,pfad,geändert,größe,zp,codepage,!!fertig FROM `"+tlydat+"`'",obverb,oblog,&datr);
			for(auto aktdat:datr) {
				caus<<aktdat<<endl;
			}
#else
			if (!dszahl) dszahl=100;
			RS li(My,"SELECT * from (SELECT d.datid,pfad,geändert,größe,zp,codepage,!!fertig,(SELECT count(0) from `"+tlysaetze+"` WHERE datid=d.datid),(SELECT COUNT(0) FROM `"+tlyus+"` WHERE datid=d.datid),SUM((SELECT COUNT(0) FROM `"+tlywert+"` WHERE usid=u.id)),SUM((SELECT COUNT(0) FROM `"+tlybakt+"` WHERE usid=u.id)) FROM `"+tlydat+"` d LEFT JOIN `"+tlyus+"` u ON d.datid = u.datid GROUP BY d.datid DESC LIMIT "+ltoan(dszahl)+") i ORDER BY datid",aktc,ZDB);
			if (!li.obqueryfehler) {
				size_t zru=0;
				while (cerg=li.HolZeile(),cerg?*cerg:0) {
					if (!zru++) {
						cout<<violett<<Tx[T_listet_alle_eingelesenen_Dateien_auf]<<schwarz<<endl;
						cout<<schwarz<<setw(6)<<"DATID"<<"|"<<setw(60)<<Tx[T_Pfad_]<<"|"<<setw(19)<<Tx[T_Eingang]<<"|"<<setw(9)<<Tx[T_Groesse]<<"|"<<setw(19)<<Tx[T_eingelesen]<<"|"<<setw(2)<<Tx[T_Zeichensatz]<<"|"<<setw(1)<<Tx[T_fertig_]<<"|"<<setw(4)<<Tx[T_saetze]<<"|"<<setw(4)<<Tx[T_unters]<<"|"<<setw(5)<<Tx[T_werte]<<"|"<<setw(4)<<Tx[T_bakt]<<schwarz<<endl;
					} // 								if (!zru++)
					cout<<blau<<setw(6)<<cjj(cerg,0)<<"|"<<violett<<setw(60)<<cjj(cerg,1)<<schwarz<<"|"<<blau<<setw(19)<<cjj(cerg,2)<<"|"
						<<schwarz<<setw(9)<<cjj(cerg,3)<<"|"<<blau<<setw(19)<<cjj(cerg,4)<<"|"<<violett<<setw(2)<<cjj(cerg,5)<<"|"
						<<blau<<setw(1)<<cjj(cerg,6)<<"|"<<setw(4)<<cjj(cerg,7)<<"|"<<setw(4)<<cjj(cerg,8)<<"|"<<setw(5)<<cjj(cerg,9)<<"|"<<setw(4)<<cjj(cerg,10)<<schwarz<<endl;
				} // while (cerg=li.HolZeile(),cerg?*cerg:0) 
			} // 			if (!li.obqueryfehler) 
#endif
		} else if (!pidnachw.empty()) {
			RS nw(My,"SELECT pfad,datid,satzid,usid,id,pat_id_0,pat_id_1,pat_id_2,pat_id_3,pat_id_4,pat_id_5,pat_id_6,pat_id_7,pat_id_laborneu,"
					"Pat_ID,Zeitpunkt,FertigStGrad,Abkü,Langtext,Wert,Einheit,Kommentar,Auftragsnummer,Auftragsschlüssel "
					"FROM labor2aNachweis WHERE pat_id="+pidnachw,aktc,ZDB);
			if (!nw.obqueryfehler) {
				size_t zru=0;
				while (cerg=nw.HolZeile(),cerg?*cerg:0) {
					if (!zru++) {
						cout<<violett<<Tx[T_listet_Eintraege_zu_pid]<<" "<<blau<<pidnachw<<schwarz<<endl;
						cout<<blau<<setw(26)<<"Name "
								<<violett<<setw(5)<<"Datid"
								<<schwarz<<setw(11)<<"Auftrag"
//								<<schwarz<<setw(5)<<"Satzid"
//								<<blau<<setw(7)<<"USID"
//								<<schwarz<<setw(8)<<"w.ID"
								<<gruen<<setw(6)<<"PID_0"
									<<setw(6)<<"PID_1"
									<<setw(6)<<"PID_2"
									<<setw(6)<<"PID_3"
									<<setw(6)<<"PID_4"
									<<setw(6)<<"PID_5"
									<<setw(6)<<"PID_6"
									<<setw(6)<<"PID_7"
									<<setw(6)<<"PID_L"
									<<setw(6)<<"PID"
								<<schwarz<<setw(9)<<"us.eing"
								<<blau<<setw(2)<<"FS"
								<<schwarz<<setw(10)<<"Abkü"
								<<blau<<setw(8)<<"Wert"
								<<schwarz<<setw(11)<<"Einh"
								<<endl;
					} // 					if (!zru++)
					string c15(cjj(cerg,15));
					cout<<blau<<setw(26)<<base_name(cjj(cerg,0))
							<<violett<<setw(5)<<cjj(cerg,1)
							<<schwarz<<setw(11)<<cjj(cerg,23)
//							<<schwarz<<setw(5)<<cjj(cerg,2)
//							<<blau<<setw(7)<<cjj(cerg,3)
//							<<schwarz<<setw(8)<<cjj(cerg,4)
							<<gruen<<setw(6)<<cjj(cerg,5)
								<<setw(6)<<cjj(cerg,6)
								<<setw(6)<<cjj(cerg,7)
								<<setw(6)<<cjj(cerg,8)
								<<setw(6)<<cjj(cerg,9)
								<<setw(6)<<cjj(cerg,10)
								<<setw(6)<<cjj(cerg,11)
								<<setw(6)<<cjj(cerg,12)
								<<setw(6)<<cjj(cerg,13)
								<<setw(6)<<cjj(cerg,14)
							<<schwarz<<setw(5)<<c15.substr(0,4)
							<<c15.substr(5,2)<<c15.substr(8,2)
							<<blau<<setw(2)<<cjj(cerg,16)
							<<schwarz<<setw(10)<<cjj(cerg,17)
							<<blau<<setw(8)<<cjj(cerg,19)
							<<schwarz<<setw(11)<<cjj(cerg,20)
							<<endl;// <<blau<<setw(10)<<cjj(cerg,21)<<endl;
				} // 				while (cerg=nw.HolZeile(),cerg?*cerg:0)
			} // 			if (!nw.obqueryfehler)
		} // 		} else if (!pidnachw.empty())
		exit(0);
	} // 	if (listdat||!pidnachw.empty())
	if (vorsl.empty()) vorsl=vorsilbe;
	//α
} // void hhcl::pvirtvorrueckfragen

void hhcl::droptables(const size_t aktc/*=0*/,uchar obumben/*=0*/)
{
	auto altZDB{ZDB};
//	ZDB=1;
	for(int aru=0;aru<2;aru++) {
		for(auto tab:{&tlyhinw,&tlypgl,&tlywert,&tlyleist,&tlybakt,&tlypnb,&tlypneu,&tlyus,&tlysaetze,&tlyaerzte,&tlyparameter,&tlyplab,&tlyfehlt,&tlydat}){
			if (obumben) {
				// erst alle constraints loeschen, dann alle umbennen
				if (!aru) {
				char ***cerg{0};
				RS holconst(My,"SELECT CONSTRAINT_NAME FROM information_schema.key_column_usage "
						"WHERE CONSTRAINT_SCHEMA = '"+dbq+"' AND TABLE_NAME='"+*tab+"' AND REFERENCED_TABLE_NAME IS NOT NULL",aktc,ZDB);
				if (!holconst.obqueryfehler) {
					while ((cerg=holconst.HolZeile())&&*cerg) {
						RS loeconst(My,"ALTER TABLE `"+*tab+"` DROP FOREIGN KEY `"+cjj(cerg,0)+"`",aktc,ZDB);
					}
				}
				} else {
				RS d1(My,"ALTER TABLE `"+*tab+"` RENAME TO `"+umben+tab->substr(vorsl.length())+"`",aktc,ZDB);
				}
			} else {
				// aber: laborparameter nicht loeschen!
				RS d1(My,"DROP TABLE IF EXISTS `"+*tab+"`",aktc,ZDB);
			}
		}
		if (!obumben) break;
	}
	ZDB=altZDB;
} // void hhcl::droptables

// wird aufgerufen in lauf
void hhcl::virtpruefweiteres()
{ //ω
	const size_t aktc{0};
	my_ulonglong zahl{0};
	if (vonvorne||loeschalle||!umben.empty()) {
		if (!My) initDB();
		for(string *vsp:{&vorsl,&umben}) {
			char ***cerg{0};
			RS z(My,"SELECT COUNT(0) FROM INFORMATION_SCHEMA.tables WHERE TABLE_CATALOG='def' and TABLE_SCHEMA='"+dbq+"'"
					" AND TABLE_NAME LIKE '"+*vsp+"%' AND TABLE_TYPE='BASE TABLE'",aktc,ZDB);
			if (!z.obqueryfehler&&(cerg=z.HolZeile())&&*cerg) {
				fLog(Tx[T_Tabellenzahl_mit]+blaus+*vsp+schwarz+": "+blau+cjj(cerg,0)+schwarz,1,oblog);
			}
			cerg=0;
			RS x(My,"SELECT COUNT(0) FROM `"+*vsp+tlydat.substr(vorsl.length())+"`",aktc,-2);
			fLog(Tx[T_Eingelesene_Labordateien]+blaus+((!x.obqueryfehler&&(cerg=x.HolZeile())&&*cerg)?cjj(cerg,0):"0")+schwarz,1,oblog);
			if (umben.empty()) break;
		}
		if (!Tippob(rots+Tx[umben.empty()?T_Soll_ich_wirklich_alle_Tabellen_mit:T_Soll_ich_wirklich_alle_Tabellen_mit___]+blau+vorsl+rot+(vonvorne?Tx[T_loeschen_und_von_vorne_anfangen]:loeschalle?Tx[T_loeschen]:Tx[T_nach___]+blaus+umben+schwarz+Tx[T_umbenennen])+schwarz,"n")) {
			fLog(Tx[T_Aktion_abgebrochen],1,1);
			exit(0);
		}
		if (umben.empty()) {
			droptables(aktc);
			fLog(blaus+Tx[vonvorne?T_Loesche_alle_Tabellen_und_fange_von_vorne_an:T_loescht_alle_Tabellen]+schwarz+Txd[T_mit]+blau+vorsl+schwarz,1,1);
		} else {
			auto const altvorsil{vorsl};
			vorsl=umben;
			tabnamen();
			droptables(aktc);
			vorsl=altvorsil;
			tabnamen();
			droptables(aktc,1);
			vorsl=umben;
			tabnamen();
			prueftbl();
			// dann bei der neuen Vorsibe bleiben:
      hccd.obzuschreib=1;
			// vorsl=altvorsil;
			// tabnamen();
		}
	} else if (!loeschab.empty() || !loeschid.empty()) {
		if (!My) initDB();
    my_ulonglong dzahl{0},szahl{0},uzahl{0};
		char ***cerg{0};
		RS datzahl(My,"SELECT datid p0, name p1 FROM `"+tlydat+"` WHERE datid"+(loeschab.empty()?"":">")+"='"+(loeschab.empty()?loeschid:loeschab)+"'",
				aktc,ZDB,0,0,0,&dzahl);
    RS satzzahl(My,"SELECT datid FROM `"+tlysaetze+"` WHERE datid"+(loeschab.empty()?"":">")+"='"+(loeschab.empty()?loeschid:loeschab)+"'",
				aktc,ZDB,0,0,0,&szahl);
    RS uszahl(My,"SELECT datid FROM `"+tlyus+"` WHERE datid"+(loeschab.empty()?"":">")+"='"+(loeschab.empty()?loeschid:loeschab)+"'",
				aktc,ZDB,0,0,0,&uzahl);
		string dzahls{ltoan(dzahl)};
		string szahls{ltoan(szahl)};
		string uzahls{ltoan(uzahl)};
		if (!Tippob(rots+Tx[T_Soll_ich_wirklich_alle_Tabellen_mit]+blau+vorsl+rot+Tx[(loeschab.empty()?T_mit_DATID:T_ab_DATID)]+blau
					+(loeschab.empty()?loeschid:loeschab)+rot+Tx[T_loeschen]+schwarz+"("+gruen+dzahls+schwarz+Tx[T_Eintraege_aus]+blau
					+tlydat+schwarz+", "+gruen+szahls+schwarz+Tx[T_Eintraege_aus]+blau+tlysaetze+schwarz+", "+gruen+uzahls+schwarz
					+Tx[T_Eintraege_aus]+blau+tlyus+schwarz+")","n")) {
			fLog(Tx[T_Aktion_abgebrochen],1,1);
			exit(0);
		}
		fLog(blaus+Tx[(loeschab.empty()?T_Loescheid:T_Loescheab)]+gruen+(loeschab.empty()?loeschid:loeschab)+schwarz,1,0);
		// ZDB=1;
		string verschobenedatei,befehl;
		while (cerg=datzahl.HolZeile(),cerg?*cerg:0) {
			verschobenedatei=ldatvz+'/'+cjj(cerg,1);
			if (rename((fertigvz+'/'+cjj(cerg,1)).c_str(),verschobenedatei.c_str())) {
				fLog(rots+Tx[T_Fehler_beim_Verschieben_von]+blau+fertigvz+'/'+cjj(cerg,1)+rot+Tx[T_nach_]+blau+ldatvz+'/'+cjj(cerg,1)+schwarz+": "+rot+strerror(errno)+schwarz,1,1);
			} else {
				befehl="vi \""+verschobenedatei+"\"";
				cout<<befehl<<endl;
			}
		} // 		while (cerg=datzahl.HolZeile(),cerg?*cerg:0)
		RS loe(My,"DELETE FROM `"+tlydat+"` WHERE datid"+(loeschab.empty()?"":">")+"='"+(loeschab.empty()?loeschid:loeschab)+"'",aktc,ZDB,0,0,0,&zahl);
		fLog(gruens+ltoan(zahl)+blau+" "+Tx[T_Datensaetze_geloescht]+schwarz,1,0);
		if (!loeschid.empty()) {
			exit(schluss(systemrueck(befehl+" "+devtty,/*obverb=*/0,/*oblog=*/0,/*rueck=*/0,/*obsudc=*/1),Txk[T_nach__]+befehl,oblog));
		}
		exit(0);
	} else if (entleer) {
		if (!Tippob(rots+Tx[T_Soll_ich_wirklich_alle_Tabellen_mit_]+blau+vorsl+rot+Tx[T_entleeren_und_von_vorne_anfangen]+schwarz,"n")) {
			fLog(Tx[T_Aktion_abgebrochen],1,1);
			exit(0);
		}
		if (!My) initDB();
		RS da(My,"SET FOREIGN_KEY_CHECKS=0",aktc,ZDB);
		const string truncate{"TRUNCATE "};
		RS d13(My,truncate+tlyhinw,aktc,ZDB);
		RS d0(My,truncate+tlypgl,aktc,ZDB);
		RS d1(My,truncate+tlywert,aktc,ZDB);
		RS d2(My,truncate+tlyleist,aktc,ZDB);
		RS d3(My,truncate+tlybakt,aktc,ZDB);
		RS d6(My,truncate+tlypnb,aktc,ZDB);
		RS d7(My,truncate+tlypneu,aktc,ZDB);
		RS d4(My,truncate+tlyus,aktc,ZDB);
		RS d5(My,truncate+tlysaetze,aktc,ZDB);
		RS d12(My,truncate+tlyaerzte,aktc,ZDB);
		RS d11(My,truncate+tlyparameter,aktc,ZDB);
		// aber: laborparameter nicht loeschen!
		RS d8(My,"DELETE FROM `"+tlyplab+"` where id>1",aktc,ZDB);
		RS d10(My,truncate+tlyfehlt,aktc,ZDB);
		RS d9(My,truncate+tlydat,aktc,ZDB);
		RS de(My,"SET FOREIGN_KEY_CHECKS=1",aktc,ZDB);
		fLog(blaus+Tx[T_Entleert_alle_Tabellen_und_faengt_von_vorne_an]+schwarz,1,1);
	} else if (loeschunvollst||nurnachb||nachbneu||nurusmod||pruefauft) {
		if (nachbneu) {
			if (!Tippob(rots+Tx[T_Soll_ich_wirklich_alle_Nachbearbeitungen_von_vorne_angefangen_werden]+schwarz,"n")) {
				fLog(Tx[T_Aktion_abgebrochen],1,1);
				exit(0);
			}
		} // 		if (nachbneu)
		if (loeschunvollst||nachbneu) {
			if (!Tippob(rots+Tx[T_Soll_ich_wirklich_alle_Tabellen_mit__]+blau+vorsl+rot+Tx[T_um_Datensaetze_aus_nicht_fertig_eingelesenen_Dateien_bereinigt_werden]+schwarz,"n")) {
				fLog(Tx[T_Aktion_abgebrochen],1,1);
				exit(0);
			}
		} // 		if (loeschunvollst||nachbneu)
		if (pruefauft) {
			caus<<"So, jetzt pruefe ich die Auftraege"<<endl;
//			vverarbeit("/DATA/down/X010LG05SKD.LDT");
			vverarbeit("/DATA/down/X010PX05SKD.LDT");
		}
		const uchar altZDB{ZDB};
		// ZDB=1;
		if (!My) initDB();
		RS loeschvor(My,"DELETE FROM `"+tlydat+"` WHERE fertig<>1",aktc,ZDB,0,0,0,&zahl);
		fLog(gruens+ltoan(zahl)+blau+" "+Tx[T_Datensaetze_geloescht]+schwarz,1,0);
		if (nachbneu) {
			RS nachloesch(My,"UPDATE `"+tlyus+"` SET pat_id_laborneu=null",aktc,ZDB);
		}
		ZDB=altZDB;
	} // if (vonvorne||loeschalle||!umben.empty()) else if ..  else if (loeschunvollst||nurnachb||nurusmod||nachbneu)
	hcl::virtpruefweiteres(); // z.Zt. leer //α
} // void hhcl::virtpruefweiteres

// wird aufgerufen in lauf
void hhcl::virtzeigueberschrift()
{ //ω
	// hier ggf. noch etwas an 'uebers' anhaengen //α
	uebers<<" (Laborimport) ";
	hcl::virtzeigueberschrift();
} // void hhcl::virtzeigueberschrift

void BDTtoDate(const string& inh,struct tm *tm,int abjahr/*=1900*/,uchar objahrzuerst/*=0*/)
{
	memset(tm,0,sizeof *tm);
//	const char* const mu[]{"%d%m%Y","%Y%m%d"};
	const char* const mu[]{"%Y%m%d","%d%m%Y"};
	for(int i=0;i<2;i++) {
		auto const& aktmu=mu[objahrzuerst?i:1-i];
//		caus<<"i: "<<i<<", aktmu: "<<violett<<aktmu<<schwarz<<endl;
		tm->tm_isdst=-1;
		strptime(inh.c_str(),aktmu,tm);
		// nehmen wir mal an, das Programm wird nach 2040 nicht mehr gebraucht
		if (tm->tm_year>=abjahr-1900 && tm->tm_year<140 && tm->tm_mon>=0 && tm->tm_mon<12 && tm->tm_mday>0 && tm->tm_mday<32)
			break;
	} // 	for(auto& aktmu:mu)
} // void BDTtoDate

// aufgerufen in wertschreib und dverarbeit
// vorher muessen zwerte und zlangt und zakb schon gefuellt sein
void hhcl::russchreib(insv &rus,const int aktc,string *usidp)
{
	hLog(violetts+Tx[T_russchreib_usid]+schwarz+*usidp);
	if (obverb) rus.ausgeb();
	// pruefPatID(aktc,rus);
	// hLog(violetts+Tx[T_pruefPatID_Standardfunktion]+schwarz);
	fuellpql();
	caus<<" "<<blau<<sqlft(My->DBS,&eingtm)<<": "<<gruen<<nname<<blau<<", "<<gruen<<vname<<schwarz<<blau<<",*"<<gruen<<sqlft(My->DBS,&gebtm)<<endl;
	for(size_t i=0;i<pql.size();i++) {
		// folgender Code aehnlich in usmod
		RS rspat(My,pql[i],aktc,ZDB);
		if (!rspat.obqueryfehler && rspat.result) { // 7.9. !obqueryfehler und !result vorgekommen
			hLog(gruens+Tx[T_Zahl]+blau+ltoan(rspat.result->row_count)+gruen+Txk[T_bei]+blau+pql[i]+schwarz);
			if (rspat.result->row_count==1){
				char ***cerg{0};
				if ((cerg=rspat.HolZeile())) {
					if (*cerg &&**cerg) {
					  hLog(Tx[T_Pat_id_fuer]+blaus+nname+", "+vname+": "+schwarz+**cerg);
						if (pid=="0" || pid.empty()) {
							pid=**cerg;
#ifdef mitsqlnachweis
							rus.hz("sql",pql[i]);
#endif
						}
	//					auswertpql(i,rus);
						rus.hz(("Pat_id_"+ltoan(i)).c_str(),pid);
						//						break;
					} // 					if (*cerg)
				} // 				if ((cerg=rspat.HolZeile()))
			} // 			if (rspat.result->row_count==1)
		} else {
			fLog(rots+Tx[T_Fehler_bei_sql]+violett+pql[i]+schwarz,1,oblog);
		} // 		if (!rspat.obqueryfehler) else
	} // 	for(size_t i=0;i<pql.size();i++)
	rus.hz("Nachname",nname);
	rus.hz("Vorname",vname);
	rus.hz("Titel",titel);
	rus.hz("NVorsatz",nvorsatz);
	rus.hz("GebDat",&gebtm);
	rus.hz("Geschlecht",sgschl);
	rus.hz("Pat_id",pid);
	rus.schreib(/*sammeln*/0,/*obverb*/obverb,/*idp*/usidp);
	usids<<*usidp;
	hLog(violetts+Txk[T_Ende]+Tx[T_russchreib_usid]+schwarz+*usidp);
} // void hhcl::russchreib

// schwache Funktion, kann ueberdeckt werden
void hhcl::usmod(const size_t aktc,svec *zlangtp/*=0*/,svec *zabkp/*=0*/,svec *zwertep/*=0*/,svec *zverfap/*=0*/,tm *eingtmp/*=0*/)
{
}

// 2 x in dverarbeit
void hhcl::usschluss(const size_t aktc)
{
	/*
	stringstream gebdp;
	gebdp<<ztacl(&gebtm,"%Y-%m-%d");
	caus<<gruen<<"vor zwerte.clear, gebdat: "<<rot<<gebdp.str()<<schwarz<<endl;
	for(size_t i=0;i<zwerte.size();i++) {
		caus<<i<<": "<<zwerte[i]<<endl;
	}
	*/
#ifndef usmoddanach
	// Normalfall
	usmod(aktc);
#endif
	zwerte.clear(); // fuer ergpql 
	zlangt.clear();
	zabk.clear();
	zverfa.clear();
	nname.clear();
	vname.clear();
	titel.clear();
	nvorsatz.clear();
	memset(&gebtm,0,sizeof gebtm);
	memset(&eingtm,0,sizeof eingtm);
	sgschl.clear();
	auftrschl.clear();
	pid="0";
	baktid="0";
	hinwid="0";
	erklid="0";
	kommid="0";
	usid.clear();
} // void hhcl::usschluss

// aufgerufen in dverarbeit
// vorher muessen zwerte und zlangt und zabk bzw. zverfa schon gefuellt sein
void hhcl::wertschreib(const int aktc,uchar *usoffenp,insv *rusp,string *usidp,insv *rpar, insv *rpneu, insv *rpnb, insv *rwe, insv *rbawep,insv *rhinwp,insv *rlep)
{
	if (*usoffenp) {
		// caus<<rusp->size()<<endl;
		russchreib(*rusp,aktc,usidp);
		*usoffenp=0;
	}
	if (!normbereich.empty()) {
		rpar->hz("NB",normbereich);
		rpnb->hz("NB",normbereich);
		normbereich.clear();
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
		rpar->schreib(/*sammeln*/0,/*obverb*/obverb,/*idp*/0,/*mitupd=*/1);
	} // 	if (rpar->size())
	if (rpneu->size()) {
		// rpneu->ausgeb();
		rpneu->schreib(/*sammeln*/0,/*obverb*/obverb,/*idp*/&pneuind);
		if (!pneuind.empty()) {
			rpnb->hz("PNEUID",pneuind);
			if (sgschl=="2") {
				rpnb->hz("uNg",uNw);
				rpnb->hz("oNg",oNw);
			} else {
				rpnb->hz("uNg",uNm);
				rpnb->hz("oNg",oNm);
			}
			rpnb->schreib(/*sammeln*/0,/*obverb*/obverb,/*idp*/&pnbid);
		}
	} // 	if (rpneu->size())

	if (rbawep) {
		if (!pnbid.empty()) {
			rbawep->hz("NBID",pnbid);
		}
		// z.B. "Labor 20101201 004634.dat"
		if (!qspez.empty()) {
			rbawep->hz("QSpez",qspez);
		}
		// Field Erklärung doesn't have a default value
		rhinwp->hz("Text",erklaerung);
		rhinwp->schreib(/*sammeln*/0,/*obverb*/obverb,/*idp*/&erklid,/*mitupd=*/0); // erklid s.u.
		//		rbawep->hz("Erklärung",erklaerung);
		if (!kommentar.empty()) {
			rhinwp->hz("Text",kommentar);
			rhinwp->schreib(/*sammeln*/0,/*obverb*/obverb,/*idp*/&kommid,/*mitupd=*/0);
			rbawep->hz("KommID",kommid);
			//			rbawep->hz("Kommentar",kommentar);
		}
		if (!auftrhinw.empty()) {
			rhinwp->hz("Text",auftrhinw);
			rhinwp->schreib(/*sammeln*/0,/*obverb*/obverb,/*idp*/&hinwid,/*mitupd=*/0);
			rbawep->hz("HinwID",hinwid);
//			rbawep->hz("AuftrHinw",auftrhinw);
		} // 						if (!auftrhinw.empty())
		if (memcmp(&abndat,&tmnull,sizeof abndat)) {
			rbawep->hz("AbnDat",&abndat);
		}
		if (rbawep->size()) {
			if (rbawep==rwe) {
				rbawep->hz("BaktID",baktid);
			} // 		if (rbawep==rwe)
			rbawep->hz("ErklID",erklid);
		}
		rbawep->schreib(/*sammeln*/0,/*obverb*/obverb,/*idp*/rbawep==rwe?0:&baktid,/*mitupd=*/1);
		rbawep=0;
		keimz=0; // "Labor 20101204 195050.dat"
		keimzda=0; // "Labor 20101210 034422.dat"
	} // 					if (rbawep)
	uNm.clear();
	oNm.clear();
	uNw.clear();
	oNw.clear();
	pnbid.clear();
	qspez.clear();
	erklaerung.clear();
	kommentar.clear();
	auftrhinw.clear();
	memset(&abndat,0,sizeof abndat);
	rlep->schreib(/*sammeln*/0,/*obverb*/obverb,/*idp*/0);
} // void hhcl::wertschreib

// aufgerufen in pvirtfuehraus; // return 0 = fertig
int hhcl::dverarbeit(const string& datei,string *datidp)
{
#define speichern
#ifdef speichern
	const size_t aktc=0;
#endif 
	string satzid,arztid,satzart;
	unsigned UsLfd=0;
	uchar lsatzart=0; // für Bedeutung von nachfolgendem 8100 (Satzlaenge): 1=8220 (Datenpaket-Header), 2=8221 (Datenpaketheader-Ende), 3=8201,8202 oder 8203 (Labor)
	uchar saetzeoffen=0, usoffen=0;
	vordverarb(aktc);
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
	reing.schreib(/*sammeln*/0,/*obverb*/obverb,/*idp*/datidp);
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

	mdatei mdat(datei,ios::in);
	if (mdat.is_open()) {
		// Zeichensatz ermitteln und verwenden
		uchar cp=0; // 0=utf-8, 1=iso-8859-15, 2=cp850
		// ä,ö,ü,Ä,Ö,Ü,ß,µ,` iso8859-15, cp850, iso8859-1
		const char* const sonder[]{"\xE4\xF6\xFC\xC4\xD6\xDC\xDF\xB5","\x84\x94\x81\x8E\x99\x9A\xE1\xE6\x80\x82\x83\x85\x86\x87\x88\x8A\x8C\x8D\x8F\xA0","\xB4"};
		string zeile,altz;
		struct tm berdat{0}; // Berichtsdatum
		uchar oblaborda=0, arztnameda=0, /*in (Vor)zeile kommt Wort Keimzahl vor*/keimz=0,/*die Keimzahl wurde schon eingesetzt*/keimzda=0;
		string labk,llang; // letzte Abkürzung, letzter Langtext
		string verf,abkue,lanr;
		float ldtvers{0}; // LDT-Version
		while(getline(mdat,zeile)) {
			string bzahl=zeile.substr(0,3);
			string cd,inh;
			if (zeile.size()>3) cd=zeile.substr(3,4);
			if (zeile.size()>7) {
				if (!cp) {
					for(unsigned p=0;p<sizeof sonder/sizeof *sonder;p++) {
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
			hLog(blaus+bzahl+" "+cd+" "+schwarz+inh);
			//			for(uchar i=0;i<inh.length();i++) { caus<<(int)(uchar)inh[i]<<" "; } caus<<endl;
#ifdef speichern

			if (cd=="8000") {
				usschluss(aktc);
				// 8220 Datenpaket-Header
				if (inh.substr(0,4)=="8220") {
					lsatzart=1;
					saetzeoffen=1;
					rsaetze.hz("Satzart",inh);
					rsaetze.hz("DatID",datid);
					UsLfd=0;
					// 8221 Datenpaket-Abschluss
				} else if (inh.substr(0,4)=="8221") {
					//					if (inh.length()>4) ... // trat nicht auf
					lsatzart=2;
						// russchreib z.B. "Labor 20120223 020708.dat"
					/* stringstream gebdp; gebdp<<ztacl(&gebtm,"%Y-%m-%d");
					caus<<rot<<"1 vor wertschreib, gebdat "<<violett<<gebdp.str()<<schwarz<<endl; */
					wertschreib(aktc,&usoffen,&rus,&usid,&rpar,&rpneu,&rpnb,&rwe,rbawep,&rhinw,&rle);
					// rle.schreib z.B. "Labor 20101201 004634.dat"
					//					satzid="0";
				// 8201 FA-Bericht, 8202 LG-Bericht, 8203 Mikrobiologiebericht
				} else {
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
						raerzte.schreib(/*sammeln*/0,/*obverb*/obverb,/*idp*/&arztid);
						rsaetze.hz("ArztID",arztid);
						rsaetze.schreib(/*sammeln*/0,/*obverb*/obverb,/*idp*/&satzid);
						arztnameda=0;
						saetzeoffen=0;
					}
					//					rus.zeig("0");
					if (usoffen) {
						// caus<<rus.size()<<endl;
						// z.B. "Labor 20091126 162200.dat"
									stringstream gebdp;
									gebdp<<ztacl(&gebtm,"%Y-%m-%d");
						russchreib(rus,aktc,&usid);
						usoffen=0;
					} // if (usoffen)
					satzart=inh;
					rus.hz("DatID",datid);
					rus.hz("SatzID",satzid);
					rus.hz("SatzArt",satzart);
					rus.hz("UsLfd",++UsLfd);
					usoffen=1;
				} // 				if (inh.substr(0,4)=="8220") else else
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
				} // 				switch (lsatzart)
				// 8410=Test-Ident, 8434=Verfahren
			} else if (cd=="8410" || cd=="8434") { 
				// russchreib z.B. "Labor 20091126 162829.dat"
				// z.B. "Labor 20101202 002036.dat"
				/*stringstream gebdp; gebdp<<ztacl(&gebtm,"%Y-%m-%d");
				caus<<rot<<"2 vor wertschreib, gebdat "<<violett<<gebdp.str()<<schwarz<<endl; */
				wertschreib(aktc,&usoffen,&rus,&usid,&rpar,&rpneu,&rpnb,&rwe,rbawep,&rhinw,&rle);
				// rle.schreib z.B. "Labor 20101202 011636.dat"
				if (cd=="8434") {
					if (rba.size()) {
						caus<<"rba.size(): "<<rba.size()<<endl;
						rba.schreib(/*sammeln*/0,/*obverb*/obverb,/*idp*/&baktid,/*mitupd=*/1);
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
					zverfa<<verf;
					rba.hz("Verf",inh);
				} else /*if (cd=="8410")*/ {
					abkue=inh;
					rwe.hz("Abkü",inh);
				} // 					if (cd=="8434") else if (cd=="8410")
				labk=inh;
				rpar.hz("Abkü",inh);
				rpneu.hz("Abkü",inh);
				rpar.hz("LabID",labind);
				rpneu.hz("LabID",labind);
			} else if (cd=="5001") {
				// z.B. 1b01042005.ld0
				rle.schreib(/*sammeln*/0,/*obverb*/obverb,/*idp*/0);
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
				// Langtext
			} else if (cd=="8411") {
				llang=inh;
				rbawep->hz("Langtext",inh);
				rpar.hz("Langtext",inh);
				rpneu.hz("Langtext",inh);
			} else if (cd=="8428") {
				if (!rbawep) cerr<<rot<<"4 Fehler rbawep 0"<<schwarz<<endl;
				rbawep->hz("KuQu",inh);
			} else if (cd=="8430") {
				if (!rbawep) cerr<<rot<<"3 Fehler rbawep 0"<<schwarz<<endl;
				rbawep->hz("Quelle",inh);
			} else if (cd=="8431") {
				if (!rbawep) cerr<<rot<<"2 Fehler rbawep 0"<<schwarz<<endl;
				if (qspez.empty()) qspez=inh;
				else {
					qspez+="\r\n";
					qspez+=inh;
				}
			} else if (cd=="8432") { // Abnahmedatum
				BDTtoDate(inh,&abndat,2000,ldtvers>1014);
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
				// caus<<"llang: "<<llang<<", fuege zu zwerte hinzu: "<<inh<<endl;
				// bei einer von zwei GFR kein Wiederfinden in laborneu Pat. 53919 am 4.7.12
				if (strncasecmp(llang.c_str(),"gfr",3) && strncasecmp(llang.c_str(),"sammel",6) && strncasecmp(llang.c_str(),"körper",6)) {
					if (zwerte.size()<9) // 8erlei, davon mindestens 5 richtige
					zwerte<<inh; 
					zlangt<<llang;
					zabk<<labk;
				} else {
//					caus<<rot<<"aussortiert!"<<schwarz<<endl;
				}
			} else if (cd=="8421") {
        string keinh;
				keinh=(inh.find("ml/min/1.73")==string::npos?inh:"ml/min/1.73m²");
				if (rbawep) {
					rbawep->hz("Einheit",keinh);
				}
				rpar.hz("Einheit",keinh);
				rpneu.hz("Einheit",keinh);
			} else if (cd=="8422") {
				rwe.hz("Grenzwerti",inh);
			} else if (cd=="8301") {
				BDTtoDate(inh,&eingtm,2000,ldtvers>1014);
				if (!memcmp(&minnachdat,&tmnull,sizeof minnachdat)|| difftime(mktime(&eingtm),mktime(&minnachdat))<0) {
					memcpy(&minnachdat,&eingtm,sizeof minnachdat);
				}
				if (!memcmp(&maxnachdat,&tmmax,sizeof maxnachdat)|| difftime(mktime(&eingtm),mktime(&maxnachdat))>0) {
					memcpy(&maxnachdat,&eingtm,sizeof maxnachdat);
				}
				rus.hz("Eingang",&eingtm);
			} else if (cd=="8302") {
				BDTtoDate(inh,&berdat,2000,ldtvers>1014);
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
				BDTtoDate(inh,&gebtm,1900,ldtvers>1014);
			} else if (cd=="3110") {
				sgschl=(inh=="W"?"2":inh=="M"?"1":inh=="X"?"3":inh);
			} else if (cd=="3104") {
				titel=inh;
			} else if (cd=="3100") {
				nvorsatz=inh;
			} else if (cd=="9212") {
				rsaetze.hz("VersionSatzb",inh);
				ldtvers=atof(inh.substr(3).c_str()); // LDT
//				caus<<"ldtvers:       "<<ldtvers<<endl;
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
				rlab.schreib(/*sammeln*/0,/*obverb*/obverb,/*idp*/&labind);
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
				rlab.schreib(/*sammeln*/0,/*obverb*/obverb,/*idp*/&labind);
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
						fLog(rots+Tx[T_Normbereich_ohne_bis]+violett+nbn+schwarz,1,1);
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
				BDTtoDate(inh,&erstd,2000,ldtvers>1014);
				rsaetze.hz("Erstellungsdatum",&erstd);
			} else if (cd=="9202") {
				rsaetze.hz("Gesamtlänge",inh);
				// update rsaetze.schreib(/*sammeln*/0,/*obverb*/1,/*idp*/0);
				rsaetze.ergaenz(satzid,/*sammeln*/0,/*obverb*/obverb,/*idp*/0);
			} else {
				rfe.hz("DatID",datid);
				rfe.hz("Kennung",cd);
				rfe.hz("Inhalt",inh);
				// z.B. "Labor 20120724 072122.dat"
				rfe.schreib(/*sammeln*/0,/*obverb*/obverb,/*idp*/0);
			}
			altz=zeile;
#endif 
		} // 		while(getline(mdat,zeile))
		/* stringstream gebdp; gebdp<<ztacl(&gebtm,"%Y-%m-%d");
		caus<<rot<<"3 vor wertschreib, gebdat "<<violett<<gebdp.str()<<schwarz<<endl; */
		wertschreib(aktc,&usoffen,&rus,&usid,&rpar,&rpneu,&rpnb,&rwe,rbawep,&rhinw,&rle);
		usschluss(aktc);
		reing.hz("codepage",cp);
		reing.hz("fertig",1);
		reing.ergaenz(datid,/*sammeln*/0,/*obverb*/obverb,/*idp*/0);
		return reing.rsp->fnr;
	} // 	if (mdat.is_open())
	return 1;
} // void hhcl::dverarbeit

void hhcl::prueftbl()
{
	const size_t aktc{0};
	if (!My) initDB();
	prueflyhinw(My, aktc, obverb, oblog, /*direkt*/0);
	prueflyplab(My, aktc, obverb, oblog, /*direkt*/0);
	prueflyparameter(My, aktc, obverb, oblog, /*direkt*/0);
	prueflypneu(My, aktc, obverb, oblog, /*direkt*/0);
	prueflypnb(My, aktc, obverb, oblog, /*direkt*/0);
	prueflydat(My, aktc, obverb, oblog, /*direkt*/0);
	prueflyfehlt(My, aktc, obverb, oblog, /*direkt*/0);
	prueflyaerzte(My, aktc, obverb, oblog, /*direkt*/0);
	prueflysaetze(My, aktc, obverb, oblog, /*direkt*/0);
	prueflyus(My, aktc, obverb, oblog, /*direkt*/0);
	prueflybakt(My, aktc, obverb, oblog, /*direkt*/0);
	prueflyleist(My, aktc, obverb, oblog, /*direkt*/0);
	prueflywert(My, aktc, obverb, oblog, /*direkt*/0);
	prueflypgl(My, aktc, obverb, oblog, /*direkt*/0);
////	My->usedb(dbq,aktc);
//	ZDB=1;
	struct {
		const string name;
		string sql;
	} vpaare[]{ {
		// soll gleich lauten wie u:\programmierung\dateielesen\formular.frm, backslashes hier verdppeln!
		"labor2a",
			"SELECT Pat_id, eingang Zeitpunkt, befart FertigStGrad, w.Abkü, w.langtext Langtext"
        ",TRIM(IF(w.Abkü='ALBUM' AND Wert='' AND k.Text LIKE 'nicht berechenb%','< 20',IF(TRIM(Wert) REGEXP '^[0-9]+\\\\,?[0-9]*$', REPLACE(Wert,',','.'),Wert))) Wert"
				",w.Einheit,w.Grenzwerti "
        ",CONCAT(IF(e.text IS NULL OR e.text RLIKE '^:[ /\\\\*:]*$','',IF(e.text RLIKE '^:[ /\\\\*]*:'"
        " ,CONCAT(MID(e.text,LOCATE(':',e.text,2)+1),';'),IF(e.text='.','',IF(e.text='','',CONCAT(e.text,';'))))),IF(ISNULL(k.text),'',k.text)) Kommentar/*, n.id*/ "
				",n.NB, uNg"
				",IF(w.abkü='LDL' AND w.einheit='mg/dl','100',oNg) oNg"
				",l.Labor, Pfad, d.DatID "
				",p.Gruppe, p.Reihe,2 Qu "
				"FROM `"+tlyus+"` u "
				"LEFT JOIN `"+tlywert+"` w ON w.usid=u.id "
				"LEFT JOIN `"+tlyhinw+"` e ON e.id=w.erklid "
				"LEFT JOIN `"+tlyhinw+"` k ON k.id=w.kommid "
				"LEFT JOIN `"+tlypnb+"` n ON n.id=w.nbid "
				"LEFT JOIN `"+tlysaetze+"` s ON u.satzid=s.satzid "
				"LEFT JOIN `"+tlydat+"` d ON d.datid=s.datid "
				"LEFT JOIN `"+tlyplab+"` l ON l.id=s.labid "
        "LEFT JOIN laborparameter p ON p.abkü=w.abkü AND p.einheit=IF(w.einheit IN ('','\\'kA\\''),'kA',w.einheit)"
        "      AND p.id = (SELECT id FROM laborparameter WHERE abkü=w.`Abkü` AND einheit=IF(w.einheit IN ('','\\'kA\\''),'kA',w.Einheit) ORDER BY gruppe DESC, reihe DESC LIMIT 1)"
        "WHERE ((wert<>'' AND wert IS NOT NULL) OR (e.text<>'' AND e.text IS NOT NULL))"
//				"LEFT JOIN laborparameter p ON p.abkü=CAST(w.abkü AS CHAR CHARSET latin1) COLLATE latin1_german2_ci AND "
//				"p.einheit=CAST(IF(w.einheit='','kA',w.einheit) AS CHAR CHARSET latin1) COLLATE latin1_german2_ci "
	}, {
		"labor2aNachweis",
			"SELECT d.Pfad,d.Datid,s.Satzid,u.id USID,w.id,pat_id_0,pat_id_1,pat_id_2,pat_id_3,pat_id_4,pat_id_5,pat_id_6,pat_id_7,pat_id_laborneu"
				",Pat_id, eingang Zeitpunkt, befart FertigStGrad, w.Abkü, w.langtext Langtext"
				",TRIM(IF(TRIM(Wert) REGEXP '^[0-9]+\\,?[0-9]*$', REPLACE(Wert,',','.'),Wert)) Wert"
				",w.Einheit "
				",CONCAT(IF(ISNULL(e.text) OR e.text RLIKE '^:[ /\\*:]*$','',IF(e.text RLIKE '^:[ /\\*]*:',CONCAT(MID(e.text,LOCATE(':',e.text,2)+1),';')"
				",IF(e.text='.','',IF(e.text='','',CONCAT(e.text,';'))))),IF(ISNULL(k.text),'',k.text)) Kommentar "
				",n.NB, uNg"
				",IF(w.abkü='LDL' AND w.einheit='mg/dl','100',oNg) oNg"
				",u.Auftragsnummer, u.Auftragsschlüssel, l.Labor "
				",p.Gruppe, p.Reihe,2 Qu "
				"FROM `"+tlyus+"` u "
				"LEFT JOIN `"+tlywert+"` w ON u.id=w.usid "
				"LEFT JOIN `"+tlyhinw+"` e ON w.erklid=e.id "
				"LEFT JOIN `"+tlyhinw+"` k ON w.kommid=k.id "
				"LEFT JOIN `"+tlypnb+"` n ON w.nbid=n.id "
				"LEFT JOIN `"+tlysaetze+"` s ON u.satzid=s.satzid "
				"LEFT JOIN `"+tlydat+"` d ON s.datid=d.datid "
				"LEFT JOIN `"+tlyplab+"` l ON s.labid=l.id "
				"LEFT JOIN laborparameter p ON p.abkü=w.abkü AND "
				"p.einheit=IF(w.einheit='','kA',w.einheit)"
//				"LEFT JOIN laborparameter p ON p.abkü=CAST(w.abkü AS CHAR CHARSET latin1) COLLATE latin1_german2_ci AND "
//				"p.einheit=CAST(IF(w.einheit='','kA',w.einheit) AS CHAR CHARSET latin1) COLLATE latin1_german2_ci "
	}, {
		"labor2bakt",
			"SELECT Verf,KuQu,Quelle,QSpez,if(isnull(k.text),'',k.text) Kommentar, if(isnull(e.text),'',e.text) Erkl"
				",if(isnull(h.text),'',h.text) Hinw, Keimzahl,abrd,Auftragsnummer"
				",Auftragsschlüssel,Eingang,Berichtsdatum,Pat_id,nachname,vorname,GebDat,Zeitpunktlaborneu,Pat_id_Laborneu "
				"FROM `"+tlybakt+"` b "
				"LEFT JOIN `"+tlyus+"` u ON u.id=b.usid "
				"LEFT JOIN `"+tlyhinw+"` k ON b.kommid=k.id "
				"LEFT JOIN `"+tlyhinw+"` e ON b.erklid=e.id "
				"LEFT JOIN `"+tlyhinw+"` h ON b.hinwid=h.id "
	},
	};
	for(size_t i=0;i<sizeof vpaare/sizeof *vpaare;i++) {
		RS delv(My,"DROP VIEW IF EXISTS `"+vpaare[i].name+"`;",aktc,ZDB);
		RS view(My,"CREATE OR REPLACE ALGORITHM=UNDEFINED DEFINER=`"+muser+"`@`%` SQL SECURITY DEFINER VIEW `"+vpaare[i].name+"` AS "+
				vpaare[i].sql,aktc,ZDB);
	}
} // void hhcl::prueftbl

void hhcl::pvirtnachrueckfragen()
{
} // void hhcl::pvirtnachrueckfragen

// wird aufgerufen in lauf
void hhcl::pvirtfuehraus()
{ //ω
	hLog(violetts+Txk[T_pvirtfueraus]+schwarz);
	auto altZDB{ZDB};
	//	ZDB=1;
	const size_t aktc{0};
	unsigned long verarbeitet{0};
	if (rzf) tabnamen(); // nach rueckfragen
	if (nurpruefdb) {
		prueftbl();
	} else if (!loeschalle && !loeschunvollst && umben.empty()) {
		if (!nurnachb && !nachbneu && !nurusmod && !pruefauft) {
			pruefverz(fertigvz,obverb,oblog);
			systemrueck("Q="+ldatvz+"/;P="+fertigvz+";find /opt/turbomed/LaborStaber/DFUE/Update_Staber/LDTArchiv -iname '*.ldt' -newer \"$(printf $P/;ls -t $P|head -n1)\"|while read U;do cp \"$U\" \"$Q\"; find /DATA/Patientendokumente/ -mindepth 1 -maxdepth 1 -type d -regex '.*/[^/]+Labor$' -exec cp \"$U\" {} \\; ; done;",2);
			sleep(2);
			systemrueck("chmod --reference '"+ldatvz+"' '"+fertigvz+"'");
			systemrueck("chown --reference '"+ldatvz+"' '"+fertigvz+"'");
			svec lrue;
			systemrueck("find "+ldatvz+" -maxdepth 1 -type f \\( -iname '1b*.ld*' -or -iname '*.ldt' -or -iname 'x*.ld*' -or -iname 'labor*.dat' \\) -printf '%TY%Tm%Td%TH%TM%TS\t%p\n' "+string(obverb?"":"2>/dev/null")+"|sort|cut -f2", obverb,oblog,&lrue,/*obsudc=*/0);
			//	systemrueck("find "+ldatvz+" -type f -iname '*' "+string(obverb?"":" 2>/dev/null")+"| sort -r", obverb,oblog,&lrue,/*obsudc=*/0);
			fLog(blaus+Tx[T_Dateien_gefunden]+schwarz+ltoan(lrue.size()),1,oblog);
			// prueftbl soll nur aufgerufen werden, wenn eine neue Datei da ist oder wenn die Vorsilbe ueber die Befehlszeile angegeben wurde
			auto woher{opn.omap.find("vorsil")->second->woher};
			//			caus<<"woher: "<<(int)woher<<endl;
			if (lrue.size()||woher==3/*vorclvors!=nachclvors*/) {
				prueftbl();
			}
			for(size_t i=0;i<lrue.size();i++) {
				string *aktl{&lrue[i]};
				//		caus<<i<<": "<<blau<<lrue[i]<<schwarz<<endl;
				/*//
					struct stat pfst{0};
					if (!lstat(aktl->c_str(),&pfst)) {
					pthread_mutex_lock(&timemutex);
					memcpy(&minnachdat,localtime(&pfst.st_mtime),sizeof minnachdat);
					pthread_mutex_unlock(&timemutex);
					}
				 */
				// wenn Datei schon angefangen wurde zu einzulesen (fertig<>1), dann dieses loeschen
				// RS loeschvor(My,"DELETE FROM `"+tlydat+"` WHERE pfad="+sqlft(My->DBS,*aktl)+" AND fertig<>1",aktc,ZDB);
				// 16.9.18: Namen sollen eindeutig sein, dafuer koennen die Pfade mal umsortiert werden, ohne dass gleich alle Dateien neu eingelesen werden
				RS loeschvor(My,"DELETE FROM `"+tlydat+"` WHERE name="+sqlft(My->DBS,base_name(*aktl))+" AND fertig<>1",aktc,ZDB);
				// der evtl. Fund folgender Suche muss also fertig==1 haben
				RS rsfertig(My,"SELECT fertig,name,datid FROM `"+tlydat+"` l WHERE name ="+sqlft(My->DBS,base_name(*aktl))
						/*+" AND pfad = "+sqlft(My->DBS,*aktl)*/,aktc,ZDB);
				if (!rsfertig.obqueryfehler) {
					uchar obverschieb{0};
					char ***cerg{0};
					if (!(cerg=rsfertig.HolZeile())||!*cerg) {
						// caus<<i<<": "<<blau<<*aktl<<schwarz<<endl;
						// yLog(-1,oblog,0,0,"%s%i%s/%s%i%s%s %s%s%s ...",blau,i,schwarz,blau,lrue.size(),schwarz,Txk[T_Datei],violett,aktl->c_str(),schwarz,blau);
						yLog(obverb+1,oblog,0,0,"%s%i%s/%s%i%s%s %s%s%s ...",blau,i+1,schwarz,blau,lrue.size(),
								schwarz,Txk[T_Datei],violett,aktl->c_str(),schwarz,blau);
						if (!dverarbeit(*aktl,&datid)) {
							verarbeitet++;
							obverschieb=1;
						}
						yLog(obverb+1,oblog,0,0,"%s%i%s/%s%i%s%s %s%s%s %s: %s%s%s",blau,i+1,schwarz,blau,lrue.size(),
								schwarz,Txk[T_Datei],violett,aktl->c_str(),schwarz,Tx[T_fertig_mit_datid],blau,datid.c_str(),schwarz);
						if (dszahl && verarbeitet==dszahl) break;
					} else { // 				if (!rsfertig.HolZeile())
						// wenn Datei schon eingetragen, dann auch verscheiben
						fLog(rots+Txk[T_datei]+blau+*aktl+rot+Tx[T_war_schon_in]+blau+dbq+rot+Tx[T_eingetragen_]+blau+"\n"+rsfertig.sql+
								rot+"), datid: "+blau+cjj(cerg,2)+schwarz,1,oblog);
						obverschieb=1;
					}        // 				if (!rsfertig.HolZeile()) else
					if (obverschieb && fertigvz!=ldatvz) {
						if (rename(aktl->c_str(),(fertigvz+'/'+base_name(*aktl)).c_str())) {
							fLog(rots+Tx[T_Fehler_beim_Verschieben_von]+blau+*aktl+rot+Tx[T_nach_]+blau+fertigvz+
									schwarz+": "+rot+strerror(errno)+schwarz,1,1);
						}
					} // 					if (obverschieb)
				} // rsfertig.obqueryfehler
			} // 			for(size_t i=0;i<lrue.size();i++)
		} // 		if (!nurnachb && !nachbneu && !nurusmod && !pruefauft) {
		if (nurnachb || nachbneu|| nurusmod || verarbeitet) nachbearbeit(aktc,nurusmod);
	} // 		else if (!loeschalle && !loeschunvollst && umben.empty())
	fLog(blaus+Tx[T_fertig]+schwarz,1,oblog);
	ZDB=altZDB;
} // void hhcl::pvirtfuehraus  //α

int hhcl::vverarbeit(const string& datei)
{
	mdatei mdat(datei,ios::in);
	if (mdat.is_open()) {
		// Zeichensatz ermitteln und verwenden
		uchar cp=0; // 0=utf-8, 1=iso-8859-15, 2=cp850
		// ä,ö,ü,Ä,Ö,Ü,ß,µ,` iso8859-15, cp850, iso8859-1
		const char* const sonder[]{"\xE4\xF6\xFC\xC4\xD6\xDC\xDF\xB5","\x84\x94\x81\x8E\x99\x9A\xE1\xE6\x80\x82\x83\x85\x86\x87\x88\x8A\x8C\x8D\x8F\xA0","\xB4"};
		string zeile,altz;
//		struct tm berdat{0}; // Berichtsdatum
		if (!My) initDB();
		string auftr,nnam,vnam,aufnr;
		tm gebvtm{0},eingvtm{0};
		float ldtvers{0};
		while(getline(mdat,zeile)) {
			string bzahl=zeile.substr(0,3);
			string cd,inh;
			if (zeile.size()>3) cd=zeile.substr(3,4);
			if (zeile.size()>7) {
				if (!cp) {
					for(unsigned p=0;p<sizeof sonder/sizeof *sonder;p++) {
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
				if (cd=="3101") {
					nnam=inh;
				} else if (cd=="8311") {
					auftr=inh;
				} else if (cd=="3102") {
					vnam=inh;
				} else if (cd=="9212") {
					ldtvers=atof(inh.substr(3).c_str()); // LDT
//					caus<<"ldtvers:       "<<ldtvers<<endl;
				} else if (cd=="8310") { // Auftragsnummer
					aufnr=inh;
				} else if (cd=="3103") {
					BDTtoDate(inh,&gebvtm,1900,ldtvers>1014);
				} else if (cd=="8301") {
					BDTtoDate(inh,&eingvtm,2000,ldtvers>1014);
				} else if (cd=="8000") {
					if (!auftr.empty()) {
						const string vorsp="SELECT distinct Nachname,Vorname,GebDat,Auftragsnummer,Auftragsschlüssel,Pfad,Eingang FROM `labor2aNachw` l WHERE ";
						const string sql[]{
							"Nachname="+sqlft(My->DBS,nnam)+" AND Vorname="+sqlft(My->DBS,vnam)
								+ " AND GebDat="+sqlft(My->DBS,&gebvtm)
								+ " AND Eingang="+sqlft(My->DBS,&eingvtm)
								+" AND "+(aufnr.empty()?"isnull(auftragsnummer)":"auftragsnummer='"+aufnr+"' ")
								+" AND auftragsschlüssel='"+auftr+"'",
								"Eingang="+sqlft(My->DBS,&eingvtm)+" AND "+(aufnr.empty()?"isnull(auftragsnummer)":"auftragsnummer='"+aufnr+"' ")+
									"AND auftragsschlüssel='"+auftr+"'",
								"Eingang="+sqlft(My->DBS,&eingvtm)+" AND auftragsschlüssel='"+auftr+"'"
						};
						unsigned fzahl{0}, iru{0};
						for(;iru<sizeof sql/sizeof *sql;iru++) {
							char ***cerg{0};
							RS vgl(My,vorsp+sql[iru],0,ZDB);
							if (vgl.obqueryfehler) {
								cerr<<rot<<"Fehler bei "<<gruen<<vgl.sql<<schwarz<<endl;
							} else {
								while (cerg=vgl.HolZeile(),cerg?*cerg:0) {
									fzahl++;
									if (nnam=="Krämer")
										caus<<blau<<nnam<<" gefunden bei "<<vgl.sql<<schwarz<<endl;
									//									caus<<setw(30)<<cjj(cerg,0)<<"|"<<setw(30)<<cjj(cerg,1)<<schwarz<<"|"<<setw(19)<<cjj(cerg,2)<<"|"<<schwarz<<endl;
									stringstream gebdp;
									gebdp<<ztacl(&gebvtm,"%Y-%m-%d");
									stringstream eingtmp;
									eingtmp<<ztacl(&eingvtm,"%Y-%m-%d");
									//// zp=buf;
									if ((cjj(cerg,0)!=nnam||cjj(cerg,1)!=vnam||(cjj(cerg,2)!=gebdp.str()&&!(!strcmp(cjj(cerg,2),"0000-01-00")&&gebdp.str()=="-1-12-31")))
											&&!(!strcmp(cjj(cerg,0),"")&&!strcmp(cjj(cerg,1),"")&&cjj(cerg,2)==gebdp.str())
										 ) {
										caus<<violett<<setw(24)<<nnam<<"|"<<violett<<setw(17)<<vnam<<schwarz<<"|"<<violett<<setw(10)<<
											gebdp.str()<<"|"<<violett<<setw(8)<<aufnr<<'|'<<auftr<<'|'<<eingtmp.str()<<'|'<<schwarz<<endl;
										caus<<blau<<setw(24)<<cjj(cerg,0)<<"|"<<blau<<setw(17)<<cjj(cerg,1)<<schwarz<<"|"<<blau<<setw(10)<<
											cjj(cerg,2)<<"|"<<blau<<setw(8)<<cjj(cerg,3)<<'|'<<cjj(cerg,4)<<'|'<<cjj(cerg,6)<<'|'<<schwarz<<cjj(cerg,5)<<endl;
										caus<<gruen<<vgl.sql<<schwarz<<endl;
									} // if ((cjj(cerg,0)
								} // 							while (cerg=vgl.HolZeile())
								if (fzahl) break;
							} // 						if (vgl.obqueryfehler)
						} // 						for(;iru<sizeof sql/sizeof *sql;iru++)
						if (iru==sizeof sql/sizeof *sql) if (!fzahl) {
							caus<<rot<<"Nix gefunden bei "<<gruen<<sql[iru-1]<<schwarz<<endl;
						}
						nnam.clear();
						vnam.clear();
						aufnr.clear();
						memset(&gebvtm,0,sizeof gebvtm);
						memset(&eingvtm,0,sizeof eingvtm);
						auftr.clear();
					} // 					if (!auftr.empty())
				} // 				} else if (cd=="8000")
				if (cd.empty()||!cd[0]) continue;
				// sonst keinen Fall von Zeilenumbruch gefunden
				if (cd=="8311" ||cd=="3101" ||cd=="3102"||cd=="3103"||cd=="8000")
					hLog((cd=="8000"?gruens:blaus)+bzahl+" "+cd+" "+schwarz+inh);
				//			for(uchar i=0;i<inh.length();i++) { caus<<(int)(uchar)inh[i]<<" "; } caus<<endl;
		}
	} // 		while(getline(mdat,zeile))
	} // 	if (mdat.is_open())
	return 0;
}

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
	const int altobverb{obverb};
	//	obverb=1;
	hLog(violetts+Txk[T_virtlieskonfein]+schwarz);
	//nachclvors=vorsl;
	hcl::virtlieskonfein(); //ω
	hLog(violetts+Txk[T_Ende]+Txk[T_virtlieskonfein]+schwarz); //α
	fLog(Tx[T_Namensanfang_aller_Einlesetabellen]+blaus+vorsl+schwarz,1,oblog);
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
	return hhi.retu;
} // int main 

void hhcl::virttesterg()
{
} //ω
