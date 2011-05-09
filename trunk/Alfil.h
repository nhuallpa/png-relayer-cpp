/*
 * Alfil.h
 *
 *  Created on: 21/04/2011
 *      Author: Nestor Huallpa
 */

#ifndef __ALFIL_H_
#define __ALFIL_H_

#include "PiezaJugadora.h"

class Alfil: public PiezaJugadora {
public:
	ListaPCoordenadas *filtrarCoordValidas(const Coordenada & coordenada,
										   TableroAjedrez *unTablero);
};

#endif /* ALFIL_H_ */
