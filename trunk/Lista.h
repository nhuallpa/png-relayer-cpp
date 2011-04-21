/*
 * Lista.h
 *
 *  Created on: 18/04/2011
 *      Author: Nestor Huallpa
 */

#ifndef __LISTA_H_
#define __LISTA_H_
#include "Nodo.h"
template < class T >
class Lista {
private:
	Nodo<T>* raiz;
	Nodo<T>* nodoUltimo;

public:
	Lista();
	virtual ~Lista();
	bool estaVacio();
	void agregar(T elem);

	/**
	 *	Begin Iterador
	 **/
	class IteratorList;
	friend class IteratorList;
	class IteratorList {
	private:
		Lista& list;
		Nodo<T>* nodoActual;
	public:

		IteratorList(Lista& l):list(l){
			nodoActual = NULL;
		}

		bool hasNext() {
			bool haySiguiente = false;
			if (!list.raiz) {
				haySiguiente = false;
			} if (nodoActual && nodoActual->getNodoSig()) {
				haySiguiente = true;
			} if (list.raiz && !nodoActual) {
				haySiguiente = true;
			}
			return haySiguiente;
		}

		T next() {
			Nodo<T>* nodoSiguiente = NULL;
			if (nodoActual) {
				nodoSiguiente = nodoActual->getNodoSig();
			} else {
				nodoSiguiente = list.raiz;
			}
			nodoActual = nodoSiguiente;
			return (nodoSiguiente)?nodoSiguiente->getData():NULL;
		}

	};
	/**
	 *	End Iterador
	 **/
	IteratorList getIterator() { return IteratorList(*this); }

};

template < class T >
Lista<T>::Lista() {
	raiz = NULL;
	nodoUltimo = NULL;
}

template < class T >
Lista<T>::~Lista() {
	if (raiz != NULL) {
		Nodo<T>* auxNodo = raiz;
		while (auxNodo != nodoUltimo) {
			Nodo<T>* nodoAEliminar = auxNodo;
			auxNodo = auxNodo->getNodoSig();
			delete nodoAEliminar;
		}
		delete nodoUltimo;
	}
}

template < class T >
bool Lista<T>::estaVacio() {
	return (raiz == NULL);
}

template < class T >
void Lista<T>::agregar(T elem) {
	if (raiz == NULL) {
		raiz = new Nodo<T>(elem);
		nodoUltimo = raiz;
	} else {
		Nodo<T>* auxNodo = new Nodo<T>(elem);
		nodoUltimo->setNodoSig(auxNodo);
		nodoUltimo = auxNodo;
	}
}

#endif /* LISTA_H_ */


