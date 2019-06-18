#pragma once

#include <iostream>
#include "dominios.hpp"


class ICodificadorDeBits { // NRZ, NRZI e Manchester
 public:
  virtual FluxoDeBits codificar(const Quadro&) = 0;
  virtual Quadro decodificar(const FluxoDeBits&) = 0;
};


class CodificadorBinario : public ICodificadorDeBits //NRZ
{
	public:
		FluxoDeBits codificar(const Quadro&) override;
		Quadro decodificar (const FluxoDeBits&) override;

};

/*
class CodificadorManchester: public ICodificadorDeBits {
   public:
      FluxoDeBits codificar(const Quadro& quadro){
         FluxoDeBits novoQuadro;
         for(int i = 0; i < quadro.size(); i++){
            std::cout << quadro[i] << std::endl;
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
*/

class CodificadorManchesterDiferencial : public ICodificadorDeBits { // Manchester Diferencial
 public:
  FluxoDeBits codificar(const Quadro&) override;
  Quadro decodificar(const FluxoDeBits&) override;
};