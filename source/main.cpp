#include "sistema_comunicacao.hpp"


int main() {
  ICodificadorDeBits* codificador = 
    // new CodificadorBinario
    new CodificadorManchester
    // new CodificadorManchesterDiferencial
  ;
  IControladorDeErro* controlador_de_erro = 
    new ControladorCRC;
    // new ControladorBitParidadePar
    // new ControladorBitParidadeImpar
    //  new ControladorCodigoDeHamming
  ;
  int taxa_de_erros = 0; // Porcentagem de erros no meio físico.
  SistemaDeComunicacao sistema_de_comunicacao(codificador, controlador_de_erro, taxa_de_erros);
  sistema_de_comunicacao.run();
  delete codificador;
  delete controlador_de_erro;
  return 0;
}

