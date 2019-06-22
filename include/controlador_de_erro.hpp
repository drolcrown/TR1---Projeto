#pragma once

#include "dominios.hpp"

class IControladorDeErro {
 public:
  virtual Quadro adicionarControle(const Quadro&) = 0;
  virtual Quadro controlarErros(const Quadro&) = 0;
};

class ControladorBitParidadePar : IControladorDeErro {
 public:
  Quadro adicionarControle(const Quadro&) override;
  Quadro controlarErros(const Quadro&) override;
};

class ControladorBitParidadeImpar : IControladorDeErro {
 public:
  Quadro adicionarControle(const Quadro&) override;
  Quadro controlarErros(const Quadro&) override;
};

class ControladorCRC : IControladorDeErro {
 public:
  Quadro adicionarControle(const Quadro&) override;
  Quadro controlarErros(const Quadro&) override;
};

class ControladorCodigoDeHamming : IControladorDeErro {
 public:
  Quadro adicionarControle(const Quadro&) override;
  Quadro controlarErros(const Quadro&) override;
};