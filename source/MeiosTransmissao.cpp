#include "meio_fisico.hpp"
#include "interfaces_comunicacao.hpp"

double MeioFisico::taxaDeErro(double taxa) { 
    std::cout << taxa << std::endl;
    return taxa;
}

void MeioFisico::configCamadaFisicaReceptora(ICamadaFisicaReceptora* camadaReceptora){
    std::cout << "Camada Fisica Receptora Configurada" << std::endl;
    this->camada_fisica_receptora = camadaReceptora;
}

void MeioFisico::transmitir(const FluxoDeBits& fluxoDeBits){
    this->camada_fisica_receptora->receber(fluxoDeBits);
}