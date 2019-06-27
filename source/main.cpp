/** @file main.cpp
 * @authors
 *   Luigi Minardi Ferreira Maia 17/0017141
 *   Maria Emília de Castro Oliveira Peres 17/0018199
 *   Jefferson Augusto Nunes Damasceno 16/0126509
 *   Ivan Bastos Lancellotti 16/0009057
 *   Rafael Oliveira de Souza. 15/0081537 
 * @date 2019-06-26 */

#include "sistema_comunicacao.hpp"


int main() {
  ICodificadorDeBits* codificador = 
    new CodificadorBinario
    // new CodificadorManchester
    // new CodificadorManchesterDiferencial
  ;
  IControladorDeErro* controlador_de_erro = 
    new ControladorBitParidadePar
    // new ControladorBitParidadeImpar
    // new ControladorCodigoDeHamming
    // new ControladorCRC
  ;
  int taxa_de_erros = 0; // Porcentagem de erros no meio fÃ­sico.
  SistemaDeComunicacao sistema_de_comunicacao(codificador, controlador_de_erro, taxa_de_erros);
  sistema_de_comunicacao.run();
  delete codificador;
  delete controlador_de_erro;
  return 0;
}

