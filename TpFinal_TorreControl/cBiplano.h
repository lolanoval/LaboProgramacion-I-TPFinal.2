#pragma once
#include "cAvion.h"
using namespace std;
class cBiplano :
    public cAvion
{
private:
    int aceleracion;

public:
    cBiplano(int _cantcombustible, int _pasajerosmax, int _tamanio, int _aceleracion);
    ~cBiplano();
    void ImprimirDatos();
    void Despegar(cPista* pista); 
    void Aterrizar(cPista* pista); 
    float TiempoUsoPista();
    float Distancia();
    string BiplanoToString() const;
    friend ostream& operator<<(ostream& os, const cBiplano* biplano);
};

