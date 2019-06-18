#include "codificador_de_bits.hpp"


FluxodeBits CodificadorBinario::codificar(const Quadro& quadro) {

	// 0 = 0 e 1 = 1 na NRZ ou seja, não precisa fazer nada

	FluxoDeBits fluxo; // vetor fluxo de bits
	fluxo.reserve(quadro.size()) ; //tamanho do vetor fluxo = tamanho do vetor quadro

	for (int i = 0; i < quadro.size(); ++i){ 
		fluxo[i] = quadro[i]; // fluxo = quadro, bit a bit

		cout << fluxo[i] <<" "; // imprime o fluxo, no caso de NRZ fluxo = quadro = mensagem
	}
	cout << "\n"; // não atrapalhar futuros printf's
}