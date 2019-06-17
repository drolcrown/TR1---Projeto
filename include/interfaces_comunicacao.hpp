#pragma once

#include "dominios.hpp"
#include "codificador_de_bits.hpp"
#include "meio_fisico.hpp"

class AplicacaoReceptora; // Classe AplicacaoReceptora declarada no arquivo aplicacao.hpp
                          // porém o arquivo inclui este.

class ICamadaAplicacaoReceptora {
 public:
  virtual void receber(const Quadro&) = 0;
  void configAplicacaoReceptora(AplicacaoReceptora*);
 protected:
  virtual Mensagem convQuadroPorMensagem(const Quadro&) = 0;
  AplicacaoReceptora* aplicacao = nullptr;
};

class ICamadaEnlaceReceptora {
 public:
  void virtual receber(const Quadro&) = 0;
  void configCamadaAplicacaoReceptora(ICamadaAplicacaoReceptora*);
 private:
  ICamadaAplicacaoReceptora* camada_aplicacao = nullptr;
};

class ICamadaFisicaReceptora {
 public:
  virtual void receber(const FluxoDeBits&) = 0;
  void configCamadaEnlaceReceptora(ICamadaEnlaceReceptora*);
  void configCodificador(ICodificadorDeBits*);
 protected:
  ICamadaEnlaceReceptora* camada_enlace = nullptr;
  ICodificadorDeBits* codificador = nullptr;
};

class ICamadaFisicaTransmissora {
 public:
  virtual void transmitir(const Quadro&) = 0;
  void configMeioFisico(MeioFisico*);
  void configCodificador(ICodificadorDeBits*); 
 protected:
  MeioFisico* meio_fisico = nullptr;
  ICodificadorDeBits* codificador = nullptr;
};

class ICamadaEnlaceTransmissora {
 public:
  virtual void transmitir(const Quadro&) = 0;
  void configCamadaFisicaTransmissora(ICamadaFisicaTransmissora*);
 protected:
  ICamadaFisicaTransmissora* camada_fisica = nullptr;
};

class ICamadaAplicacaoTransmissora {
 public:
  virtual void transmitir(const Mensagem&) = 0;
  void configCamadaEnlaceTransmissora(ICamadaEnlaceTransmissora*); 
 protected:
  virtual Quadro convMensagemPorQuadro(const Mensagem&) = 0;
  ICamadaEnlaceTransmissora* camada_enlace = nullptr;
};
