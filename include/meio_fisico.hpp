#pragma once // incluir o arquivo apenas uma vez

#include "dominios.hpp"

class ICamadaFisicaReceptora; // Classe declarada em interfaces_comunicacao.hpp

class MeioFisico{
 
 public:
  void configCamadaFisicaReceptora(ICamadaFisicaReceptora*);
  
  void transmitir(const FluxoDeBits&);

  void taxaDeErro(double taxa);

  FluxoDeBits meioDeComunicacao(const FluxoDeBits&);
  
 public:
  ICamadaFisicaReceptora* camada_fisica_receptora = nullptr;
  double porcentagemDeErros = 0;
};

class FioTrancado : public MeioFisico{
  public:
    FioTrancado();
};

class RedeSemFio : public MeioFisico{
  public:
    RedeSemFio();
};

class FibraOtica : public MeioFisico{
  public:
    FibraOtica();
};