

/*
 * VistaReplayer.cpp
 *
 *  Created on: 27/04/2011
 *      Author: administrador
 */

#include "VistaReplayer.h"

using namespace std;




std::string VistaReplayer::toString() {
	return out.str();
}

VistaReplayer::VistaReplayer() {
}

void VistaReplayer::visualizar(TableroAjedrez* tablero, ListaPPieza* listaPiezas) {
	for (int fila = 8; fila > 0; fila--) {
		for (char columna = 'a'; columna <= 'h'; columna++) {
			if (tablero->hayPiezaJugadora(fila, columna)) {
				PiezaJugadora* piezaJugadora = tablero->getPiezaJugadora(fila, columna);
				out<<encontrarSymbolo(piezaJugadora, listaPiezas);
			} else {
				out<<".";
			}
		}
		out<<endl;
	}
	//cout<<out.str();
}

char VistaReplayer::encontrarSymbolo(PiezaJugadora* piezaJugadora, ListaPPieza* listaPiezas) {

	char symbol = '?';
	bool encontrado = false;

	Pieza* piezaEnLista = NULL;
	ListaPPieza::IteratorList it = listaPiezas->getIterator();
	while (it.hasNext() && !encontrado) {
		piezaEnLista = it.next();
		if (piezaEnLista->getPiezaJugadora() == piezaJugadora) {
			symbol = piezaEnLista->getSymbol();
			encontrado = true;
		}
	}
	return symbol;
}




VistaReplayer::~VistaReplayer() {
	// TODO Auto-generated destructor stub
}



