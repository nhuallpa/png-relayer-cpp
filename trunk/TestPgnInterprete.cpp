/*
 * TestPgnInterprete.cpp
 *
 *  Created on: 21/04/2011
 *      Author: administrador
 */

#include "TestPgnInterprete.h"

using namespace std;


void TestPgnInterprete::run() {
	testUnaPiezaBlanca();
	testUnaPiezaNegra();
	testUnaPiezaNegra1a();
	testUnaPiezaBlanca1h();

	testPosicionInicial8a();
	testPosicionInicial1a();
	testPosicionInicial1h();
	testPosicionInicial8h();
	testPosicionInicial5d();
	testPosicionInicial5d5h();

	testMovimientoSimple();
	testBlancoNegroEnroqueCorto();
	testBlancoNegroEnroqueLargo();
	testPromocionAAlfil();
	testTurnoEmpiezaNegra();

	testJaqueCombinable();
	testMovimientoMateCombinable();
	testMovidaSipleCombinable();
}
void TestPgnInterprete::testUnaPiezaNegra() {
	stringstream streamtest;

	streamtest<<"p7/8/8/8/8/8/8/8 w"<<endl;
	streamtest<<endl;
	streamtest<<""<<endl;

	PgnAjedrez pgn;
	pgn.cargarPng(streamtest);
	PgnInterprete interprete;
	interprete.setPgn(&pgn);
	interprete.interpretar();
	ListaPPieza* piezas = interprete.getPiezasIniciales();
	if (piezas) {
		ListaPPieza::IteratorList it = piezas->getIterator();
		Assert::assertTrue(it.hasNext(), "testUnaPiezaNegra-hasNext");
		if (it.hasNext()) {
			Pieza* pieza = it.next();
			Assert::assertEquals(NEGRO, pieza->getPiezaJugadora()->getColor(), "testUnaPiezaNegra");
		}
	}
}

void TestPgnInterprete::testUnaPiezaBlanca() {
	stringstream streamtest;

	streamtest<<"P7/8/8/8/8/8/8/8 w"<<endl;
	streamtest<<endl;
	streamtest<<""<<endl;

	PgnAjedrez pgn;
	pgn.cargarPng(streamtest);
	PgnInterprete interprete;
	interprete.setPgn(&pgn);
	interprete.interpretar();
	ListaPPieza* piezas = interprete.getPiezasIniciales();
	if (piezas) {
		ListaPPieza::IteratorList it = piezas->getIterator();
		Assert::assertTrue(it.hasNext(), "testUnaPiezaBlanca-hasNext");
		if (it.hasNext()) {
			Pieza* pieza = it.next();
			Assert::assertEquals(BLANCO, pieza->getPiezaJugadora()->getColor(), "testUnaPiezaBlanca");
		}
	}
}

void TestPgnInterprete::testUnaPiezaNegra1a() {
	stringstream streamtest;

	streamtest<<"8/8/8/8/8/8/8/n7 w"<<endl;
	streamtest<<endl;
	streamtest<<""<<endl;

	PgnAjedrez pgn;
	pgn.cargarPng(streamtest);
	PgnInterprete interprete;
	interprete.setPgn(&pgn);
	interprete.interpretar();
	ListaPPieza* piezas = interprete.getPiezasIniciales();
	if (piezas) {
		ListaPPieza::IteratorList it = piezas->getIterator();
		Assert::assertTrue(it.hasNext(), "testUnaPiezaNegra-hasNext");
		if (it.hasNext()) {
			Pieza* pieza = it.next();
			Assert::assertEquals(NEGRO, pieza->getPiezaJugadora()->getColor(), "testUnaPiezaNegra");
		}
	}
}

