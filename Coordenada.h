/*
 * Coordenada.h
 *
 *  Created on: 21/04/2011
 *      Author: administrador
 */

#ifndef __COORDENADA_H_
#define __COORDENADA_H_
#include "Lista.h"
#include <string>

class Coordenada {

private:
	int fila;
	char columna;

public:
	Coordenada();
	Coordenada(const Coordenada & coordena);
	Coordenada(const Coordenada* coordena);
	void operator=(const Coordenada & coordena);
	bool operator==(const Coordenada & coordena);
	bool esIgual(const Coordenada & coordena);
	Coordenada(int fila, char columna);
	virtual ~Coordenada();
    char getColumna() const;
    int getFila() const;
    void setColumna(char columna);
    void setFila(int fila);
    std::string toString();
    bool validaEnAjedrez() const;
};
typedef Lista<Coordenada*> ListaPCoordenadas;


#endif /* COORDENADA_H_ */
