#include "cTorreControl.h"

cTorreControl::cTorreControl()
{
	ListaAviones = new cLista<cAvion>();
	Pistas = new ListaPistas();
}

cTorreControl::cTorreControl(cLista<cAvion>* _ListaAviones, ListaPistas* _Pistas)
{
	ListaAviones = new cLista<cAvion>();
	Pistas = new ListaPistas();
	try
	{
		ListaAviones->igualar(_ListaAviones);
		Pistas->IgualarPistas(_Pistas);
	}
	catch (exception* e)
	{
		cout << string(e->what()) << endl;
		delete e;
	}
	/*this->ListaAviones = new cLista<cAvion>;
	for (int i = 0; i < _ListaAviones->getCA(); i++)
	{
		(*ListaAviones) + (*_ListaAviones)[i];
	}
	this->Pistas = new cLista<cPista>;
	for (int i = 0; i < _Pistas->getCA(); i++)
	{
		(*Pistas) + (*_Pistas)[i];
	}*/
}

cTorreControl::~cTorreControl()
{
	//if (ListaAviones != NULL)
	//{
	//	delete ListaAviones;
	//}
	//if (Pistas != NULL)
	//{
	//	delete Pistas;
	//}
	delete ListaAviones;
	delete Pistas;
}

cPista* cTorreControl::AsignarPista(cAvion* avion) //try catch
{
	if (avion == NULL)
		throw new exception("Puntero nulo");
	int pos = ListaAviones->getItemPos(avion);
	if (pos == -1)
	{
		throw new exception("El avion no se encuentra en el sistema");
	}
		int tamanio = avion->getTam();
		float distancia = avion->Distancia();
		//cLista<cPista>* subLista = subListaPistasLibres();
		int i = 0;
		for (i = 0; i < Pistas->getCA() + 1; i++)
		{
			if ((*Pistas)[i]->getDistancia() <= distancia && (*Pistas)[i]->getTamanio() <= tamanio && (*Pistas)[i]->getOcupada() == false)
			{
				return (*Pistas)[i];
				//cPista* pistaLibre = (*subLista)[i]; //ver si xq se elimina la subLista no se elimina el puntero; en ese caso hay que crear un new 
				//delete subLista;
				//return pistaLibre;
			}
		}
		//delete subLista;
		if (i == Pistas->getCA() + 1)
			throw new exception("No hay pistas libres");
}

void cTorreControl::ImprimirAvionesEnVuelo()
{
	for (int i = 0; i < ListaAviones->getCA(); i++)
	{
		if (EstadoToString((*ListaAviones)[i]->getEstado()) == "Volando")
			(*ListaAviones)[i]->ImprimirDatos();
	}
}

void cTorreControl::ImprimirAvionesAterrizando()
{
	for (int i = 0; i < ListaAviones->getCA(); i++)
	{
		if (EstadoToString((*ListaAviones)[i]->getEstado()) == "Aterrizando")
			(*ListaAviones)[i]->ImprimirDatos();
	}
}

void cTorreControl::ImprimirAvionesDespegando()
{
	for (int i = 0; i < ListaAviones->getCA(); i++)
	{
		if (EstadoToString((*ListaAviones)[i]->getEstado()) == "Despegando")
			(*ListaAviones)[i]->ImprimirDatos();
	}
}

void cTorreControl::ImprimirPistasLibres()
{
	Pistas->Listar();
	//int j = Pistas->getCA();
	//for (int i = 0; i < j; i++)
	//{
	//	//if ((*Pistas)[i]->getOcupada() == false)
	//	//Pistas[i]->ImprimirDatos();
	//}
}

void cTorreControl::DespegarAvion(cAvion* avion)
{
	try
	{
		AsignarPista(avion);
	}
	catch (exception* e)
	{
		cout << string(e->what()) << endl;
		delete e;
	}
	avion->Despegar(AsignarPista(avion));

}

void cTorreControl::AterrizarAvion(cAvion* avion)
{
	try
	{
		AsignarPista(avion);
	}
	catch (exception* e)//chequear esto si era asi
	{
		cout << e->what() << endl;
		delete e;
	}
	avion->Aterrizar(AsignarPista(avion)); 
}

bool cTorreControl::PistasOcupadas()
{
	int j = 0;
	int i = 0;
	for (i = 0; i < Pistas->getCA(); i++);
	{
		if (!(*Pistas)[i]->getOcupada()) //si no esta ocupada, j++
			j++;
	}
	if (j != 0)
		return false;
	return true;
}

void cTorreControl::LlamarComando(cAvion* avion)
{
	switch (avion->getEstado())
	{
	case eEstado::Aterrizando:
		cout << "Avion "<<to_string(avion->getID())<<"aterrizando";
		break;
	case eEstado::Despegando:
		cout << "Avion " << to_string(avion->getID()) << "despegando";
		break;
	case eEstado::enEspera:
		DespegarAvion(avion);
		break;
	case eEstado::Volando:
		AterrizarAvion(avion);
		break;
	}

}

bool cTorreControl::AgregarPista(cPista* pista)
{
	return ((*Pistas) + pista);
}

bool cTorreControl::AgregarAvion(cAvion* avion)
{
	return ((*ListaAviones) + avion);
}

