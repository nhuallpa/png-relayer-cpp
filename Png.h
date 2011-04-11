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
using namespace std;

class Png {

private:
	string tableroInicial;
	stringstream movidas;

public:
	Png();
	tEstado cargarPng(char* rutaPng);
	tEstado cargarPng(istream &inStream);
    stringstream* getMovidas();
    string getTableroInicial();

};

#endif /* PNGFILE_H_ */
