#include "interfaces_comunicacao.hpp"

void ICamadaAplicacaoReceptora::configAplicacaoReceptora(AplicacaoReceptora *aplicacao)
{
    this->aplicacao = aplicacao;
}

void ICamadaEnlaceReceptora::configCamadaAplicacaoReceptora(ICamadaAplicacaoReceptora *camada_aplicacao)
{
    this->camada_aplicacao = camada_aplicacao;
}

void ICamadaFisicaReceptora::configCamadaEnlaceReceptora(ICamadaEnlaceReceptora *camada_enlace)
{
    this->camada_enlace = camada_enlace;
}

void ICamadaFisicaTransmissora::configMeioFisico(MeioFisico *meio)
{
    this->meio_fisico = meio;
}

void ICamadaFisicaTransmissora::configCodificador(ICodificadorDeBits *codificador)
{
    this->codificador = codificador;
}

void ICamadaEnlaceTransmissora::configCamadaFisicaTransmissora(ICamadaFisicaTransmissora *camada_fisica)
{
    this->camada_fisica = camada_fisica;
}

void ICamadaAplicacaoTransmissora::configCamadaEnlaceTransmissora(ICamadaEnlaceTransmissora *camada_enlace)
{
    this->camada_enlace = camada_enlace;
}