#include "sistema_comunicacao.hpp"


int main() {
  ICodificadorDeBits* codificador = new CodificadorBinario;
  double taxa_de_erros = 0.1;
  SistemaDeComunicacao sistema_de_comunicacao(codificador, taxa_de_erros);
  sistema_de_comunicacao.run();
}

