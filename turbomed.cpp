#include "kons.h"
#include "DB.h"
#include "labimp.h"

enum Txt_ {
	T_ergpql_ueberladene_Funktion,
	T_auswertpql_ueberladene_Funktion,
	T_eingetragen,
	T_Abfrage,
	T_pvirtVorgbSpeziellvoll,
	T_tmMAX,
}; // enum Txt_

// const char *Txvgcl::TextC[T_vgMAX+1][SprachZahl]={
const char *tm_T[T_tmMAX+1][SprachZahl]={
	// T_ergpql_ueberladene_Funktion
	{"ergpql() (ueberladene Funktion)","ergpql() (filled function)"},
	// T_auswertpql_ueberladene_Funktion
	{"auswertpql() (ueberladene Funktion)","auswertpql() (filled function)"},
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

// passt anhand spaeterer Informationen die Pat_id an
void hhcl::usmod(const size_t aktc)
{
	char const nz{'\n'};
	unsigned const akbgrenze{4};
	string const buchzahl{"2"};
	if (!usid.empty()) {
		string gsql{"SELECT l.pat_id,zeitpunkt FROM laborneu l WHERE 1 "};
		gsql+=nz;
		gsql+="AND ";
		if (zwerte.size() || zverfa.size()) {
			gsql+="l.zeitpunkt BETWEEN SUBDATE("+sqlft(My->DBS,&eingtm)+",interval "+(zwerte.size()?"5":"1")+" DAY)"
				                    "AND ADDDATE("+sqlft(My->DBS,&eingtm)+",interval "+(zwerte.size()?"15":"1")+" DAY) "+nz+"AND ";
			if (zwerte.size()) {
				for(size_t i=0;i<zwerte.size();i++) {
#define unscharf
#ifndef unscharf
					gsql+="(SELECT MAX(pat_id) FROM laborneu WHERE fid=l.fid AND zeitpunkt=l.zeitpunkt AND wert="+sqlft(My->DBS,zwerte[i])+") IS NOT NULL ";
					if (i!=zverfa.size()-1) {gsql+=nz;gsql+="AND ";}
#else
					gsql+="((SELECT MAX(pat_id) FROM laborneu";
					if (zwerte.size()<akbgrenze) {
						gsql+=" LEFT JOIN laborlangtext using (LangtextVW)";
					}
					gsql+=" WHERE fid=l.fid AND zeitpunkt=l.zeitpunkt AND wert="+sqlft(My->DBS,zwerte[i]);
					if (zwerte.size()<akbgrenze) {
						gsql+=" AND LEFT(Langtext,"+buchzahl+")=LEFT("+sqlft(My->DBS,zlangt[i])+","+buchzahl+")";
					}
					gsql+=") IS NOT NULL)";
					if (i!=zwerte.size()-1) {gsql+=nz;gsql+="   +";}
#endif
				}
#ifdef unscharf
				gsql+=">=";
				gsql+=ltoan(zwerte.size()<6?zwerte.size():zwerte.size()<9?5:zwerte.size()<10?6:zwerte.size()-4);
#endif
			} else {
				for(size_t i=0;i<zverfa.size();i++) {
					gsql+="(SELECT MAX(pat_id) FROM laborneu WHERE fid=l.fid AND zeitpunkt=l.zeitpunkt AND Abkü="+sqlft(My->DBS,zverfa[i])+") IS NOT NULL ";
					if (i!=zverfa.size()-1) {gsql+=nz;gsql+="AND ";}
				}
			}
			gsql+=" ";
			gsql+=nz;
			gsql+="GROUP BY pat_id";
			const unsigned i{7};
			// folgender Code aehnlich in russchreib
			string mods{"UPDATE `"+tlyus+"` SET "};
			mods+="SQL7="+sqlft(My->DBS,gsql);
			RS rspat(My,gsql,aktc,ZDB);
			// 7.9. !obqueryfehler und !result vorgekommen
			if (!rspat.obqueryfehler && rspat.result) {
				hLog(gruens+Tx[T_Zahl]+blau+ltoan(rspat.result->row_count)+gruen+Txk[T_bei]+blau+gsql+schwarz);
				mods+=",z7="+ltoan(rspat.result->row_count);
				if (rspat.result->row_count==1){
					char ***cerg{0};
					if ((cerg=rspat.HolZeile())) {
						if (*cerg && **cerg) {
							hLog(Tx[T_Pat_id_fuer]+blaus+nname+", "+vname+": "+schwarz+**cerg);
							mods+=",Pat_id_"+ltoan(i)+"="+sqlft(My->DBS,**cerg);
							mods+=",ZeitpunktLaborneu="+sqlft(My->DBS,cjj(cerg,1));
							mods+=",Pat_id=IF(pat_id_0 IS NULL AND pat_id_1 IS NULL,"+sqlft(My->DBS,**cerg)+",Pat_id)";
							/*
								 if (pid=="0" || pid.empty()) {
								 pid=**cerg;
								 rus.hz("sql",gsql);
								 }
							 */
							//						break;
						} // 					if (*cerg)
					} // 				if ((cerg=rspat.HolZeile()))
				} // 			if (rspat.result->row_count==1)
			} else {
				fLog(rots+Tx[T_Fehler_bei_sql]+violett+gsql+schwarz,1,oblog);
			} // 		if (!rspat.obqueryfehler) else
			mods+=" WHERE id="+usid;
			RS rsmod(My,mods,aktc,ZDB);
		}
	} // 	if (!usid.empty())
} // void hhcl::usmod

// fuellt den Vektor pql, dessen Elemente dann in der Funktion pruefPatID verwendet werden, um hhcl::pat_id zu belegen
// ueberdeckt die gleichnamige Funktion in labimp.cpp
void hhcl::ergpql()
{
	if (My->obtabspda("namen","gebdat")) {
		hLog(violetts+Txt[T_ergpql_ueberladene_Funktion]+schwarz);
		pql.insert(pql.begin(),"SELECT pat_id FROM namen WHERE nachname=CONVERT("+sqlft(My->DBS,nname)+" USING latin1) COLLATE latin1_german2_ci AND vorname="+sqlft(My->DBS,vname)+" AND gebdat="+sqlft(My->DBS,&gebtm)+" AND kaufdat<="+sqlft(My->DBS,&eingtm)+" GROUP BY pat_id");
		pql.insert(pql.begin()+1,"SELECT pat_id FROM namen WHERE nachname=CONVERT("+sqlft(My->DBS,nname)+" USING latin1) COLLATE latin1_german2_ci AND vorname="+sqlft(My->DBS,vname)+" AND kaufdat<="+sqlft(My->DBS,&eingtm)+" GROUP BY pat_id");
		// Pat_ID_3:
		pql.insert(pql.begin()+2,"SELECT pat_id FROM namen n WHERE gebdat="+sqlft(My->DBS,&gebtm)+" AND kaufdat<="+sqlft(My->DBS,&eingtm)+" GROUP BY pat_id");
		pql.insert(pql.begin()+3,"SELECT pat_id FROM namen WHERE gebdat="+sqlft(My->DBS,&gebtm)+" AND geschlecht='"+(sgschl=="1"?'m':sgschl=="2"?'w':' ')+"' AND kaufdat<="+sqlft(My->DBS,&eingtm)+" GROUP BY pat_id");
		pql.insert(pql.begin()+4,"SELECT pat_id FROM namen WHERE nachname=CONVERT("+sqlft(My->DBS,nname)+" USING latin1) COLLATE latin1_german2_ci AND gebdat="+sqlft(My->DBS,&gebtm)+" AND geschlecht='"+(sgschl=="1"?'m':sgschl=="2"?'w':' ')+"' AND kaufdat<="+sqlft(My->DBS,&eingtm)+" GROUP BY pat_id");
		pql.insert(pql.begin()+5,"SELECT pat_id FROM namen WHERE nachname=CONVERT("+sqlft(My->DBS,nname)+" USING latin1) COLLATE latin1_german2_ci AND gebdat="+sqlft(My->DBS,&gebtm)+" AND kaufdat<="+sqlft(My->DBS,&eingtm)+" GROUP BY pat_id");
		// hier steht dann die Standardvorgabe
		/*
		pql<<"SELECT n.pat_id FROM namen n LEFT JOIN laborneu l ON n.pat_id = l.pat_id WHERE n.gebdat="+sqlft(My->DBS,&gebtm)+
		" AND l.zeitpunkt BETWEEN SUBDATE("+sqlft(My->DBS,&eingtm)+",interval 5 day) AND ADDDATE("+sqlft(My->DBS,&eingtm)+",interval 15 day) "
		"GROUP BY n.pat_id";
		//	pql<<"SELECT n.pat_id FROM namen n LEFT JOIN laborneu l ON n.pat_id = l.pat_id WHERE n.nachname="+nname+" AND l.zeitpunkt BETWEEN "
		//		"SUBDATE("+sqlft(My->DBS,&eingtm)+",interval 5 day) AND ADDDATE("+sqlft(My->DBS,&eingtm)+",interval 15 day) GROUP BY n.pat_id";
		*/
		string gsql{"SELECT NULL"};
		pql<<gsql;
		/*
		for(unsigned i=0;i<pql.size();i++) {
			caus<<gruen<<i<<": "<<blau<<pql[i]<<schwarz<<endl;
		}
		*/
	}
	hLog(violetts+Txk[T_Ende]+Txt[T_ergpql_ueberladene_Funktion]+schwarz);
} // void hhcl::ergpql

/*
// ueberdeckt gleichnamige Funktion in labimp.cpp
// wird aufgerufen in pruefPatID
void hhcl::auswertpql(const size_t i,insv& rus)
{
hLog(violetts+Txt[T_auswertpql_ueberladene_Funktion]+schwarz);
rus.hz(("Pat_id_"+ltoan(i)).c_str(),pat_id);
} // void hhcl::auswertpql
 */

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
	RS vor(My,"SET @@GROUP_concat_max_len=150000; ",aktc,ZDB);
	if (1) {
	if (My->obtabspda("laborneu","wert")) {
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
				") i ON u.id=i.id set u.pat_id_laborneu=i.pat_id, u.zeitpunktlaborneu=if(i.zp is null,u.zeitpunktlaborneu,i.zp), u.verglichen=now() "
				"WHERE (ISNULL(pat_id_laborneu) OR pat_id_laborneu=0) AND u.eingang between date("+sqlft(My->DBS,&minnachdat)+") and "+sqlft(My->DBS,&maxnachdat)+";",aktc,ZDB,0,0,0,&zahl);
		fLog(dblaus+Txt[T_Abfrage]+schwarz+"1, "+dblau+Txt[T_eingetragen]+schwarz+ltoan(zahl),1,0);

		RS v2(My,"UPDATE `"+tlyus+"` u LEFT JOIN ("
				"SELECT us.id,us.pat_id,us.eingang zp FROM `"+tlyus+"` us INNER JOIN (\n"
				"SELECT GROUP_concat(concat(w.abkü,REPLACE(REPLACE(REPLACE(REPLACE(w.wert,'.',''),'<',''),':',''),'-','')) order BY w.abkü,w.wert) werte, "
				"us.id, us.pat_id"/*, gesname(us.pat_id) name*/", eingang, befart "
				"FROM `"+tlyus+"` us LEFT JOIN `"+tlywert+"` w ON w.usid=us.id AND w.wert REGEXP '^-?[0-9.,]+$' \n"
				"GROUP BY pat_id,eingang,befart\n"
				") x ON us.pat_id=x.pat_id AND us.eingang=x.eingang AND us.befart=x.befart LEFT JOIN (\n"
				"SELECT pat_id, DATE(zeitpunkt) zp, fertigstgrad, "
				"GROUP_concat(concat(abkü,REPLACE(REPLACE(REPLACE(REPLACE(wert,'.',''),'<',''),':',''),'-','')) order BY abkü,wert) werte "
				"FROM laborneu WHERE wert REGEXP '^-?[0-9.,]+$' \n"
				"GROUP BY pat_id,DATE(zeitpunkt),fertigstgrad\n"
				") y ON x.werte=y.werte AND x.eingang =y.zp AND x.pat_id=y.pat_id AND x.befart=y.fertigstgrad "
				"WHERE NOT ISNULL(y.pat_id) "
				") i ON u.id=i.id set u.pat_id_laborneu=i.pat_id, u.zeitpunktlaborneu=if(i.zp is null,u.zeitpunktlaborneu,i.zp), u.verglichen=now() "
				"WHERE (ISNULL(pat_id_laborneu) OR pat_id_laborneu=0) AND u.eingang between date("+sqlft(My->DBS,&minnachdat)+") and "+sqlft(My->DBS,&maxnachdat)+";",aktc,ZDB,0,0,0,&zahl);
		fLog(dblaus+Txt[T_Abfrage]+schwarz+"2, "+dblau+Txt[T_eingetragen]+schwarz+ltoan(zahl),1,0);

		RS v3(My,"UPDATE `"+tlyus+"` u LEFT JOIN ("
				"SELECT us.id,us.pat_id,us.eingang zp FROM `"+tlyus+"` us INNER JOIN (\n"
				"SELECT GROUP_concat(concat(w.abkü,REPLACE(REPLACE(REPLACE(REPLACE(w.wert,'.',''),'<',''),':',''),'-','')) order BY w.abkü,w.wert) werte, "
				"usi.id, usi.pat_id, gesname(usi.pat_id) name, eingang, befart "
				"FROM `"+tlyus+"` usi LEFT JOIN (SELECT usid,abkü,wert FROM `"+tlywert+"` union SELECT usid,verf,'' FROM `"+tlybakt+"`) w ON w.usid=usi.id AND w.wert = '' \n"
				"GROUP BY pat_id,eingang,befart\n"
				") x ON us.pat_id=x.pat_id AND us.eingang=x.eingang AND us.befart=x.befart LEFT JOIN (\n"
				"SELECT pat_id, DATE(zeitpunkt) zp, fertigstgrad, "
				"GROUP_concat(concat(abkü,REPLACE(REPLACE(REPLACE(REPLACE(wert,'.',''),'<',''),':',''),'-','')) order BY abkü,wert) werte "
				"FROM laborneu WHERE wert ='' \n"
				"GROUP BY pat_id,DATE(zeitpunkt),fertigstgrad\n"
				") y ON x.werte=y.werte AND x.eingang =y.zp AND x.pat_id=y.pat_id AND x.befart=y.fertigstgrad "
				"WHERE NOT ISNULL(y.pat_id) "
				") i ON u.id=i.id set u.pat_id_laborneu=i.pat_id, u.zeitpunktlaborneu=if(i.zp is null,u.zeitpunktlaborneu,i.zp), u.verglichen=now() "
				"WHERE (ISNULL(pat_id_laborneu) OR pat_id_laborneu=0) AND u.eingang between date("+sqlft(My->DBS,&minnachdat)+") and "+sqlft(My->DBS,&maxnachdat)+";",aktc,ZDB,0,0,0,&zahl);
		fLog(dblaus+Txt[T_Abfrage]+schwarz+"3, "+dblau+Txt[T_eingetragen]+schwarz+ltoan(zahl),1,0);

		RS v4(My,"UPDATE `"+tlyus+"` u LEFT JOIN ("
				"SELECT us.id,us.pat_id,us.eingang zp FROM `"+tlyus+"` us INNER JOIN (\n"
				"SELECT GROUP_concat(w.abkü order BY w.abkü) werte, "
				"usi.id, usi.pat_id, gesname(usi.pat_id) name, eingang, befart "
				"FROM `"+tlyus+"` usi LEFT JOIN (SELECT usid,abkü,wert FROM `"+tlywert+"` union SELECT usid,verf,'' FROM `"+tlybakt+"`) w "
				"ON w.usid=usi.id AND (w.wert = '' OR w.wert regexp '[0-9.,:<>]') \n"
				"GROUP BY pat_id,eingang,befart\n"
				") x ON us.pat_id=x.pat_id AND us.eingang=x.eingang AND us.befart=x.befart LEFT JOIN (\n"
				"SELECT pat_id, DATE(zeitpunkt) zp, fertigstgrad, "
				"GROUP_concat(abkü order BY abkü) werte "
				"FROM laborneu WHERE (wert ='' OR wert regexp '[0-9.,:<>]') \n"
				"GROUP BY pat_id,DATE(zeitpunkt),fertigstgrad\n"
				") y ON x.werte=y.werte AND x.eingang =y.zp AND x.pat_id=y.pat_id AND x.befart=y.fertigstgrad "
				"WHERE NOT ISNULL(y.pat_id) "
				") i ON u.id=i.id set u.pat_id_laborneu=i.pat_id, u.zeitpunktlaborneu=if(i.zp is null,u.zeitpunktlaborneu,i.zp), u.verglichen=now() "
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
				") j ON u.id=j.id set u.pat_id_laborneu=j.pat_id, u.zeitpunktlaborneu=if(j.eingang is null,u.zeitpunktlaborneu,j.eingang), u.verglichen=now() "
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
				"AND eingang BETWEEN SUBDATE(zeitpunkt,interval 10 day) AND ADDDATE(zeitpunkt,interval 15 day) "
				"WHERE zahl>3 "
				"GROUP BY i.id,i.eingang,i.pat_id,n.pat_id,DATE(n.zeitpunkt), i.befart) j "
				"WHERE gleiche>2"
				") j ON u.id=j.id set u.pat_id_laborneu=j.pat_id, u.zeitpunktlaborneu=if(j.eingang is null,u.zeitpunktlaborneu,j.eingang), u.verglichen=now() "
				"WHERE (ISNULL(pat_id_laborneu) OR pat_id_laborneu=0) AND u.eingang between date("+sqlft(My->DBS,&minnachdat)+") and "+sqlft(My->DBS,&maxnachdat)+";",aktc,ZDB,0,0,0,&zahl);
		fLog(dblaus+Txt[T_Abfrage]+schwarz+"6, "+dblau+Txt[T_eingetragen]+schwarz+ltoan(zahl),1,0);

//#define fremde
#ifdef fremde
		RS v7(My,"UPDATE `"+tlyus+"` u LEFT JOIN ("
				"SELECT * FROM ("
				"SELECT i.*,n.zeitpunkt,COUNT(w.abkü) gleiche FROM "
				"(SELECT us.id, eingang, pat_id,BefArt, COUNT(wi.id) zahl FROM `"+tlyus+"` us LEFT JOIN `"+tlywert+"` wi "
				"ON us.id=wi.usid AND wi.wert<>'' "
				"WHERE ISNULL(pat_id_laborneu) "
				"GROUP BY us.id) i "
				"LEFT JOIN `"+tlywert+"` w ON w.usid=i.id AND w.wert<>'' "
				"INNER JOIN laborneu n ON n.pat_id<>i.pat_id AND n.abkü=w.abkü AND n.wert=w.wert AND n.fertigstgrad=i.Befart "
				"AND eingang BETWEEN SUBDATE(zeitpunkt,interval 3 day) AND ADDDATE(zeitpunkt,interval 3 day) "
				"WHERE zahl>3 "
				"GROUP BY i.id,i.eingang,i.pat_id,n.pat_id,DATE(n.zeitpunkt), i.befart) j "
				"WHERE gleiche>2"
				") j ON u.id=j.id set u.pat_id_laborneu=j.pat_id, u.zeitpunktlaborneu=if(j.eingang is null,u.zeitpunktlaborneu,j.eingang), u.verglichen=now() "
				"WHERE (ISNULL(pat_id_laborneu) OR pat_id_laborneu=0) AND u.eingang between date("+sqlft(My->DBS,&minnachdat)+") and "+sqlft(My->DBS,&maxnachdat)+";",aktc,ZDB,0,0,0,&zahl);
		fLog(dblaus+Txt[T_Abfrage]+schwarz+"7, "+dblau+Txt[T_eingetragen]+schwarz+ltoan(zahl),1,0);
#endif
	} // 	if (My->obtabspda("laborneu","wert"))
	} // (0)

	{
		const string labor2a{"labor2a"};
		RS view(My,"DROP VIEW IF EXISTS `"+labor2a+"`;"
				"CREATE OR REPLACE ALGORITHM=UNDEFINED DEFINER=`praxis`@`%` SQL SECURITY DEFINER VIEW `"+labor2a+"` AS "
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
				"LEFT JOIN `"+tlyplab+"` l on s.labid=l.id",aktc,ZDB);
	}
	{
		const string labor2aNachw{"labor2aNachw"};
		RS viewN(My,"DROP VIEW IF EXISTS `"+labor2aNachw+"`;"
				"CREATE OR REPLACE ALGORITHM=UNDEFINED DEFINER=`praxis`@`%` SQL SECURITY DEFINER VIEW `"+labor2aNachw+"` AS "
				"SELECT Pat_id, eingang Zeitpunkt,befart FertigStGrad, w.Abkü,w.langtext Langtext, Wert,Einheit "
				",concat(if(e.text rlike '^:[ /\\*:]*$','',if(e.text rlike '^:[ /\\*]*:',concat(mid(e.text,locate(':',e.text,2)+1),';'),if(e.text='.','',if(e.text='','',concat(e.text,';'))))),k.text) Kommentar "
				",NB,uNg, "
				"IF(abkü = 'LDL' AND einheit = 'mg/dl','100',oNg) oNg,"
				"Labor,u.DatID,u.SatzID,u.SatzLänge,u.Auftragsnummer,u.Auftragsschlüssel,u.Eingang,u.Berichtsdatum,u.Nachname,u.Vorname,u.GebDat,Pfad,Erstellungsdatum,geändert "
				"FROM `"+tlyus+"` u "
				"LEFT JOIN `"+tlywert+"` w on u.id=w.usid "
				"LEFT JOIN `"+tlyhinw+"` e on w.erklid=e.id "
				"LEFT JOIN `"+tlyhinw+"` k on w.kommid=k.id "
				"LEFT JOIN `"+tlypnb+"` n on w.nbid=n.id "
				"LEFT JOIN `"+tlysaetze+"` s on u.satzid=s.satzid "
				"LEFT JOIN `"+tlydat+"` d on s.datid=d.datid "
				"LEFT JOIN `"+tlyplab+"` l on s.labid=l.id",aktc,ZDB);
	}

	ZDB=altZDB;
} // void hhcl::nachbearbeit
