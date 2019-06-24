#include "meio_fisico.hpp"
#include "interfaces_comunicacao.hpp"

RedeSemFio::RedeSemFio(){
    this->taxaDeErro(40);
}

FioTrancado::FioTrancado(){
    this->taxaDeErro(20);
}

FibraOtica::FibraOtica(){
    this->taxaDeErro(0);
}

void MeioFisico::taxaDeErro(double taxa) { 
    this->porcentagemDeErros = taxa;
}

void MeioFisico::configCamadaFisicaReceptora(ICamadaFisicaReceptora* camadaReceptora){
    this->camada_fisica_receptora = camadaReceptora;
}

void MeioFisico::transmitir(const FluxoDeBits& fluxoDeBits){
    FluxoDeBits fluxo;
    fluxo = this->meioDeComunicacao(fluxoDeBits);
    this->camada_fisica_receptora->receber(fluxo);
}

FluxoDeBits MeioFisico::meioDeComunicacao(const FluxoDeBits& fluxo){
    FluxoDeBits fluxoBitsTransmissor, fluxoBitsReceptor;
    fluxoBitsTransmissor.reserve(fluxo.size());
    fluxoBitsTransmissor = fluxo;
    double numAleatorio = 0;
    
    srand(time(NULL)); // Gerar numeros baseados no relogio do pc
    for (int i = 0 ; fluxoBitsReceptor.size() < fluxoBitsTransmissor.size(); ++i) {
        if ((rand()%100+1) == this->porcentagemDeErros ){ //verificar se o numero de 1 a 100 gerado está no valor da porcentagem de erro
            fluxoBitsReceptor.push_back(!fluxoBitsTransmissor[i]); // Inverte o Bit
            // std::cout << "Erro no Bit " << i << std::endl;
        }
        else{ 
            fluxoBitsReceptor.push_back(fluxoBitsTransmissor[i]);
        }
    }

    return fluxoBitsReceptor;
}