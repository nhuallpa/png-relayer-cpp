/*
 * TestPiezas.cpp
 *
 *  Created on: 03/05/2011
 *      Author: Nestor Huallpa
 */

#include "TestPiezas.h"
#include "TableroAjedrez.h"


void TestPiezas::run()
{
	testCaballo();
	testTorre();
	testAlfil();
	testReina();
	testAnalizadorCaballoB1YEnemigo();
	testAnalizadorCaballoB1YAliado();
	testAnalizadorTorreF4yAliado();
	testAnalizadorTorreF4yEnemigo();
	testAnalizadorAlfilB6yAliado();
	testAnalizadorAlfilB6yEnemigo();
	testAnalizadorReinag2yAliado();
	testAnalizadorReinag2yEnemigo();

}


void TestPiezas::testCaballo()
{

//	PiezaJugadora* caballo = new Caballo();
//	Coordenada d4(4, 'd');
//
//	ListaPCoordenadas* lCoordenas = caballo->coordDestinoDesde(d4);
//
//	ListaPCoordenadas::IteratorList it = lCoordenas->getIterator();
//	Assert::assertTrue(it.hasNext(), "testCaballo-1");
//	if (it.hasNext()){
//		Coordenada coordEsperado(6, 'e');
//		Coordenada* coordResul = it.next();
//		Assert::assertTrue(coordResul->esIgual(coordEsperado), "testCaballo-1");
//	}
//	Assert::assertTrue(it.hasNext(), "testCaballo-2");
//	if (it.hasNext()){
//		Coordenada coordEsperado(5, 'f');
//		Coordenada* coordResul = it.next();
//		Assert::assertTrue(coordResul->esIgual(coordEsperado), "testCaballo-2");
//	}
//	Assert::assertTrue(it.hasNext(), "testCaballo-3");
//	if (it.hasNext()){
//		Coordenada coordEsperado(3, 'f');
//		Coordenada* coordResul = it.next();
//		Assert::assertTrue(coordResul->esIgual(coordEsperado), "testCaballo-3");
//	}
//	Assert::assertTrue(it.hasNext(), "testCaballo-4");
//	if (it.hasNext()){
//		Coordenada coordEsperado(2, 'e');
//		Coordenada* coordResul = it.next();
//		Assert::assertTrue(coordResul->esIgual(coordEsperado), "testCaballo-4");
//	}
//	Assert::assertTrue(it.hasNext(), "testCaballo-5");
//	if (it.hasNext()){
//		Coordenada coordEsperado(2, 'c');
//		Coordenada* coordResul = it.next();
//		Assert::assertTrue(coordResul->esIgual(coordEsperado), "testCaballo-5");
//	}
//	Assert::assertTrue(it.hasNext(), "testCaballo-6");
//	if (it.hasNext()){
//		Coordenada coordEsperado(3, 'b');
//		Coordenada* coordResul = it.next();
//		Assert::assertTrue(coordResul->esIgual(coordEsperado), "testCaballo-6");
//	}
//	Assert::assertTrue(it.hasNext(), "testCaballo-7");
//	if (it.hasNext()){
//		Coordenada coordEsperado(5, 'b');
//		Coordenada* coordResul = it.next();
//		Assert::assertTrue(coordResul->esIgual(coordEsperado), "testCaballo-7");
//	}
//	Assert::assertTrue(it.hasNext(), "testCaballo-8");
//	if (it.hasNext()){
//		Coordenada coordEsperado(6, 'c');
//		Coordenada* coordResul = it.next();
//		Assert::assertTrue(coordResul->esIgual(coordEsperado), "testCaballo-8");
//	}
//	if (lCoordenas){
//		ListaPCoordenadas::IteratorList it = lCoordenas->getIterator();
//		while (it.hasNext()) {
//			delete (it.next());
//		}
//		delete lCoordenas;
//	}
//	delete caballo;
}


void TestPiezas::testTorre()
{
	int cant = 0;
	TableroAjedrez tablero;
	PiezaJugadora* torre = new Torre();
	Coordenada f4(4, 'f');
	tablero.posionar(torre, f4);
	ListaPCoordenadas* lAnalizadas = torre->filtrarCoordValidas(f4, &tablero);

	if (lAnalizadas) {
	ListaPCoordenadas::IteratorList it = lAnalizadas->getIterator();
		while (it.hasNext()) {
			it.next();
			cant++;
		}
	}

	Assert::assertEquals(14, cant , "testTorre");

	if (lAnalizadas) {
		ListaPCoordenadas::IteratorList it = lAnalizadas->getIterator();
		while (it.hasNext()) {
			delete it.next();
		}
		delete lAnalizadas;
	}
	delete torre;

}



