#pragma once

#include "interfaces_comunicacao.hpp"
#include "dominios.hpp"

class CamadaFisicaTransmissora : public ICamadaFisicaTransmissora {
	void transmitir(const Quadro&) override;

};

class CamadaFisicaReceptora : public ICamadaFisicaReceptora {
	void receber(const FluxoDeBits&) override;

};