#include "cTorreControl.h"
#include "GeneradorRand.h"

using namespace std;

int main()
{
	//Pistas:
	cPista* pista1 = new cPista(100, 400, 1);//pista disponible
	cPista* pista2 = new cPista(300, 1000.0, 2); //pista disponible

	//Aviones:
	cAvion* cessna1 = new cCESSNA(40, 10, 50, eModelo::A1);
	cAvion* cessna2 = new cCESSNA(100, 20, 70, eModelo::B2);
	cBiplano* biplano1 = new cBiplano(200, 0, 100, 30);

	//Listas:
	cLista<cAvion>* listaAviones = new cLista<cAvion>;
	ListaPistas* listaPistas = new ListaPistas();
	(*listaAviones) + cessna1;
	(*listaAviones) + cessna2;
	(*listaAviones) + biplano1;
	(*listaPistas) + pista1;
	(*listaPistas) + pista2;

	//Torre de Control:
	cTorreControl* torre = new cTorreControl(listaAviones, listaPistas);

	//Generador Random:
	GeneradorRand* random = new GeneradorRand();

	//uso de sobrecargas; VER COMO USARLAS
	//*biplano1 << ;
	//*cessna1 >> 100; //le asignamos la carga con la sobrecarga de >> VER

	try
	{
		cessna1++; //le agregamos un pasajero 
	}
	catch (exception* e)
	{
		cout << string(e->what()) << endl;
		delete e;
	}
	unsigned int numero = 0;
	do
	{
		switch (torre->PistasOcupadas())
		{
		case true:
			cout << "Todas las pistas estan ocupadas en este momento" << endl;
			cout << "Ingrese un numero par para seguir: ";
			cin >> numero;
		case false:
			torre->LlamarComando(random->AvionRandom(listaAviones));
		}

	} while (numero % 2 != 0); //numero impar

	torre->ImprimirAvionesDespegando();
	torre->ImprimirAvionesAterrizando();
	torre->ImprimirAvionesEnVuelo();
	torre->ImprimirPistasLibres();

	system("pause");

	delete torre; 
	delete listaAviones;
	delete listaPistas;
	delete pista1;
	delete pista2;
	delete cessna1;
	delete cessna2;
	delete biplano1;
	delete random;
	
	system("pause");
}