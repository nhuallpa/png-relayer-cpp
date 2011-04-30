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
public:
	Movimiento();
	virtual ~Movimiento();
	virtual void aplicarEn(TableroAjedrez* tablero) = 0;
};

#endif /* MOVIMIENTO_H_ */
