

/*
 * Analizador.cpp
 *
 *  Created on: 01/05/2011
 *      Author: Nestor Huallpa
 */

#include "Analizador.h"



Analizador::Analizador() {
	reportes = new listaPReporte();
}

void Analizador::analizar(Turno* unTurno,
						  TableroAjedrez* unTablero) {
	Coordenada coordBlanco = unTurno->getCoordOrigenBlanco();
	PiezaJugadora* piezaJugadora = unTablero->getPiezaJugadora(coordBlanco);
	ListaPCoordenadas * listCoordBlancas =
				piezaJugadora->filtrarCoordValidas(coordBlanco, unTablero);

	Coordenada coordNegro = unTurno->getCoordOrigenNegro();
	piezaJugadora = unTablero->getPiezaJugadora(coordNegro);
	ListaPCoordenadas * listCoordNegras =
				piezaJugadora->filtrarCoordValidas(coordNegro, unTablero);

	int nroTurno = unTurno->getNroTurno();
	Reporte* unReporte = new Reporte(nroTurno,
									listCoordBlancas,
									listCoordNegras);
	reportes->agregar(unReporte);
}


listaPReporte *Analizador::getReportes() const {
    return reportes;
}

Analizador::~Analizador() {
	listaPReporte::IteratorList it = reportes->getIterator();
	while (it.hasNext()) {
		delete it.next();
	}
	delete reportes;
}

