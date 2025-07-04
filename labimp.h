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
	T_prueflpath,
	T_prueflpatel,
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
#ifdef altfelder
	T_8490_Auftragsbezogene_Hinweise_Turbomed,
	T_Ursprung_der_Pat_id_E__erwogene_Pat_id_su_L__vergleich_mit_ueber_Turbomed_eingelesenem_Labor,
	T_erwogene_Pat_id_mit_gleichem_Vornamen_Nachnamen_und_Geburtstag,
	T_erwogene_Pat_id_mit_gleichem_Vornamen_und_Nachnamen,
	T_erwogene_Pat_id_mit_gleichem_Geburtstag,
	T_erwogene_Pat_id_mit_gleichem_Geburtstag_und_zeitlich_passender_Behandlung,
	T_erwogene_Pat_id_mit_gleichem_Geburtstag_und_zeitlich_passendem_Labor,
	T_Pat_ids_von_in_Laborneu_zuordnbaren_Patienten,
#endif
	T_Zeitpunkt_der_Untersuchung_die_in_Laborneu_zugeordnet_wurde,
	T_Zahl_der_verglichenen_Parameter,
	T_Zahl_der_infragekommenden_Patienten,
	T_Laborwerte_die_zur_Zuordnung_gefuehrt_haben,
	T_Datum_zu_dem_Datensatz_zuletzt_verglichen_wurde,
	T_Affected_Number_Zahl_der_zugehoerigen_Datensaetze_in_Laborneu,
	T_Laborwerte,
	T_8420_Ergebniswert_Turbomed,
	T_8422_Grenzwertindikator_Turbomed,
	T_8418_Teststatus_Turbomed,
	T_Bezug_zu_laborxplab_id,
	T_8411_Testbezeichnung_Turbomed,
	T_ldvz_k,
	T_ldvz_l,
	T_vors_k,
	T_vors_l,
	T_fgvz_k,
	T_fgvz_l,
	T_Verzeichnis_der_Labordateien,
	T_Verzeichnis_der_Fertigen,
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
	T_Bezug_auf_,
	T_Abkuerzung_mit_gleicher_Bedeutung_gleicher_Einheit_und_gleichem_Normbereich,
	T_8421,
	T_LaborParameter,
	T_prueflyparameter,
	T_Reihenfolge_innerhalb_der_Gruppe,
	T_unterer_Normwert_maennlich,
	T_oberer_Normwert_maennlich,
	T_unterer_Normwert_weiblich,
	T_oberer_Normwert_weiblich,
	T_Normbereich_aus_,
	T_Aktualisierungszeitpunt,
	T_Ordnungsnummer_der_Dateiuebertragung,
	T_fehlend,
	T_Bezug_auf_LaborBakt,
//	T_pruefPatID_Standardfunktion,
	T_ergpql_leere_Funktion,
	T_Bezug_zu_laborynb,
	T_prueflyaerzte,
	T_zum_Bezug_fuer_Laborsaetze,
	T_Bezug_auf_lyaerzte,
	T_prueflyhinw,
	T_prueflyqspez,
	T_Auftragshinweis_Kommentar_oder_Erklaerung,
	T_Probenmaterial_Spezifikation,
	T_Hinweise,
	T_Spezifikation,
	T_codepage_0_utf8_1_iso88591_2_cp850,
	T_Auftragshinweis_Bezug_auf_lyhinw,
	T_Erklaerung_Bezug_auf_lyhinw,
	T_Kommentar_Bezug_auf_lyhinw,
	T_Bezug_auflspez,
	T_Auftragshinweis_Bezug_aufspez,
	T_Kommentar_Bezug_auf_lqspez,
	T_letzte_Aenderung,
	T_Groesse,
