#include "controlador_de_erro.hpp"

Quadro ControladorBitParidadePar::adicionarControle(const Quadro& quadro) {
    Quadro quadro_controlado = quadro;
    quadro_controlado.push_back(this->bitParidadePar(quadro));
    return quadro_controlado;
}

Quadro ControladorBitParidadePar::controlarErros(const Quadro& quadro_recebido) {
    Bit bit_paridade_recebido = quadro_recebido[quadro_recebido.size() - 1];
    Quadro quadro_sem_bit_paridade = quadro_recebido;
    quadro_sem_bit_paridade.pop_back(); // Tirar bit paridade;
    Bit bit_paridade_teorico = this->bitParidadePar(quadro_sem_bit_paridade);
    if (bit_paridade_teorico != bit_paridade_recebido) {
        std::cout << "Quadro com erro!" << '\n';
    }
    return quadro_sem_bit_paridade;
}

Bit ControladorBitParidadePar::bitParidadePar(const Quadro& quadro) {
    Bit bit_paridade = 0;
    for (int i = 0; i < quadro.size(); ++i) {
	 	bit_paridade = bit_paridade xor quadro[i];
	}
    return bit_paridade;
}