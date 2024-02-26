#include <iostream>
#include "elsobbsegi_sor.h"
#include "todoList.h"
using namespace std;

template<class T>
Elsobbsegi_Sor<T> :: Elsobbsegi_Sor(int max_meret)	
{
	this->max_meret = max_meret;
	this->max_kupac = new Elem[this->max_meret];
	this->meret = 0;

} 

template<class T>
void Elsobbsegi_Sor<T> :: push(T adat, int kulcs)
{
	if (!tele())
	{
		Elem uj_elem = { adat,kulcs };
		this->meret++;
		this->max_kupac[this->meret] = uj_elem;
		max_kupacol(meret);
	}
	else
	{
		cout << "A lista megtelt , az uj elem nem kerult be." << endl;
	}
}

template<class T>
bool Elsobbsegi_Sor<T> :: tele()
{
	if (meret == max_meret-1)
	{
		return true;
	}
	return false;
}

template<class T>
bool Elsobbsegi_Sor<T> ::ures()
{
	if (meret == 0)
	{
		return true;
	}
	return false;
}

template<class T>
void Elsobbsegi_Sor<T> :: pop_max()
{
	if (meret == 0)
	{
		return;
	}

	int max_elem = max_kupac[1].kulcs;
	max_kupac[1] = max_kupac[meret];
	meret--;

	int index = 1;
	while (true)
	{
		int bal = 2 * index;
		int jobb = 2 * index + 1;
		int max_gyerek = index;	
		if (bal <= meret && max_kupac[bal].kulcs > max_kupac[max_gyerek].kulcs)
		{
			max_gyerek = bal;
		}
		if (jobb <= meret && max_kupac[jobb].kulcs > max_kupac[max_gyerek].kulcs)
		{
			max_gyerek = jobb;
		}
		if (max_gyerek != index)
		{
			swap(max_kupac[index], max_kupac[max_gyerek]);
			index = max_gyerek;
		}
		else
		{
			break;
		}
	}

	return;
}

template<class T>
void Elsobbsegi_Sor<T> :: kulcs_modositasa(int i,int ertek)
{															
	max_kupac[i].kulcs = ertek;
	max_kupacol(i);
}


template<class T>
int Elsobbsegi_Sor<T> :: search_max()
{
	if (meret == 0) 
	{
		return 0; 
	}
	return max_kupac[1].kulcs;
}

template<class T>
void Elsobbsegi_Sor<T> :: max_kupacol(int i)
{
	while (i > 1) 
	{
		int szulo = i/2;
		if (max_kupac[szulo].kulcs < max_kupac[i].kulcs) 
		{
			swap(max_kupac[szulo], max_kupac[i]);
			i = szulo;
		}
		else 
		{
			break;
		}
	}

}

template<class T>
void Elsobbsegi_Sor<T> :: max_kupacot_epit(int* A, int n)
{
	for (int i = 1; i <=n; i++)
	{
		push("", A[i]);
	}
}

template<class T>
void Elsobbsegi_Sor<T> :: rendez()
{
	for (int i = 1; i <meret; i++)
	{
		for (int j = i + 1; j <= meret; j++)
		{
			if (max_kupac[i].kulcs < max_kupac[j].kulcs)
			{
				swap(max_kupac[i], max_kupac[j]);
			}
		}
	}
}

template<class T>
int Elsobbsegi_Sor<T>::merete()
{
	return meret;
}

template<class T>			
Elsobbsegi_Sor<T> :: ~Elsobbsegi_Sor()
{
	delete[]max_kupac;
}