//	T_auswertpql,
	T_PatID_aus_Laborneu,
	T_nachbearbeit_leere_Funktion,
	T_vordverarb_leere_Funktion,
	T_loescht_Datensaetze_aus_unvollstaendig_eingelesenen_Dateien,
	T_lu_k,
	T_lu_l,
	T_Pat_id_fuer,
	T_Zahl,
	T_nurnachb_k,
	T_nurnachb_l,
	T_nachbneu_k,
	T_nachbneu_l,
	T_nurusmod_k,
	T_nurusmod_l,
	T_pruefauft_k,
	T_pruefauft_l,
	T_pruefe_alle_Auftraege,
	T_nur_Nachbearbeitung,
	T_nur_usmod,
	T_fertig,
	T_Dateien_gefunden,
	T_lab_k,
	T_lab_l,
	T_loescht_alle_Datensaetze_ab,
	T_Loescheab,
	T_pidnachw_k,
	T_pidnachw_l,
	T_listet_Eintraege_zu_pid,
	T_lid_k,
	T_lid_l,
	T_loescht_Datensatz_id,
	T_Loescheid,
	T_Datensaetze_geloescht,
	T_fertig_mit_datid,
	T_Fehler_bei_sql,
	T_labor,
	T_fertige,
	T_Verzeichnis_der_fertig_Verarbeiteten,
	T_Fehler_beim_Verschieben_von,
	T_nach_,
	T_listdat_k,
	T_listdat_l,
	T_pruefdb_k,
	T_pruefdb_l,
	T_umben_k,
	T_umben_l,
	T_listet_alle_eingelesenen_Dateien_auf,
	T_Pfad_,
	T_Eingang,
	T_eingelesen,
	T_Zeichensatz,
	T_fertig_,
	T_n_k,
	T_dszahl_l,
	T_Zahl_der_aufzulistenden_Datensaetze_ist_zahl_statt,
	T_Normbereich_ohne_bis,
	T_Soll_ich_wirklich_alle_Tabellen_mit,
	T_Soll_ich_wirklich_alle_Tabellen_mit_,
	T_Soll_ich_wirklich_alle_Tabellen_mit__,
	T_Soll_ich_wirklich_alle_Tabellen_mit___,
	T_loeschen_und_von_vorne_anfangen,
	T_Aktion_abgebrochen,
	T_loeschen,
	T_ab_DATID,
	T_mit_DATID,
	T_entleeren_und_von_vorne_anfangen,
	T_um_Datensaetze_aus_nicht_fertig_eingelesenen_Dateien_bereinigt_werden,
	T_Nachbearbeitung_von_vorne,
	T_Soll_ich_wirklich_alle_Nachbearbeitungen_von_vorne_angefangen_werden,
	T_Eintraege_aus,
	T_saetze,
	T_unters,
	T_werte,
	T_bakt,
	T_initialisiert_nur_die_Tabellen,
	T_benennt_die_Tabellen_um,
	T_fuer_PatID_gewaehlte_SQL_Abfrage,
	T_russchreib_usid,
	T_SQL_Abfrage_zur_direkten_Pat_id_Ermittlung_aus_laborneu,
	T_Zahl_der_Antworten_aus_laborneu,
	T_Vorsilbe_fuer_Datenbanktabellen,
	T_nach___,
	T_umbenennen,
	T_Namensanfang_aller_Einlesetabellen,
	T_Tabellenzahl_mit,
	T_Eingelesene_Labordateien,
	T_war_schon_in,
	T_eingetragen_,
	T_pvirtfueraus,
	T_Einlesedatum,
	T_Pfad,
	T_Name,
	T_Aenderungsdatum,
	T_dfertig,
	T_Path_Labor_Einlesungen,
	T_ID_der_Einlesung,
	T_Laborparameter,
	T_LWert,
	T_Einheit,
	T_Vorwert_1,
	T_Vorwert_2,
	T_HinweisedL,
	T_fehlende_ICDs,
	T_namsp,
	T_wertsp,
	T_hinwsp,
	T_termsp,
	T_ficdsp,
	T_Termine,
	T_Laborwert,
	T_Berichtsdatum,
	T_Dateidatum,
	T_MAX //α
}; // enum T_ //ω

void BDTtoDate(const string& inh,struct tm *tm,int abjahr=1900,uchar objahrzuerst=0);

