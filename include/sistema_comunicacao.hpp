#pragma once

#include "aplicacao.hpp"
#include "camada_aplicacao.hpp"
#include "camada_enlace.hpp"
#include "meio_fisico.hpp"
#include "camada_fisica.hpp"
#include "codificador_de_bits.hpp"

class Transmissor {
 private:
  AplicacaoTransmissora aplicacao;
  CamadaAplicacaoTransmissora camada_aplicacao;
  CamadaEnlaceTransmissora camada_enlace;
  CamadaFisicaTransmissora camada_fisica;
  MeioFisico* meio_fisico = nullptr;
 public:
  void run();
  void configMeioFisico(MeioFisico*);
  void configCodificadorDeBits(ICodificadorDeBits*);
};

class Receptor {
 private:
  AplicacaoReceptora aplicacao;
  CamadaAplicacaoReceptora camada_aplicacao;
  CamadaEnlaceReceptora camada_enlace;
  CamadaFisicaReceptora camada_fisica;
 public:
  void configCodificadorDeBits(ICodificadorDeBits*);
};

class SistemaDeComunicacao {
 public:
  void run();
 private:
  Transmissor transmissor;
  Receptor receptor;
  MeioFisico meio_fisico;
};

