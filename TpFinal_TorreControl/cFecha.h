#pragma once
#include <ctime>
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <windows.h>
using namespace std;
 
class cFecha
{
private:
#pragma region Atributos

	tm fecha;

#pragma endregion	

#pragma region Constructor y Destructor

public:
	//Constructor por default, inicia en la fecha de hoy
	cFecha();
	//Constructor inicia en dia, mes, año
	cFecha(int d, int m, int a);
	cFecha(int dia, int mes, int anio, int hora, int minutos);
	~cFecha();
	void ImprimirFecha();
	string toString();
#pragma endregion

#pragma region Metodos

	//Calcula el numero de días entre dos fechas
	float HorasEntreFechas(cFecha* otra);


	//Cambia la fecha a la fecha actual
	void SetHoy();

	//Verifica que la fecha esté completa
	bool FechaCompleta();

	////Devuelve la fecha actual en forma de string
	//string To_string();

	//// Imprime fecha
	//void ImprimirFecha();

	//// Determina si las dos fechas tiene el mismo dia
	//static bool MismoDia(cFecha* fecha1, cFecha* fecha2);

#pragma endregion

#pragma region Sobrecarga de Operadores

	bool operator<(cFecha& otra) {
		time_t aux_this = mktime(&(this->fecha));
		time_t aux_otra = mktime(&(otra.fecha));
		return aux_this < aux_otra;
	}

	bool operator>(cFecha& otra) { //faltan if mktime =! a -1 pq cuando devuelve error iguala a -1
		time_t aux_this = mktime(&(this->fecha));
		time_t aux_otra = mktime(&(otra.fecha));
		return aux_this > aux_otra;
	}

	bool operator==(cFecha& otra) {
		time_t aux_this = mktime(&(this->fecha));
		time_t aux_otra = mktime(&(otra.fecha));
		return aux_this == aux_otra;
	}

	bool operator!=(cFecha& otra) {
		return !(*this == otra);
	}

	int getAnio() { return fecha.tm_year; };
	int getMes() { return fecha.tm_mon; };
	int getDia() { return fecha.tm_wday; };

	void reSet()
	{
		fecha.tm_year = 0;
		fecha.tm_mday = 0;
		fecha.tm_mon = 0;
		fecha.tm_hour = 0;
		fecha.tm_min = 0;
	};
};
inline void Cronometro(float tiempototal) {

	if (tiempototal == -1)
		cout << "Avion Aterrizado" << endl;
	else {
		time_t current_time = time(0);
		while (time(0) - current_time < tiempototal) //hacer que parecusndo aterriza
		{
			Sleep(1); //sleep suspende la ejecucion del programa temporalmente
		}
		cout << "Avion cayendo. AAAAAAA" << endl;
	}
}
