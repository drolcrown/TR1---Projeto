#include "camada_enlace.hpp"

void CamadaEnlaceTransmissora::transmitir(const Quadro& quadro) {
  this->camada_fisica->transmitir(quadro);
}

void CamadaEnlaceReceptora::receber(const Quadro& quadro) {
  this->camada_aplicacao->receber(quadro);
}