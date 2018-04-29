#include "kons.h"
#include "DB.h"
#include "labimp.h"

enum Txt_ {
	T_ergpql_volle_Funktion,
	T_auswertpql_volle_Funktion,
	T_eingetragen,
	T_Abfrage,
	T_tmMAX,
};

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
	{"",""}
}; // const char *Txvgcl::TextC[T_vgMAX+1][SprachZahl]=

// class Txvgcl Txv;
class TxB Txt((const char* const* const* const*)tm_T);


void hhcl::ergpql()
{
	hLog(violetts+Txt[T_ergpql_volle_Funktion]+schwarz);
	pql.insert(pql.begin(),"SELECT pat_id FROM namen WHERE nachname='"+nname+"' AND vorname='"+vname+"' AND gebdat="+sqlft(My->DBS,&gebdat)+" AND kaufdat<="+sqlft(My->DBS,&eingtm));
	pql.insert(pql.begin()+1,"SELECT pat_id FROM namen WHERE nachname='"+nname+"' AND vorname='"+vname+"' AND kaufdat<="+sqlft(My->DBS,&eingtm));
	pql.insert(pql.begin()+2,"SELECT pat_id FROM namen WHERE gebdat="+sqlft(My->DBS,&gebdat)+" AND kaufdat<="+sqlft(My->DBS,&eingtm));
	pql.insert(pql.begin()+3,"SELECT pat_id FROM namen WHERE gebdat="+sqlft(My->DBS,&gebdat)+" AND geschlecht='"+(sgschl=="1"?'m':sgschl=="2"?'w':' ')+"' AND kaufdat<="+sqlft(My->DBS,&eingtm));
	pql.insert(pql.begin()+4,"SELECT pat_id FROM namen WHERE nachname='"+nname+"' AND gebdat="+sqlft(My->DBS,&gebdat)+" AND geschlecht='"+(sgschl=="1"?'m':sgschl=="2"?'w':' ')+"' AND kaufdat<="+sqlft(My->DBS,&eingtm));
	pql.insert(pql.begin()+5,"SELECT pat_id FROM namen WHERE nachname='"+nname+"' AND gebdat="+sqlft(My->DBS,&gebdat)+" AND kaufdat<="+sqlft(My->DBS,&eingtm));
	// hier steht dann die Standardvorgabe
	pql<<"SELECT n.pat_id FROM namen n LEFT JOIN laborneu l ON n.pat_id = l.pat_id WHERE n.gebdat="+sqlft(My->DBS,&gebdat)+" AND l.zeitpunkt BETWEEN "
		"SUBDATE("+sqlft(My->DBS,&eingtm)+",interval 5 day) AND ADDDATE("+sqlft(My->DBS,&eingtm)+",interval 10 day) GROUP BY n.pat_id";
//	pql<<"SELECT n.pat_id FROM namen n LEFT JOIN laborneu l ON n.pat_id = l.pat_id WHERE n.nachname="+nname+" AND l.zeitpunkt BETWEEN "
//		"SUBDATE("+sqlft(My->DBS,&eingtm)+",interval 5 day) AND ADDDATE("+sqlft(My->DBS,&eingtm)+",interval 10 day) GROUP BY n.pat_id";
} // void hhcl::ergpql

// schwache Funktion, kann ueberdeckt werden
void hhcl::auswertpql(const size_t i,insv& rus)
{
	hLog(violetts+Txt[T_auswertpql_volle_Funktion]+schwarz);
	rus.hz(("Pat_id_"+ltoan(i)).c_str(),pat_id);
}

void hhcl::vordverarb(const size_t aktc)
{
	// Zahl der unbekannten Geschlechter aus Namen reduzieren
	RS unbekgschl(My,"update namen n set geschlecht = if((SELECT COUNT(DISTINCT i.geschlecht) FROM (SELECT * FROM namen) i WHERE vorname=n.vorname AND geschlecht<>' ')=1,(SELECT MAX(i.geschlecht) FROM (SELECT * FROM namen) i WHERE vorname=n.vorname AND geschlecht<>' '),n.geschlecht) WHERE geschlecht= ' '",aktc,ZDB);
} // void hhcl::vordverarb

