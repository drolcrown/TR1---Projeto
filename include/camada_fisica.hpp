#pragma once

class CamadaFisicaTransmissora : public ICamadaFisicaTransmissora {
	void transmitir(const Quadro&);

};

class CamadaFisicaReceptora : public ICamadaFisicaReceptora {
	void receber(const FluxoDeBits&);

};