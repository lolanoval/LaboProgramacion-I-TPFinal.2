#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS
#include "cFecha.h"
#include <string>
cFecha::cFecha() {
	fecha.tm_hour = 0;
	fecha.tm_min = 0;
	fecha.tm_sec = 0;
	fecha.tm_mday = 0;
	fecha.tm_mon = 0;
	fecha.tm_year = 0;
	SetHoy();
	fecha.tm_wday = 0;
	fecha.tm_yday = 0;
	fecha.tm_isdst = 0;
}

cFecha::cFecha(int d, int m, int a)
{
	fecha.tm_hour = 0;
	fecha.tm_min = 0;
	fecha.tm_sec = 0;
	fecha.tm_mday = d;
	fecha.tm_mon = m - 1;
	fecha.tm_year = a - 1900;
	fecha.tm_wday = 0;
	fecha.tm_yday = 0;
	fecha.tm_isdst = 0;
}

cFecha::cFecha(int d, int m, int a, int hs, int min) {

	fecha.tm_hour = hs;
	fecha.tm_min = min;
	fecha.tm_sec = 0;
	fecha.tm_mday = d;
	fecha.tm_mon = m - 1;
	fecha.tm_year = a - 1900;
	fecha.tm_wday = 0;
	fecha.tm_yday = 0;
	fecha.tm_isdst = 0;
}

cFecha::~cFecha() {
}

float cFecha::HorasEntreFechas(cFecha* otra) //la otra es la fecha de fin
{
	float dif = 0;
	time_t aux_inicio = mktime(&(fecha)); //paso las fechas a segundos
	time_t aux_fin = mktime(&(otra->fecha));

	//verifico que las fechas que recibo no sean null ni estén incompletas
	if ((otra != NULL) && FechaCompleta() && otra->FechaCompleta())
	{
		//verifico que fecha fin > fecha inicio con operador sobrecargado
		if (aux_inicio > aux_fin)
			throw exception("Las fechas no son válidas");
		else
		{
			dif = difftime(aux_fin, aux_inicio) /(float) (3600); //calculo la diferencia en horas
			return dif;
		}
	}
	else throw exception("Fechas incompletas");
}


void cFecha::SetHoy()
{
	time_t now = time(0);
	tm* aux = localtime(&now); //obtengo fecha actual
	fecha.tm_mday = aux->tm_mday;
	fecha.tm_mon = aux->tm_mon;
	fecha.tm_year = aux->tm_year;
	fecha.tm_hour = aux->tm_hour;
	fecha.tm_min = aux->tm_min;
}

bool cFecha::FechaCompleta()
{
	if (fecha.tm_year != 0 && fecha.tm_mon != 0 && fecha.tm_mday != 0) //verifico que los parámetros de día no estén en sus valores nulos
		return true;
	return false;
}

string cFecha::toString()
{
	return to_string(fecha.tm_year + 1900) + "/" + to_string(fecha.tm_mon + 1) + "/" + to_string(fecha.tm_mday);
}

void cFecha::ImprimirFecha()
{
	cout << toString() << endl;;
}