void TestPgnInterprete::testUnaPiezaBlanca1h() {
	stringstream streamtest;

	streamtest<<"8/8/8/8/8/8/8/7P w"<<endl;
	streamtest<<endl;
	streamtest<<""<<endl;

	PgnAjedrez pgn;
	pgn.cargarPng(streamtest);
	PgnInterprete interprete;
	interprete.setPgn(&pgn);
	interprete.interpretar();
	ListaPPieza* piezas = interprete.getPiezasIniciales();
	if (piezas) {
		ListaPPieza::IteratorList it = piezas->getIterator();
		Assert::assertTrue(it.hasNext(), "testUnaPiezaBlanca1h-hasNext");
		if (it.hasNext()) {
			Pieza* pieza = it.next();
			Assert::assertEquals(BLANCO, pieza->getPiezaJugadora()->getColor(), "testUnaPiezaBlanca1h");
		}
	}
}


void TestPgnInterprete::testPosicionInicial8a() {
	stringstream streamtest;

	streamtest<<"P7/8/8/8/8/8/8/8 w"<<endl;
	streamtest<<endl;
	streamtest<<""<<endl;

	PgnAjedrez pgn;
	pgn.cargarPng(streamtest);
	PgnInterprete interprete;
	interprete.setPgn(&pgn);
	interprete.interpretar();
	ListaPPieza* piezas = interprete.getPiezasIniciales();
	if (piezas) {
		ListaPPieza::IteratorList it = piezas->getIterator();
		Assert::assertTrue(it.hasNext(), "testPosicionInicial8a-hasNext");
		if (it.hasNext()) {
			Pieza* pieza = it.next();
			Coordenada coor;
			coor.setFila(8);
			coor.setColumna('a');
			Assert::assertEquals(coor.getFila(), pieza->getCoordenadaInicial().getFila() ,
									"testPosicionInicial8a");
			Assert::assertEquals(coor.getColumna(), pieza->getCoordenadaInicial().getColumna() ,
												"testPosicionInicial8a");
		}
	}
}

void TestPgnInterprete::testPosicionInicial1a()
{
	stringstream streamtest;

	streamtest<<"8/8/8/8/8/8/8/P7 w"<<endl;
	streamtest<<endl;
	streamtest<<""<<endl;

	Coordenada coor;
	coor.setFila(1);
	coor.setColumna('a');

	PgnAjedrez pgn;
	pgn.cargarPng(streamtest);
	PgnInterprete interprete;
	interprete.setPgn(&pgn);
	interprete.interpretar();
	ListaPPieza* piezas = interprete.getPiezasIniciales();
	if (piezas) {
		ListaPPieza::IteratorList it = piezas->getIterator();
		Assert::assertTrue(it.hasNext(), "testPosicionInicial1a-hasNext");
		if (it.hasNext()) {
			Pieza* pieza = it.next();
			Assert::assertEquals(coor.getFila(), pieza->getCoordenadaInicial().getFila() ,
									"testPosicionInicial1a");
			Assert::assertEquals(coor.getColumna(), pieza->getCoordenadaInicial().getColumna() ,
												"testPosicionInicial1a");
		}
	}
}

void TestPgnInterprete::testPosicionInicial8h() {
	stringstream streamtest;
	streamtest<<"7p/8/8/8/8/8/8/8 w"<<endl;
	streamtest<<endl;
	streamtest<<""<<endl;

	PgnAjedrez pgn;
	pgn.cargarPng(streamtest);
	PgnInterprete interprete;
	interprete.setPgn(&pgn);
	interprete.interpretar();
	ListaPPieza* piezas = interprete.getPiezasIniciales();
	if (piezas) {
		ListaPPieza::IteratorList it = piezas->getIterator();
		Assert::assertTrue(it.hasNext(), "testPosicionInicial8h-hasNext");
		if (it.hasNext()) {
			Pieza* pieza = it.next();
			Coordenada coor;
			coor.setFila(8);
			coor.setColumna('h');
			Assert::assertEquals(coor.getFila(), pieza->getCoordenadaInicial().getFila() ,
									"testPosicionInicial8h");
			Assert::assertEquals(coor.getColumna(), pieza->getCoordenadaInicial().getColumna() ,
												"testPosicionInicial8h");
		}
	}
}