void hhcl::nachbearbeit(const size_t aktc)
{
	uchar altZDB=ZDB;
	ZDB=1;
	RS vor(My,"SET @@GROUP_concat_max_len=150000; ",aktc,ZDB);
	my_ulonglong zahl=0;
	RS v1(My,"UPDATE `"+tlyus+"` u LEFT JOIN ("
"SELECT u.id,u.pat_id,u.eingang zp FROM `"+tlyus+"` u INNER JOIN (\n"
"SELECT GROUP_concat(concat(w.abkü,REPLACE(REPLACE(REPLACE(REPLACE(w.wert,'.',''),'<',''),':',''),'-','')) order BY w.abkü,w.wert) werte,"
"u.id, u.pat_id, gesname(u.pat_id) name, eingang, befart "
"FROM `"+tlyus+"` u LEFT JOIN `"+tlywert+"` w ON w.usid=u.id \n"
"GROUP BY pat_id,eingang,befart\n"
") x ON u.pat_id=x.pat_id AND u.eingang=x.eingang AND u.befart=x.befart LEFT JOIN (\n"
"SELECT GROUP_concat(concat(abkü,REPLACE(REPLACE(REPLACE(REPLACE(wert,'.',''),'<',''),':',''),'-','')) order BY abkü,wert) werte, "
"pat_id, DATE(zeitpunkt) zp, fertigstgrad "
"FROM laborneu\n"
"GROUP BY pat_id,DATE(zeitpunkt),fertigstgrad\n"
") y ON x.werte=y.werte AND x.eingang =y.zp AND x.pat_id=y.pat_id AND x.befart=y.fertigstgrad "
"WHERE NOT ISNULL(y.pat_id) "
") i ON u.id=i.id set u.pat_id_laborneu=i.pat_id, u.zeitpunktlaborneu=i.zp "
"WHERE ISNULL(pat_id_laborneu) AND u.eingang>=date("+sqlft(My->DBS,&minnachdat)+");",aktc,ZDB,0,0,0,&zahl);
	fLog(dblaus+Txt[T_Abfrage]+schwarz+"1, "+dblau+Txt[T_eingetragen]+schwarz+ltoan(zahl),1,0);

	RS v2(My,"UPDATE `"+tlyus+"` u LEFT JOIN ("
"SELECT u.id,u.pat_id,u.eingang zp FROM `"+tlyus+"` u INNER JOIN (\n"
"SELECT GROUP_concat(concat(w.abkü,REPLACE(REPLACE(REPLACE(REPLACE(w.wert,'.',''),'<',''),':',''),'-','')) order BY w.abkü,w.wert) werte, "
"u.id, u.pat_id, gesname(u.pat_id) name, eingang, befart "
"FROM `"+tlyus+"` u LEFT JOIN `"+tlywert+"` w ON w.usid=u.id AND w.wert REGEXP '^-?[0-9.,]+$' \n"
"GROUP BY pat_id,eingang,befart\n"
") x ON u.pat_id=x.pat_id AND u.eingang=x.eingang AND u.befart=x.befart LEFT JOIN (\n"
"SELECT pat_id, DATE(zeitpunkt) zp, fertigstgrad, "
"GROUP_concat(concat(abkü,REPLACE(REPLACE(REPLACE(REPLACE(wert,'.',''),'<',''),':',''),'-','')) order BY abkü,wert) werte "
"FROM laborneu WHERE wert REGEXP '^-?[0-9.,]+$' \n"
"GROUP BY pat_id,DATE(zeitpunkt),fertigstgrad\n"
") y ON x.werte=y.werte AND x.eingang =y.zp AND x.pat_id=y.pat_id AND x.befart=y.fertigstgrad "
"WHERE NOT ISNULL(y.pat_id) "
") i ON u.id=i.id set u.pat_id_laborneu=i.pat_id, u.zeitpunktlaborneu=i.zp "
"WHERE ISNULL(pat_id_laborneu) AND u.eingang>=date("+sqlft(My->DBS,&minnachdat)+");",aktc,ZDB,0,0,0,&zahl);
	fLog(dblaus+Txt[T_Abfrage]+schwarz+"2, "+dblau+Txt[T_eingetragen]+schwarz+ltoan(zahl),1,0);

	RS v3(My,"UPDATE `"+tlyus+"` u LEFT JOIN ("
"SELECT u.id,u.pat_id,u.eingang zp FROM `"+tlyus+"` u INNER JOIN (\n"
"SELECT GROUP_concat(concat(w.abkü,REPLACE(REPLACE(REPLACE(REPLACE(w.wert,'.',''),'<',''),':',''),'-','')) order BY w.abkü,w.wert) werte, "
"u.id, u.pat_id, gesname(u.pat_id) name, eingang, befart "
"FROM `"+tlyus+"` u LEFT JOIN (SELECT usid,abkü,wert FROM `"+tlywert+"` union SELECT usid,verf,'' FROM `"+tlybakt+"`) w ON w.usid=u.id AND w.wert = '' \n"
"GROUP BY pat_id,eingang,befart\n"
") x ON u.pat_id=x.pat_id AND u.eingang=x.eingang AND u.befart=x.befart LEFT JOIN (\n"
"SELECT pat_id, DATE(zeitpunkt) zp, fertigstgrad, "
"GROUP_concat(concat(abkü,REPLACE(REPLACE(REPLACE(REPLACE(wert,'.',''),'<',''),':',''),'-','')) order BY abkü,wert) werte "
"FROM laborneu WHERE wert ='' \n"
"GROUP BY pat_id,DATE(zeitpunkt),fertigstgrad\n"
") y ON x.werte=y.werte AND x.eingang =y.zp AND x.pat_id=y.pat_id AND x.befart=y.fertigstgrad "
"WHERE NOT ISNULL(y.pat_id) "
") i ON u.id=i.id set u.pat_id_laborneu=i.pat_id, u.zeitpunktlaborneu=i.zp "
"WHERE ISNULL(pat_id_laborneu) AND u.eingang>=date("+sqlft(My->DBS,&minnachdat)+");",aktc,ZDB,0,0,0,&zahl);
	fLog(dblaus+Txt[T_Abfrage]+schwarz+"3, "+dblau+Txt[T_eingetragen]+schwarz+ltoan(zahl),1,0);

	RS v4(My,"UPDATE `"+tlyus+"` u LEFT JOIN ("
"SELECT u.id,u.pat_id,u.eingang zp FROM `"+tlyus+"` u INNER JOIN (\n"
"SELECT GROUP_concat(w.abkü order BY w.abkü) werte, "
"u.id, u.pat_id, gesname(u.pat_id) name, eingang, befart "
"FROM `"+tlyus+"` u LEFT JOIN (SELECT usid,abkü,wert FROM `"+tlywert+"` union SELECT usid,verf,'' FROM `"+tlybakt+"`) w "
"ON w.usid=u.id AND (w.wert = '' OR w.wert regexp '[0-9.,:<>]') \n"
"GROUP BY pat_id,eingang,befart\n"
") x ON u.pat_id=x.pat_id AND u.eingang=x.eingang AND u.befart=x.befart LEFT JOIN (\n"
"SELECT pat_id, DATE(zeitpunkt) zp, fertigstgrad, "
"GROUP_concat(abkü order BY abkü) werte "
"FROM laborneu WHERE (wert ='' OR wert regexp '[0-9.,:<>]') \n"
"GROUP BY pat_id,DATE(zeitpunkt),fertigstgrad\n"
") y ON x.werte=y.werte AND x.eingang =y.zp AND x.pat_id=y.pat_id AND x.befart=y.fertigstgrad "
"WHERE NOT ISNULL(y.pat_id) "
") i ON u.id=i.id set u.pat_id_laborneu=i.pat_id, u.zeitpunktlaborneu=i.zp "
"WHERE ISNULL(pat_id_laborneu) AND u.eingang>=date("+sqlft(My->DBS,&minnachdat)+");",aktc,ZDB,0,0,0,&zahl);
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
") j ON u.id=j.id set u.pat_id_laborneu=j.pat_id, u.zeitpunktlaborneu=j.eingang "
"WHERE ISNULL(pat_id_laborneu) AND u.eingang>=date("+sqlft(My->DBS,&minnachdat)+");",aktc,ZDB,0,0,0,&zahl);
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
") j ON u.id=j.id set u.pat_id_laborneu=j.pat_id, u.zeitpunktlaborneu=j.eingang "
"WHERE ISNULL(pat_id_laborneu) AND u.eingang>=date("+sqlft(My->DBS,&minnachdat)+");",aktc,ZDB,0,0,0,&zahl);
	fLog(dblaus+Txt[T_Abfrage]+schwarz+"6, "+dblau+Txt[T_eingetragen]+schwarz+ltoan(zahl),1,0);

	RS v7(My,"UPDATE `"+tlyus+"` u LEFT JOIN ("
"SELECT * FROM ("
"SELECT i.*,n.zeitpunkt,COUNT(w.abkü) gleiche FROM "
"(SELECT us.id, eingang, pat_id,BefArt, COUNT(w.id) zahl FROM `"+tlyus+"` us LEFT JOIN `"+tlywert+"` w "
"ON us.id=w.usid AND w.wert<>'' "
"WHERE ISNULL(pat_id_laborneu) AND pat_id<>0 "
"GROUP BY us.id) i "
"LEFT JOIN `"+tlywert+"` w ON w.usid=i.id AND w.wert<>'' "
"INNER JOIN laborneu n ON n.pat_id<>i.pat_id AND n.abkü=w.abkü AND n.wert=w.wert AND n.fertigstgrad=i.Befart "
"AND eingang BETWEEN SUBDATE(zeitpunkt,interval 3 day) AND ADDDATE(zeitpunkt,interval 3 day) "
"WHERE zahl>3 "
"GROUP BY i.id,i.eingang,i.pat_id,n.pat_id,DATE(n.zeitpunkt), i.befart) j "
"WHERE gleiche>2"
") j ON u.id=j.id set u.pat_id_laborneu=j.pat_id, u.zeitpunktlaborneu=j.eingang "
"WHERE ISNULL(pat_id_laborneu) AND u.eingang>=date("+sqlft(My->DBS,&minnachdat)+");",aktc,ZDB,0,0,0,&zahl);
	fLog(dblaus+Txt[T_Abfrage]+schwarz+"7, "+dblau+Txt[T_eingetragen]+schwarz+ltoan(zahl),1,0);

	ZDB=altZDB;
}
