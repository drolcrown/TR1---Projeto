#pragma once

#include "dominios.hpp"
#include "codificador_de_bits.hpp"
#include "meio_fisico.hpp"
#include "controlador_de_erro.hpp"

class AplicacaoReceptora; // Classe AplicacaoReceptora declarada no arquivo aplicacao.hpp
                          // por�m o arquivo inclui este.

class ICamadaAplicacaoReceptora {
 public:
  virtual void receber(const Quadro&) = 0;
  void configAplicacaoReceptora(AplicacaoReceptora*);
  virtual Mensagem convQuadroPorMensagem(const Quadro&) = 0;
 protected:
  AplicacaoReceptora* aplicacao = nullptr;
};

class ICamadaEnlaceReceptora {
 public:
  void virtual receber(const Quadro&) = 0;
  void configCamadaAplicacaoReceptora(ICamadaAplicacaoReceptora*);
  void configControladorDeErro(IControladorDeErro*);
 protected:
  ICamadaAplicacaoReceptora* camada_aplicacao = nullptr;
  IControladorDeErro* controlador_de_erro = nullptr;
};

class ICamadaFisicaReceptora {
 public:
  virtual void receber(const FluxoDeBits&) = 0;
  void configCamadaEnlaceReceptora(ICamadaEnlaceReceptora*);
  void configCodificador(ICodificadorDeBits*);
  void configMeioFisico(MeioFisico*);
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
  void configControladorDeErro(IControladorDeErro*);
 protected:
  ICamadaFisicaTransmissora* camada_fisica = nullptr;
  IControladorDeErro* controlador_de_erro = nullptr;
};

class ICamadaAplicacaoTransmissora {
 public:
  virtual void transmitir(const Mensagem&) = 0;
  void configCamadaEnlaceTransmissora(ICamadaEnlaceTransmissora*); 
  virtual Quadro convMensagemPorQuadro(const Mensagem&) = 0;
protected:
  ICamadaEnlaceTransmissora* camada_enlace = nullptr;
};
