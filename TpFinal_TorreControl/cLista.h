#pragma once
#include <string>
#include <iostream>
using namespace std;
#define TMAX 100
template <class T>
class cLista
{
protected:
	T** lista;
	int ca;
	unsigned int ct;

public:
	cLista(unsigned int tam = TMAX);
	virtual ~cLista();

	bool operator+(T* puntero); //P= puntero que recibe, método agregar
	//void ImprimirPacientes(); //imprime el listado de receptores y donantes
	T* operator-(T* P); //sobrecarga del operator - para quitar elementos
	T* operator[](int i); //se le pasa la posición y devuelve el puntero
	int getItemPos(T* P);
	unsigned int getCA() { return ca; }
	bool Agregar(T* P);
	T* Quitar(T* P);
	bool Eliminar(T* P);
	T* BuscarenPos(int i);
	void igualar(cLista<T>* nuevaLista);
};

template<class T>
cLista<T>::cLista(unsigned int tam)
{
	this->ca = 0;
	this->ct = tam; //cantidad total es igual al tamaño
	lista = new T * [ct];
	for (unsigned int i = 0; i < ct; i++)
	{
		lista[i] = NULL;
	}
}

template<class T>
cLista<T>::~cLista()
{
	if (lista != NULL) {

		for (int i = 0; i < ca; i++)
		{
			lista[i] = NULL;
		}
		delete[]lista;
	}
}

template<class T>
bool cLista<T>::operator+(T* puntero) // al agregar se asegura que el elemento no exista en la lista
{
	int i = 0;
	int pos = getItemPos(puntero);
	if (ca < ct && pos == -1) {
		ca++;
		lista[ca] = puntero;
		return true;
	}
	return false;
}

template<class T>
bool cLista<T>::Agregar(T* P)
{
	if (P != NULL && ca < ct)
	{
		ca++;
		lista[ca] = P;
		return true;
	}
	return false;
}

template<class T>
T* cLista<T>::operator-(T* P)
{
	T* aux = NULL;
	aux = P;
	int pos = getItemPos(P);
	if (pos != -1)
	{
		ca--;
		for (unsigned int j = pos; j < ca; j++)
		{
			lista[j] = lista[j + 1];
		}

		lista[ca] = NULL;
		return aux;
	}
	return NULL;
}

template<class T>
T* cLista<T>::Quitar(T* P)
{
	if (P == NULL)
		return NULL;
	int pos = getItemPos(P);
	if (pos != -1)
	{
		ca--; //disminuimos la cantidad actual
		T* aux = P; //igualamos el aux al puntero en la posición para despues devolverlo
		for (int i = pos; i < ca; i++)
		{
			lista[i] = lista[i + 1];
		}
		lista[pos] = NULL; //quitamos el puntero
		return aux; //devolvemos el auxiliar creado
	}
	return NULL;
}

template<class T>
bool cLista<T>::Eliminar(T* P)
{
	T* aux = Quitar(P);
	if (aux != NULL)
	{
		aux = NULL;
		return true;
	}
	return false;
}

template<class T>
T* cLista<T>::operator[](int i)
{
	if (i <= ca)
	{
		return lista[i];
	}
	return NULL;
}

template<class T>
int cLista<T>::getItemPos(T* puntero)
{
	for (int i = 0; i < ca + 1; i++)
	{
		if (lista[i] == puntero)
			return i;
	}
	return -1;
}

template<class T>
T* cLista<T>::BuscarenPos(int i)
{
	if (i <= ca)
	{
		return lista[i];
	}
}

template<class T>
inline void cLista<T>::igualar(cLista<T>* nuevaLista)
{
	if (nuevaLista == NULL)
		throw new exception("Lista vacia");
	if (nuevaLista->getCA() > ct)
		throw new exception("Nueva lista supera el tamaño posible para almacenar");

	int i = 0;
	for (i = 0; i < nuevaLista->getCA(); i++)
	{
		this->lista[i] = (*nuevaLista)[i];
	}
}