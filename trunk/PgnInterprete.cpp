/*
 * PgnInterprete.cpp
 *
 *  Created on: 21/04/2011
 *      Author: Nestor Huallpa
 */

#include "PgnInterprete.h"
using namespace std;


// todo : sacar
//istream &operator >> (istream &in, Turno &turno) {
//	cout<<"jeje";
//	return in;
//}

PgnInterprete::PgnInterprete() {
	piezasIniciales = NULL;
	turnos = NULL;
	pgn = NULL;

}

void PgnInterprete::interpretar() {
	interpretarTableroInicial();
	interpretarTurnos();
}

void PgnInterprete::interpretarTurnos() {
	if (!turnos && pgn) {

		stringstream& inTurnos = pgn->getMovidas();
		Turno turnoActual;
		string valor;
//		while (!inTurnos.eof()) {
//			inTurnos>>turnoActual;
//		}


	}

}

void PgnInterprete::interpretarTableroInicial() {
	if (!piezasIniciales && pgn) {
		piezasIniciales = new ListaPPieza();
		for (int fila = PNG_CANT_FILA; fila > 0; fila--) {
			string filaString = pgn->dameFila(fila);
			interpretarFila(filaString, fila);
		}
	}
}

void PgnInterprete::interpretarFila(string filaString, int fila) {
	int columna = 0;
	for (size_t index = 0; index < filaString.length(); ++index) {
		char simbolo = filaString.at(index);
		if (simbolo > '0' && simbolo <= '8') {
			columna += (simbolo - '0');
		} else {
			PiezaJugadora* pJugadadora = factoryPiezaJugadora.crear(simbolo);
			if (pJugadadora) {
				Coordenada coord(fila, 'a' + columna );
				piezasIniciales->agregar(new Pieza(pJugadadora, coord, simbolo));
			}
			++columna;
		}
	}
}

PgnAjedrez *PgnInterprete::getPgn() const {
    return pgn;
}

void PgnInterprete::setPgn(PgnAjedrez *pgn) {
    this->pgn = pgn;
}

ListaPPieza* PgnInterprete::getPiezasIniciales() {
	return piezasIniciales;
}

PgnInterprete::~PgnInterprete() {
	if (piezasIniciales){
		ListaPPieza::IteratorList it = piezasIniciales->getIterator();
		while (it.hasNext()) {
			delete it.next();
		}
		delete piezasIniciales;
	}

}






