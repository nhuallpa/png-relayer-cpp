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



