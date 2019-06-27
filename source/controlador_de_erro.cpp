#include "controlador_de_erro.hpp"
#include <cmath>
#include "escape.hpp"

using namespace std;

Quadro ControladorCRC :: adicionarControle(const Quadro &quadro){

    Quadro crc;
    //Gera o polinomio IEEE32
    for(int i = 0; i <= 32; i++){
        if(i == 0|| i == 32 || i == 26 || i == 23 || i == 22 || i == 16 || i == 12 || i == 11 || i == 10 || i == 8 || i == 7 || i == 5 || i == 4 || i == 2 || i == 1 || i == 0){
            crc.push_back(1);
        }else{
            crc.push_back(0);
        }
    }

    Quadro quadro_completo = quadro; //Quadro que vai receber a sequencia de 0's

    //Preenche quadro_completo com zeros para completar as posicoes
    for(int i = 0; i < crc.size(); i++){
         quadro_completo.push_back(0);
    }


    vector<bool> CRC = quadro_completo;
    int tam_CRC = crc.size();


    //Adiciona as posicoes para o CRC
    for(int i = 1; i <= tam_CRC-1; i++){
        CRC.push_back(0);
    }

    //Calcula o CRC
    for(int i = 0; i <= CRC.size() - tam_CRC; ){
        for(int j = 0; j < tam_CRC; j++)
            CRC[i + j] = CRC[i+j] == crc[j]? 0:1; //XOR
        for(; i < CRC.size() && CRC[i] != 1; i++);//Condicao de iteracao de i
    }

    //Junta o quadro com o CRC
    for(int i = quadro_completo.size(); i < CRC.size(); i++){

        quadro_completo.push_back(CRC[i]);
    }

    return quadro_completo; 


}

Quadro ControladorCRC::controlarErros(const Quadro &quadro){

    Quadro crc;
    //Gera o polinomio IEEE32
    for(int i = 0; i <= 32; i++){
        if(i == 0|| i == 32 || i == 26 || i == 23 || i == 22 || i == 16 || i == 12 || i == 11 || i == 10 || i == 8 || i == 7 || i == 5 || i == 4 || i == 2 || i == 1 || i == 0){
            crc.push_back(1);
        }else{
            crc.push_back(0);
        }
    }

    Quadro quadro_recebido = quadro;
    Quadro quadro_transmitido = quadro; 

    int tam_CRC = crc.size();

    //Realiza a operacao de divisao
    for(int i = 0; i <= quadro_recebido.size() - tam_CRC; ){
        for(int j = 0; j < tam_CRC; j++)
            quadro_recebido[i + j] = quadro_recebido[i+j] == crc[j]? 0:1; //XOR
        for(; i < quadro_recebido.size() && quadro_recebido[i] != 1; i++);//Condicao de iteracao do i
    }

    for(int i = 0; i < quadro_recebido.size(); i++){

        if(quadro_recebido[i] == 0){
            continue;
        }else{
            std::cout
                << esc::color::foreground::BRIGHT_YELLOW
                << "Quadro com erro!" << '\n'
                << esc::RESET
            ;
            for(int i = quadro_recebido.size(); i >= quadro_recebido.size()-tam_CRC; i--){
                quadro_transmitido.pop_back();
            }
            return quadro_transmitido;
        }
    }

    for(int i = quadro_recebido.size();i >= quadro_recebido.size()-tam_CRC ; i--){

        quadro_transmitido.pop_back();

    }

    return quadro_transmitido;

}

// ControladorBitParidadePar //////////////////////////////////////////////////
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
        std::cout
            << esc::color::foreground::BRIGHT_YELLOW
            << "Quadro com erro!" << '\n'
            << esc::RESET
        ;
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

// ControladorBitParidadeImpar ////////////////////////////////////////////////

Quadro ControladorBitParidadeImpar::adicionarControle(const Quadro& quadro) {
    Quadro quadro_controlado = quadro;
    quadro_controlado.push_back(this->bitParidadeImpar(quadro));
    return quadro_controlado;
}

Quadro ControladorBitParidadeImpar::controlarErros(const Quadro& quadro_recebido) {
    Bit bit_paridade_recebido = quadro_recebido[quadro_recebido.size() - 1];
    Quadro quadro_sem_bit_paridade = quadro_recebido;
    quadro_sem_bit_paridade.pop_back(); // Tirar bit paridade;
    Bit bit_paridade_teorico = this->bitParidadeImpar(quadro_sem_bit_paridade);
    if (bit_paridade_teorico != bit_paridade_recebido) {
        std::cout
            << esc::color::foreground::BRIGHT_YELLOW
            << "Quadro com erro!" << '\n'
            << esc::RESET
        ;
    }
    return quadro_sem_bit_paridade;
}

