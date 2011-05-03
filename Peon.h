/*
 * Peon.h
 *
 *  Created on: 21/04/2011
 *      Author: Nestor Huallpa
 */

#ifndef __PEON_H_
#define __PEON_H_

#include "PiezaJugadora.h"

class Peon: public PiezaJugadora {
public:
	Peon();
	ListaPCoordenadas* coordDestinoDesde(const Coordenada& coord);
	virtual ~Peon();
};

#endif /* PEON_H_ */