void TestPgnInterprete::testPosicionInicial1h() {
	stringstream streamtest;
	streamtest<<"8/8/8/8/8/8/8/7p w"<<endl;
	streamtest<<endl;
	streamtest<<""<<endl;

	PgnAjedrez pgn;
	pgn.cargarPng(streamtest);
	PgnInterprete interprete;
	interprete.setPgn(&pgn);
	interprete.interpretar();
	ListaPPieza* piezas = interprete.getPiezasIniciales();
	if (piezas) {
		ListaPPieza::IteratorList it = piezas->getIterator();
		Assert::assertTrue(it.hasNext(), "testPosicionInicial1h-hasNext");
		if (it.hasNext()) {
			Pieza* pieza = it.next();
			Coordenada coor;
			coor.setFila(1);
			coor.setColumna('h');
			Assert::assertEquals(coor.getFila(), pieza->getCoordenadaInicial().getFila() ,
									"testPosicionInicial1h");
			Assert::assertEquals(coor.getColumna(), pieza->getCoordenadaInicial().getColumna() ,
												"testPosicionInicial1h");
		}
	}
}



void TestPgnInterprete::testPosicionInicial5d()
{
	stringstream streamtest;
	streamtest<<"8/8/8/3p4/8/8/8/8 w"<<endl;
	streamtest<<endl;
	streamtest<<""<<endl;

	PgnAjedrez pgn;
	pgn.cargarPng(streamtest);
	PgnInterprete interprete;
	interprete.setPgn(&pgn);
	interprete.interpretar();
	ListaPPieza* piezas = interprete.getPiezasIniciales();
	if (piezas) {
		ListaPPieza::IteratorList it = piezas->getIterator();
		Assert::assertTrue(it.hasNext(), "testPosicionInicial5d-hasNext");
		if (it.hasNext()) {
			Pieza* pieza = it.next();
			Coordenada coor;
			coor.setFila(5);
			coor.setColumna('d');
			Assert::assertEquals(coor.getFila(), pieza->getCoordenadaInicial().getFila() ,
									"testPosicionInicial5d");
			Assert::assertEquals(coor.getColumna(), pieza->getCoordenadaInicial().getColumna() ,
												"testPosicionInicial5d");
		}
	}
}

void TestPgnInterprete::testPosicionInicial5d5h() {
	stringstream streamtest;
	streamtest<<"8/8/8/3p3n/8/8/8/8 w"<<endl;
	streamtest<<endl;
	streamtest<<""<<endl;


	Coordenada coor, coor2;
	coor.setFila(5);
	coor.setColumna('d');
	coor2.setFila(5);
	coor2.setColumna('h');


	PgnAjedrez pgn;
	pgn.cargarPng(streamtest);
	PgnInterprete interprete;
	interprete.setPgn(&pgn);
	interprete.interpretar();
	ListaPPieza* piezas = interprete.getPiezasIniciales();
	if (piezas) {
		ListaPPieza::IteratorList it = piezas->getIterator();
		Assert::assertTrue(it.hasNext(), "testPosicionInicial5d5h-hasNext");
		if (it.hasNext()) {
			Pieza* pieza = it.next();
			Assert::assertEquals(coor.getFila(), pieza->getCoordenadaInicial().getFila() ,
									"testPosicionInicial5d5h");
			Assert::assertEquals(coor.getColumna(), pieza->getCoordenadaInicial().getColumna() ,
												"testPosicionInicial5d5h");
		}
		Assert::assertTrue(it.hasNext(), "testPosicionInicial5d5h-hasNext-2");
		if (it.hasNext()) {
			Pieza* pieza = it.next();
			Assert::assertEquals(coor2.getFila(), pieza->getCoordenadaInicial().getFila() ,
									"testPosicionInicial5d5h-2");
			Assert::assertEquals(coor2.getColumna(), pieza->getCoordenadaInicial().getColumna() ,
												"testPosicionInicial5d5h-2");
		}
	}
}

