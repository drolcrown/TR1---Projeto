#pragma once

#include "interfaces_comunicacao.hpp"

class CamadaEnlaceTransmissora : public ICamadaEnlaceTransmissora {
 public:
  void transmitir(const Quadro&) override;
};

class CamadaEnlaceReceptora : public ICamadaEnlaceReceptora {
 public:
  void receber(const Quadro&) override;
};