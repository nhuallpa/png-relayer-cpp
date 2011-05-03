/*
 * Reina.h
 *
 *  Created on: 21/04/2011
 *      Author: Nestor Huallpa
 */

#ifndef __REINA_H_
#define __REINA_H_

#include "PiezaJugadora.h"

class Reina: public PiezaJugadora {
public:
	Reina();
	ListaPCoordenadas* coordDestinoDesde(const Coordenada& coord);
	virtual ~Reina();
};

#endif /* REINA_H_ */
