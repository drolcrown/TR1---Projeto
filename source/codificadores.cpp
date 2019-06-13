#include <iostream>
#include "codificador_de_bits.hpp"
 
using namespace std;
 
// Classes que implementam a interface ICodificadorDeBits
class CodificadorManchester: public ICodificadorDeBits {
   public:
      FluxoDeBits codificar(const Quadro&){
         cout << Quadro << endl;
      }

      Quadro decodificar(const FluxoDeBits){
         
      }
};

class CodificadorManchesterDiferencial: public ICodificadorDeBits {
   public:
      FluxoDeBits codificar(const Quadro&){
         
      }
      
      Quadro decodificar(const FluxoDeBits){
         
      }
};

class CodificadorBinario: public ICodificadorDeBits {
   public:
      FluxoDeBits codificar(const Quadro&){
         
      }
      
      Quadro decodificar(const FluxoDeBits){
         
      }
};
 
int main(void) {
   GeradorDeQuadros gerador;
   CodificadorManchester codManchester;
   codManchester.codificar(gerador.gerarQuadro(32));

   return 0;
}