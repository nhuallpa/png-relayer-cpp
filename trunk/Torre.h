/*
 * Torre.h
 *
 *  Created on: 21/04/2011
 *      Author: Nestor Huallpa
 */

#ifndef __TORRE_H_
#define __TORRE_H_

#include "PiezaJugadora.h"

class Torre: public PiezaJugadora {
public:
	ListaPCoordenadas* filtrarCoordValidas(const Coordenada& coordenada,
										   TableroAjedrez* unTablero);
};

#endif /* TORRE_H_ */
