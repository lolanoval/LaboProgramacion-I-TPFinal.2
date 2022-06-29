#include "cPista.h"

cPista::cPista(const int _tamanio, const float _largo, const int num):numPista(num),largo(_largo), tamanio(_tamanio)
{
	this->ocupada = false;
}

cPista::~cPista()
{

}

void cPista::Ocupar()
{
	this->ocupada = true;
}

void cPista::Desocupar()
{
	this->ocupada = false;
}

void cPista::ImprimirDatos()
{
	string estado;
	if (getOcupada())
		estado = "Ocupada";
	if (!(getOcupada()))
		estado = "Libre";

	cout << "Datos de la pista numero " << to_string(numPista) << endl;
	cout << "Ancho: " << getTamanio() << endl;
	cout << "Largo: " << to_string(largo) << endl;
	cout << "Estado: " << estado << endl;
}

bool cPista::getOcupada() 
{
	return ocupada;
}

int cPista::getID() const
{
	return numPista;
}

int cPista::getTamanio() const
{
	return tamanio;
}

float cPista::getDistancia() const
{
	return largo;
}

