#include "cCESSNA.h"

cCESSNA::cCESSNA(int _cantcombustible, int _pasajerosmax, int _tamanio, eModelo _modelo) : cAvion(_cantcombustible, _pasajerosmax, _tamanio)
{
	this->modelo = _modelo;
	this->helice = 1;
	this->pasajerosmax = 0;
	this->aceleracion = 0;
	this->carga = 0;
	setDatos();
}

cCESSNA::~cCESSNA()
{
}

/// Segun el modelo de cessna, se le asigna una aceleracion
void cCESSNA::setDatos()
{
	if (ModeloToString(modelo) == "A1") {
		aceleracion = 20;
		pasajerosmax = 13;
		carga = 90;
	}
	else if (ModeloToString(modelo) == "B2") {
		aceleracion = 50;
		pasajerosmax = 12;
		carga = 150;
	}
}

void cCESSNA::Despegar(cPista* pista)
{
	cout << "--------Despegue del CESSNA " << to_string(ID) << ":--------" << endl;
	this->velocidad = 200;
	cout << "Bajando alerones del avion " << endl;
	cout << "Activando control automatico del avion " << endl;
	estado = eEstado::Volando;
	pista->Desocupar();
	pistaAsiganda = NULL;
}

void cCESSNA::Aterrizar(cPista* pista)
{
	cout << "--------Aterrizaje del CESSNA " << to_string(ID) << ":--------" << endl;
	cout << "Subiendo alerones del avion " << endl;
	cout << "Desactivando control automatico del avion " << endl;
	estado = eEstado::enEspera;
	this->velocidad = 0;
	pistaAsiganda->Desocupar();
	pistaAsiganda = NULL;
}

void cCESSNA::ImprimirDatos()
{
}

float cCESSNA::Distancia() 
{
	float _acel = (float)aceleracion;
	float tiempo = (float)velocidad / _acel;
	float distancia = 1 / 2 * _acel * (tiempo * tiempo);
	return distancia;
}

float cCESSNA::TiempoUsoPista()
{
	float tiempo = (float)velocidad / aceleracion;
	return tiempo;
}


istream& operator>>(istream& input, cCESSNA* cessna)
{
	input >> cessna->carga;
	return input;
}
