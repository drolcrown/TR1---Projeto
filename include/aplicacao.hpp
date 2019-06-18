#pragma once

#include <iostream>

#include "interfaces_comunicacao.hpp"

using namespace std;

class AplicacaoTransmissora {
 public:
  void run();
  void configCamadaAplicacaoTransmissora(ICamadaAplicacaoTransmissora *appTransmissora);
  Mensagem criarMensagem();
 private:
  ICamadaAplicacaoTransmissora* camada_aplicacao = nullptr;
};

class AplicacaoReceptora {
 public:
  void receber(const Mensagem &msg);
};