void TestPgnInterprete::testMovimientoSimple() {
	stringstream streamtest;
	streamtest<<"8/pppppppp/8/8/8/8/PPPPPPPP/8 w"<<endl;
	streamtest<<endl;
	streamtest<<"23. e2e4 e7e5"<<endl;

	PgnAjedrez entradaPng;
	entradaPng.cargarPng(streamtest);
	TableroAjedrez ajedrez;
	VistaReplayer vista;
	ControladorReplayer controlador(&ajedrez, &vista);
	controlador.reproducir(&entradaPng);

	Coordenada coord1(2,'e');
	Assert::assertFalse(ajedrez.hayPiezaJugadora(coord1), "testMovimientoSimple-1");
	Coordenada coord2(7,'e');
	Assert::assertFalse(ajedrez.hayPiezaJugadora(coord2), "testMovimientoSimple-2");
	Coordenada coord3(4,'e');
	Assert::assertTrue(ajedrez.hayPiezaJugadora(coord3), "testMovimientoSimple-3");
	Coordenada coord4(5,'e');
	Assert::assertTrue(ajedrez.hayPiezaJugadora(coord4), "testMovimientoSimple-4");
}


void TestPgnInterprete::testBlancoNegroEnroqueLargo() {
	stringstream streamtest;
	streamtest<<"r3k3/8/8/8/8/8/8/R3K3 w"<<endl;
	streamtest<<endl;
	streamtest<<"1. 0-0-0 0-0-0"<<endl;

	PgnAjedrez entradaPng;
	entradaPng.cargarPng(streamtest);
	TableroAjedrez ajedrez;
	VistaReplayer vista;
	ControladorReplayer controlador(&ajedrez, &vista);
	controlador.reproducir(&entradaPng);

	Coordenada coord1(1, 'a');
	Assert::assertFalse(ajedrez.hayPiezaJugadora(coord1), "testBlancoNegroEnroqueLargo-1");
	Coordenada coord2(1, 'e');
	Assert::assertFalse(ajedrez.hayPiezaJugadora(coord2), "testBlancoNegroEnroqueLargo-1");
	Coordenada coord3(1, 'd');
	Assert::assertTrue(ajedrez.hayPiezaJugadora(coord3), "testBlancoNegroEnroqueLargo-1");
	Coordenada coord4(1, 'c');
	Assert::assertTrue(ajedrez.hayPiezaJugadora(coord4), "testBlancoNegroEnroqueLargo-1");



	Coordenada coord5(8, 'a');
	Assert::assertFalse(ajedrez.hayPiezaJugadora(coord5), "testBlancoNegroEnroqueLargo-2");
	Coordenada coord6(8, 'e');
	Assert::assertFalse(ajedrez.hayPiezaJugadora(coord6), "testBlancoNegroEnroqueLargo-2");
	Coordenada coord7(8, 'd');
	Assert::assertTrue(ajedrez.hayPiezaJugadora(coord7), "testBlancoNegroEnroqueLargo-2");
	Coordenada coord8(8, 'c');
	Assert::assertTrue(ajedrez.hayPiezaJugadora(coord8), "testBlancoNegroEnroqueLargo-2");
}

