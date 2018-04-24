#include "kons.h"
#include "DB.h"
#include "labimp.h"

enum Txt_ {
	T_ergpql_volle_Funktion,
	T_tmMAX,
};

// const char *Txvgcl::TextC[T_vgMAX+1][SprachZahl]={
const char *tm_T[T_tmMAX+1][SprachZahl]={
	// T_ergpql_volle_Funktion
	{"ergpql() (volle Funktion)","ergpql() (filled function)"},
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
	pql<<"select n.pat_id from namen n left join laborneu l on n.pat_id = l.pat_id where n.nachname="+nname+" and l.zeitpunkt between "
		"subdate("+sqlft(My->DBS,&eingtm)+",interval 5 day) and adddate("+sqlft(My->DBS,&eingtm)+",interval 10 day) group by n.pat_id";
} // void hhcl::ergpql
