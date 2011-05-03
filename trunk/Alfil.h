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
	Alfil();
	ListaPCoordenadas* coordDestinoDesde(const Coordenada& coord);
	virtual ~Alfil();
};

#endif /* ALFIL_H_ */
