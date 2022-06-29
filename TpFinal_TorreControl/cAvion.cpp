#include "cAvion.h"
int cAvion::ID = 0;
cAvion::cAvion(int _cantcombustible, int _pasajerosmax, int _tamanio)
{
	this->cantcombustible = _cantcombustible;
	this->pasajerosmax = _pasajerosmax;
	this->tamanio = _tamanio;
	ID++;
	this->pasajeros = 0;
	this->velocidad = 0;
	this->helice = 0;
	this->tiempomaxvuelo = 0;
	setTiempoVuelo();
	this->pistaAsiganda = NULL;
	this->estado = eEstado::enEspera;
}

cAvion::~cAvion()
{
}

void cAvion::Despegar(cPista* pista)
{
	Cronometro(tiempomaxvuelo);
	pistaAsiganda = pista;
	pista->Ocupar();
	time_t current_time = time(0);
	while (time(0) - current_time < (float)5)
	{
		estado = eEstado::Despegando;
	}
}

void cAvion::Aterrizar(cPista* pista)
{
	Cronometro(-1);
	pistaAsiganda = pista;
	pista->Ocupar();
	//tiempo default de aterrizaje 5 segundos
	time_t current_time = time(0);
	while (time(0) - current_time < (float)5)
	{
		estado = eEstado::Aterrizando;
	}
}

void cAvion::setTiempoVuelo()
{
	//gasta 5 litros por segundo
	tiempomaxvuelo = ((float)cantcombustible / (float) 5);
}

void cAvion::ImprimirDatos()
{
	cout << this->toString() << endl;
}

string cAvion::toString()
{
	return "Avion de ID numero " + to_string(ID) + "\nCombustible: "+to_string(cantcombustible) + "\nTiempo maximo de vuelo: " + to_string(tiempomaxvuelo) +
		"\nCantidad de pasajeros: " + to_string(pasajeros) + "\nEstado: " + EstadoToString(estado);
}

void cAvion::operator++()
{
	if (pasajeros > pasajerosmax)
		throw new exception("No hay mas espacip en el avion");

	pasajeros++;
}
