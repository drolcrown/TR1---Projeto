#include "sistema_comunicacao.hpp"

int main() {
    //Instanciar o codificador
    CodificadorBinario codificador;

    SistemaDeComunicacao sistema_de_comunicacao;
    // sistema_de_comunicacao.config(codificador);
    //  void config(ICodificadorDeBits *codificador); 
    sistema_de_comunicacao.run();
    return 0;
}