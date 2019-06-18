#pragma once // incluir o arquivo apenas uma vez

#include "dominios.hpp"

class ICamadaFisicaReceptora; // Classe declarada em interfaces_comunicacao.hpp

class MeioFisico{
 
 public:
  void configCamadaFisicaReceptora(ICamadaFisicaReceptora*);
  
  void transmitir(const FluxoDeBits&);

  double taxaDeErro(double taxa);

 public:
  ICamadaFisicaReceptora* camada_fisica_receptora = nullptr;
};