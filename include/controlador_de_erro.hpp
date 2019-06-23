#pragma once

#include "dominios.hpp"

class IControladorDeErro {
 public:
  virtual Quadro adicionarControle(const Quadro&) = 0;
  virtual Quadro controlarErros(const Quadro&) = 0;
};

class ControladorBitParidadePar : public IControladorDeErro {
 public:
  Quadro adicionarControle(const Quadro&) override {}
  Quadro controlarErros(const Quadro&) override {}
};

class ControladorBitParidadeImpar : public IControladorDeErro {
 public:
  Quadro adicionarControle(const Quadro&) override;
  Quadro controlarErros(const Quadro&) override;
};

class ControladorCRC : public IControladorDeErro {
 public:
  Quadro adicionarControle(const Quadro&) override;
  Quadro controlarErros(const Quadro&) override;
};

class ControladorCodigoDeHamming : public IControladorDeErro {
 public:
  Quadro adicionarControle(const Quadro&) override;
  Quadro controlarErros(const Quadro&) override;
};