/*
 * TestTableroAjedrez.h
 *
 *  Created on: 16/04/2011
 *      Author: administrador
 */

#ifndef TESTTABLEROAJEDREZ_H_
#define TESTTABLEROAJEDREZ_H_
#include "TableroAjedrez.h"
#include "PgnAjedrez.h"
#include "ControladorReplayer.h"
#include "Assert.h"
class TestTableroAjedrez {

public:
	void testTableroVacio();
	void testTableroCargado();
	void run();
};

#endif /* TESTTABLEROAJEDREZ_H_ */
