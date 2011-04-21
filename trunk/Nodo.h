/*
 * Nodo.h
 *
 *  Created on: 18/04/2011
 *      Author: Nestor Huallpa
 */

#ifndef __NODO_H_
#define __NODO_H_
#include "stdlib.h"

template <class T>
class Nodo {
	T data;
	Nodo *nodoSig;
public:

	Nodo();
	Nodo(T dat);
	virtual ~Nodo();
    T getData() const;
    void setData(T data);
    Nodo<T> *getNodoSig() const;
    void setNodoSig(Nodo *nodoSig);

};


template <class T>
T Nodo<T>::getData() const { return data; }

template <class T>
void Nodo<T>::setData(T data) { this->data = data; }

template <class T>
Nodo<T>* Nodo<T>::getNodoSig() const { return nodoSig; }

template <class T>
Nodo<T>::Nodo() {
	nodoSig = NULL;
	data = NULL;
}

template <class T>
Nodo<T>::Nodo(T dat){
	nodoSig = NULL;
	data = dat;
}

template <class T>
Nodo<T>::~Nodo() {
}

template <class T>
void Nodo<T>::setNodoSig(Nodo *nodo) { this->nodoSig = nodo; }

#endif /* NODO_H_ */