void TestPiezas::testAlfil() {

	int cant = 0;
	TableroAjedrez tablero;
	PiezaJugadora* alfil = new Alfil();
	Coordenada b6(6, 'b');
	tablero.posionar(alfil, b6);
	ListaPCoordenadas* lAnalizadas = alfil->filtrarCoordValidas(b6, &tablero);

	if (lAnalizadas) {
	ListaPCoordenadas::IteratorList it = lAnalizadas->getIterator();
		while (it.hasNext()) {
			it.next();
			cant++;
		}
	}

	Assert::assertEquals(9, cant , "testAlfil");

	if (lAnalizadas) {
		ListaPCoordenadas::IteratorList it = lAnalizadas->getIterator();
		while (it.hasNext()) {
			delete it.next();
		}
		delete lAnalizadas;
	}
	delete alfil;
}



void TestPiezas::testReina() {
	int cant = 0;
	TableroAjedrez tablero;
	PiezaJugadora* reina = new Reina();
	Coordenada g3(3, 'g');
	tablero.posionar(reina, g3);
	ListaPCoordenadas* lAnalizadas = reina->filtrarCoordValidas(g3, &tablero);

	if (lAnalizadas) {
		ListaPCoordenadas::IteratorList it = lAnalizadas->getIterator();
		while (it.hasNext()) {
			it.next();
			cant++;
		}
	}

	Assert::assertEquals(23, cant , "testReina");

	if (lAnalizadas) {
		ListaPCoordenadas::IteratorList it = lAnalizadas->getIterator();
		while (it.hasNext()) {
			delete it.next();
		}
		delete lAnalizadas;
	}
	delete reina;
}


void TestPiezas::testAnalizadorCaballoB1YAliado()
{

	TableroAjedrez tablero;
	PiezaJugadora* caballo = new Caballo();
	caballo->setColor(NEGRO);
	PiezaJugadora* aliado = new Peon();
	aliado->setColor(NEGRO);
	Coordenada b1(1, 'b');
	Coordenada a3(3, 'a');
	tablero.posionar(caballo, b1);
	tablero.posionar(aliado, a3);
	ListaPCoordenadas* lAnalizadas = caballo->filtrarCoordValidas(b1, &tablero);

	ListaPCoordenadas::IteratorList it = lAnalizadas->getIterator();
	int cant = 0;
	while (it.hasNext()) {
		it.next();
		cant++;
	}

	Assert::assertEquals(2, cant , "testAnalizadorCaballoB1YAliado");

	if (lAnalizadas) {
		ListaPCoordenadas::IteratorList it = lAnalizadas->getIterator();
		while (it.hasNext()) {
			delete it.next();
		}
		delete lAnalizadas;
	}
	delete caballo;
	delete aliado;
}



void TestPiezas::testAnalizadorCaballoB1YEnemigo()
{

	TableroAjedrez tablero;
	PiezaJugadora* caballo = new Caballo();
	caballo->setColor(NEGRO);
	PiezaJugadora* enemigo = new Peon();
	enemigo->setColor(BLANCO);
	Coordenada b1(1, 'b');
	Coordenada a3(3, 'a');
	tablero.posionar(caballo, b1);
	tablero.posionar(enemigo, a3);
	ListaPCoordenadas* lAnalizadas = caballo->filtrarCoordValidas(b1, &tablero);

	ListaPCoordenadas::IteratorList it = lAnalizadas->getIterator();
	int cant = 0;
	while (it.hasNext()) {
		it.next();
		cant++;
	}

	Assert::assertEquals(3, cant , "testAnalizadorCaballoB1YEnemigo");



	if (lAnalizadas) {
		ListaPCoordenadas::IteratorList it = lAnalizadas->getIterator();
		while (it.hasNext()) {
			delete it.next();
		}
		delete lAnalizadas;
	}
	delete caballo;
	delete enemigo;
}

void TestPiezas::testAnalizadorTorreF4yEnemigo()
{
	int cant = 0;
	TableroAjedrez tablero;
	PiezaJugadora* torre = new Torre();
	PiezaJugadora* rey = new Rey();
	torre->setColor(NEGRO);
	rey->setColor(BLANCO);

	Coordenada f4(4, 'f');
	Coordenada c4(4, 'c');
	tablero.posionar(torre, f4);
	tablero.posionar(rey, c4);
	ListaPCoordenadas* lAnalizadas = torre->filtrarCoordValidas(f4, &tablero);

	if (lAnalizadas) {
		ListaPCoordenadas::IteratorList it = lAnalizadas->getIterator();
		while (it.hasNext()) {
			it.next();
			cant++;
		}
	}

	Assert::assertEquals(12, cant , "testAnalizadorTorreF4yEnemigo");

	if (lAnalizadas) {
		ListaPCoordenadas::IteratorList it = lAnalizadas->getIterator();
		while (it.hasNext()) {
			delete it.next();
		}
		delete lAnalizadas;
	}
	delete torre;
	delete rey;
}



