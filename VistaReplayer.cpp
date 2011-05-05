

/*
 * VistaReplayer.cpp
 *
 *  Created on: 27/04/2011
 *      Author: Nestor Huallpa
 */

#include "VistaReplayer.h"

using namespace std;

std::string VistaReplayer::toString() {
	return out.str();
}

VistaReplayer::VistaReplayer() {
}

void VistaReplayer::visualizarTableroInicial(TableroAjedrez* tablero,
											ListaPPieza* piezasIniciales,
											ListaPPieza* piezasPromociones) {
	string cadena();
	out<<"Tablero inicial:"<<endl;
	visualizar(tablero, piezasIniciales, piezasPromociones);
	out<<endl;
	out<<endl;
}
void VistaReplayer::visualizarTableroFinal(TableroAjedrez* tablero,
										   ListaPPieza* piezasIniciales,
										   ListaPPieza* piezasPromociones) {
	string cadena();
	out<<"Tablero final:"<<endl;
	visualizar(tablero, piezasIniciales, piezasPromociones);
}


void VistaReplayer::visualizar(TableroAjedrez* tablero,
							   ListaPPieza* piezasIniciales,
							   ListaPPieza* piezasPromociones) {
	for (int fila = 8; fila > 0; fila--) {
		for (char columna = 'a'; columna <= 'h'; columna++) {
			if (tablero->hayPiezaJugadora(fila, columna)) {
				PiezaJugadora* piezaJugadora = tablero->getPiezaJugadora(fila, columna);

				char simbolo = encontrarSymbolo(piezaJugadora, piezasIniciales);
				if 	(simbolo ==	c_SIN_SIMBOLO && piezasPromociones) {
					simbolo = encontrarSymbolo(piezaJugadora, piezasPromociones);
				}
				out<<simbolo;
			} else {
				out<<c_VACIO;
			}
		}
		if (fila != 1){
			out<<endl;
		}
	}
}

char VistaReplayer::encontrarSymbolo(PiezaJugadora* piezaJugadora, ListaPPieza* listaPiezas) {

	char symbol = c_SIN_SIMBOLO;
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


void VistaReplayer::visualizarAnalisis(Analizador& analizador){



}

void VistaReplayer::listar(ListaPCoordenadas* listaCoord) {
	if (listaCoord) {
		ListaPCoordenadas::IteratorList it = listaCoord->getIterator();
		while (it.hasNext()) {
			Coordenada* coord = it.next();
			out<<coord->toString();
		}
		out<<endl;
	}
}




