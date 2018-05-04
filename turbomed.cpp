#include "kons.h"
#include "DB.h"
#include "labimp.h"

enum Txt_ {
	T_ergpql_volle_Funktion,
	T_auswertpql_volle_Funktion,
	T_eingetragen,
	T_Abfrage,
	T_pvirtVorgbSpeziellvoll,
	T_tmMAX,
}; // enum Txt_

// const char *Txvgcl::TextC[T_vgMAX+1][SprachZahl]={
const char *tm_T[T_tmMAX+1][SprachZahl]={
	// T_ergpql_volle_Funktion
	{"ergpql() (volle Funktion)","ergpql() (filled function)"},
	// T_auswertpql_volle_Funktion
	{"auswertpql() (volle Funktion)","auswertpql() (filled function)"},
	// 	T_eingetragen
	{"eintragen: ","entered: "},
	// 	T_Abfrage
	{"Abfrage: ","Query: "},
	// T_pvirtVorgbSpeziellvoll
	{"pvirtVorgbSpeziell() (ueberladen)","pvirtVorgbSpeziell() (overloaded)"},
	{"",""}
}; // const char *Txvgcl::TextC[T_vgMAX+1][SprachZahl]=

// class Txvgcl Txv;
class TxB Txt((const char* const* const* const*)tm_T);

// wird aufgerufen in lauf
void hhcl::pvirtVorgbSpeziell()
{
	hLog(violetts+Txt[T_pvirtVorgbSpeziellvoll]+schwarz); //ω
	dbq="quelle";
	dhcl::pvirtVorgbSpeziell(); //α
	if (strstr(cpt,"linux1")) {
		ldatvz="/opt/turbomed/labor/backup";
	} else {
		ldatvz=gethome()+vtz+Tx[T_labor];
	}
	fertigvz=ldatvz+vtz+Tx[T_fertige];
} // void hhcl::pvirtVorgbSpeziell


void hhcl::ergpql()
{
	if (My->obtabspda("namen","gebdat")) {
		hLog(violetts+Txt[T_ergpql_volle_Funktion]+schwarz);
		pql.insert(pql.begin(),"SELECT pat_id FROM namen WHERE nachname=CONVERT("+sqlft(My->DBS,nname)+" USING latin1) COLLATE latin1_german2_ci AND vorname="+sqlft(My->DBS,vname)+" AND gebdat="+sqlft(My->DBS,&gebdat)+" AND kaufdat<="+sqlft(My->DBS,&eingtm));
		pql.insert(pql.begin()+1,"SELECT pat_id FROM namen WHERE nachname=CONVERT("+sqlft(My->DBS,nname)+" USING latin1) COLLATE latin1_german2_ci AND vorname="+sqlft(My->DBS,vname)+" AND kaufdat<="+sqlft(My->DBS,&eingtm));
		pql.insert(pql.begin()+2,"SELECT pat_id FROM namen WHERE gebdat="+sqlft(My->DBS,&gebdat)+" AND kaufdat<="+sqlft(My->DBS,&eingtm));
		pql.insert(pql.begin()+3,"SELECT pat_id FROM namen WHERE gebdat="+sqlft(My->DBS,&gebdat)+" AND geschlecht='"+(sgschl=="1"?'m':sgschl=="2"?'w':' ')+"' AND kaufdat<="+sqlft(My->DBS,&eingtm));
		pql.insert(pql.begin()+4,"SELECT pat_id FROM namen WHERE nachname=CONVERT("+sqlft(My->DBS,nname)+" USING latin1) COLLATE latin1_german2_ci AND gebdat="+sqlft(My->DBS,&gebdat)+" AND geschlecht='"+(sgschl=="1"?'m':sgschl=="2"?'w':' ')+"' AND kaufdat<="+sqlft(My->DBS,&eingtm));
		pql.insert(pql.begin()+5,"SELECT pat_id FROM namen WHERE nachname=CONVERT("+sqlft(My->DBS,nname)+" USING latin1) COLLATE latin1_german2_ci AND gebdat="+sqlft(My->DBS,&gebdat)+" AND kaufdat<="+sqlft(My->DBS,&eingtm));
		// hier steht dann die Standardvorgabe
		pql<<"SELECT n.pat_id FROM namen n LEFT JOIN laborneu l ON n.pat_id = l.pat_id WHERE n.gebdat="+sqlft(My->DBS,&gebdat)+" AND l.zeitpunkt BETWEEN "
			"SUBDATE("+sqlft(My->DBS,&eingtm)+",interval 5 day) AND ADDDATE("+sqlft(My->DBS,&eingtm)+",interval 10 day) GROUP BY n.pat_id";
		//	pql<<"SELECT n.pat_id FROM namen n LEFT JOIN laborneu l ON n.pat_id = l.pat_id WHERE n.nachname="+nname+" AND l.zeitpunkt BETWEEN "
		//		"SUBDATE("+sqlft(My->DBS,&eingtm)+",interval 5 day) AND ADDDATE("+sqlft(My->DBS,&eingtm)+",interval 10 day) GROUP BY n.pat_id";
	}
} // void hhcl::ergpql

