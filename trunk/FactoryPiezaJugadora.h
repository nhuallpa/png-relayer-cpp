/*
 * FactoryPiezaJugadora.h
 *
 *  Created on: 21/04/2011
 *      Author: Nestor Huallpa
 */

#ifndef __FACTORYPIEZAJUGADORA_H_
#define __FACTORYPIEZAJUGADORA_H_
#include "PiezaJugadora.h"
#include "Peon.h"
#include "Torre.h"
#include "Caballo.h"
#include "Alfil.h"
#include "Reina.h"
#include "Rey.h"
#include "commonType.h"
#include <cctype>
#include "CreadorEstandar.h"

class FactoryPiezaJugadora {

	//static FactoryPiezaJugadora* singletonFactory;

private:
	Creador* creadores[CANT_PIEZAS];

public:
	FactoryPiezaJugadora();
	PiezaJugadora* crear(char simbolo);
	virtual ~FactoryPiezaJugadora();

	//static FactoryPiezaJugadora* getFactory();

private:
	bool esMinuscula(char value);

};

#endif /* FACTORYPIEZAJUGADORA_H_ */
