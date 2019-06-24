#include "sistema_comunicacao.hpp"

// Transmissor ////////////////////////////////////////////////////////////////

Transmissor::Transmissor() {
  this->aplicacao.configCamadaAplicacaoTransmissora(&this->camada_aplicacao);
  this->camada_aplicacao.configCamadaEnlaceTransmissora(&this->camada_enlace);
  this->camada_enlace.configCamadaFisicaTransmissora(&this->camada_fisica);
}

void Transmissor::run() {
  this->aplicacao.run();
}

void Transmissor::configMeioFisico(MeioFisico* meio_fisico) {
  this->camada_fisica.configMeioFisico(meio_fisico);
}

void Transmissor::configCodificadorDeBits(ICodificadorDeBits* codificador) {
  this->camada_fisica.configCodificador(codificador);
}

void Transmissor::configControladorDeErro(IControladorDeErro* controlador_de_erro) {
  this->camada_enlace.configControladorDeErro(controlador_de_erro);
}

// Receptor ///////////////////////////////////////////////////////////////////

Receptor::Receptor() {
  this->camada_aplicacao.configAplicacaoReceptora(&this->aplicacao);
  this->camada_enlace.configCamadaAplicacaoReceptora(&this->camada_aplicacao);
  this->camada_fisica.configCamadaEnlaceReceptora(&this->camada_enlace);
}

void Receptor::configCodificadorDeBits(ICodificadorDeBits* codificador) {
  this->camada_fisica.configCodificador(codificador);
}

void Receptor::configMeioFisico(MeioFisico* meio_fisico) {
  this->camada_fisica.configMeioFisico(meio_fisico);
}

void Receptor::configControladorDeErro(IControladorDeErro* controlador_de_erro) {
  this->camada_enlace.configControladorDeErro(controlador_de_erro);
}

// SistemaDeComunicacao ///////////////////////////////////////////////////////

//Instanciar o codificador e a porcentagem de erros no meio fisico
SistemaDeComunicacao::SistemaDeComunicacao(ICodificadorDeBits* codificador,
                                           IControladorDeErro* controlador_de_erro,
                                           double taxa_de_erro) {
  this->meio_fisico.taxaDeErro(taxa_de_erro); //Definir Taxa de erro
  this->transmissor.configMeioFisico(&this->meio_fisico);
  this->transmissor.configCodificadorDeBits(codificador);
  this->transmissor.configControladorDeErro(controlador_de_erro);
  this->receptor.configCodificadorDeBits(codificador);
  this->receptor.configMeioFisico(&this->meio_fisico);
  this->receptor.configControladorDeErro(controlador_de_erro);
}


void SistemaDeComunicacao::run() {
  this->transmissor.run();
}