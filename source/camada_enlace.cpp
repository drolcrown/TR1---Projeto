#include "camada_enlace.hpp"

void CamadaEnlaceTransmissora::transmitir(const Quadro& quadro) {
  Quadro quadro_controlado = this->controlador_de_erro->adicionarControle(quadro);
  std::cout 
    << esc::color::foreground::BRIGHT_GREEN // green text escape code
    << "Camada Enlace transmitiu:    " << quadro_controlado << '\n'
    << esc::RESET // reset escape code
  ;
  this->camada_fisica->transmitir(quadro_controlado);
}

void CamadaEnlaceReceptora::receber(const Quadro& quadro_controlado) {
  std::cout 
    << esc::color::foreground::BRIGHT_GREEN // green text escape code
    << "Camada Enlace recebeu:       " << quadro_controlado << '\n'
    << esc::RESET // reset escape code
  ;
  Quadro quadro = this->controlador_de_erro->controlarErros(quadro_controlado);
  this->camada_aplicacao->receber(quadro);

}