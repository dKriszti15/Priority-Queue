#ifndef ES_H
#define ES_H
#include <string>
using namespace std;

template<class T>
class Elsobbsegi_Sor
{
	struct Elem
	{
		T adat;
		int kulcs=0;
	};
	Elem* max_kupac;
	int meret;
	int max_meret;

public:
	Elsobbsegi_Sor(int);				//Letrehoz egy adott maximalis meretu elsobbsegi sort
	void max_kupacot_epit(int*, int);	//Egy adott tombbol maximumkupacot kepez
	void push(T,int);					//Beszur egy uj elemet az elsobbsegi sor vegere
	void pop_max();						//Kitorli a legnagyobb prioritasu elemet a varakozasi sorbol,majd helyreallitja a max_kupactulajdonsagot
	void max_kupacol(int);				//Beallitja a max_kupactulajdonsagot a megadott indexu elemre(termeszetesen a kulcs alapjan)
	void kulcs_modositasa(int,int);		//Modositja a max_kupac egy adott indexu elemenek kulcsat egy adott ertekre majd "max_kupacolja" az elemet az uj kulcs alapjan
	int search_max();					//Visszateriti a legnagyobb prioritasu elemet
	void rendez();						//Rendezi a max_kupacot kulcs szerinti csokkeno sorrendbe
	bool tele();						//Igazat terit vissza , ha az elsobbsegi sor tele van , hamisat , ha nem
	bool ures();						//Igazat terit vissza , ha az elsobbsegi sor ures , hamisat , ha nem
	int merete();						//Visszateriti a kupac meretet
	~Elsobbsegi_Sor();					//felszabaditja az elsobbsegi sornak lefoglalt memoriat
};

#endif