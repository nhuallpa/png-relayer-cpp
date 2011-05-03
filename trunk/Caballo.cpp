/*
 * Caballo.cpp
 *
 *  Created on: 21/04/2011
 *      Author: Nestor Huallpa
 */

#include "Caballo.h"
#include "TableroAjedrez.h"

int despFila[8] = { 2, 1, -1, -2 , -2, -1,  1,  2};
int despColu[8] = { 1, 2,  2,  1 , -1, -2, -2, -1};

ListaPCoordenadas* Caballo::coordDestinoDesde(const Coordenada& coord) {

	ListaPCoordenadas* lCoordenadas = NULL;

	if (coord.validaEnAjedrez()){
		lCoordenadas = new ListaPCoordenadas();
		for (int i = 0; i < 8; i++) {
			Coordenada coordAux(coord.getFila() + despFila[i],
								  coord.getColumna() + despColu[i]);
			if (coordAux.validaEnAjedrez()) {
				lCoordenadas->agregar(new Coordenada(coordAux));
			}
		}
	}
	return lCoordenadas;
}


ListaPCoordenadas* Caballo::
filtrarCoordValidas(const Coordenada& coordenada, TableroAjedrez* unTablero) {

	ListaPCoordenadas* coordenasDestinoTemporal = NULL,
					 * coordenasResultantes = NULL;
	coordenasDestinoTemporal = this->coordDestinoDesde(coordenada);     //todo: test
	coordenasResultantes = validarCoordenadasDestino(coordenasDestinoTemporal,  //todo: test
													 unTablero);

	if (coordenasDestinoTemporal){
		ListaPCoordenadas::IteratorList it = coordenasDestinoTemporal->getIterator();
		while (it.hasNext()) {
			delete it.next();
		}
		delete coordenasDestinoTemporal;
	}
	return coordenasResultantes;
}

ListaPCoordenadas* Caballo::
validarCoordenadasDestino(ListaPCoordenadas* coordenasDestino,
						  	  TableroAjedrez* unTablero) {
	ListaPCoordenadas* coordResultantes = NULL;
	if (coordenasDestino){
		ListaPCoordenadas::IteratorList it = coordenasDestino->getIterator();
		coordResultantes = new ListaPCoordenadas();
		while (it.hasNext()) {
			Coordenada* coord = it.next();
			if (estaHabilitada(coord, unTablero)) {
				coordResultantes->agregar(new Coordenada(coord->getFila(), coord->getColumna()));
			}
		}
	}
	return coordResultantes;
}

