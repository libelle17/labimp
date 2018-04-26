#include "kons.h"
#include "DB.h"
#include "labimp.h"

enum Txt_ {
	T_ergpql_volle_Funktion,
	T_auswertpql_volle_Funktion,
	T_tmMAX,
};

// const char *Txvgcl::TextC[T_vgMAX+1][SprachZahl]={
const char *tm_T[T_tmMAX+1][SprachZahl]={
	// T_ergpql_volle_Funktion
	{"ergpql() (volle Funktion)","ergpql() (filled function)"},
	// T_auswertpql_volle_Funktion
	{"auswertpql() (volle Funktion)","auswertpql() (filled function)"},
	{"",""}
}; // const char *Txvgcl::TextC[T_vgMAX+1][SprachZahl]=

// class Txvgcl Txv;
class TxB Txt((const char* const* const* const*)tm_T);


void hhcl::ergpql()
{
	hLog(violetts+Txt[T_ergpql_volle_Funktion]+schwarz);
	pql.insert(pql.begin(),"select pat_id from namen where nachname='"+nname+"' and vorname='"+vname+"' and gebdat="+sqlft(My->DBS,&gebdat)+" and aufndat<="+sqlft(My->DBS,&eingtm));
	pql.insert(pql.begin()+1,"select pat_id from namen where nachname='"+nname+"' and vorname='"+vname+"' and aufndat<="+sqlft(My->DBS,&eingtm));
	pql.insert(pql.begin()+2,"select pat_id from namen where gebdat="+sqlft(My->DBS,&gebdat)+" and aufndat<="+sqlft(My->DBS,&eingtm));
	pql.insert(pql.begin()+3,"select pat_id from namen where gebdat="+sqlft(My->DBS,&gebdat)+" and geschlecht='"+(sgschl=="1"?'m':sgschl=="2"?'w':' ')+"' and aufndat<="+sqlft(My->DBS,&eingtm));
	pql.insert(pql.begin()+4,"select pat_id from namen where nachname='"+nname+"' and gebdat="+sqlft(My->DBS,&gebdat)+" and geschlecht='"+(sgschl=="1"?'m':sgschl=="2"?'w':' ')+"' and aufndat<="+sqlft(My->DBS,&eingtm));
	pql.insert(pql.begin()+5,"select pat_id from namen where nachname='"+nname+"' and gebdat="+sqlft(My->DBS,&gebdat)+" and aufndat<="+sqlft(My->DBS,&eingtm));
	// hier steht dann die Standardvorgabe
	pql<<"select n.pat_id from namen n left join laborneu l on n.pat_id = l.pat_id where n.gebdat="+sqlft(My->DBS,&gebdat)+" and l.zeitpunkt between "
		"subdate("+sqlft(My->DBS,&eingtm)+",interval 5 day) and adddate("+sqlft(My->DBS,&eingtm)+",interval 10 day) group by n.pat_id";
//	pql<<"select n.pat_id from namen n left join laborneu l on n.pat_id = l.pat_id where n.nachname="+nname+" and l.zeitpunkt between "
//		"subdate("+sqlft(My->DBS,&eingtm)+",interval 5 day) and adddate("+sqlft(My->DBS,&eingtm)+",interval 10 day) group by n.pat_id";
} // void hhcl::ergpql

// schwache Funktion, kann ueberdeckt werden
void hhcl::auswertpql(const size_t i,insv& rus)
{
	hLog(violetts+Tx[T_auswertpql_volle_Funktion]+schwarz);
	rus.hz(("Pat_id_"+ltoan(i)).c_str(),pat_id);
}

void hhcl::nachbearbeit(const size_t aktc)
{
	uchar altZDB=ZDB;
	ZDB=1;
	RS vor1(My,"SET group_concat_max_len=15000;",aktc,ZDB);
	RS upd1(My,"update `"+tlyus+"` u left join ("
  "select x.id,y.pat_id,y.zeitpunkt from ("
	"select u.id, u.pat_id, gesname(u.pat_id) name,eingang,group_concat(concat(w.abkü,replace(replace(replace(replace(w.wert,'.',''),'<',''),':',''),'-',''))) werte "
	"from `"+tlyus+"` u left join `"+tlywert+"` w on w.usid=u.id "
  "group by u.eingang) x "
	"left join "
	"(select pat_id, zeitpunkt, group_concat(concat(abkü,replace(replace(replace(replace(wert,'.',''),'<',''),':',''),'-',''))) werte from laborneu group by pat_id,zeitpunkt) y "
	"on x.werte=y.werte and date(x.eingang) =date(y.zeitpunkt) "
	"where not isnull(y.pat_id) "
	") i on u.id=i.id set u.pat_id_laborneu=i.pat_id, u.zeitpunktlaborneu=i.zeitpunkt "
	"where isnull(pat_id_laborneu);"
,aktc,ZDB);
	RS vor2(My,"SET group_concat_max_len=15000;",aktc,ZDB);
	RS upd2(My,"update `"+tlyus+"` u left join ("
  "select x.id,y.pat_id,y.zeitpunkt from ("
	"select u.id, u.pat_id, gesname(u.pat_id) name,eingang,group_concat(concat(w.abkü,replace(replace(replace(replace(w.wert,'.',''),'<',''),':',''),'-',''))) werte "
	"from `"+tlyus+"` u left join `"+tlywert+"` w on w.usid=u.id "
  "group by u.eingang) x "
	"left join "
	"(select pat_id, zeitpunkt, group_concat(concat(abkü,replace(replace(replace(replace(wert,'.',''),'<',''),':',''),'-',''))) werte from laborneu group by pat_id,zeitpunkt) y "
	"on x.werte=y.werte and x.eingang between subdate(y.zeitpunkt, interval 5 day) and adddate(y.zeitpunkt, interval 5 day) "
	"where not isnull(y.pat_id) "
	") i on u.id=i.id set u.pat_id_laborneu=i.pat_id, u.zeitpunktlaborneu=i.zeitpunkt "
	"where isnull(pat_id_laborneu) and eingang<subdate(now(),interval 10 day);"
,aktc,ZDB);
	ZDB=altZDB;
}
