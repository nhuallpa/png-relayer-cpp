/*
 * PngFile.h
 *
 *  Created on: 10/04/2011
 *      Author: administrador
 */

#ifndef PNGFILE_H_
#define PNGFILE_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include "commonType.h"

#define PNG_CANT_FILA 8

class PngAjedrez {

private:
	std::string tableroInicial;
	std::stringstream movidas;

public:
	PngAjedrez();
	tEstado cargarPng(char* rutaPng);
	tEstado cargarPng(std::istream &inStream);
	std::string dameFila(int nroFila);

	std::stringstream* getMovidas();
	std::string getTableroInicial();


};

#endif /* PNGFILE_H_ */
