/*
 * FactoryPiezaJugadora.h
 *
 *  Created on: 21/04/2011
 *      Author: administrador
 */

#ifndef __FACTORYPIEZAJUGADORA_H_
#define __FACTORYPIEZAJUGADORA_H_
#include "PiezaJugadora.h"
#include "commonType.h"

class FactoryPiezaJugadora {


public:
	FactoryPiezaJugadora();

	PiezaJugadora* crear(char simbolo);

	virtual ~FactoryPiezaJugadora();
};

#endif /* FACTORYPIEZAJUGADORA_H_ */
