#include "camada_fisica.hpp"

void CamadaFisicaTransmissora::transmitir(const Quadro& quadro) {

	FluxoDeBits fluxo = codificador->codificar(quadro); // ponteiro codificador aponta para o quadro
	//que será codificado da maneira que o usuário selecionou

	std::cout
		<< esc::color::foreground::BRIGHT_RED  // Transformar texto para vermelho 
		<< "Camada Fisica transmitiu:    " << fluxo << '\n'
		<< esc::RESET; // Resetar para configura??es originais de texto.
	;
	meio_fisico->transmitir(fluxo); //meio fisico manda o fluxo codificado
		
};

void CamadaFisicaReceptora::receber(const FluxoDeBits& fluxo) {
    std::cout 
		<< esc::color::foreground::BRIGHT_RED // Transformar texto em vermelho.
		<< "Camada Fisica recebeu:       " << fluxo << '\n'
		<< esc::RESET // Voltar ?s configura??es originais de texto.
	;

	Quadro quadro = codificador->decodificar(fluxo); //camada fisica receptora decodifica fluxo de bits codificado

	camada_enlace->receber(quadro);	//ponteiro camada_enlace aponta pro fluxo de bits
	//decodificado e transforma fluxo em um quadro

};