#pragma once
#include "cLista.h"
#include "cPista.h"

using namespace std;

class ListaPistas : public cLista<cPista> {

public:
	ListaPistas() {}
	~ListaPistas() {}
	void IgualarPistas(ListaPistas* nuevaLista)
	{
		if (nuevaLista == NULL)
			throw new exception("Lista vacia");
		if (nuevaLista->getCA() > ct)
			throw new exception("Nueva lista supera el tamaño posible para almacenar");
		int i = 0;
		for (i = 0; i < nuevaLista->getCA(); i++)
		{
			this->lista[i] = (*nuevaLista)[i];
		}
	}
	bool operator+(cPista* puntero)
	{
		int i = 0;
		int pos = getItemPos(puntero);
		if (ca < ct && pos == -1) {
			ca++;
			lista[ca] = puntero;
			return true;
		}
		return false;

	}

	void Listar()
	{
		for (int i = 0; i < ca; i++)
		{
			lista[i]->ImprimirDatos();
		}
	}

};