void TestPiezas::testAnalizadorTorreF4yAliado()
{
	int cant = 0;
	TableroAjedrez tablero;
	PiezaJugadora* torre = new Torre();
	PiezaJugadora* rey = new Rey();
	torre->setColor(NEGRO);
	rey->setColor(NEGRO);

	Coordenada f4(4, 'f');
	Coordenada c4(4, 'c');
	tablero.posionar(torre, f4);
	tablero.posionar(rey, c4);
	ListaPCoordenadas* lAnalizadas = torre->filtrarCoordValidas(f4, &tablero);

	if (lAnalizadas) {
		ListaPCoordenadas::IteratorList it = lAnalizadas->getIterator();
		while (it.hasNext()) {
			it.next();
			cant++;
		}
	}

	Assert::assertEquals(11, cant , "testAnalizadorTorreF4yAliado");

	if (lAnalizadas) {
		ListaPCoordenadas::IteratorList it = lAnalizadas->getIterator();
		while (it.hasNext()) {
			delete it.next();
		}
		delete lAnalizadas;
	}
	delete torre;
	delete rey;
}

void TestPiezas::testAnalizadorReinag2yEnemigo() {
	int cant = 0;
	TableroAjedrez tablero;
	PiezaJugadora* reina = new Reina();
	PiezaJugadora* rey = new Rey();
	reina->setColor(NEGRO);
	rey->setColor(BLANCO);

	Coordenada g3(3, 'g');
	Coordenada d6(6, 'd');
	tablero.posionar(reina, g3);
	tablero.posionar(rey, d6);
	ListaPCoordenadas* lAnalizadas = reina->filtrarCoordValidas(g3, &tablero);

	if (lAnalizadas) {
		ListaPCoordenadas::IteratorList it = lAnalizadas->getIterator();
		while (it.hasNext()) {
			it.next();
			cant++;
		}
	}

	Assert::assertEquals(21, cant , "testAnalizadorReinag2yEnemigo");

	if (lAnalizadas) {
		ListaPCoordenadas::IteratorList it = lAnalizadas->getIterator();
		while (it.hasNext()) {
			delete it.next();
		}
		delete lAnalizadas;
	}
	delete reina;
	delete rey;
}



void TestPiezas::testAnalizadorReinag2yAliado() {
	int cant = 0;
	TableroAjedrez tablero;
	PiezaJugadora* reina = new Reina();
	PiezaJugadora* rey = new Rey();
	reina->setColor(NEGRO);
	rey->setColor(NEGRO);

	Coordenada g3(3, 'g');
	Coordenada d6(6, 'd');
	tablero.posionar(reina, g3);
	tablero.posionar(rey, d6);
	ListaPCoordenadas* lAnalizadas = reina->filtrarCoordValidas(g3, &tablero);

	if (lAnalizadas) {
		ListaPCoordenadas::IteratorList it = lAnalizadas->getIterator();
		while (it.hasNext()) {
			it.next();
			cant++;
		}
	}

	Assert::assertEquals(20, cant , "testAnalizadorReinag2yAliado");

	if (lAnalizadas) {
		ListaPCoordenadas::IteratorList it = lAnalizadas->getIterator();
		while (it.hasNext()) {
			delete it.next();
		}
		delete lAnalizadas;
	}
	delete reina;
	delete rey;
}



void TestPiezas::testAnalizadorAlfilB6yEnemigo() {

	int cant = 0;
	TableroAjedrez tablero;
	PiezaJugadora* alfil = new Alfil();
	PiezaJugadora* enemigo = new Alfil();
	alfil->setColor(NEGRO);
	enemigo->setColor(BLANCO);
	Coordenada b6(6, 'b');
	tablero.posionar(alfil, b6);
	Coordenada d4(4, 'd');
	tablero.posionar(enemigo, d4);

	ListaPCoordenadas* lAnalizadas = alfil->filtrarCoordValidas(b6, &tablero);

	if (lAnalizadas) {
		ListaPCoordenadas::IteratorList it = lAnalizadas->getIterator();
		while (it.hasNext()) {
			it.next();
			cant++;
		}
	}

	Assert::assertEquals(6, cant , "testAnalizadorAlfilB6yEnemigo");

	if (lAnalizadas) {
		ListaPCoordenadas::IteratorList it = lAnalizadas->getIterator();
		while (it.hasNext()) {
			delete it.next();
		}
		delete lAnalizadas;
	}
	delete alfil;
	delete enemigo;
}



void TestPiezas::testAnalizadorAlfilB6yAliado() {
	int cant = 0;
	TableroAjedrez tablero;
	PiezaJugadora* alfil = new Alfil();
	PiezaJugadora* aliado = new Alfil();
	alfil->setColor(NEGRO);
	aliado->setColor(NEGRO);
	Coordenada b6(6, 'b');
	tablero.posionar(alfil, b6);
	Coordenada d4(4, 'd');
	tablero.posionar(aliado, d4);

	ListaPCoordenadas* lAnalizadas = alfil->filtrarCoordValidas(b6, &tablero);

	if (lAnalizadas) {
		ListaPCoordenadas::IteratorList it = lAnalizadas->getIterator();
		while (it.hasNext()) {
			it.next();
			cant++;
		}
	}

	Assert::assertEquals(5, cant , "testAnalizadorAlfilB6yAliado");

	if (lAnalizadas) {
		ListaPCoordenadas::IteratorList it = lAnalizadas->getIterator();
		while (it.hasNext()) {
			delete it.next();
		}
		delete lAnalizadas;
	}
	delete alfil;
	delete aliado;
}










