#pragma once
#include <string>
#include <iostream>
using namespace std;
class cPista
{
	const int numPista; //uso de static
	const int tamanio; //uso de const
	const float largo; //uso de const
	bool ocupada;
public:
	friend class cTorreControl;
	cPista(const int _tamanio, const float _largo, const int num);
	~cPista();
	void Ocupar();
	void Desocupar();
	void ImprimirDatos();
	bool getOcupada();
	int getID()const;
	int getTamanio()const;
	float getDistancia()const;

};

