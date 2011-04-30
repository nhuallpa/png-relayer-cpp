/*
 * Promocion.h
 *
 *  Created on: 30/04/2011
 *      Author: Nestor Huallpa
 */

#ifndef __PROMOCION_H_
#define __PROMOCION_H_

#include "Movimiento.h"

class Promocion: public Movimiento {

private:
	char symbol;

public:
	Promocion(char simbolo);
	void aplicarEn(TableroAjedrez* tablero);
};

#endif /* PROMOCION_H_ */
