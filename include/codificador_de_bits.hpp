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

class CodificadorManchesterDiferencial : public ICodificadorDeBits { // Manchester Diferencial
 public:
  FluxoDeBits codificar(const Quadro&) override;
  Quadro decodificar(const FluxoDeBits&) override;
};

class CodificadorManchester: public ICodificadorDeBits { // Manchester
 public:
  FluxoDeBits codificar(const Quadro&) override;
  Quadro decodificar(const FluxoDeBits&) override;
};