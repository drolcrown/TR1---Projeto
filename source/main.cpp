#include "sistema_comunicacao.hpp"


int main() {
  ICodificadorDeBits* codificador = new CodificadorBinario;
  IControladorDeErro* controlador_de_erro = new ControladorBitParidadePar;
  double taxa_de_erros = 0.1;
  SistemaDeComunicacao sistema_de_comunicacao(codificador, controlador_de_erro, taxa_de_erros);
  sistema_de_comunicacao.run();
}

