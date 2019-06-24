#include "aplicacao.hpp"

void AplicacaoTransmissora::run(){
    Mensagem msg = this->criarMensagem();
    this->camada_aplicacao->transmitir(msg);
}

void AplicacaoTransmissora::configCamadaAplicacaoTransmissora(ICamadaAplicacaoTransmissora* appTransmissora){
    this->camada_aplicacao = appTransmissora;
}

Mensagem  AplicacaoTransmissora::criarMensagem(){
    Mensagem msg;
    std::cout << std::endl << "Digite sua mensagem: ";
    std::getline(cin, msg);
    std::cout << std::endl;

    return msg;
}

void AplicacaoReceptora::receber(const Mensagem& msg){
    //recebe mensagem e trata.
    std::cout << std::endl << "Mensagem Enviada: " << msg << std::endl << std::endl;
}