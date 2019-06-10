#pragma once // incluir o arquivo apenas uma vez

#include "interfaces_comunicacao.hpp"

class MeioFisico {
 public:
  void configCamadaFisicaReceptora(ICamadaFisicaReceptora*);
  void transmitir(const FluxoDeBits&);
 private:
  ICamadaFisicaReceptora* camada_fisica_receptora = nullptr;
};