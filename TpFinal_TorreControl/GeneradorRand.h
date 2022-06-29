#pragma 
#include "cBiplano.h"
#include "cCESSNA.h"
#include "ListaPistas.h"
class GeneradorRand
{


public:
	GeneradorRand();
	~GeneradorRand();
	cAvion* AvionRandom(cLista<cAvion>* listaAviones);
	//cPista* PistaRandom(ListaPistas* listaPistas);

};

