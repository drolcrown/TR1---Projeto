#include "camada_enlace.hpp"

void CamadaElaceTransmissora::transmitir(const Quadro& quadro) {
  this->camada_fisica.transmitir(quadro);
}

void CamadaEnlaceReceptora::receber(const Quadro&) {
  this->camada_aplicacao.receber(quadro);
}