Bit ControladorBitParidadeImpar::bitParidadeImpar(const Quadro& quadro) {
    Bit bit_paridade = 1;
    for (int i = 0; i < quadro.size(); ++i) {
        bit_paridade = bit_paridade xor quadro[i];
    }
    return bit_paridade;
}

// ControladorCodigoHamming ///////////////////////////////////////////////////

Quadro ControladorCodigoDeHamming::adicionarControle(const Quadro& quadro) {
	Quadro quadro_controlado = quadro;
	quadro_controlado = this->moverBitsDados(quadro_controlado);
	quadro_controlado = this->adicionarBitsParidade(quadro_controlado);
	return quadro_controlado;
}

Quadro ControladorCodigoDeHamming::moverBitsDados(const Quadro& quadro) {
	Quadro movidos;
	int proxima_potencia2 = 1; // Quarda a próxima potência de 2.
	int idx_quadro = 1; // Guarda o índice do primeiro termo de quadro ainda não passado para hamming.
	while (idx_quadro != quadro.size() + 1) {
		if (movidos.size() + 1 == proxima_potencia2) {
			movidos.push_back(0); // Coloca 0 onde deve ser um bit de paridade.
			proxima_potencia2 = proxima_potencia2 * 2;
		} else {
			movidos.push_back(quadro[idx_quadro - 1]);
			idx_quadro = idx_quadro + 1;
		}
	}
	return movidos;
}

Quadro ControladorCodigoDeHamming::adicionarBitsParidade(const Quadro& quadro) {
	Quadro hamming = quadro;
	for (int potencia2 = 1; potencia2 <= quadro.size(); potencia2 = potencia2 * 2) {
		hamming[potencia2 - 1] = this->bitParidade(potencia2, quadro);
	}
	return hamming;
}

Bit ControladorCodigoDeHamming::bitParidade(int potencia2, const Quadro &quadro) {
	Bit bit_paridade = 0;
	for (int idx = potencia2 + 1; idx <= quadro.size(); ++idx) {
		if ((potencia2 & idx) != 0) { // and bit a bit
			bit_paridade = bit_paridade xor quadro[idx - 1];
		}
	}
	return bit_paridade;
}

Quadro ControladorCodigoDeHamming::controlarErros(const Quadro& hamming_recebido) {
    Quadro quadro_recebido = this->removerBitsParidade(hamming_recebido);
    Quadro hamming_teorico = this->adicionarControle(quadro_recebido);
    std::vector<int> paridades_divergentes = this->indicesDosBitsParidadeDiferentes(hamming_recebido, hamming_teorico);
    if (paridades_divergentes.size() > 0) {
        std::cout
            << esc::color::foreground::BRIGHT_YELLOW
            << "Quadro com erro!" << '\n'
            << esc::RESET
        ;
        return this->corrigirQuadro(quadro_recebido, paridades_divergentes);
    }
    return quadro_recebido;
}

Quadro ControladorCodigoDeHamming::removerBitsParidade(const Quadro& quadro) {
    Quadro sem_bits_paridade;
    int proxima_potencia2 = 1;
    for (int idx = 1; idx <= quadro.size(); ++idx) {
        if (idx == proxima_potencia2) {
            proxima_potencia2 = proxima_potencia2 * 2;
        } else {
            sem_bits_paridade.push_back(quadro[idx - 1]);
        }
    }
    return sem_bits_paridade;
}

std::vector<int> ControladorCodigoDeHamming::indicesDosBitsParidadeDiferentes(const Quadro& a, const Quadro& b) {
    std::vector<int> indices;
    for (int proxima_potencia2 = 1; proxima_potencia2 < a.size() - 1; proxima_potencia2 = proxima_potencia2 * 2) {
        if (a[proxima_potencia2 - 1] != b[proxima_potencia2 - 1]) {
            indices.push_back(proxima_potencia2);
        }
    }
    return indices;
}

Quadro ControladorCodigoDeHamming::corrigirQuadro(const Quadro& quadro, const std::vector<int>& paridades_divergentes) {
    int bit_errado = 0; // bit_errado = sum paridades_divergentes;
    for (int i = 0; i < paridades_divergentes.size(); ++i) {
        bit_errado = bit_errado + paridades_divergentes[i];
    }
    Quadro corrigido = this->moverBitsDados(quadro);
    corrigido[bit_errado-1] = !corrigido[bit_errado-1];
    corrigido = this->removerBitsParidade(corrigido);
    return corrigido;
}