#pragma once
#include <string>
//#include <stdio.h>
#include <iostream>
using namespace std;

enum class eEstado { Volando, Despegando, Aterrizando, enEspera};
enum class eModelo{A1,B2};

string EstadoToString(eEstado estado);
string ModeloToString(eModelo modelo); //hola