#include "meio_fisico.hpp"
#include "interfaces_comunicacao.hpp"

double MeioFisico::taxaDeErro(double taxa) { 
    std::cout << taxa << std::endl;
    return taxa;
}

void MeioFisico::configCamadaFisicaReceptora(ICamadaFisicaReceptora* camadaReceptora){
    this->camada_fisica_receptora = camadaReceptora;
    std::cout << "Receptor Configurado" << std::endl;
}

void MeioFisico::transmitir(const FluxoDeBits& fluxoDeBits){
    this->camada_fisica_receptora->receber(fluxoDeBits);
    std::cout << "Fluxo Transmitido" << std::endl;
}