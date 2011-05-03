/*
 * TestAnalisisMovidas.h
 *
 *  Created on: 01/05/2011
 *      Author: Nestor Huallpa
 */

#ifndef __TESTANALISISMOVIDAS_H_
#define __TESTANALISISMOVIDAS_H_
#include "PgnInterprete.h"
#include "TableroAjedrez.h"
#include "VistaReplayer.h"
#include "ControladorReplayer.h"
#include "Assert.h"
#include <sstream>


class TestAnalizador {
public:
	void run();
	void testCaballoSolo_d4();
	void testAlfil();
	void testTorre();
	void testReina();
	void testRey();
};

#endif /* TESTANALISISMOVIDAS_H_ */