//α
class hhcl:public dhcl
{
	private: //ω
		string tlydat; /*=vorsil+"dat"*/
		string tlyleist; /*=vorsil+"leist"*/
		string tlypgl; /*=vorsil+"pgl"*/
		string tlyplab; /*=vorsil+"plab"*/
		string tlypnb; /*=vorsil+"pnb"*/
		string tlypneu; /*=vorsil+"pneu"*/
		string tlyaerzte; /*=vorsil+"saetze"*/
		string tlysaetze; /*=vorsil+"saetze"*/
		string tlyus; /*=vorsil+"us"*/
		string tlywert; /*=vorsil+"wert"*/
		string tlybakt; /*=vorsil+"bakt"*/
		string tlyfehlt; /*=vorsil+"fehlt"*/
		string tlyparameter; /*=vorsil+"parameter"*/
		string tlyhinw; /*=vorsil+"hinw"*/
		string tlyqspez; /*=vorsil+"qspez"*/
	 string labpatel;
	 string labpath;
		const static tm tmnull; // {0}
		const static tm tmmax; // {0,0,0,1,0,200,0,0,0}
		string labind,pneuind,pnbid,hinwind,spezind;
		string datid;
		string patelid;
		string usid;
		svec usids; // alle eingetragenen usids
		ic_cl *icp[3];
		tm eingtm{0}, gebtm{0};
		tm minnachdat{0}; // minimales Datum der Tabelle tlyus fuer die Nachbearbeitung
		tm maxnachdat{0,0,0,1,0,200,0,0,0}; // maximale Datum der Tabelle tlyus fuer die Nachbearbeitung
		string nname,vname,titel,nvorsatz,sgschl,pid{"0"},auftrschl,baktid,hinwid,qspezid,erklid,kommid,gschl,obs;
		int obpid{0};
		long palter{0};
		char berzt[15];
		tm voret{0};
		svec pql; // Vektor fuer SQL-Abfragen zum Herausfinden der Pat_ID
		string dateidat;
		string normbereich,uNm,oNm,uNw,oNw,erklaerung,kommentar,auftrhinw,qspez,grenzwi,labk,lwert,koreinh;
		struct tm berdat{0}; // Berichtsdatum
		tm abndat{0};
		uchar keimz{0},keimzda{0};
		svec zlangt,zabk,zwerte,zverfa; // fuer Vergleich mit laborneu
	protected: //α //ω
//		long listz=30; //ω
    unsigned long dszahl=0; // Datensatzzahl fuer Tabellenausgaben
		string p1;
		int p2;
		string p3;
		uchar oblista=0;
		uchar vonvorne=0;
		uchar entleer=0;
		uchar loeschalle=0;
		uchar loeschunvollst=0;
		uchar nurnachb=0;
		uchar nachbneu=0;
		uchar nurusmod=0;
		uchar pruefauft=0; // pruefe Patientenidentität der Auträge X010LG05SKD.LDT und X010PG05SKD.LDT
		string loeschab;
		string loeschid;
		uchar listdat=0;
		string pidnachw;
		uchar nurpruefdb=0;
		string umben;
		string vorsl/*,vorclvors,nachclvors*/;   // Vorsilbe für Datenbanktabellen, vor und nach command line-Auswertung
		string ldatvz;   // Verzeichnis der Labordateien
		string fertigvz; // Verzeichnis der fertig bearbeiteten
	public: //α //ω
	private: //α //ω
		int fui0();
		void tabnamen();
		void prueflydat(DB *My, const size_t aktc, const int obverb, const int oblog, const uchar direkt=0);
		void prueflyleist(DB *My, const size_t aktc, const int obverb, const int oblog, const uchar direkt=0);
		void prueflypgl(DB *My, const size_t aktc, const int obverb, const int oblog, const uchar direkt=0);
		void prueflyplab(DB *My, const size_t aktc, const int obverb, const int oblog, const uchar direkt=0);
		void prueflypnb(DB *My, const size_t aktc, const int obverb, const int oblog, const uchar direkt=0);
		void prueflypneu(DB *My, const size_t aktc, const int obverb, const int oblog, const uchar direkt=0);
		void prueflyaerzte(DB *My, const size_t aktc, const int obverb, const int oblog, const uchar direkt=0);
		void prueflysaetze(DB *My, const size_t aktc, const int obverb, const int oblog, const uchar direkt=0);
		void prueflyus(DB *My, const size_t aktc, const int obverb, const int oblog, const uchar direkt=0);
		void prueflywert(DB *My, const size_t aktc, const int obverb, const int oblog, const uchar direkt=0);
		void prueflybakt(DB *My, const size_t aktc, const int obverb, const int oblog, const uchar direkt=0);
		void prueflyfehlt(DB *My, const size_t aktc, const int obverb, const int oblog, const uchar direkt=0);
		void prueflyparameter(DB *My, const size_t aktc, const int obverb, const int oblog, const uchar direkt=0);
		void prueflyhinw(DB *My, const size_t aktc, const int obverb, const int oblog, const uchar direkt=0);
		void prueflyqspez(DB *My, const size_t aktc, const int obverb, const int oblog, const uchar direkt=0);
		void prueflpath(DB *My, const size_t aktc, const int obverb, const int oblog, const uchar direkt=0);
		void prueflpatel(DB *My, const size_t aktc, const int obverb, const int oblog, const uchar direkt=0);
		void prueftbl();
		void droptables(const size_t aktc=0,uchar obumben=0);
		void virttesterg(); //α
		void virtlieskonfein();
		void virtautokonfschreib();
		int dverarbeit(const string& datei,string *datidp,string *patelidp);
		int vverarbeit(const string& datei); // Vergleichsdatei verarbeiten
		void usschluss(const size_t aktc);
		void wertschreib(const int aktc,uchar *usoffenp,insv *rusp,string *usidp,insv *rpar, insv *rpneu, insv *rpnb, insv *rwe, insv *rbawep,insv *rhinwp,insv *rspezp,insv *rlep);
	protected: 
		// void virtlgnzuw(); // wird aufgerufen in: virtrueckfragen, parsecl, lieskonfein, hcl::hcl nach holsystemsprache
		void virtVorgbAllg();
		void pvirtVorgbSpeziell()
#ifdef VOMHAUPTCODE
			__attribute__((weak)) // implementationsspezifische Vorgaben, Modul vgb.cpp)
#endif
			;
		/*
		void pruefPatID(const int aktc,insv& rus)
#ifdef VOMHAUPTCODE
			__attribute__((weak)) // implementationsspezifische Adresspruefung)
#endif
			;
		*/
		void fuellpql();
		/*
		void auswertpql(const size_t i,insv& rus)
#ifdef VOMHAUPTCODE
			__attribute__((weak)) // implementationsspezifische Adresspruefung)
#endif
			;
		*/
		void ergpql()
#ifdef VOMHAUPTCODE
			__attribute__((weak)) // implementationsspezifische Adresspruefung)
#endif
			;
		void usmod(const size_t aktc,svec *zlangtp=0,svec *zabkp=0, svec *zwertep=0,svec *zverfap=0,tm *eingtmp=0)
#ifdef VOMHAUPTCODE
			__attribute__((weak)) // implementationsspezifische Adresspruefung)
#endif
			;
		void vordverarb(const size_t aktc)
#ifdef VOMHAUPTCODE
			__attribute__((weak)) // implementationsspezifische Adresspruefung)
#endif
			;
		void nachbearbeit(const size_t aktc,const uchar obusmod/*=0*/)
#ifdef VOMHAUPTCODE
			__attribute__((weak)) // implementationsspezifische Adresspruefung)
#endif
			;
		void russchreib(insv &rus,const int aktc,string *usidp);
		void virtinitopt(); // (programm-)spezifische Optionen
		void pvirtmacherkl();
		void virtMusterVorgb();
		void pvirtvorzaehler();
		void virtzeigversion(const string& ltiffv=nix);
		void pvirtvorrueckfragen();
		void pvirtnachrueckfragen();
		void virtpruefweiteres();
		void virtzeigueberschrift();
		void pvirtfuehraus();
		void virtschlussanzeige(); //ω
	public: //α
		hhcl(const int argc, const char *const *const argv);
		~hhcl();
}; // class hhcl //ω
