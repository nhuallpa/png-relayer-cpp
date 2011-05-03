/*
 * TestAnalisisMovidas.cpp
 *
 *  Created on: 01/05/2011
 *      Author: Nestor Huallpa
 */

#include "TestAnalizador.h"
using namespace std;



void TestAnalizador::run()
{
	testCaballoSolo_d4();
	testAlfil();
	testTorre();
	testReina();
	testRey();
}



void TestAnalizador::testAlfil()
{
}



void TestAnalizador::testReina()
{
}



void TestAnalizador::testCaballoSolo_d4() {

	stringstream streamtest;
	streamtest<<"8/8/8/8/3N4/8/8/6N1 w"<<endl;
	streamtest<<endl;
	streamtest<<"23?. g1h3 d4e6"<<endl;

	PgnAjedrez entradaPng;
	entradaPng.cargarPng(streamtest);
	TableroAjedrez ajedrez;
	VistaReplayer vista;
	ControladorReplayer controlador(&ajedrez, &vista);
	controlador.reproducir(&entradaPng);
	//controlador.mostrarResultados();

}



void TestAnalizador::testTorre() {

}

void TestAnalizador::testRey() {
}


