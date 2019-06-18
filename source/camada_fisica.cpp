#include "camada_fisica.hpp"

void CamadaFisicaTransmissora::transmitir(const Quadro& quadro) {

	FluxoDeBits fluxo = codificador->codificar(quadro); // ponteiro codificador aponta para o quadro
	//que será codificado da maneira que o usuário selecionou
	meio_fisico->transmitir(fluxo); //meio fisico manda o fluxo codificado
		
};

void CamadaFisicaReceptora::receber(const FluxoDeBits& fluxo) {

	Quadro quadro = codificador->decodificar(fluxo); //camada fisica receptora decodifica fluxo de bits codificado
	camada_enlace->receber(quadro);				//ponteiro camada_enlace aponta pro fluxo de bits
	//decodificado e transforma fluxo em um quadro

};