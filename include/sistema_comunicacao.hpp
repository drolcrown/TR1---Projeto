#pragma once

#include "aplicacao.hpp"
#include "camada_aplicacao.hpp"
#include "camada_enlace.hpp"
#include "meio_fisico.hpp"
#include "camada_fisica.hpp"
#include "codificador_de_bits.hpp"
#include "controlador_de_erro.hpp"

class Transmissor {
 public:
  Transmissor();
  void run();
  void configMeioFisico(MeioFisico*);
  void configCodificadorDeBits(ICodificadorDeBits*);
  void configControladorDeErro(IControladorDeErro*);
 private:
  AplicacaoTransmissora aplicacao;
  CamadaAplicacaoTransmissora camada_aplicacao;
  CamadaEnlaceTransmissora camada_enlace;
  CamadaFisicaTransmissora camada_fisica;
};

class Receptor {
 public:
  Receptor();
  void configCodificadorDeBits(ICodificadorDeBits*);
  void configMeioFisico(MeioFisico*);
  void configControladorDeErro(IControladorDeErro*);
 private:
  AplicacaoReceptora aplicacao;
  CamadaAplicacaoReceptora camada_aplicacao;
  CamadaEnlaceReceptora camada_enlace;
  CamadaFisicaReceptora camada_fisica;
};

class SistemaDeComunicacao {
 public:
   SistemaDeComunicacao(ICodificadorDeBits*,
                        IControladorDeErro*,
                        double taxa_de_erros);
   void run();
 private:
  Transmissor transmissor;
  Receptor receptor;
  MeioFisico meio_fisico;
};

