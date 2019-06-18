#pragma once

#include <sstream>

#include "aplicacao.hpp"
#include "interfaces_comunicacao.hpp"

    class CamadaAplicacaoTransmissora : public ICamadaAplicacaoTransmissora
{
public:
    void transmitir(const Mensagem &);

protected:
    Quadro convMensagemPorQuadro(const Mensagem &);

};

class CamadaAplicacaoReceptora : public ICamadaAplicacaoReceptora {
    public:
        void receber(const Quadro&);
    protected:
        Mensagem convQuadroPorMensagem(const Quadro&);
};