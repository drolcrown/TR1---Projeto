#include "codificador_de_bits.hpp"

FluxoDeBits CodificadorManchesterDiferencial::codificar(const Quadro& quadro) {
  int tamanho_quadro = quadro.size();
  int tamanho_fluxo = 2 * tamanho_quadro;
  FluxoDeBits fluxo_de_bits;
  fluxo_de_bits.reserve(tamanho_fluxo);
  Bit ultimo_bit = 1;
  for (int i = 0; i < tamanho_quadro; ++i) {
    if (quadro[i] == 0) {
      fluxo_de_bits.push_back(!ultimo_bit);
      fluxo_de_bits.push_back(ultimo_bit);
    } else {
      fluxo_de_bits.push_back(ultimo_bit);
      fluxo_de_bits.push_back(!ultimo_bit);
      ultimo_bit = !ultimo_bit;
    }
  }
  return fluxo_de_bits;
}

Quadro CodificadorManchesterDiferencial::decodificar(const FluxoDeBits& fluxo_de_bits) {
  int tamanho_fluxo = fluxo_de_bits.size();
  int tamanho_quadro = tamanho_fluxo / 2;
  Quadro quadro;
  Bit ultimo_bit = 1;
  for (int i = 0 ; i < tamanho_quadro; ++i) {
    if (fluxo_de_bits[2*i] == !ultimo_bit && fluxo_de_bits[2*i+1] == ultimo_bit) {
      quadro.push_back(0);
    }
    else if (fluxo_de_bits[2*i] == ultimo_bit && fluxo_de_bits[2*i+1] == !ultimo_bit) {
      quadro.push_back(1);
      ultimo_bit = !ultimo_bit;
    }
    else {
      //error
    }
  }
  return quadro;
}

// CodificadorManchester //////////////////////////////////////////////////////

FluxoDeBits CodificadorManchester::codificar(const Quadro &quadro){ // codifica estilo Manchester

  // 0 = 01 e 1 = 10 ,vetor tem o dobro do tamanho

  int i;
  FluxoDeBits fluxo;
  fluxo.reserve(2 * quadro.size());

  for (i = 0; i < quadro.size(); ++i){

    if (quadro[i] == 0){
      fluxo.push_back(0);
      fluxo.push_back(1); //se é 0 manda 01
    }

    else if (quadro[i] == 1){
      fluxo.push_back(1);
      fluxo.push_back(0); //se é 1 manda 10
    }
  }
  
  return fluxo;
}

Quadro CodificadorManchester::decodificar(const FluxoDeBits& fluxo_de_bits) { // decodifica estilo Manchester

  // 01 = 0 e 10 = 1 ,vetor tem o metade do tamanho
  Quadro quadro;

  quadro.reserve(fluxo_de_bits.size() / 2 ); //quadro tem metade do tamanho de fluxo_de_bits

  for (int i = 0; i < fluxo_de_bits.size(); i++){

    if (fluxo_de_bits[i] == 0 && fluxo_de_bits[i+1] == 1){ // se for 01 manda 0
      quadro.push_back(0);
    }

    else if (fluxo_de_bits[i] == 1 && fluxo_de_bits[i+1] == 0){//se for 10 manda 1
      quadro.push_back(1);
    }

    else{
      // se deu erro manda nada, quadro não terá metade do tamanho de fluxo_de_bits
    }

    i++; //tem que ser incrementado duas vezes pois quadro tem metade do tamanho de fluxo_de_bits
  }

  return quadro;
}

// CodificadorBinario /////////////////////////////////////////////////////////

FluxoDeBits CodificadorBinario::codificar(const Quadro& quadro) { // codifica estilo NRZ
	// 0 = 0 e 1 = 1 na NRZ ou seja, nÃ£o precisa fazer nada
	FluxoDeBits fluxo; // vetor fluxo de bits
	fluxo.reserve(quadro.size()) ; //tamanho do vetor fluxo = tamanho do vetor quadro

	for (int i = 0; i < quadro.size(); ++i){ 
		fluxo.push_back(quadro[i]); // fluxo = quadro, bit a bit
	}

  return fluxo;
}

Quadro CodificadorBinario::decodificar(const FluxoDeBits& fluxo) { // codifica estilo NRZ
	// 0 = 0 e 1 = 1 na NRZ ou seja, nÃ£o precisa fazer nada
	Quadro quadro; // vetor fluxo de bits
	quadro.reserve(fluxo.size()) ; //tamanho do vetor fluxo = tamanho do vetor fluxo

	for (int i = 0; i < fluxo.size(); ++i){ 
		quadro.push_back(fluxo[i]); // fluxo = fluxo, bit a bit
	}

  return quadro;
}