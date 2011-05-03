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
	Torre();
	ListaPCoordenadas* coordDestinoDesde(const Coordenada& coord);
	ListaPCoordenadas* filtrarCoordValidas(const Coordenada& coordenada, TableroAjedrez* unTablero);
	virtual ~Torre();
};

#endif /* TORRE_H_ */
