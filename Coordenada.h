/*
 * Coordenada.h
 *
 *  Created on: 21/04/2011
 *      Author: administrador
 */

#ifndef __COORDENADA_H_
#define __COORDENADA_H_

class Coordenada {

private:
	int fila;
	char columna;

public:
	Coordenada();
	Coordenada(int fila, char columna);
	virtual ~Coordenada();
    char getColumna() const;
    int getFila() const;
    void setColumna(char columna);
    void setFila(int fila);
};

#endif /* COORDENADA_H_ */
