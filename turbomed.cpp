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
void hhcl::usmod(const size_t aktc,svec *zlangtp/*=0*/,svec *zabkp/*=0*/,svec *zwertep/*=0*/,svec *zverfap/*=0*/,tm *eingtmp/*=0*/)
{
	char const nz{'\n'};
	unsigned const akbgrenze{4};
	string const buchzahl{"2"};
	if (!zlangtp) zlangtp=&zlangt;
	if (!zabkp) zabkp=&zabk;
	if (!zwertep) zwertep=&zwerte;
	if (!zverfap) zverfap=&zverfa;
	if (!eingtmp) eingtmp=&eingtm;
	if (!usid.empty()) {
		string gsql{"SELECT l.pat_id,zeitpunkt FROM laborneu l WHERE 1 "};
		gsql+=nz;
		gsql+="AND ";
		if (zwertep->size() || zverfap->size()) {
			gsql+="l.zeitpunkt BETWEEN SUBDATE("+sqlft(My->DBS,eingtmp)+",interval "+(zwertep->size()?"5":"1")+" DAY)"
				                    "AND ADDDATE("+sqlft(My->DBS,eingtmp)+",interval "+(zwertep->size()?"15":"1")+" DAY) "+nz+"AND ";
			if (zwertep->size()) {
				for(size_t i=0;i<zwertep->size();i++) {
#define unscharf
#ifndef unscharf
					gsql+="(SELECT MAX(pat_id) FROM laborneu WHERE fid=l.fid AND zeitpunkt=l.zeitpunkt AND wert="+sqlft(My->DBS,zwertep->at(i))+") IS NOT NULL ";
					if (i!=zverfap->size()-1) {gsql+=nz;gsql+="AND ";}
#else
					gsql+="((SELECT MAX(pat_id) FROM laborneu";
					if (zwertep->size()<akbgrenze) {
						gsql+=" LEFT JOIN laborlangtext USING (LangtextVW)";
					}
					gsql+=" WHERE fid=l.fid AND zeitpunkt=l.zeitpunkt AND wert="+sqlft(My->DBS,zwertep->at(i));
					if (zwertep->size()<akbgrenze) {
						gsql+=" AND (LEFT(Abkü,"+buchzahl+")=LEFT("+sqlft(My->DBS,zabkp->at(i))+","+buchzahl+")";
						gsql+=" OR LEFT(Langtext,"+buchzahl+")=LEFT("+sqlft(My->DBS,zlangtp->at(i))+","+buchzahl+"))";
					}
					gsql+=") IS NOT NULL)";
					if (i!=zwertep->size()-1) {gsql+=nz;gsql+="   +";}
#endif
				}
#ifdef unscharf
				gsql+=">=";
				// so viele Werte bzw. Werte plus Langtexte sollen uebereinstimmen
				gsql+=ltoan(zwertep->size()<6?zwertep->size():zwertep->size()<9?5:zwertep->size()<10?6:zwertep->size()-4);
#endif
			} else {
				for(size_t i=0;i<zverfap->size();i++) {
					gsql+="(SELECT MAX(pat_id) FROM laborneu WHERE fid=l.fid AND zeitpunkt=l.zeitpunkt AND Abkü="+sqlft(My->DBS,zverfap->at(i))+") IS NOT NULL ";
					if (i!=zverfap->size()-1) {gsql+=nz;gsql+="AND ";}
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
							mods+=",Pat_id_Laborneu="+sqlft(My->DBS,**cerg);
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
//			if (rsmod.geaendert) caus<<rot<<"geänderte Sätze: "<<violett<<rsmod.geaendert<<schwarz<<endl;
		}
	} // 	if (!usid.empty())
} // void hhcl::usmod

// fuellt den Vektor pql, dessen Elemente dann in der Funktion pruefPatID verwendet werden, um hhcl::pat_id zu belegen
// ueberdeckt die gleichnamige Funktion in labimp.cpp
// aufgerufen in fuellpql
void hhcl::ergpql()
{
	// pql enthaelt schon einen Eintrag aus fuellpql
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
		RS unbekgschl(My,"UPDATE namen n SET geschlecht = IF((SELECT COUNT(DISTINCT i.geschlecht) FROM (SELECT * FROM namen) i WHERE vorname=n.vorname AND geschlecht<>' ')=1,(SELECT MAX(i.geschlecht) FROM (SELECT * FROM namen) i WHERE vorname=n.vorname AND geschlecht<>' '),n.geschlecht) WHERE geschlecht= ' '",aktc,ZDB);
	}
} // void hhcl::vordverarb


void hhcl::nachbearbeit(const size_t aktc,const uchar obusmod/*=0*/)
{
	uchar altZDB{ZDB};
//	ZDB=1;
	my_ulonglong zahl{0},gzahl{0};
	RS vor(My,"SET @@GROUP_CONCAT_MAX_LEN=150000; ",aktc,ZDB);
	string usbed; // usid-Bedingung, wenn nicht -nurnachb aufgerufen
	// usids.clear(); usids<<"92811";
	if (!usids.empty()) {
		usbed=".ID IN (";
		for(size_t i=0;i<usids.size();i++) {
			usbed+=usids[i];
			if (i==usids.size()-1) usbed+=')'; else usbed+=',';
		}
	} // 	if (!usids.empty())
	const bool oballes{obusmod?0:1};
	if (oballes) {
		if (My->obtabspda("laborneu","wert")) {
			RS v1(My,"UPDATE `"+tlyus+"` u LEFT JOIN ("
					"SELECT us.id,us.pat_id,us.eingang zp FROM `"+tlyus+"` us INNER JOIN (\n"
					"SELECT GROUP_CONCAT(CONCAT(w.abkü,REPLACE(REPLACE(REPLACE(REPLACE(w.wert,'.',''),'<',''),':',''),'-','')) ORDER BY w.abkü,w.wert) werte,"
					"usi.id, usi.pat_id, gesname(usi.pat_id) name, eingang, befart "
					"FROM `"+tlyus+"` usi LEFT JOIN `"+tlywert+"` w ON w.usid=usi.id \n"
					+(usids.empty()?"":"WHERE usi"+usbed)+
					" GROUP BY pat_id,eingang,befart\n"
					") x ON us.pat_id=x.pat_id AND us.eingang=x.eingang AND us.befart=x.befart LEFT JOIN (\n"
					"SELECT GROUP_CONCAT(CONCAT(abkü,REPLACE(REPLACE(REPLACE(REPLACE(wert,'.',''),'<',''),':',''),'-','')) ORDER BY abkü,wert) werte, "
					"pat_id, DATE(zeitpunkt) zp, fertigstgrad "
					"FROM laborneu\n"
					"GROUP BY pat_id,DATE(zeitpunkt),fertigstgrad\n"
					") y ON x.werte=y.werte AND x.eingang =y.zp AND x.pat_id=y.pat_id AND x.befart=y.fertigstgrad "
					"WHERE NOT ISNULL(y.pat_id) "
					+(usids.empty()?"":"AND us"+usbed)+
					") i ON u.id=i.id SET u.pat_id_laborneu=i.pat_id, u.zeitpunktlaborneu=IF(i.zp IS NULL,u.zeitpunktlaborneu,i.zp), u.verglichen=now() "
					"WHERE (ISNULL(pat_id_laborneu) OR pat_id_laborneu=0) "/*AND u.eingang BETWEEN date("+sqlft(My->DBS,&minnachdat)+") AND "+sqlft(My->DBS,&maxnachdat)*/+(usids.empty()?"":" AND u"+usbed)+";",aktc,ZDB,0,0,0,&zahl);
			fLog(dblaus+Txt[T_Abfrage]+schwarz+"1, "+dblau+Txt[T_eingetragen]+schwarz+ltoan(zahl),1,0);

			RS v2(My,"UPDATE `"+tlyus+"` u LEFT JOIN ("
					"SELECT us.id,us.pat_id,us.eingang zp FROM `"+tlyus+"` us INNER JOIN (\n"
					"SELECT GROUP_CONCAT(CONCAT(w.abkü,REPLACE(REPLACE(REPLACE(REPLACE(w.wert,'.',''),'<',''),':',''),'-','')) ORDER BY w.abkü,w.wert) werte, "
					"usi.id, usi.pat_id"/*, gesname(usi.pat_id) name*/", eingang, befart "
					"FROM `"+tlyus+"` usi LEFT JOIN `"+tlywert+"` w ON w.usid=usi.id AND w.wert REGEXP '^-?[0-9.,]+$' \n"
					+(usids.empty()?"":"WHERE usi"+usbed)+
					" GROUP BY pat_id,eingang,befart\n"
					") x ON us.pat_id=x.pat_id AND us.eingang=x.eingang AND us.befart=x.befart LEFT JOIN (\n"
					"SELECT pat_id, DATE(zeitpunkt) zp, fertigstgrad, "
					"GROUP_CONCAT(CONCAT(abkü,REPLACE(REPLACE(REPLACE(REPLACE(wert,'.',''),'<',''),':',''),'-','')) ORDER BY abkü,wert) werte "
					"FROM laborneu WHERE wert REGEXP '^-?[0-9.,]+$' \n"
					"GROUP BY pat_id,DATE(zeitpunkt),fertigstgrad\n"
					") y ON x.werte=y.werte AND x.eingang =y.zp AND x.pat_id=y.pat_id AND x.befart=y.fertigstgrad "
					"WHERE NOT ISNULL(y.pat_id) "
					+(usids.empty()?"":"AND us"+usbed)+
					") i ON u.id=i.id SET u.pat_id_laborneu=i.pat_id, u.zeitpunktlaborneu=IF(i.zp IS NULL,u.zeitpunktlaborneu,i.zp), u.verglichen=now() "
					"WHERE (ISNULL(pat_id_laborneu) OR pat_id_laborneu=0) "/*AND u.eingang BETWEEN date("+sqlft(My->DBS,&minnachdat)+") AND "+sqlft(My->DBS,&maxnachdat)*/+(usids.empty()?"":" AND u"+usbed)+";",aktc,ZDB,0,0,0,&zahl);
			fLog(dblaus+Txt[T_Abfrage]+schwarz+"2, "+dblau+Txt[T_eingetragen]+schwarz+ltoan(zahl),1,0);

			RS v3(My,"UPDATE `"+tlyus+"` u LEFT JOIN ("
					"SELECT us.id,us.pat_id,us.eingang zp FROM `"+tlyus+"` us INNER JOIN (\n"
					"SELECT GROUP_CONCAT(CONCAT(w.abkü,REPLACE(REPLACE(REPLACE(REPLACE(w.wert,'.',''),'<',''),':',''),'-','')) ORDER BY w.abkü,w.wert) werte, "
					"usi.id, usi.pat_id, gesname(usi.pat_id) name, eingang, befart "
					"FROM `"+tlyus+"` usi LEFT JOIN (SELECT usid,abkü,wert FROM `"+tlywert+"` "
					" UNION SELECT usid,verf,'' FROM `"+tlybakt+"`) w ON w.usid=usi.id AND w.wert = '' \n"
					+(usids.empty()?"":"WHERE usi"+usbed)+
					" GROUP BY pat_id,eingang,befart\n"
					") x ON us.pat_id=x.pat_id AND us.eingang=x.eingang AND us.befart=x.befart LEFT JOIN (\n"
					"SELECT pat_id, DATE(zeitpunkt) zp, fertigstgrad, "
					"GROUP_CONCAT(CONCAT(abkü,REPLACE(REPLACE(REPLACE(REPLACE(wert,'.',''),'<',''),':',''),'-','')) ORDER BY abkü,wert) werte "
					"FROM laborneu WHERE wert ='' \n"
					"GROUP BY pat_id,DATE(zeitpunkt),fertigstgrad\n"
					") y ON x.werte=y.werte AND x.eingang =y.zp AND x.pat_id=y.pat_id AND x.befart=y.fertigstgrad "
					"WHERE NOT ISNULL(y.pat_id) "
					+(usids.empty()?"":"AND us"+usbed)+
					") i ON u.id=i.id SET u.pat_id_laborneu=i.pat_id, u.zeitpunktlaborneu=IF(i.zp IS NULL,u.zeitpunktlaborneu,i.zp), u.verglichen=now() "
					"WHERE (ISNULL(pat_id_laborneu) OR pat_id_laborneu=0) "/*AND u.eingang BETWEEN date("+sqlft(My->DBS,&minnachdat)+") AND "+sqlft(My->DBS,&maxnachdat)*/+(usids.empty()?"":" AND u"+usbed)+";",aktc,ZDB,0,0,0,&zahl);
			fLog(dblaus+Txt[T_Abfrage]+schwarz+"3, "+dblau+Txt[T_eingetragen]+schwarz+ltoan(zahl),1,0);

			RS v4(My,"UPDATE `"+tlyus+"` u LEFT JOIN ("
					"SELECT us.id,us.pat_id,us.eingang zp FROM `"+tlyus+"` us INNER JOIN (\n"
					"SELECT GROUP_CONCAT(w.abkü ORDER BY w.abkü) werte, "
					"usi.id, usi.pat_id, gesname(usi.pat_id) name, eingang, befart "
					"FROM `"+tlyus+"` usi LEFT JOIN (SELECT usid,abkü,wert FROM `"+tlywert+"` union SELECT usid,verf,'' FROM `"+tlybakt+"`) w "
					"ON w.usid=usi.id AND (w.wert = '' OR w.wert regexp '[0-9.,:<>]') \n"
					+(usids.empty()?"":"WHERE usi"+usbed)+
					" GROUP BY pat_id,eingang,befart\n"
					") x ON us.pat_id=x.pat_id AND us.eingang=x.eingang AND us.befart=x.befart LEFT JOIN (\n"
					"SELECT pat_id, DATE(zeitpunkt) zp, fertigstgrad, "
					"GROUP_CONCAT(abkü ORDER BY abkü) werte "
					"FROM laborneu WHERE (wert ='' OR wert regexp '[0-9.,:<>]') \n"
					"GROUP BY pat_id,DATE(zeitpunkt),fertigstgrad\n"
					") y ON x.werte=y.werte AND x.eingang =y.zp AND x.pat_id=y.pat_id AND x.befart=y.fertigstgrad "
					"WHERE NOT ISNULL(y.pat_id) "
					+(usids.empty()?"":"AND us"+usbed)+
					") i ON u.id=i.id SET u.pat_id_laborneu=i.pat_id, u.zeitpunktlaborneu=IF(i.zp IS NULL,u.zeitpunktlaborneu,i.zp), u.verglichen=now() "
					"WHERE (ISNULL(pat_id_laborneu) OR pat_id_laborneu=0) "/*AND u.eingang BETWEEN date("+sqlft(My->DBS,&minnachdat)+") AND "+sqlft(My->DBS,&maxnachdat)*/+(usids.empty()?"":" AND u"+usbed)+";",aktc,ZDB,0,0,0,&zahl);
			fLog(dblaus+Txt[T_Abfrage]+schwarz+"4, "+dblau+Txt[T_eingetragen]+schwarz+ltoan(zahl),1,0);

			RS v5(My,"UPDATE `"+tlyus+"` u LEFT JOIN ("
					"SELECT i.*,COUNT(w.abkü) gleiche FROM "
					"(SELECT us.id, eingang, pat_id,BefArt, COUNT(w.id) zahl FROM `"+tlyus+"` us LEFT JOIN `"+tlywert+"` w "
					"ON us.id=w.usid AND w.wert<>'' "
					"WHERE ISNULL(pat_id_laborneu) AND pat_id<>0 "
					+(usids.empty()?"":"AND us"+usbed)+
					" GROUP BY us.id) i "
					"LEFT JOIN `"+tlywert+"` w ON w.usid=i.id AND w.wert<>'' "
					"INNER JOIN laborneu n ON n.pat_id=i.pat_id AND n.abkü=w.abkü AND n.wert=w.wert AND n.fertigstgrad=i.Befart AND DATE(n.zeitpunkt)=i.eingang "
					"WHERE zahl>2 "
					"GROUP BY i.id,i.eingang,i.pat_id,i.befart"
					") j ON u.id=j.id SET u.pat_id_laborneu=j.pat_id, u.zeitpunktlaborneu=IF(j.eingang IS NULL,u.zeitpunktlaborneu,j.eingang), u.verglichen=now() "
					"WHERE (ISNULL(pat_id_laborneu) OR pat_id_laborneu=0) "/*AND u.eingang BETWEEN date("+sqlft(My->DBS,&minnachdat)+") AND "+sqlft(My->DBS,&maxnachdat)*/+(usids.empty()?"":" AND u"+usbed)+";",aktc,ZDB,0,0,0,&zahl);
			fLog(dblaus+Txt[T_Abfrage]+schwarz+"5, "+dblau+Txt[T_eingetragen]+schwarz+ltoan(zahl),1,0);

			RS v6(My,"UPDATE `"+tlyus+"` u LEFT JOIN ("
					"SELECT * FROM ("
					"SELECT i.*,n.zeitpunkt,COUNT(w.abkü) gleiche FROM "
					"(SELECT us.id, eingang, pat_id,BefArt, COUNT(w.id) zahl FROM `"+tlyus+"` us LEFT JOIN `"+tlywert+"` w "
					"ON us.id=w.usid AND w.wert<>'' "
					"WHERE ISNULL(pat_id_laborneu) AND pat_id<>0 "
					+(usids.empty()?"":"AND us"+usbed)+
					" GROUP BY us.id) i "
					"LEFT JOIN `"+tlywert+"` w ON w.usid=i.id AND w.wert<>'' "
					"INNER JOIN laborneu n ON n.pat_id=i.pat_id AND n.abkü=w.abkü AND n.wert=w.wert AND n.fertigstgrad=i.Befart "
					"AND eingang BETWEEN SUBDATE(zeitpunkt,interval 10 day) AND ADDDATE(zeitpunkt,interval 15 day) "
					"WHERE zahl>3 "
					"GROUP BY i.id,i.eingang,i.pat_id,n.pat_id,DATE(n.zeitpunkt), i.befart) j "
					"WHERE gleiche>2"
					") j ON u.id=j.id SET u.pat_id_laborneu=j.pat_id, u.zeitpunktlaborneu=IF(j.eingang IS NULL,u.zeitpunktlaborneu,j.eingang), u.verglichen=now() "
					"WHERE (ISNULL(pat_id_laborneu) OR pat_id_laborneu=0) "/*AND u.eingang BETWEEN date("+sqlft(My->DBS,&minnachdat)+") AND "+sqlft(My->DBS,&maxnachdat)*/+(usids.empty()?"":" AND u"+usbed)+";",aktc,ZDB,0,0,0,&zahl);
			fLog(dblaus+Txt[T_Abfrage]+schwarz+"6, "+dblau+Txt[T_eingetragen]+schwarz+ltoan(zahl),1,0);

			//#define fremde
#ifdef fremde
			RS v7(My,"UPDATE `"+tlyus+"` u LEFT JOIN ("
					"SELECT * FROM ("
					"SELECT i.*,n.zeitpunkt,COUNT(w.abkü) gleiche FROM "
					"(SELECT us.id, eingang, pat_id,BefArt, COUNT(wi.id) zahl FROM `"+tlyus+"` us LEFT JOIN `"+tlywert+"` wi "
					"ON us.id=wi.usid AND wi.wert<>'' "
					"WHERE ISNULL(pat_id_laborneu) "
					+(usids.empty()?"":"AND us"+usbed)+
					" GROUP BY us.id) i "
					"LEFT JOIN `"+tlywert+"` w ON w.usid=i.id AND w.wert<>'' "
					"INNER JOIN laborneu n ON n.pat_id<>i.pat_id AND n.abkü=w.abkü AND n.wert=w.wert AND n.fertigstgrad=i.Befart "
					"AND eingang BETWEEN SUBDATE(zeitpunkt,interval 3 day) AND ADDDATE(zeitpunkt,interval 3 day) "
					"WHERE zahl>3 "
					"GROUP BY i.id,i.eingang,i.pat_id,n.pat_id,DATE(n.zeitpunkt), i.befart) j "
					"WHERE gleiche>2"
					") j ON u.id=j.id SET u.pat_id_laborneu=j.pat_id, u.zeitpunktlaborneu=IF(j.eingang IS NULL,u.zeitpunktlaborneu,j.eingang), u.verglichen=now() "
					"WHERE (ISNULL(pat_id_laborneu) OR pat_id_laborneu=0) "/*AND u.eingang BETWEEN date("+sqlft(My->DBS,&minnachdat)+") AND "+sqlft(My->DBS,&maxnachdat)*/+(usids.empty()?"":" AND u"+usbed)+";",aktc,ZDB,0,0,0,&zahl);
			fLog(dblaus+Txt[T_Abfrage]+schwarz+"7, "+dblau+Txt[T_eingetragen]+schwarz+ltoan(zahl),1,0);
#endif
			gzahl=0;
			// mit einem group weniger dürfte es auch ohne while gehen, hier will ich aber keinen Fehler machen
			// wenn zu Laborwerten mit selber Auftragsnummer und selbem Eingangsdatum, aber verschiedenen Pat_id sich zur ersten Pat_id kein
			// Eintrag in laborneu findet, dann wende die 2. Pat_id auch auf die ersetzen Sätze an
			RS begin(My,"BEGIN",aktc,obverb);
			while (1) {
				RS labneu1leer(My,"SELECT l1.id ID, l2.pat_id P2 "
						"FROM laboryus l1 LEFT JOIN laboryus l2 USING (eingang,auftragsschlüssel) "
						"LEFT JOIN laborydat d1 ON d1.datid=l1.datid "
						"LEFT JOIN laborydat d2 ON d2.datid=l2.datid "
						"LEFT JOIN laborneu ln ON ln.pat_id=l1.pat_id AND DATE(ln.zeitpunkt)=l1.eingang "
						"WHERE l1.pat_id<>l2.pat_id AND l1.pat_id<>0 AND l2.pat_id<>0 AND d1.geändert>d2.geändert "
						"AND ISNULL(ln.abkü) "
						"AND l1.eingang<SUBDATE(NOW(),INTERVAL 5 DAY) "
						"GROUP BY l1.pat_id,l2.pat_id,l1.eingang;"
						,aktc,ZDB);
				char ***cergb{0};
				zahl=0;
				while (cergb=labneu1leer.HolZeile(),cergb?*cergb&&**cergb:0) {
					caus<<"     "<<blau<<cjj(cergb,0)<<schwarz<<" "<<cjj(cergb,1)<<endl;
					RS korr(My,string("UPDATE laboryus SET pat_id=")+cjj(cergb,1)+" WHERE ID="+cjj(cergb,0),aktc,ZDB,0,0,0,&zahl);
					gzahl+=zahl;
				}
				if (!zahl) break;
			}
			RS commit(My,"COMMIT",aktc,obverb);
			fLog(dblaus+Txt[T_Abfrage]+schwarz+"laborneu1leer, "+dblau+Txt[T_eingetragen]+schwarz+ltoan(gzahl),1,0);
			// s.o.; wenn zu Laborwerten mit selber Auftragsnummer und selbem Eingangsdatum, aber verschiedenen Pat_id sich zur zweiten Pat_id kein
			// Eintrag in laborneu findet, dann wende die 1. Pat_id auch auf die zweiten Sätze an
			gzahl=0;
			while (1) {
				RS labneu2leer(My,"SELECT l2.id ID, l1.pat_id P1 "
						"FROM laboryus l1 LEFT JOIN laboryus l2 USING (eingang,auftragsschlüssel) "
						"LEFT JOIN laborydat d1 ON d1.datid=l1.datid "
						"LEFT JOIN laborydat d2 ON d2.datid=l2.datid "
						"LEFT JOIN laborneu ln ON ln.pat_id=l2.pat_id AND DATE(ln.zeitpunkt)=l1.eingang "
						"WHERE l1.pat_id<>l2.pat_id AND l1.pat_id<>0 AND l2.pat_id<>0 AND d1.geändert>d2.geändert "
						"AND ISNULL(ln.abkü) "
						"AND l1.eingang<SUBDATE(NOW(),INTERVAL 5 DAY) "
						"GROUP BY l1.pat_id,l2.pat_id,l1.eingang;"
						,aktc,ZDB);
				char ***cergb{0};
				zahl=0;
				while (cergb=labneu2leer.HolZeile(),cergb?*cergb&&**cergb:0) {
					caus<<"     "<<blau<<cjj(cergb,0)<<schwarz<<" "<<cjj(cergb,1)<<endl;
					RS korr(My,string("UPDATE laboryus SET pat_id=")+cjj(cergb,1)+" WHERE ID="+cjj(cergb,0),aktc,ZDB,0,0,0,&zahl);
					gzahl+=zahl;
				}
				if (!zahl) break;
			}
			fLog(dblaus+Txt[T_Abfrage]+schwarz+"laborneu2leer, "+dblau+Txt[T_eingetragen]+schwarz+ltoan(gzahl),1,0);
			// wenn sich zur ersten pat_id kein Kassenfall findet, dann zweite nehmen
			gzahl=0;
			while (1) {
				RS fall1leer(My,"SELECT l1.id, l2.pat_id P2 "
						"FROM laboryus l1 LEFT JOIN laboryus l2 USING (eingang,auftragsschlüssel) "
						"LEFT JOIN laborydat d1 ON d1.datid=l1.datid "
						"LEFT JOIN laborydat d2 ON d2.datid=l2.datid "
						"LEFT JOIN faelle f ON f.pat_id=l1.pat_id AND l1.eingang BETWEEN f.bhfb AND f.bhfe1 "
						"WHERE l1.pat_id<>l2.pat_id AND l1.pat_id<>0 AND l2.pat_id<>0 AND d1.geändert>d2.geändert "
						"AND ISNULL(f.fid) AND(select MAX(schgr) FROM faelle "
						" WHERE pat_id=l1.pat_id AND bhfb=(SELECT MAX(bhfb) FROM faelle WHERE pat_id=l1.pat_id))<>90 "
						"AND l1.eingang<SUBDATE(NOW(),INTERVAL 5 DAY) "
						"GROUP BY l1.pat_id,l2.pat_id,l1.eingang;"
						,aktc,ZDB);
				char ***cergb{0};
				zahl=0;
				while (cergb=fall1leer.HolZeile(),cergb?*cergb&&**cergb:0) {
					caus<<"     "<<blau<<cjj(cergb,0)<<schwarz<<" "<<cjj(cergb,1)<<endl;
					RS korr(My,string("UPDATE laboryus SET pat_id=")+cjj(cergb,1)+" WHERE ID="+cjj(cergb,0),aktc,ZDB,0,0,0,&zahl);
					gzahl+=zahl;
				}
				if (!zahl) break;
			}
			fLog(dblaus+Txt[T_Abfrage]+schwarz+"fall1leer, "+dblau+Txt[T_eingetragen]+schwarz+ltoan(gzahl),1,0);
			// wenn sich zur zweiten pat_id kein Kassenfall findet, dann erste nehmen
			gzahl=0;
			while (1) {
				RS fall2leer(My,"SELECT l2.id, l1.pat_id P1 "
						"FROM laboryus l1 LEFT JOIN laboryus l2 USING (eingang,auftragsschlüssel) "
						"LEFT JOIN laborydat d1 ON d1.datid=l1.datid "
						"LEFT JOIN laborydat d2 ON d2.datid=l2.datid "
						"LEFT JOIN faelle f ON f.pat_id=l2.pat_id AND l1.eingang BETWEEN f.bhfb AND f.bhfe1 "
						"WHERE l1.pat_id<>l2.pat_id AND l1.pat_id<>0 AND l2.pat_id<>0 AND d1.geändert>d2.geändert "
						"AND ISNULL(f.fid) AND(select MAX(schgr) FROM faelle "
						" WHERE pat_id=l2.pat_id AND bhfb=(SELECT MAX(bhfb) FROM faelle WHERE pat_id=l2.pat_id))<>90 "
						"AND l1.eingang<SUBDATE(NOW(),INTERVAL 5 DAY) "
						"GROUP BY l1.pat_id,l2.pat_id,l1.eingang;"
						,aktc,ZDB);
				char ***cergb{0};
				zahl=0;
				while (cergb=fall2leer.HolZeile(),cergb?*cergb&&**cergb:0) {
					caus<<"     "<<blau<<cjj(cergb,0)<<schwarz<<" "<<cjj(cergb,1)<<endl;
					RS korr(My,string("UPDATE laboryus SET pat_id=")+cjj(cergb,1)+" WHERE ID="+cjj(cergb,0),aktc,ZDB,0,0,0,&zahl);
					gzahl+=zahl;
				}
				if (!zahl) break;
			}
			fLog(dblaus+Txt[T_Abfrage]+schwarz+"fall2leer, "+dblau+Txt[T_eingetragen]+schwarz+ltoan(gzahl),1,0);
			// wenn pat_id_7 identisch, dann dieses nehmen (für l1)
			gzahl=0;
			while (1) {
				RS p7fuerl1(My,"SELECT l1.id, l1.pat_id_7 "
						"FROM laboryus l1 LEFT JOIN laboryus l2 USING (eingang,auftragsschlüssel) "
						"LEFT JOIN laborydat d1 ON d1.datid=l1.datid "
						"LEFT JOIN laborydat d2 ON d2.datid=l2.datid "
						"WHERE l1.pat_id<>l2.pat_id AND l1.pat_id<>0 AND l2.pat_id<>0 AND d1.geändert>d2.geändert "
						"AND l1.pat_id_7=l2.pat_id_7 "
						"AND l1.pat_id<>l1.pat_id_7 "
						"AND l1.eingang<SUBDATE(NOW(),INTERVAL 5 DAY) "
						"GROUP BY l1.pat_id,l2.pat_id,l1.pat_id_7,l2.pat_id_7,l1.eingang;"
						,aktc,ZDB);
				char ***cergb{0};
				zahl=0;
				while (cergb=p7fuerl1.HolZeile(),cergb?*cergb&&**cergb:0) {
					caus<<"     "<<blau<<cjj(cergb,0)<<schwarz<<" "<<cjj(cergb,1)<<endl;
					RS korr(My,string("UPDATE laboryus SET pat_id=")+cjj(cergb,1)+" WHERE ID="+cjj(cergb,0),aktc,ZDB,0,0,0,&zahl);
					gzahl+=zahl;
				}
				if (!zahl) break;
			}
			fLog(dblaus+Txt[T_Abfrage]+schwarz+"p7fuerl1, "+dblau+Txt[T_eingetragen]+schwarz+ltoan(gzahl),1,0);
			// wenn pat_id_7 identisch, dann dieses nehmen (für l2)
			gzahl=0;
			while (1) {
				RS p7fuerl2(My,"SELECT l2.id, l1.pat_id_7 "
						"FROM laboryus l1 LEFT JOIN laboryus l2 USING (eingang,auftragsschlüssel) "
						"LEFT JOIN laborydat d1 ON d1.datid=l1.datid "
						"LEFT JOIN laborydat d2 ON d2.datid=l2.datid "
						"WHERE l1.pat_id<>l2.pat_id AND l1.pat_id<>0 AND l2.pat_id<>0 AND d1.geändert>d2.geändert "
						"AND l1.pat_id_7=l2.pat_id_7 "
						"AND l2.pat_id<>l1.pat_id_7 "
						"AND l1.eingang<SUBDATE(NOW(),INTERVAL 5 DAY) "
						"GROUP BY l1.pat_id,l2.pat_id,l1.pat_id_7,l2.pat_id_7,l1.eingang;"
						,aktc,ZDB);
				char ***cergb{0};
				zahl=0;
				while (cergb=p7fuerl2.HolZeile(),cergb?*cergb&&**cergb:0) {
					caus<<"     "<<blau<<cjj(cergb,0)<<schwarz<<" "<<cjj(cergb,1)<<endl;
					RS korr(My,string("UPDATE laboryus SET pat_id=")+cjj(cergb,1)+" WHERE ID="+cjj(cergb,0),aktc,ZDB,0,0,0,&zahl);
					gzahl+=zahl;
				}
				if (!zahl) break;
			}
			fLog(dblaus+Txt[T_Abfrage]+schwarz+"p7fuerl2, "+dblau+Txt[T_eingetragen]+schwarz+ltoan(gzahl),1,0);
		} // 	if (My->obtabspda("laborneu","wert"))
		// KLZ // (0)
	} // (oballes)
	// usmod wird normalerweise (obusmod==0) nicht hier aufgerufen, sondern einzeln
	if (obusmod) {
		if (1) {
			RS selid(My,"SELECT id,eingang FROM `"+tlyus+"` u WHERE 1"+(usids.empty()?"":" AND u"+usbed),aktc,ZDB);
			char ***cerg{0};
			while (cerg=selid.HolZeile(),cerg?*cerg&&**cerg:0) {
				svec zzwerte,zzlangt,zzabk,zzverfa;
				tm eingtm{0};
				usid=cjj(cerg,0);
				strptime(cjj(cerg,1),"%Y-%m-%d",&eingtm);
				RS werte(My,"SELECT wert,langtext,abkü FROM `"+tlywert+"` w WHERE usid="+usid+" AND wert<>'' LIMIT 9",aktc,ZDB);
				char ***cergw{0};
				while (cergw=werte.HolZeile(),cergw?*cergw&&**cergw:0) {
					caus<<" "<<dblau<<cjj(cergw,0)<<schwarz<<" "<<violett<<cjj(cergw,1)<<schwarz<<endl;
					zzwerte<<cjj(cergw,0);
					zzlangt<<cjj(cergw,1);
					zzabk<<cjj(cergw,2);
				}
				RS lab(My,"SELECT verf FROM `"+tlybakt+"` w WHERE usid="+usid+" AND verf<>''",aktc,ZDB);
				char ***cergb{0};
				while (cergb=lab.HolZeile(),cergb?*cergb&&**cergb:0) {
					caus<<"     "<<blau<<cjj(cergb,0)<<schwarz<<endl;
					zzverfa<<cjj(cergb,0);
				}
				caus<<blau<<"usid: "<<violett<<usid<<schwarz<<" "<<ztacl(&eingtm)<<endl;
				usmod(aktc,&zzlangt,&zzabk,&zzwerte,&zzverfa,&eingtm);
			}
		}
		// falsche Eintraege loeschen
		string rsid[]{
			"DELETE FROM `"+tlyus+"` WHERE auftragsschlüssel='0511249475' and auftragsnummer='11249475' and pat_id=1558",
		};
		for(size_t i=0;i<sizeof rsid/sizeof *rsid;i++) {
			RS rsloe(My,rsid[i],aktc,1);
		}
	} // obusmod
	ZDB=altZDB;
} // void hhcl::nachbearbeit
