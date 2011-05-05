/*
 * Reina.h
 *
 *  Created on: 21/04/2011
 *      Author: Nestor Huallpa
 */

#ifndef __REINA_H_
#define __REINA_H_

#include "PiezaJugadora.h"
#include "Coordenada.h"

class Reina: public PiezaJugadora {
public:
	Reina();
	ListaPCoordenadas* coordDestinoDesde(const Coordenada& coord);
	ListaPCoordenadas* filtrarCoordValidas(const Coordenada& coordenada,
											TableroAjedrez* unTablero);
	virtual ~Reina();
};

#endif /* REINA_H_ */
