/*
 * Ajedrez.h
 *
 *  Created on: 15/04/2011
 *      Author: Nestor Huallpa
 */

#ifndef __AJEDREZ_H_
#define __AJEDREZ_H_
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

	/*
	 *Dimensiones
	 */
	int getCantColumnas() const {return cantColumnas;}
	int getCantFilas() const {return cantFilas;}
	void setCantColumnas(int cantColumnas) {this->cantColumnas = cantColumnas;}
	void setCantFilas(int cantFilas) {this->cantFilas = cantFilas;}


	bool hayPiezaJugadora(const Coordenada &coord);
	/*
	 * Tomo un punto a Pieza jugadora y lo ubica en el tablero en base a la
	 * coordenada pasa por parametro
	 * */
	void posionar(PiezaJugadora* piezaJugadora, const Coordenada &coord);

};

#endif /* AJEDREZ_H_ */
