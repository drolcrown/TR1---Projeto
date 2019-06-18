#include "camada_fisica.hpp"

void CamadaFisicaTransmissora::transmitir(const Quadro& quadro) {

	cout << "Imprimindo mesagem antes de codificar (isso e o que a camada fisica transmissora recebeu).\n"

	for (i = 0; i < quadro.size(); ++i){
    cout << quadro[i] << " "; //imprime a saída... supostamente
    }

    cout << "\n";

	FluxoDeBits fluxo = codificador->codificar(quadro); // ponteiro codificador aponta para o quadro
	//que será codificado da maneira que o usuário selecionou

	cout << "Imprimindo mesagem depois de codificar (isso sera transmitido pelo meio fisico).\n"

	for (i = 0; i < fluxo.size(); ++i){
    cout << fluxo[i] << " "; //imprime a saída... supostamente
    }

    cout << "\n";

	meio_fisico->transmitir(fluxo); //meio fisico manda o fluxo codificado
		
};

void CamadaFisicaReceptora::receber(const FluxoDeBits& fluxo) {

	cout << "Imprimindo mesagem codificada recebida (isso foi recebido do meio fisico).\n"

	for (i = 0; i < fluxo.size(); ++i){
    cout << fluxo[i] << " "; //imprime a saída... supostamente
    }

    cout << "\n";

	Quadro quadro = codificador->decodificar(fluxo); //camada fisica receptora decodifica fluxo de bits codificado

	cout << "Imprimindo mesagem depois de decodificar (isso e o que sera transmitido para a camada de enlace receptora).\n"

	for (i = 0; i < quadro.size(); ++i){
    cout << quadro[i] << " "; //imprime a saída... supostamente
    }

    cout << "\n";

	camada_enlace->receber(quadro);	//ponteiro camada_enlace aponta pro fluxo de bits
	//decodificado e transforma fluxo em um quadro

};