/*
 * TestPgnInterprete.cpp
 *
 *  Created on: 21/04/2011
 *      Author: administrador
 */

#include "TestPgnInterprete.h"
#include "Assert.h"
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
}
void TestPgnInterprete::testUnaPiezaNegra() {
	stringstream streamtest;

	streamtest<<"p7/8/8/8/8/8/8/8 w"<<endl;
	streamtest<<endl;
	streamtest<<"1. e2e4 e7e5 2. Qd1f3 Nb8c6 3. Bf1c4 Ng8f6 4. Ng1e2 Bf8c5 5. a2a3 d7d6 6. 0-0 Bc8g4 "<<endl;
	streamtest<<"7. Qf3d3 Nf6h5 8. h2h3 Bg4e2 9. Qd3e2 Nh5f4 10. Qe2e1 Nc6d4 11. Bc4b3"<<endl;
	streamtest<<"Nf4h3+ 12. Kg1h2 Qd8h4 13. g2g3 Nd4f3+ 14. Kh2g2 Nf3e1+ 15. Rf1e1 Qh4g4 16."<<endl;
	streamtest<<"d2d3 Bc5f2 17. Re1h1 Qg4g3+ 18. Kg2f1 Bf2d4 19. Kf1e2 Qg3g2+ 20. Ke2d1"<<endl;
	streamtest<<"Qg2h1+ 21. Kd1d2 Qh1g2+ 22. Kd2e1 Nh3g1 23. Nb1c3 Bd4c3+ 24. b2c3 Qg2e2#"<<endl;

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
	streamtest<<"1. e2e4 e7e5 2. Qd1f3 Nb8c6 3. Bf1c4 Ng8f6 4. Ng1e2 Bf8c5 5. a2a3 d7d6 6. 0-0 Bc8g4 "<<endl;
	streamtest<<"7. Qf3d3 Nf6h5 8. h2h3 Bg4e2 9. Qd3e2 Nh5f4 10. Qe2e1 Nc6d4 11. Bc4b3"<<endl;
	streamtest<<"Nf4h3+ 12. Kg1h2 Qd8h4 13. g2g3 Nd4f3+ 14. Kh2g2 Nf3e1+ 15. Rf1e1 Qh4g4 16."<<endl;
	streamtest<<"d2d3 Bc5f2 17. Re1h1 Qg4g3+ 18. Kg2f1 Bf2d4 19. Kf1e2 Qg3g2+ 20. Ke2d1"<<endl;
	streamtest<<"Qg2h1+ 21. Kd1d2 Qh1g2+ 22. Kd2e1 Nh3g1 23. Nb1c3 Bd4c3+ 24. b2c3 Qg2e2#"<<endl;

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
	streamtest<<"1. e2e4 e7e5 2. Qd1f3 Nb8c6 3. Bf1c4 Ng8f6 4. Ng1e2 Bf8c5 5. a2a3 d7d6 6. 0-0 Bc8g4 "<<endl;
	streamtest<<"7. Qf3d3 Nf6h5 8. h2h3 Bg4e2 9. Qd3e2 Nh5f4 10. Qe2e1 Nc6d4 11. Bc4b3"<<endl;
	streamtest<<"Nf4h3+ 12. Kg1h2 Qd8h4 13. g2g3 Nd4f3+ 14. Kh2g2 Nf3e1+ 15. Rf1e1 Qh4g4 16."<<endl;
	streamtest<<"d2d3 Bc5f2 17. Re1h1 Qg4g3+ 18. Kg2f1 Bf2d4 19. Kf1e2 Qg3g2+ 20. Ke2d1"<<endl;
	streamtest<<"Qg2h1+ 21. Kd1d2 Qh1g2+ 22. Kd2e1 Nh3g1 23. Nb1c3 Bd4c3+ 24. b2c3 Qg2e2#"<<endl;

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
	streamtest<<"1. e2e4 e7e5 2. Qd1f3 Nb8c6 3. Bf1c4 Ng8f6 4. Ng1e2 Bf8c5 5. a2a3 d7d6 6. 0-0 Bc8g4 "<<endl;
	streamtest<<"7. Qf3d3 Nf6h5 8. h2h3 Bg4e2 9. Qd3e2 Nh5f4 10. Qe2e1 Nc6d4 11. Bc4b3"<<endl;
	streamtest<<"Nf4h3+ 12. Kg1h2 Qd8h4 13. g2g3 Nd4f3+ 14. Kh2g2 Nf3e1+ 15. Rf1e1 Qh4g4 16."<<endl;
	streamtest<<"d2d3 Bc5f2 17. Re1h1 Qg4g3+ 18. Kg2f1 Bf2d4 19. Kf1e2 Qg3g2+ 20. Ke2d1"<<endl;
	streamtest<<"Qg2h1+ 21. Kd1d2 Qh1g2+ 22. Kd2e1 Nh3g1 23. Nb1c3 Bd4c3+ 24. b2c3 Qg2e2#"<<endl;

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
	streamtest<<"1. e2e4 e7e5 2. Qd1f3 Nb8c6 3. Bf1c4 Ng8f6 4. Ng1e2 Bf8c5 5. a2a3 d7d6 6. 0-0 Bc8g4 "<<endl;
	streamtest<<"7. Qf3d3 Nf6h5 8. h2h3 Bg4e2 9. Qd3e2 Nh5f4 10. Qe2e1 Nc6d4 11. Bc4b3"<<endl;
	streamtest<<"Nf4h3+ 12. Kg1h2 Qd8h4 13. g2g3 Nd4f3+ 14. Kh2g2 Nf3e1+ 15. Rf1e1 Qh4g4 16."<<endl;
	streamtest<<"d2d3 Bc5f2 17. Re1h1 Qg4g3+ 18. Kg2f1 Bf2d4 19. Kf1e2 Qg3g2+ 20. Ke2d1"<<endl;
	streamtest<<"Qg2h1+ 21. Kd1d2 Qh1g2+ 22. Kd2e1 Nh3g1 23. Nb1c3 Bd4c3+ 24. b2c3 Qg2e2#"<<endl;

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
	streamtest<<"1. e2e4 e7e5 2. Qd1f3 Nb8c6 3. Bf1c4 Ng8f6 4. Ng1e2 Bf8c5 5. a2a3 d7d6 6. 0-0 Bc8g4 "<<endl;
	streamtest<<"7. Qf3d3 Nf6h5 8. h2h3 Bg4e2 9. Qd3e2 Nh5f4 10. Qe2e1 Nc6d4 11. Bc4b3"<<endl;
	streamtest<<"Nf4h3+ 12. Kg1h2 Qd8h4 13. g2g3 Nd4f3+ 14. Kh2g2 Nf3e1+ 15. Rf1e1 Qh4g4 16."<<endl;
	streamtest<<"d2d3 Bc5f2 17. Re1h1 Qg4g3+ 18. Kg2f1 Bf2d4 19. Kf1e2 Qg3g2+ 20. Ke2d1"<<endl;
	streamtest<<"Qg2h1+ 21. Kd1d2 Qh1g2+ 22. Kd2e1 Nh3g1 23. Nb1c3 Bd4c3+ 24. b2c3 Qg2e2#"<<endl;

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
	streamtest<<"1. e2e4 e7e5 2. Qd1f3 Nb8c6 3. Bf1c4 Ng8f6 4. Ng1e2 Bf8c5 5. a2a3 d7d6 6. 0-0 Bc8g4 "<<endl;
	streamtest<<"7. Qf3d3 Nf6h5 8. h2h3 Bg4e2 9. Qd3e2 Nh5f4 10. Qe2e1 Nc6d4 11. Bc4b3"<<endl;
	streamtest<<"Nf4h3+ 12. Kg1h2 Qd8h4 13. g2g3 Nd4f3+ 14. Kh2g2 Nf3e1+ 15. Rf1e1 Qh4g4 16."<<endl;
	streamtest<<"d2d3 Bc5f2 17. Re1h1 Qg4g3+ 18. Kg2f1 Bf2d4 19. Kf1e2 Qg3g2+ 20. Ke2d1"<<endl;
	streamtest<<"Qg2h1+ 21. Kd1d2 Qh1g2+ 22. Kd2e1 Nh3g1 23. Nb1c3 Bd4c3+ 24. b2c3 Qg2e2#"<<endl;

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
	streamtest<<"1. e2e4 e7e5 2. Qd1f3 Nb8c6 3. Bf1c4 Ng8f6 4. Ng1e2 Bf8c5 5. a2a3 d7d6 6. 0-0 Bc8g4 "<<endl;
	streamtest<<"7. Qf3d3 Nf6h5 8. h2h3 Bg4e2 9. Qd3e2 Nh5f4 10. Qe2e1 Nc6d4 11. Bc4b3"<<endl;
	streamtest<<"Nf4h3+ 12. Kg1h2 Qd8h4 13. g2g3 Nd4f3+ 14. Kh2g2 Nf3e1+ 15. Rf1e1 Qh4g4 16."<<endl;
	streamtest<<"d2d3 Bc5f2 17. Re1h1 Qg4g3+ 18. Kg2f1 Bf2d4 19. Kf1e2 Qg3g2+ 20. Ke2d1"<<endl;
	streamtest<<"Qg2h1+ 21. Kd1d2 Qh1g2+ 22. Kd2e1 Nh3g1 23. Nb1c3 Bd4c3+ 24. b2c3 Qg2e2#"<<endl;

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
	streamtest<<"1. e2e4 e7e5 2. Qd1f3 Nb8c6 3. Bf1c4 Ng8f6 4. Ng1e2 Bf8c5 5. a2a3 d7d6 6. 0-0 Bc8g4 "<<endl;
	streamtest<<"7. Qf3d3 Nf6h5 8. h2h3 Bg4e2 9. Qd3e2 Nh5f4 10. Qe2e1 Nc6d4 11. Bc4b3"<<endl;
	streamtest<<"Nf4h3+ 12. Kg1h2 Qd8h4 13. g2g3 Nd4f3+ 14. Kh2g2 Nf3e1+ 15. Rf1e1 Qh4g4 16."<<endl;
	streamtest<<"d2d3 Bc5f2 17. Re1h1 Qg4g3+ 18. Kg2f1 Bf2d4 19. Kf1e2 Qg3g2+ 20. Ke2d1"<<endl;
	streamtest<<"Qg2h1+ 21. Kd1d2 Qh1g2+ 22. Kd2e1 Nh3g1 23. Nb1c3 Bd4c3+ 24. b2c3 Qg2e2#"<<endl;

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
	streamtest<<"1. e2e4 e7e5 2. Qd1f3 Nb8c6 3. Bf1c4 Ng8f6 4. Ng1e2 Bf8c5 5. a2a3 d7d6 6. 0-0 Bc8g4 "<<endl;


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



