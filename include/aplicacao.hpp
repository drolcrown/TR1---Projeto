#pragma once

#include <iostream>
#include "interfaces_comunicacao.hpp"

using namespace std;

class AplicacaoTransmissora {
 public:
  void run();
  void configCamadaAplicacaoTransmissora(ICamadaAplicacaoTransmissora *appTransmissora);
  Mensagem criarMensagem();
};

class AplicacaoReceptora {
 public:
  void receber(const Mensagem &msg);
};