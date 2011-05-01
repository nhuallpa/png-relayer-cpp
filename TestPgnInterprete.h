/*
 * TestPgnInterprete.h
 *
 *  Created on: 21/04/2011
 *      Author: administrador
 */

#ifndef __TESTPGNINTERPRETE_H_
#define __TESTPGNINTERPRETE_H_
#include "PgnInterprete.h"
#include "TableroAjedrez.h"
#include "VistaReplayer.h"
#include "ControladorReplayer.h"

#include "iostream"

class TestPgnInterprete {

public:
	void run();
	void testUnaPiezaBlanca();
	void testUnaPiezaNegra();
	void testPosicionInicial8a();
	void testPosicionInicial1a();
	void testPosicionInicial1h();
	void testPosicionInicial8h();
	void testPosicionInicial5d();
	void testUnaPiezaNegra1a();
	void testUnaPiezaBlanca1h();
	void testPosicionInicial5d5h();

	void testMovimientoSimple();
	void testBlancoNegroEnroqueCorto();
	void testBlancoNegroEnroqueLargo();
	void testPromocionAAlfil();
	void testTurnoEmpiezaNegra();
	void testJackeCombinable();
	void testMateCombinable();

};

#endif /* TESTPGNINTERPRETE_H_ */
