/*
 * TestTableroAjedrez.h
 *
 *  Created on: 16/04/2011
 *      Author: administrador
 */

#ifndef TESTTABLEROAJEDREZ_H_
#define TESTTABLEROAJEDREZ_H_
#include "Ajedrez.h"
#include "PngAjedrez.h"
#include "ControladorReplayer.h"
#include "Assert.h"
#include "assert.h"
class TestTableroAjedrez {

private:


public:
	TestTableroAjedrez();
	void testTableroVacio();
	void testTableroCargado();
	void run();
	virtual ~TestTableroAjedrez();
};

#endif /* TESTTABLEROAJEDREZ_H_ */
