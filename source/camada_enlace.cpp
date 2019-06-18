#include "camada_enlace.hpp"

void CamadaEnlaceTransmissora::transmitir(const Quadro& quadro) {
  std::cout << "Camada Enlace transmitiu: " << quadro << '\n';
  this->camada_fisica->transmitir(quadro);
}

void CamadaEnlaceReceptora::receber(const Quadro& quadro) {
  std::cout << "Camada Enlace recebeu: " << quadro << '\n';
  this->camada_aplicacao->receber(quadro);
}