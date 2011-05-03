/*
 * TestPiezas.h
 *
 *  Created on: 03/05/2011
 *      Author: Nestor Huallpa
 */

#ifndef __TESTPIEZAS_H_
#define __TESTPIEZAS_H_
#include "PiezaJugadora.h"
#include "Coordenada.h"
#include "Caballo.h"
#include "Peon.h"
#include "Lista.h"
#include "Assert.h"
#include "Torre.h"
#include "Rey.h"


class TestPiezas {

public:
	void run();
	void testCaballo();

	void testTorre();
	void testAlfil();
	void testReina();
	void testAnalizadorCaballoB1YAliado();
	void testAnalizadorCaballoB1YEnemigo();
	void testAnalizadorTorreF4yAliado();
	void testAnalizadorTorreF4yEnemigo();


};

#endif /* TESTPIEZAS_H_ */
