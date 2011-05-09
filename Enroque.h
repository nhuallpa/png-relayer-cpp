/*
 * Enroque.h
 *
 *  Created on: 30/04/2011
 *      Author: Nestor Huallpa
 */

#ifndef __ENROQUE_H_
#define __ENROQUE_H_

#include "Movimiento.h"
#include "PiezaJugadora.h"

class Enroque: public Movimiento {
protected:
	Coordenada origenRey;
	Coordenada destinoRey;
	Coordenada origenTorre;
	Coordenada destinoTorre;
public:
	void aplicarEn(TableroAjedrez* tablero);
};

#endif /* ENROQUE_H_ */
