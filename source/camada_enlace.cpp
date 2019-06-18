#include "camada_enlace.hpp"

void CamadaEnlaceTransmissora::transmitir(const Quadro& quadro) {
  std::cout 
    << esc::color::foreground::BRIGHT_GREEN // green text escape code
    << "Camada Enlace transmitiu: " << quadro << '\n'
    << esc::RESET // reset escape code
  ;
  this->camada_fisica->transmitir(quadro);
}

void CamadaEnlaceReceptora::receber(const Quadro& quadro) {
  std::cout 
    << esc::color::foreground::BRIGHT_GREEN // green text escape code
    << "Camada Enlace recebeu: " << quadro << '\n'
    << esc::RESET // reset escape code
  ;
  this->camada_aplicacao->receber(quadro);
}