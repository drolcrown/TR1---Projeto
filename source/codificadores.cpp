#include <iostream>
#include "codificador_de_bits.hpp"
#include "GeradorDeQuadros.cpp"
 
using namespace std;

// Classes que implementam a interface ICodificadorDeBits
class CodificadorManchester: public ICodificadorDeBits {
   public:
      FluxoDeBits codificar(const Quadro& quadro){
         FluxoDeBits fl;
          cout << "In Derived \n";
         return fl;
         // cout << quadro << endl;
      }

      Quadro decodificar(const FluxoDeBits& fluxo){
         Quadro qd;
          cout << "In Derived \n";
         return  qd;
         
      }
};

// class CodificadorManchesterDiferencial: public ICodificadorDeBits {
//    public:
//       FluxoDeBits codificar(const Quadro& quadro){
//          // cout << quadro << endl;
//       }

//       Quadro decodificar(const FluxoDeBits& fluxo){
         
//       }
// };

// class CodificadorBinario: public ICodificadorDeBits {
//    public:
//       FluxoDeBits codificar(const Quadro&){
         
//       }
      
//       Quadro decodificar(const FluxoDeBits){
         
//       }
// };


 
int main(void) {
   FluxoDeBits f;
   GeradorDeQuadros gerador;
   ICodificadorDeBits* codManchester = new CodificadorManchester();
   codManchester->decodificar(f);
   // codManchester->codificar(gerador.gerarQuadro(32));

   return 0;
} 