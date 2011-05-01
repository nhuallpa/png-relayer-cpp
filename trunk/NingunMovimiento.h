/*
 * NingunMovimiento.h
 *
 *  Created on: 30/04/2011
 *      Author: administrador
 */

#ifndef NINGUNMOVIMIENTO_H_
#define NINGUNMOVIMIENTO_H_

#include "Movimiento.h"

class NingunMovimiento: public Movimiento {
public:
	void aplicarEn(TableroAjedrez* tablero);
};

#endif /* NINGUNMOVIMIENTO_H_ */
