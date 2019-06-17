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