void TestPgnInterprete::testBlancoNegroEnroqueCorto()
{
	stringstream streamtest;
	streamtest<<"4k2r/8/8/8/8/8/8/4K2R w"<<endl;
	streamtest<<endl;
	streamtest<<"1. 0-0 0-0"<<endl;

	PgnAjedrez entradaPng;
	entradaPng.cargarPng(streamtest);
	TableroAjedrez ajedrez;
	VistaReplayer vista;
	ControladorReplayer controlador(&ajedrez, &vista);
	controlador.reproducir(&entradaPng);

	Coordenada coord1(1, 'h');
	Assert::assertFalse(ajedrez.hayPiezaJugadora(coord1), "testBlancoNegroEnroqueCorto-1");
	Coordenada coord2(1, 'e');
	Assert::assertFalse(ajedrez.hayPiezaJugadora(coord2), "testBlancoNegroEnroqueCorto-1");
	Coordenada coord3(1, 'f');
	Assert::assertTrue(ajedrez.hayPiezaJugadora(coord3), "testBlancoNegroEnroqueCorto-1");
	Coordenada coord4(1, 'g');
	Assert::assertTrue(ajedrez.hayPiezaJugadora(coord4), "testBlancoNegroEnroqueCorto-1");



	Coordenada coord5(8, 'h');
	Assert::assertFalse(ajedrez.hayPiezaJugadora(coord5), "testBlancoNegroEnroqueCorto-2");
	Coordenada coord6(8, 'e');
	Assert::assertFalse(ajedrez.hayPiezaJugadora(coord6), "testBlancoNegroEnroqueCorto-2");
	Coordenada coord7(8, 'f');
	Assert::assertTrue(ajedrez.hayPiezaJugadora(coord7), "testBlancoNegroEnroqueCorto-2");
	Coordenada coord8(8, 'g');
	Assert::assertTrue(ajedrez.hayPiezaJugadora(coord8), "testBlancoNegroEnroqueCorto-2");

}


void TestPgnInterprete::testPromocionAAlfil() {
	stringstream streamtest;
	streamtest<<"8/P7/8/8/8/8/4p3/8 w"<<endl;
	streamtest<<endl;
	streamtest<<"1. a7a8B e2e1B"<<endl;

	PgnAjedrez entradaPng;
	entradaPng.cargarPng(streamtest);
	TableroAjedrez ajedrez;
	VistaReplayer vista;
	ControladorReplayer controlador(&ajedrez, &vista);
	controlador.reproducir(&entradaPng);

	Coordenada coord1(7,'a');
	Assert::assertFalse(ajedrez.hayPiezaJugadora(coord1), "testPromocionAAlfil-1");
	Coordenada coord2(8,'a');
	Assert::assertTrue(ajedrez.hayPiezaJugadora(coord2), "testPromocionAAlfil-1");

	Coordenada coord3(2,'e');
	Assert::assertFalse(ajedrez.hayPiezaJugadora(coord3), "testPromocionAAlfil-2");
	Coordenada coord4(1,'e');
	Assert::assertTrue(ajedrez.hayPiezaJugadora(coord4), "testPromocionAAlfil-2");
}

void TestPgnInterprete::testTurnoEmpiezaNegra()
{

	stringstream streamtest;
	streamtest<<"p7/4p3/8/8/8/8/4P3/P7 b"<<endl;
	streamtest<<endl;
	streamtest<<"1. e7e6 2. a1a2  a8a7"<<endl;

	PgnAjedrez entradaPng;
	entradaPng.cargarPng(streamtest);
	TableroAjedrez ajedrez;
	VistaReplayer vista;
	ControladorReplayer controlador(&ajedrez, &vista);
	controlador.reproducir(&entradaPng);

	Coordenada coord1(7,'e');
	Assert::assertFalse(ajedrez.hayPiezaJugadora(coord1), "testTurnoEmpiezaNegra-1");
	Coordenada coord2(6,'e');
	Assert::assertTrue(ajedrez.hayPiezaJugadora(coord2), "testTurnoEmpiezaNegra-1");
	Coordenada coord3(2,'e');
	Assert::assertTrue(ajedrez.hayPiezaJugadora(coord3), "testTurnoEmpiezaNegra-1");

	Coordenada coord4(2,'a');
	Assert::assertTrue(ajedrez.hayPiezaJugadora(coord4), "testTurnoEmpiezaNegra-2");
	Coordenada coord5(7,'a');
	Assert::assertTrue(ajedrez.hayPiezaJugadora(coord5), "testTurnoEmpiezaNegra-2");

}


