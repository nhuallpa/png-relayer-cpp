/*
 * Reporte.cpp
 *
 *  Created on: 01/05/2011
 *      Author: Nestor Huallpa
 */

#include "Reporte.h"

Reporte::Reporte() {
	nro = 0;
	lCoordBlanco = NULL;
	lCoordNegro = NULL;
}

Reporte::Reporte(int nroTurno, ListaPCoordenadas* listaCoordBlanco,
		 	 	 ListaPCoordenadas* listaCoordNegro) {
	nro = nroTurno;
	lCoordBlanco = listaCoordBlanco;
	lCoordNegro = listaCoordBlanco;
}

int Reporte::getNroTurno() {
	return nro;
}

ListaPCoordenadas *Reporte::getCoordenasDestinoBlanco() {
	return lCoordBlanco;
}

ListaPCoordenadas *Reporte::getCoordenasDestinoNegro() {
	return lCoordNegro;
}

Reporte::~Reporte() {
	if (lCoordBlanco){
		ListaPCoordenadas::IteratorList it = lCoordBlanco->getIterator();
		while (it.hasNext()) {
			delete (it.next());
		}
		delete lCoordBlanco;
	}
	if (lCoordNegro){
		ListaPCoordenadas::IteratorList it = lCoordNegro->getIterator();
		while (it.hasNext()) {
			delete (it.next());
		}
		delete lCoordNegro;
	}
}
