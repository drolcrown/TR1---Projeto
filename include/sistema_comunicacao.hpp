#pragma once

#include "aplicacao.hpp"
#include "camada_aplicacao.hpp"
#include "camada_enlace.hpp"
#include "meio_fisico.hpp"
#include "camada_fisica.hpp"
#include "codificador_de_bits.hpp"

class Transmissor {
 public:
  Transmissor();
  void run();
  void configMeioFisico(MeioFisico*);
  void configCodificadorDeBits(ICodificadorDeBits*);
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
 private:
  AplicacaoReceptora aplicacao;
  CamadaAplicacaoReceptora camada_aplicacao;
  CamadaEnlaceReceptora camada_enlace;
  CamadaFisicaReceptora camada_fisica;
};

class SistemaDeComunicacao {
 public:
  SistemaDeComunicacao();
  void run();
 private:
  // ICodificadorDeBits*  codificador; 
  CodificadorBinario codificador; // Altere essa linha para alterar o codificador.
  Transmissor transmissor;
  Receptor receptor;
  MeioFisico meio_fisico;
};