void TestPgnInterprete::testMovimientoMateCombinable() {
	stringstream streamtest;
	streamtest<<"8/pppppppp/8/8/8/8/PPPPPPPP/8 w"<<endl;
	streamtest<<endl;
	streamtest<<"1. e2e4# Ae7e5#"<<endl;

	PgnAjedrez entradaPng;
	entradaPng.cargarPng(streamtest);
	TableroAjedrez ajedrez;
	VistaReplayer vista;
	ControladorReplayer controlador(&ajedrez, &vista);
	controlador.reproducir(&entradaPng);

	Coordenada coord1(2,'e');
	Assert::assertFalse(ajedrez.hayPiezaJugadora(coord1), "testMovimientoMateCombinable-1");
	Coordenada coord2(7,'e');
	Assert::assertFalse(ajedrez.hayPiezaJugadora(coord2), "testMovimientoMateCombinable-2");
	Coordenada coord3(4,'e');
	Assert::assertTrue(ajedrez.hayPiezaJugadora(coord3), "testMovimientoMateCombinable-3");
	Coordenada coord4(5,'e');
	Assert::assertTrue(ajedrez.hayPiezaJugadora(coord4), "testMovimientoMateCombinable-4");
}



void TestPgnInterprete::testJaqueCombinable()
{
	stringstream streamtest;
	streamtest<<"8/pppppppp/8/8/8/8/PPPPPPPP/8 w"<<endl;
	streamtest<<endl;
	streamtest<<"1. e2e4+ Ae7e5+"<<endl;

	PgnAjedrez entradaPng;
	entradaPng.cargarPng(streamtest);
	TableroAjedrez ajedrez;
	VistaReplayer vista;
	ControladorReplayer controlador(&ajedrez, &vista);
	controlador.reproducir(&entradaPng);

	Coordenada coord1(2,'e');
	Assert::assertFalse(ajedrez.hayPiezaJugadora(coord1), "testJaqueCombinable-1");
	Coordenada coord2(7,'e');
	Assert::assertFalse(ajedrez.hayPiezaJugadora(coord2), "testJaqueCombinable-2");
	Coordenada coord3(4,'e');
	Assert::assertTrue(ajedrez.hayPiezaJugadora(coord3), "testJaqueCombinable-3");
	Coordenada coord4(5,'e');
	Assert::assertTrue(ajedrez.hayPiezaJugadora(coord4), "testJaqueCombinable-4");

}

void TestPgnInterprete::testMovidaSipleCombinable()
{
	stringstream streamtest;
	streamtest<<"8/pppppppp/8/8/8/8/PPPPPPPP/8 w"<<endl;
	streamtest<<endl;
	streamtest<<"1. Ne2e4 Ae7e5"<<endl;

	PgnAjedrez entradaPng;
	entradaPng.cargarPng(streamtest);
	TableroAjedrez ajedrez;
	VistaReplayer vista;
	ControladorReplayer controlador(&ajedrez, &vista);
	controlador.reproducir(&entradaPng);

	Coordenada coord1(2,'e');
	Assert::assertFalse(ajedrez.hayPiezaJugadora(coord1), "testMovidaSipleCombinable-1");
	Coordenada coord2(7,'e');
	Assert::assertFalse(ajedrez.hayPiezaJugadora(coord2), "testMovidaSipleCombinable-2");
	Coordenada coord3(4,'e');
	Assert::assertTrue(ajedrez.hayPiezaJugadora(coord3), "testMovidaSipleCombinable-3");
	Coordenada coord4(5,'e');
	Assert::assertTrue(ajedrez.hayPiezaJugadora(coord4), "testMovidaSipleCombinable-4");

}


