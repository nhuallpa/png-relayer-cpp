/*
 * Rey.h
 *
 *  Created on: 21/04/2011
 *      Author: Nestor Huallpa
 */

#ifndef __REY_H_
#define __REY_H_

#include "PiezaJugadora.h"

class Rey: public PiezaJugadora {
public:
	Rey();
	ListaPCoordenadas* coordDestinoDesde(const Coordenada& coord);
	virtual ~Rey();
};

#endif /* REY_H_ */
