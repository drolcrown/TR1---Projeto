#pragma once

#include <iostream>
#include "dominios.hpp"

using namespace std;

class ICodificadorDeBits {
 public:
  virtual FluxoDeBits codificar(const Quadro&) = 0;
  virtual Quadro decodificar(const FluxoDeBits) = 0;
};

  // std::vector<Bit> codificarComClock(vector<Bit> quadro, Bit bit, int frequencia);
// std::vector<Bit> ICodificadorDeBits::codificarComClock(std::vector<Bit> quadro, Bit bit, int frequencia){
//   Bit clock = false;
//   for(int i =0; i < frequencia; i++){
//     // switch (operador){
//     //   case '^':
//         quadro.push_back(bit ^ clock);
//         clock = !clock;
//         // break;
      
//       // default:
//       //   quadro.push_back(bit + clock);
//       //   clock = !clock; 
//       //   break;
//     // }
//   }
//   return quadro;
// } 


// Classes que implementam a interface ICodificadorDeBits
class CodificadorManchester: public ICodificadorDeBits {
   public:
      FluxoDeBits codificar(const Quadro& quadro){
         FluxoDeBits novoQuadro;
         for(int i = 0; i < quadro.size(); i++){
            cout << quadro[i] << endl;
            codificarComClock(novoQuadro, quadro[i], 2);
         }
         return novoQuadro;
      }

      Quadro decodificar(const FluxoDeBits& fluxo){
         Quadro qd;
          cout << "codificador Manchester decodificar "<< endl;
         return  qd;
         
      }
};