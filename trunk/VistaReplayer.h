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


//std::ostream& operator<< (std::ostream& out, const VistaReplayer& vista);

class VistaReplayer {

	std::stringstream out;

public:
	VistaReplayer();

	void visualizar(TableroAjedrez* tablero, ListaPPieza* listaPiezas);

	char encontrarSymbolo(PiezaJugadora* piezaJugadora, ListaPPieza* listaPiezas);

	std::string toString();

	virtual ~VistaReplayer();
};

#endif /* VISTAREPLAYER_H_ */
