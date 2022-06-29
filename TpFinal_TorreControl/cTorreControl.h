#pragma once
#include "ListaPistas.h" //ver si conviene que el include de lista este aca
#include "cCESSNA.h"
#include "cBiplano.h"
#include <stdio.h>
using namespace std;
class cTorreControl
{
private:
	cLista<cAvion>* ListaAviones;
	ListaPistas* Pistas;

public:
	cTorreControl();
	cTorreControl(cLista<cAvion>* _ListaAviones, ListaPistas* _Pistas);
	~cTorreControl();
	cPista* AsignarPista(cAvion* avion);
	//void EstadoAvion();
	//cLista<cPista>* subListaPistasLibres();

//probando:
	bool AgregarPista(cPista* pista);
	bool AgregarAvion(cAvion* avion);

	void ImprimirAvionesEnVuelo();
	void ImprimirAvionesAterrizando();
	void ImprimirAvionesDespegando();
	void ImprimirPistasLibres();

	void DespegarAvion(cAvion* avion);
	void AterrizarAvion(cAvion* avion);

	bool PistasOcupadas();

	void LlamarComando(cAvion* avion);
};

