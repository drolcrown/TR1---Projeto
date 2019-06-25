#include "sistema_comunicacao.hpp"


int main() {
  ICodificadorDeBits* codificador = new CodificadorManchester;
  IControladorDeErro* controlador_de_erro = new ControladorBitParidadePar;
  int taxa_de_erros = 25; // Porcentagem
  SistemaDeComunicacao sistema_de_comunicacao(codificador, controlador_de_erro, taxa_de_erros);
  sistema_de_comunicacao.run();
  delete codificador;
  delete controlador_de_erro;
  return 0;
}

