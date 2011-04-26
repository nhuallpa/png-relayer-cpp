/*
 * Ajedrez.h
 *
 *  Created on: 15/04/2011
 *      Author: administrador
 */

#ifndef AJEDREZ_H_
#define AJEDREZ_H_
#define AJ_CANT_FILAS 8
#define AJ_CANT_COLUMNAS 8
#include "Celda.h"
#include "PiezaJugadora.h"
#include "Coordenada.h"

class TableroAjedrez {

private:
	int cantFilas;
	int cantColumnas;
	Celda tablero[AJ_CANT_FILAS][AJ_CANT_COLUMNAS];

public:
	TableroAjedrez();
	bool hayFicha(int fila, int colum);
	virtual ~TableroAjedrez();
	int getCantColumnas() const {return cantColumnas;}
	int getCantFilas() const {return cantFilas;}
	void setCantColumnas(int cantColumnas) {this->cantColumnas = cantColumnas;}
	void setCantFilas(int cantFilas) {this->cantFilas = cantFilas;}
	void posionar(PiezaJugadora* piezaJugadora, const Coordenada &coord);

};

#endif /* AJEDREZ_H_ */
