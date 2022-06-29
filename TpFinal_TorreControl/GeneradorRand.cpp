#include "GeneradorRand.h"

GeneradorRand::GeneradorRand()
{
}

GeneradorRand::~GeneradorRand()
{
}

cAvion* GeneradorRand::AvionRandom(cLista<cAvion>* listaAviones)
{
	if (listaAviones != NULL)
	{
		srand(time(NULL)); //semilla random 
		int limite = listaAviones->getCA();
		int random = 1 + rand() % limite; //numero random del 1 al ca de la lista
		return (*listaAviones)[random];
	}
	return NULL;
}

//cPista* GeneradorRand::PistaRandom(ListaPistas* listaPistas)
//{
//	if (listaPistas != NULL)
//	{
//		srand(time(NULL)); //semilla random 
//		int limite = listaPistas->getCA();
//		int random = 1 + rand() % limite; //numero random del 1 al ca de la lista
//		return (*listaPistas)[random];
//	}
//	return NULL;
//}