// schwache Funktion, kann ueberdeckt werden
void hhcl::auswertpql(const size_t i,insv& rus)
{
	hLog(violetts+Txt[T_auswertpql_volle_Funktion]+schwarz);
	rus.hz(("Pat_id_"+ltoan(i)).c_str(),pat_id);
} // void hhcl::auswertpql

void hhcl::vordverarb(const size_t aktc)
{
	if (My->obtabspda("namen","geschlecht")) {
		// Zahl der unbekannten Geschlechter aus Namen reduzieren
		RS unbekgschl(My,"update namen n set geschlecht = if((SELECT COUNT(DISTINCT i.geschlecht) FROM (SELECT * FROM namen) i WHERE vorname=n.vorname AND geschlecht<>' ')=1,(SELECT MAX(i.geschlecht) FROM (SELECT * FROM namen) i WHERE vorname=n.vorname AND geschlecht<>' '),n.geschlecht) WHERE geschlecht= ' '",aktc,ZDB);
	}
} // void hhcl::vordverarb

void hhcl::nachbearbeit(const size_t aktc)
{
	uchar altZDB=ZDB;
	ZDB=1;
	if (My->obtabspda("laborneu","wert")) {
		RS vor(My,"SET @@GROUP_concat_max_len=150000; ",aktc,ZDB);
		my_ulonglong zahl=0;
		RS v1(My,"UPDATE `"+tlyus+"` u LEFT JOIN ("
				"SELECT us.id,us.pat_id,us.eingang zp FROM `"+tlyus+"` us INNER JOIN (\n"
				"SELECT GROUP_concat(concat(w.abkü,REPLACE(REPLACE(REPLACE(REPLACE(w.wert,'.',''),'<',''),':',''),'-','')) order BY w.abkü,w.wert) werte,"
				"usi.id, usi.pat_id, gesname(usi.pat_id) name, eingang, befart "
				"FROM `"+tlyus+"` usi LEFT JOIN `"+tlywert+"` w ON w.usid=usi.id \n"
				"GROUP BY pat_id,eingang,befart\n"
				") x ON us.pat_id=x.pat_id AND us.eingang=x.eingang AND us.befart=x.befart LEFT JOIN (\n"
				"SELECT GROUP_concat(concat(abkü,REPLACE(REPLACE(REPLACE(REPLACE(wert,'.',''),'<',''),':',''),'-','')) order BY abkü,wert) werte, "
				"pat_id, DATE(zeitpunkt) zp, fertigstgrad "
				"FROM laborneu\n"
				"GROUP BY pat_id,DATE(zeitpunkt),fertigstgrad\n"
				") y ON x.werte=y.werte AND x.eingang =y.zp AND x.pat_id=y.pat_id AND x.befart=y.fertigstgrad "
				"WHERE NOT ISNULL(y.pat_id) "
				") i ON u.id=i.id set u.pat_id_laborneu=i.pat_id, u.zeitpunktlaborneu=i.zp, u.verglichen=now() "
				"WHERE (ISNULL(pat_id_laborneu) OR pat_id_laborneu=0) AND u.eingang between date("+sqlft(My->DBS,&minnachdat)+") and "+sqlft(My->DBS,&maxnachdat)+";",aktc,ZDB,0,0,0,&zahl);
		fLog(dblaus+Txt[T_Abfrage]+schwarz+"1, "+dblau+Txt[T_eingetragen]+schwarz+ltoan(zahl),1,0);

		RS v2(My,"UPDATE `"+tlyus+"` u LEFT JOIN ("
				"SELECT us.id,us.pat_id,us.eingang zp FROM `"+tlyus+"` u INNER JOIN (\n"
				"SELECT GROUP_concat(concat(w.abkü,REPLACE(REPLACE(REPLACE(REPLACE(w.wert,'.',''),'<',''),':',''),'-','')) order BY w.abkü,w.wert) werte, "
				"us.id, us.pat_id"/*, gesname(us.pat_id) name*/", eingang, befart "
				"FROM `"+tlyus+"` u LEFT JOIN `"+tlywert+"` w ON w.usid=us.id AND w.wert REGEXP '^-?[0-9.,]+$' \n"
				"GROUP BY pat_id,eingang,befart\n"
				") x ON uns.pat_id=x.pat_id AND us.eingang=x.eingang AND us.befart=x.befart LEFT JOIN (\n"
				"SELECT pat_id, DATE(zeitpunkt) zp, fertigstgrad, "
				"GROUP_concat(concat(abkü,REPLACE(REPLACE(REPLACE(REPLACE(wert,'.',''),'<',''),':',''),'-','')) order BY abkü,wert) werte "
				"FROM laborneu WHERE wert REGEXP '^-?[0-9.,]+$' \n"
				"GROUP BY pat_id,DATE(zeitpunkt),fertigstgrad\n"
				") y ON x.werte=y.werte AND x.eingang =y.zp AND x.pat_id=y.pat_id AND x.befart=y.fertigstgrad "
				"WHERE NOT ISNULL(y.pat_id) "
				") i ON u.id=i.id set u.pat_id_laborneu=i.pat_id, u.zeitpunktlaborneu=i.zp, u.verglichen=now() "
				"WHERE (ISNULL(pat_id_laborneu) OR pat_id_laborneu=0) AND u.eingang between date("+sqlft(My->DBS,&minnachdat)+") and "+sqlft(My->DBS,&maxnachdat)+";",aktc,ZDB,0,0,0,&zahl);
		fLog(dblaus+Txt[T_Abfrage]+schwarz+"2, "+dblau+Txt[T_eingetragen]+schwarz+ltoan(zahl),1,0);

		RS v3(My,"UPDATE `"+tlyus+"` u LEFT JOIN ("
				"SELECT us.id,us.pat_id,us.eingang zp FROM `"+tlyus+"` u INNER JOIN (\n"
				"SELECT GROUP_concat(concat(w.abkü,REPLACE(REPLACE(REPLACE(REPLACE(w.wert,'.',''),'<',''),':',''),'-','')) order BY w.abkü,w.wert) werte, "
				"us.id, us.pat_id, gesname(us.pat_id) name, eingang, befart "
				"FROM `"+tlyus+"` u LEFT JOIN (SELECT usid,abkü,wert FROM `"+tlywert+"` union SELECT usid,verf,'' FROM `"+tlybakt+"`) w ON w.usid=us.id AND w.wert = '' \n"
				"GROUP BY pat_id,eingang,befart\n"
				") x ON us.pat_id=x.pat_id AND us.eingang=x.eingang AND us.befart=x.befart LEFT JOIN (\n"
				"SELECT pat_id, DATE(zeitpunkt) zp, fertigstgrad, "
				"GROUP_concat(concat(abkü,REPLACE(REPLACE(REPLACE(REPLACE(wert,'.',''),'<',''),':',''),'-','')) order BY abkü,wert) werte "
				"FROM laborneu WHERE wert ='' \n"
				"GROUP BY pat_id,DATE(zeitpunkt),fertigstgrad\n"
				") y ON x.werte=y.werte AND x.eingang =y.zp AND x.pat_id=y.pat_id AND x.befart=y.fertigstgrad "
				"WHERE NOT ISNULL(y.pat_id) "
				") i ON u.id=i.id set u.pat_id_laborneu=i.pat_id, u.zeitpunktlaborneu=i.zp, u.verglichen=now() "
				"WHERE (ISNULL(pat_id_laborneu) OR pat_id_laborneu=0) AND u.eingang between date("+sqlft(My->DBS,&minnachdat)+") and "+sqlft(My->DBS,&maxnachdat)+";",aktc,ZDB,0,0,0,&zahl);
		fLog(dblaus+Txt[T_Abfrage]+schwarz+"3, "+dblau+Txt[T_eingetragen]+schwarz+ltoan(zahl),1,0);

		RS v4(My,"UPDATE `"+tlyus+"` u LEFT JOIN ("
				"SELECT us.id,us.pat_id,us.eingang zp FROM `"+tlyus+"` us INNER JOIN (\n"
				"SELECT GROUP_concat(w.abkü order BY w.abkü) werte, "
				"us.id, us.pat_id, gesname(us.pat_id) name, eingang, befart "
				"FROM `"+tlyus+"` u LEFT JOIN (SELECT usid,abkü,wert FROM `"+tlywert+"` union SELECT usid,verf,'' FROM `"+tlybakt+"`) w "
				"ON w.usid=us.id AND (w.wert = '' OR w.wert regexp '[0-9.,:<>]') \n"
				"GROUP BY pat_id,eingang,befart\n"
				") x ON us.pat_id=x.pat_id AND us.eingang=x.eingang AND us.befart=x.befart LEFT JOIN (\n"
				"SELECT pat_id, DATE(zeitpunkt) zp, fertigstgrad, "
				"GROUP_concat(abkü order BY abkü) werte "
				"FROM laborneu WHERE (wert ='' OR wert regexp '[0-9.,:<>]') \n"
				"GROUP BY pat_id,DATE(zeitpunkt),fertigstgrad\n"
				") y ON x.werte=y.werte AND x.eingang =y.zp AND x.pat_id=y.pat_id AND x.befart=y.fertigstgrad "
				"WHERE NOT ISNULL(y.pat_id) "
				") i ON u.id=i.id set u.pat_id_laborneu=i.pat_id, u.zeitpunktlaborneu=i.zp, u.verglichen=now() "
				"WHERE (ISNULL(pat_id_laborneu) OR pat_id_laborneu=0) AND u.eingang between date("+sqlft(My->DBS,&minnachdat)+") and "+sqlft(My->DBS,&maxnachdat)+";",aktc,ZDB,0,0,0,&zahl);
		fLog(dblaus+Txt[T_Abfrage]+schwarz+"4, "+dblau+Txt[T_eingetragen]+schwarz+ltoan(zahl),1,0);

		RS v5(My,"UPDATE `"+tlyus+"` u LEFT JOIN ("
				"SELECT i.*,COUNT(w.abkü) gleiche FROM "
				"(SELECT us.id, eingang, pat_id,BefArt, COUNT(w.id) zahl FROM `"+tlyus+"` us LEFT JOIN `"+tlywert+"` w "
				"ON us.id=w.usid AND w.wert<>'' "
				"WHERE ISNULL(pat_id_laborneu) AND pat_id<>0 "
				"GROUP BY us.id) i "
				"LEFT JOIN `"+tlywert+"` w ON w.usid=i.id AND w.wert<>'' "
				"INNER JOIN laborneu n ON n.pat_id=i.pat_id AND n.abkü=w.abkü AND n.wert=w.wert AND n.fertigstgrad=i.Befart AND DATE(n.zeitpunkt)=i.eingang "
				"WHERE zahl>2 "
				"GROUP BY i.id,i.eingang,i.pat_id,i.befart"
				") j ON u.id=j.id set u.pat_id_laborneu=j.pat_id, u.zeitpunktlaborneu=j.eingang, u.verglichen=now() "
				"WHERE (ISNULL(pat_id_laborneu) OR pat_id_laborneu=0) AND u.eingang between date("+sqlft(My->DBS,&minnachdat)+") and "+sqlft(My->DBS,&maxnachdat)+";",aktc,ZDB,0,0,0,&zahl);
		fLog(dblaus+Txt[T_Abfrage]+schwarz+"5, "+dblau+Txt[T_eingetragen]+schwarz+ltoan(zahl),1,0);

		RS v6(My,"UPDATE `"+tlyus+"` u LEFT JOIN ("
				"SELECT * FROM ("
				"SELECT i.*,n.zeitpunkt,COUNT(w.abkü) gleiche FROM "
				"(SELECT us.id, eingang, pat_id,BefArt, COUNT(w.id) zahl FROM `"+tlyus+"` us LEFT JOIN `"+tlywert+"` w "
				"ON us.id=w.usid AND w.wert<>'' "
				"WHERE ISNULL(pat_id_laborneu) AND pat_id<>0 "
				"GROUP BY us.id) i "
				"LEFT JOIN `"+tlywert+"` w ON w.usid=i.id AND w.wert<>'' "
				"INNER JOIN laborneu n ON n.pat_id=i.pat_id AND n.abkü=w.abkü AND n.wert=w.wert AND n.fertigstgrad=i.Befart "
				"AND eingang BETWEEN SUBDATE(zeitpunkt,interval 10 day) AND ADDDATE(zeitpunkt,interval 10 day) "
				"WHERE zahl>3 "
				"GROUP BY i.id,i.eingang,i.pat_id,n.pat_id,DATE(n.zeitpunkt), i.befart) j "
				"WHERE gleiche>2"
				") j ON u.id=j.id set u.pat_id_laborneu=j.pat_id, u.zeitpunktlaborneu=j.eingang, u.verglichen=now() "
				"WHERE (ISNULL(pat_id_laborneu) OR pat_id_laborneu=0) AND u.eingang between date("+sqlft(My->DBS,&minnachdat)+") and "+sqlft(My->DBS,&maxnachdat)+";",aktc,ZDB,0,0,0,&zahl);
		fLog(dblaus+Txt[T_Abfrage]+schwarz+"6, "+dblau+Txt[T_eingetragen]+schwarz+ltoan(zahl),1,0);

#define echt
#ifdef echt
		RS v7(My,"UPDATE `"+tlyus+"` u LEFT JOIN ("
				"SELECT * FROM ("
				"SELECT i.*,n.zeitpunkt,COUNT(w.abkü) gleiche FROM "
				"(SELECT us.id, eingang, pat_id,BefArt, COUNT(w.id) zahl FROM `"+tlyus+"` us LEFT JOIN `"+tlywert+"` w "
				"ON us.id=w.usid AND w.wert<>'' "
				"WHERE ISNULL(pat_id_laborneu) "
				"GROUP BY us.id) i "
				"LEFT JOIN `"+tlywert+"` w ON w.usid=i.id AND w.wert<>'' "
				"INNER JOIN laborneu n ON n.pat_id<>i.pat_id AND n.abkü=w.abkü AND n.wert=w.wert AND n.fertigstgrad=i.Befart "
				"AND eingang BETWEEN SUBDATE(zeitpunkt,interval 3 day) AND ADDDATE(zeitpunkt,interval 3 day) "
				"WHERE zahl>3 "
				"GROUP BY i.id,i.eingang,i.pat_id,n.pat_id,DATE(n.zeitpunkt), i.befart) j "
				"WHERE gleiche>2"
				") j ON u.id=j.id set u.pat_id_laborneu=j.pat_id, u.zeitpunktlaborneu=j.eingang, u.verglichen=now() "
				"WHERE (ISNULL(pat_id_laborneu) OR pat_id_laborneu=0) AND u.eingang between date("+sqlft(My->DBS,&minnachdat)+") and "+sqlft(My->DBS,&maxnachdat)+";",aktc,ZDB,0,0,0,&zahl);
		fLog(dblaus+Txt[T_Abfrage]+schwarz+"7, "+dblau+Txt[T_eingetragen]+schwarz+ltoan(zahl),1,0);
#endif
	} // 	if (My->obtabspda("laborneu","wert"))

	RS view(My,"DROP VIEW IF EXISTS `labor2a`;"
			"CREATE OR REPLACE ALGORITHM=UNDEFINED DEFINER=`praxis`@`%` SQL SECURITY DEFINER VIEW `labor2a` AS "
			"SELECT Pat_id, eingang Zeitpunkt,befart FertigStGrad, Abkü,w.abkü abk_ur,w.langtext Langtext, Wert,Einheit, Einheit Einheit_ur "
			",concat(if(e.text rlike '^:[ /\\*:]*$','',if(e.text rlike '^:[ /\\*]*:',concat(mid(e.text,locate(':',e.text,2)+1),';'),if(e.text='.','',if(e.text='','',concat(e.text,';'))))),k.text) Kommentar "
			",NB, nb NB_ur,uNg,uNg uNg_ur, "
			"IF(abkü = 'LDL' AND einheit = 'mg/dl','100',oNg) oNg,"
			"oNg oNg_ur, Labor,Pfad "
			"FROM `"+tlyus+"` u "
			"LEFT JOIN `"+tlywert+"` w on u.id=w.usid "
			"LEFT JOIN `"+tlyhinw+"` e on w.erklid=e.id "
			"LEFT JOIN `"+tlyhinw+"` k on w.kommid=k.id "
			"LEFT JOIN `"+tlypnb+"` n on w.nbid=n.id "
			"LEFT JOIN `"+tlysaetze+"` s on u.satzid=s.satzid "
			"LEFT JOIN `"+tlydat+"` d on s.datid=d.datid "
			"LEFT JOIN `"+tlyplab+"` l on s.labid=l.id;",aktc,ZDB);

	ZDB=altZDB;
} // void hhcl::nachbearbeit
