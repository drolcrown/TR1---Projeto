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

// SistemaDeComunicacao ///////////////////////////////////////////////////////

SistemaDeComunicacao::SistemaDeComunicacao() {
  this->meio_fisico.taxaDeErro(0); //Definir Taxa de erro
  this->transmissor.configMeioFisico(&this->meio_fisico);
  this->transmissor.configCodificadorDeBits(&this->codificador);
  this->receptor.configCodificadorDeBits(&this->codificador);
  this->receptor.configMeioFisico(&this->meio_fisico);
}

//Instanciar o codificador e a porcentagem de erros no meio fisico
SistemaDeComunicacao::SistemaDeComunicacao(ICodificadorDeBits& codificador, const double& taxa) {
  this->meio_fisico.taxaDeErro(taxa); //Definir Taxa de erro
  this->transmissor.configMeioFisico(&this->meio_fisico);
  this->transmissor.configCodificadorDeBits(&codificador);
  this->receptor.configCodificadorDeBits(&codificador);
  this->receptor.configMeioFisico(&this->meio_fisico);
}

//Instanciar o codificador e o tipo de meio fisico
SistemaDeComunicacao::SistemaDeComunicacao(ICodificadorDeBits& codificador, MeioFisico& meio) {
  this->transmissor.configMeioFisico(&meio);
  this->transmissor.configCodificadorDeBits(&codificador);
  this->receptor.configCodificadorDeBits(&codificador);
  this->receptor.configMeioFisico(&meio);
}


void SistemaDeComunicacao::run() {
  this->transmissor.run();
}