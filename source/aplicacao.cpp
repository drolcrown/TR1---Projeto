#include "aplicacao.hpp"

using namespace std;

void AplicacaoTransmissora::run(){
    Mensagem msg = this->criarMensagem();
    this->camada_aplicacao->transmitir(msg);
}

void AplicacaoTransmissora::configCamadaAplicacaoTransmissora(ICamadaAplicacaoTransmissora* appTransmissora){
    this->camada_aplicacao = appTransmissora;
}

Mensagem  AplicacaoTransmissora::criarMensagem(){
    Mensagem msg;
    cout << "Digite sua mensagem: " << endl;
    getline(cin, msg);

    return msg;
}

void AplicacaoReceptora::receber(const Mensagem& msg){
    //recebe mensagem e trata.
    cin << msg << endl;
}