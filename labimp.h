#define DPROG "labimp"
// fuer verschiedene Sprachen //α
enum T_      
{
	T_virtVorgbAllg,
	T_pvirtVorgbSpeziell,
	T_virtMusterVorgb,
	T_pvirtvorrueckfragen,
	T_virtrueckfragen,
	T_Fehler_beim_Pruefen_von,
	T_Fuege_ein, //ω
	T_prueflydat,
	T_prueflyleist,
	T_prueflypgl,
	T_prueflyplab,
	T_prueflypnb,
	T_prueflypneu,
	T_prueflysaetze,
	T_prueflyus,
	T_prueflywert,
	T_prueflybakt,
	T_eindeutige_Identifikation,
	T_Pfadname,
	T_Name_der_eingelesenen_Labordatei_ohne_Endung,
	T_Einlesezeitpunkt,
	T_ob_Einlesen_fertig,
	T_LaborEinlesungen,
	T_Bezug_auf_LaborUS,
	T_8410_Test_Ident_Turbomed,
	T_8434,
	T_5001_GNR_Turbomed,
	T_8406,
	T_5005,
	T_8614_Abrechnung_durch_1_Labor_2_Einweiser,
	T_LaborLeistungen,
	T_Laborpgl,
	T_Laborbakt,
	T_Laborfehlt,
	T_laborxpneu,
	T_laborparameter,
	T_ist_identisch_mit_laborxpneu,
	T_Zeitpunkt_der_Ergaenzung,
	T_8428_Probenmaterial_Ident_Turbomed,
	T_8430_Probenmaterial_Bezeichnung_Turbomed,
	T_8431_Probenmaterial_Spezifikation_Turbomed,
	T_8432_Abnahmedatum_Turbomed,
	T_8480_Ergebnistest_Turbomed,
	T_8300_maximale_Laenge_36,
	T_Laborplab,
	T_Labornb,
	T_Bezug_auf_laborxpneu,
	T_1_Mann_2_Frau_3_unbek_4_Knabe_5_Maedchen_0_Name_fehlt_9_beide,
	T_Eingangsdatum_im_Labor,
	T_untere_Normgrenze,
	T_obere_Normgrenze,
	T_Normbereich,
	T_Haeufigkeit_eines_Laborparameters,
	T_laborxus_id_des_ersten_Eintrags,
	T_Laborneu,
	T_8410_maximale_Laenge_8,
	T_8411_maximale_Laenge_40,
	T_8421_maximale_Laenge_12,
	T_Bezug_auf_laborxplab_id,
	T_Bezug_auf_laborgruppen_laborgruppe,
	T_Laborsaetze,
	T_zum_Bezug_fuer_LaborUS,
	T_Bezug_zu_LaborDat,
	T_8000_Satzart_Turbomed,
	T_8100_Satzlaenge_Turbomed,
	T_8100_Satzlaenge_Turbomed_nach_8221_in_Feld_8000,
	T_9212_Version_der_Satzbeschreibung_Turbomed,
	T_201_Arztnummer_Turbomed,
	T_203_Arztname_Turbomed,
	T_205_Strasse_der_Praxis_Turbomed,
	T_211_Ausfuehrender_Arzt,
	T_212_LANR,
	T_215_PLZ_der_Praxis_Turbomed,
	T_216_Ort_der_Praxis_Turbomed,
	T_8320_Labor,
	T_8321_Strasse_der_Laboradresse_Turbomed,
	T_8322_PLZ_der_Laboradresse_Turbomed,
	T_8323_Ort_der_Laboradresse_Turbomed,
	T_101_KBV_Pruefnummer_Turbomed,
	T_9106_verwendeter_Zeichensatz_Turbomed,
	T_8312_Kundenarztnummer_Turbomed,
	T_9103_Erstellungsdatum_Turbomed,
	T_9202_Gesamtlaenge_des_Datenpaketes_Turbomed,
	T_Laborus,
	T_Bezug_auf_LaborWert,
	T_Bezug_auf_LaborXSaetze,
	T_8310_Anforderungsident_Turbomed,
	T_8311_Anforderungsnr_d_Labors_Turbomed,
	T_8302_Berichtsdatum,
	T_8401_Befundart_Turbomed__Fertigstellungsgrad_EEndbefund_T__Teilbefund,
	T_8609_Abrechnungstyp_Kasse_Privat_X_anderer_RE_Einsender_Turbomed,
	T_8403_Gebuehrenordnung_Turbomed,
	T_8615_Auftraggeber_LANR,
	T_8405_Patienteninformation_Turbomed,
	T_8407_Geschlecht_Turbomed,
	T_8490_Auftragsbezogene_Hinweise_Turbomed,
	T_Ursprung_der_Pat_id_E__erwogene_Pat_id_su_L__vergleich_mit_ueber_Turbomed_eingelesenem_Labor,
	T_erwogene_Pat_id_mit_gleichem_Vornamen_Nachnamen_und_Geburtstag,
	T_erwogene_Pat_id_mit_gleichem_Vornamen_und_Nachnamen,
	T_erwogene_Pat_id_mit_gleichem_Geburtstag,
	T_erwogene_Pat_id_mit_gleichem_Geburtstag_und_zeitlich_passender_Behandlung,
	T_erwogene_Pat_id_mit_gleichem_Geburtstag_und_zeitlich_passendem_Labor,
	T_Pat_ids_von_in_Laborneu_zuordnbaren_Patienten,
	T_Zeitpunkt_der_Untersuchung_die_in_Laborneu_zugeordnet_wurde,
	T_Zahl_der_verglichenen_Parameter,
	T_Zahl_der_infragekommenden_Patienten,
	T_Laborwerte_die_zur_Zuordnung_gefuehrt_haben,
	T_Datum_zu_dem_Datensatz_zuletzt_verglichen_wurde,
	T_Affected_Number_Zahl_der_zugehoerigen_Datensaetze_in_Laborneu,
	T_Laborwert,
	T_8420_Ergebniswert_Turbomed,
	T_8422_Grenzwertindikator_Turbomed,
	T_8418_Teststatus_Turbomed,
	T_Bezug_zu_laborxplab_id,
	T_8411_Testbezeichnung_Turbomed,
	T_ldvz_k,
	T_ldvz_l,
	T_Verzeichnis_der_Faxdateien,
	T_vv_k,
	T_vv_l,
	T_tr_k,
	T_tr_l,
	T_la_k,
	T_la_l,
	T_loescht_alle_Tabellen,
	T_Loesche_alle_Tabellen_und_fange_von_vorne_an,
	T_Entleert_alle_Tabellen_und_faengt_von_vorne_an,
	T_Kennung,
	T_Inhalt,
	T_prueflyfehlt,
	T_Bezug_auf_lyplab,
	T_Abkuerzung_mit_gleicher_Bedeutung_gleicher_Einheit_und_gleichem_Normbereich,
	T_8421,
	T_LaborParameter,
	T_prueflyparameter,
	T_Reihenfolge_innerhalb_der_Gruppe,
	T_unterer_Normwert_maennlich,
	T_oberer_Normwert_maennlich,
	T_unterer_Normwert_weiblich,
	T_oberer_Normwert_weiblich,
	T_Normbereich_aus_lywert,
	T_Aktualisierungszeitpunt,
	T_Ordnungsnummer_der_Dateiuebertragung,
	T_fehlend,
	T_Bezug_auf_LaborBakt,
	T_pruefPatID_leere_Funktion,
	T_MAX //α
}; // enum T_ //ω
const string fertiguvz="fertig";
//α
class hhcl:public dhcl
{
 private: //ω
	const static string vorsil; /*=labory*/
	string tlydat=vorsil+"dat";
	string tlyleist=vorsil+"leist";
	string tlypgl=vorsil+"pgl";
	string tlyplab=vorsil+"plab";
	string tlypnb=vorsil+"pnb";
	string tlypneu=vorsil+"pneu";
	string tlysaetze=vorsil+"saetze";
	string tlyus=vorsil+"us";
	string tlywert=vorsil+"wert";
	string tlybakt=vorsil+"bakt";
	string tlyfehlt=vorsil+"fehlt";
	string tlyparameter=vorsil+"parameter";
	string labind;
	ic_cl *icp[2];
 protected: //α
	string p1;
	int p2;
	string p3;
	uchar oblista=0;
	uchar vonvorne=0;
	uchar entleer=0;
	uchar loeschalle=0;
	long listz=30; //ω
  string ldatvz;   // Verzeichnis der Labordateien
 public: //α //ω
 private: //α //ω
	void prueflydat(DB *My, const string& tlydat, const int obverb, const int oblog, const uchar direkt=0);
	void prueflyleist(DB *My, const string& tlyleist, const int obverb, const int oblog, const uchar direkt=0);
	void prueflypgl(DB *My, const string& tlypgl, const int obverb, const int oblog, const uchar direkt=0);
	void prueflyplab(DB *My, const string& tlyplab, const int obverb, const int oblog, const uchar direkt=0);
	void prueflypnb(DB *My, const string& tlypnb, const int obverb, const int oblog, const uchar direkt=0);
	void prueflypneu(DB *My, const string& tlypneu, const int obverb, const int oblog, const uchar direkt=0);
	void prueflysaetze(DB *My, const string& tlysaetze, const int obverb, const int oblog, const uchar direkt=0);
	void prueflyus(DB *My, const string& tlyus, const int obverb, const int oblog, const uchar direkt=0);
	void prueflywert(DB *My, const string& tlywert, const int obverb, const int oblog, const uchar direkt=0);
	void prueflybakt(DB *My, const string& tlybakt, const int obverb, const int oblog, const uchar direkt=0);
	void prueflyfehlt(DB *My, const string& tlyfehlt, const int obverb, const int oblog, const uchar direkt=0);
	void prueflyparameter(DB *My, const string& tlyparameter, const int obverb, const int oblog, const uchar direkt=0);
	void virttesterg(); //α
	void virtlieskonfein();
	void virtautokonfschreib();
	void dverarbeit(const string& datei);
 protected: 
	// void virtlgnzuw(); // wird aufgerufen in: virtrueckfragen, parsecl, lieskonfein, hcl::hcl nach holsystemsprache
	void virtVorgbAllg();
	void pvirtVorgbSpeziell()
#ifdef VOMHAUPTCODE
		__attribute__((weak)) // implementationsspezifische Vorgaben, Modul vgb.cpp)
#endif
		;
	void pruefPatID(const int aktc,tm &eingang, string &nname,string &vname,string &titel,string &nvorsatz,tm &gebdat,string &sgschl,string &pat_id)
#ifdef VOMHAUPTCODE
		__attribute__((weak)) // implementationsspezifische Adresspruefung)
#endif
		;
	void russchreib(insv &rus,const int aktc,tm &eingtm,string &usid,string &baktid,string &nname,string &vname,string &titel,string &nvorsatz,tm &gebdat,string &sgschl,string &pat_id);
	void virtinitopt(); // (programm-)spezifische Optionen
	void pvirtmacherkl();
	void virtMusterVorgb();
	void virtzeigversion(const string& ltiffv=nix);
	void pvirtvorrueckfragen();
	void virtrueckfragen();
	void virtpruefweiteres();
	void virtzeigueberschrift();
	void pvirtfuehraus();
	void virtschlussanzeige(); //ω
 public: //α
  hhcl(const int argc, const char *const *const argv);
	~hhcl();
}; // class hhcl //ω
