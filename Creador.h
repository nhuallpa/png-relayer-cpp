/*
 * Creador.h
 *
 *  Created on: 21/04/2011
 *      Author: administrador
 */

#ifndef __CREADOR_H_
#define __CREADOR_H_
#include "PiezaJugadora.h"

class Creador {
public:
	virtual PiezaJugadora* getInstancia() = 0;
};

#endif /* CREADOR_H_ */
