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

#include "PgnInterprete.h"
#include <iosfwd>



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

	std::string toString();

private:
	void visualizar(TableroAjedrez* tablero,
						ListaPPieza* piezasIniciales,
						ListaPPieza* piezasPromociones);

};

#endif /* VISTAREPLAYER_H_ */
