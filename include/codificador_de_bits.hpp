#pragma once

#include "dominios.hpp"

class ICodificadorDeBits {
 public:
  virtual FluxoDeBits codificar(const Quadro&) = 0;
  virtual Quadro decodificar(const FluxoDeBits) = 0;
};