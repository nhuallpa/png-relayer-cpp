/*
 * Reporte.cpp
 *
 *  Created on: 07/05/2011
 *      Author: Nestor Huallpa
 */

#include "Reporte.h"

Reporte::Reporte(int nro, ListaPCoordenadas* listCoordBlancas,
				 	 	  ListaPCoordenadas* listCoordNegras) {
	nroTurno = nro;
	listCoordenadasBlancas = listCoordBlancas;
	listCoordenadasNegras = listCoordNegras;
}

ListaPCoordenadas *Reporte::getListCoordenadasBlancas() const {
    return listCoordenadasBlancas;
}

ListaPCoordenadas *Reporte::getListCoordenadasNegras() const {
    return listCoordenadasNegras;
}

int Reporte::getNroTurno() const {
    return nroTurno;
}

void Reporte::setListCoordenadasBlancas(
		ListaPCoordenadas *listCoordenadasBlancas) {
    this->listCoordenadasBlancas = listCoordenadasBlancas;
}

void Reporte::setListCoordenadasNegras(
		ListaPCoordenadas *listCoordenadasNegras) {
    this->listCoordenadasNegras = listCoordenadasNegras;
}

void Reporte::setNroTurno(int nroTurno) {
    this->nroTurno = nroTurno;
}

Reporte::~Reporte() {
	if (listCoordenadasBlancas) {
		ListaPCoordenadas::IteratorList it = listCoordenadasBlancas->getIterator();
		while (it.hasNext()) {
			delete it.next();
		}
		delete listCoordenadasBlancas;
	}
	if (listCoordenadasNegras) {
		ListaPCoordenadas::IteratorList it = listCoordenadasNegras->getIterator();
		while (it.hasNext()) {
			delete it.next();
		}
		delete listCoordenadasNegras;
	}
}
