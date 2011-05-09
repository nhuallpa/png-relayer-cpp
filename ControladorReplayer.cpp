/*
 * ControladorReplayer.cpp
 *
 *  Created on: 15/04/2011
 *      Author: Nestor Huallpa
 */

#include "ControladorReplayer.h"
using std::ostream;
using std::cout;

ostream& operator<< (ostream& out, VistaReplayer* vista) {
	out << vista->toString();
	return out;
}


ControladorReplayer::ControladorReplayer(TableroAjedrez* unAjedrez,
											VistaReplayer* unaVista) {
	tableroAjedrez = unAjedrez;
	vista = unaVista;
}

ControladorReplayer::~ControladorReplayer() {
}

void ControladorReplayer::mostrarResultados() {
	cout << vista;
}

void ControladorReplayer::reproducir(PgnAjedrez* entradaPng) {
	pgnInterprete.setPgn(entradaPng);
	pgnInterprete.interpretar();
	prepararTableroInicial();
	vista->visualizarTableroInicial(tableroAjedrez,
									pgnInterprete.getPiezasIniciales(),
									pgnInterprete.getPiezasPromocion());
	ejecutarTurnos();
	vista->visualizarAnalisis(analizador);
	vista->visualizarTableroFinal(tableroAjedrez,
								  pgnInterprete.getPiezasIniciales(),
								  pgnInterprete.getPiezasPromocion());
}

void ControladorReplayer::prepararTableroInicial() {
	ListaPPieza* piezasIniciales = pgnInterprete.getPiezasIniciales();
	if (piezasIniciales) {
		colocarPiezasIniciales(piezasIniciales);
	}
}
void ControladorReplayer::colocarPiezasIniciales(ListaPPieza* piezasIniciales) {
	ListaPPieza::IteratorList itPiezasInicales =
											piezasIniciales->getIterator();
    while (itPiezasInicales.hasNext()) {
        Pieza *unaPieza = itPiezasInicales.next();
        tableroAjedrez->posionar(unaPieza->getPiezaJugadora(),
        								unaPieza->getCoordenadaInicial());
    }
}

void ControladorReplayer::ejecutarTurnos() {
	ListaPTurno* turnos = pgnInterprete.getTurnos();
	if (turnos) {
		ListaPTurno::IteratorList it = turnos->getIterator();
		while (it.hasNext()) {
			Turno* turno = it.next();
			if (turno->requiereAnalisis()) {
				analizador.analizar(turno, tableroAjedrez);
			}
			Movimiento* unMovimiento = NULL;
			unMovimiento = turno->getMovimientoBlanco();
			unMovimiento->aplicarEn(tableroAjedrez);
			unMovimiento = turno->getMovimientoNegro();
			unMovimiento->aplicarEn(tableroAjedrez);
		}
	}
}



