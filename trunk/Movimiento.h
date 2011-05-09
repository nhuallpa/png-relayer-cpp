/*
 * Movimiento.h
 *
 *  Created on: 30/04/2011
 *      Author: Nestor Huallpa
 */

#ifndef __MOVIMIENTO_H_
#define __MOVIMIENTO_H_
#include "TableroAjedrez.h"
#include "Coordenada.h"

class Movimiento {
protected:
	bool conPomocion;

public:
	Movimiento();
	bool tienePromocion();
	virtual void aplicarEn(TableroAjedrez* tablero) = 0;
	virtual ~Movimiento();
};

#endif /* MOVIMIENTO_H_ */
