#include "codificador_de_bits.hpp"

FluxoDeBits CodificadorManchesterDiferencial::codificar(const Quadro& quadro) {
  int tamanho_quadro = quadro.size();
  int tamanho_fluxo = 2 * tamanho_quadro;
  FluxoDeBits fluxo_de_bits;
  fluxo_de_bits.reserve(tamanho_fluxo);
  Bit ultimo_bit = 1;
  for (auto i = 0; i < tamanho_quadro; ++i) {
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