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
	NingunMovimiento();
	void aplicarEn(TableroAjedrez* tablero);
	virtual ~NingunMovimiento();
};

#endif /* NINGUNMOVIMIENTO_H_ */
