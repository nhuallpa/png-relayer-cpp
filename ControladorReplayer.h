/*
 * ControladorReplayer.h
 *
 *  Created on: 15/04/2011
 *      Author: administrador
 */

#ifndef _CONTROLADORREPLAYER_H_
#define _CONTROLADORREPLAYER_H_
#include "Ajedrez.h"
#include "PngAjedrez.h"
#include "string.h"


class ControladorReplayer {

private:
	Ajedrez* ajedrez;

public:
	ControladorReplayer(Ajedrez* ajedrez);
	void reproducir(PngAjedrez* entradaPng);
	virtual ~ControladorReplayer();
	void mostrarResultados();

private:
	void armarTableroInicial(PngAjedrez* entradaPng);
	void construirFila(std::string cadenaFilaActual, int nroFila);
	bool hayPosicionesVacias(char indicador);

};

#endif /* CONTROLADORREPLAYER_H_ */
