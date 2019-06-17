#pragma once

#include "dominios.hpp"

class ICodificadorDeBits {
 public:
  virtual FluxoDeBits codificar(const Quadro&) = 0;
  virtual Quadro decodificar(const FluxoDeBits&) = 0;
};

class CodificadorManchesterDiferencial : ICodificadorDeBits {
 public:
  FluxoDeBits codificar(const Quadro&) override;
  Quadro decodificar(const FluxoDeBits&) override;
};