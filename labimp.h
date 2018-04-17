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
	T_prueflaborydat,
	T_prueflaboryleist,
	T_prueflaborypgl,
	T_prueflaboryplab,
	T_prueflaborypnb,
	T_prueflaborypneu,
	T_prueflaborysaetze,
	T_prueflaboryus,
	T_prueflaborywert,
	T_prueflaborybakt,
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
	T_loescht_alle_Tabellen,
	T_entleert_alle_Tabellen,
	T_Loesche_alle_Tabellen_und_fange_von_vorne_an,
	T_Entleere_alle_Tabellen_und_fange_von_vorne_an,
	T_Kennung,
	T_Inhalt,
	T_prueflaboryfehlt,
	T_Bezug_auf_Laboryplab,
	T_Abkuerzung_mit_gleicher_Bedeutung_gleicher_Einheit_und_gleichem_Normbereich,
	T_8421,
	T_LaborParameter,
	T_prueflaboryparameter,
	T_Reihenfolge_innerhalb_der_Gruppe,
	T_unterer_Normwert_maennlich,
	T_oberer_Normwert_maennlich,
	T_unterer_Normwert_weiblich,
	T_oberer_Normwert_weiblich,
	T_Normbereich_aus_laborywert,
	T_Aktualisierungszeitpunt,
	T_Ordnungsnummer_der_Dateiuebertragung,
	T_fehlend,
	T_Bezug_auf_LaborBakt,
	T_MAX //α
}; // enum T_ //ω
const string fertiguvz="fertig";
//α
class hhcl:public dhcl
{
 private: //ω
	string tlaborydat="laborydat";
	string tlaboryleist="laboryleist";
	string tlaborypgl="laborypgl";
	string tlaboryplab="laboryplab";
	string tlaborypnb="laborypnb";
	string tlaborypneu="laborypneu";
	string tlaborysaetze="laborysaetze";
	string tlaboryus="laboryus";
	string tlaborywert="laborywert";
	string tlaborybakt="laborybakt";
	string tlaboryfehlt="laboryfehlt";
	string tlaboryparameter="laboryparameter";
	string labind;
	ic_cl *icp;
 protected: //α
	string p1;
	int p2;
	string p3;
	uchar oblista=0;
	uchar vonvorne=0;
	uchar entleer=0;
	long listz=30; //ω
  string ldatvz;   // Verzeichnis der Labordateien
 public: //α //ω
 private: //α //ω
	void prueflaborydat(DB *My, const string& tlaborydat, const int obverb, const int oblog, const uchar direkt=0);
	void prueflaboryleist(DB *My, const string& tlaboryleist, const int obverb, const int oblog, const uchar direkt=0);
	void prueflaborypgl(DB *My, const string& tlaborypgl, const int obverb, const int oblog, const uchar direkt=0);
	void prueflaboryplab(DB *My, const string& tlaboryplab, const int obverb, const int oblog, const uchar direkt=0);
	void prueflaborypnb(DB *My, const string& tlaborypnb, const int obverb, const int oblog, const uchar direkt=0);
	void prueflaborypneu(DB *My, const string& tlaborypneu, const int obverb, const int oblog, const uchar direkt=0);
	void prueflaborysaetze(DB *My, const string& tlaborysaetze, const int obverb, const int oblog, const uchar direkt=0);
	void prueflaboryus(DB *My, const string& tlaboryus, const int obverb, const int oblog, const uchar direkt=0);
	void prueflaborywert(DB *My, const string& tlaborywert, const int obverb, const int oblog, const uchar direkt=0);
	void prueflaborybakt(DB *My, const string& tlaborybakt, const int obverb, const int oblog, const uchar direkt=0);
	void prueflaboryfehlt(DB *My, const string& tlaboryfehlt, const int obverb, const int oblog, const uchar direkt=0);
	void prueflaboryparameter(DB *My, const string& tlaboryparameter, const int obverb, const int oblog, const uchar direkt=0);
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
