/*
 * PgnFile.h
 *
 *  Created on: 10/04/2011
 *      Author: Nestor Huallpa
 */

#ifndef __PGNAJEDREZ_H_
#define __PGNAJEDREZ_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include "commonType.h"

#define PNG_CANT_FILA 8

class PgnAjedrez {

private:
	std::string tableroInicial;
	std::stringstream movidas;

public:
	PgnAjedrez();
	tEstado cargarPng(char* rutaPng);
	tEstado cargarPng(std::istream &inStream);
	std::string dameFila(int nroFila);
	char getSimboloSiguienteJugador();
	std::stringstream& getMovidas();
	std::string getTableroInicial();


};

#endif /* PNGFILE_H_ */
