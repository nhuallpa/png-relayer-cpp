/*
 * VistaReplayer.h
 *
 *  Created on: 27/04/2011
 *      Author: administrador
 */

#ifndef __VISTAREPLAYER_H_
#define __VISTAREPLAYER_H_
#include "TableroAjedrez.h"
#include <sstream>
#include <iostream>
#include <iomanip>
#include "PgnInterprete.h"
#include <iosfwd>
#include "Analizador.h"



const char c_SIN_SIMBOLO = '-';
const char c_VACIO = '.';

class VistaReplayer {
	std::stringstream out;
public:
	VistaReplayer();

	void visualizarTableroInicial(TableroAjedrez* tablero,
								  ListaPPieza* piezasIniciales,
								  ListaPPieza* piezasPromociones);
	void visualizarTableroFinal(TableroAjedrez* tablero,
								ListaPPieza* piezasIniciales,
								ListaPPieza* piezasPromociones);
	char encontrarSymbolo(PiezaJugadora* piezaJugadora, ListaPPieza* listaPiezas);

	void visualizarAnalisis(Analizador& analizador);
	std::string toString();
private:
	void visualizar(TableroAjedrez* tablero,
						ListaPPieza* piezasIniciales,
						ListaPPieza* piezasPromociones);
	void listarCoordenadas(ListaPCoordenadas* listaCoord);
};

#endif /* VISTAREPLAYER_H_ */
