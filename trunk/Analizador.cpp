/*
 * Analizador.cpp
 *
 *  Created on: 01/05/2011
 *      Author: Nestor Huallpa
 */

#include "Analizador.h"


Analizador::Analizador() {
	reportes = new ListaPReportes;
}

void Analizador::analizar(Turno* unTurno,
						  TableroAjedrez* unTablero) {

//	Coordenada coorBlanco = unTurno->getCoordOrigenBlanco();
//	PiezaJugadora* piezaJugadora = unTablero->getPiezaJugadora(coorBlanco);
//
//	ListaPCoordenadas* listaCoordBlanco = NULL;
//	if (piezaJugadora) {
//		listaCoordBlanco = piezaJugadora->filtrarCoordValidas(coorBlanco, unTablero);
//	}
//
//	ListaPCoordenadas* listaCoordNegro = NULL;
//	Coordenada coordNegro = unTurno->getCoordOrigenNegro();
//	piezaJugadora = unTablero->getPiezaJugadora(coordNegro);
//	if (piezaJugadora) {
//		listaCoordNegro = piezaJugadora->filtrarCoordValidas(coordNegro, unTablero);
//	}
//
//
//	Reporte* reporte = NULL;
//
//	reporte = new Reporte(unTurno->getNroTurno(), listaCoordBlanco, listaCoordNegro);
//	delete reporte;
//	//reportes->agregar(reporte);
}


ListaPReportes* Analizador::getReportes() {
	return reportes;
}



Analizador::~Analizador() {
	ListaPReportes::IteratorList it = reportes->getIterator();
	while (it.hasNext()) {
		delete it.next();
	}
	delete reportes;
}

