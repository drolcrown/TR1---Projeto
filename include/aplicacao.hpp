#pragma once

#include "interfaces_comunicacao.hpp"

class AplicacaoTransmissora {
 public:
  void run();
  void configCamadaAplicacaoTransmissora(ICamadaAplicacaoTransmissora*);
 private:
  Mensagem criarMensagem();
  ICamadaAplicacaoTransmissora* camada_aplicacao = nullptr;
};

class AplicacaoReceptora {
 public:
  void receber(const Mensagem&);
};