#include "camada_aplicacao.hpp"

void CamadaAplicacaoTransmissora :: transmitir(const Mensagem &mensagem){
    
    Quadro mensagem_bits = convMensagemPorQuadro(mensagem);

}

Quadro CamadaAplicacaoTransmissora:: convMensagemPorQuadro(const Mensagem &mensagem){
    
    string mensagem_string_binaria; //Armazena a string binária
    Mensagem mensagem_original =  mensagem;
    for(int i = 0; i < mensagem_original.length(); i++){    
        mensagem_string_binaria += bitset<8> (mensagem_original[i]).to_string();
    }

    Quadro mensagem_binaria = {};

    for(int i = 0; i < mensagem_string_binaria.length(); i++){
        if(mensagem_string_binaria[i] == '1'){
            mensagem_binaria.push_back(true);
        }if(mensagem_string_binaria[i] == '0'){
            mensagem_binaria.push_back(false);
        }
    }
    return (mensagem_binaria);
}

void CamadaAplicacaoReceptora :: receber(const Quadro &quadro){

    Mensagem mensagem_convertida = convQuadroPorMensagem(quadro);

}

Mensagem CamadaAplicacaoReceptora::convQuadroPorMensagem(const Quadro &quadro){
    
}