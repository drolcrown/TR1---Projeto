#include "controlador_de_erro.hpp"
#include <cmath>

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
        std::cout << "Quadro com erro!" << '\n';
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


//////////// Codificação de Hamming ///////////////////////////////////////////////////////////////////////////////////////
Quadro ControladorCodigoDeHamming::adicionarControle(const Quadro& quadro){
	
	int i,j,k,l,m, aux, tamanho, potencia;
	bool flag;

//////////////////////////// Número de Bits de controle ///////////////////////////////////////////////////////////////////

	i = 0; // auxiliar do loop
	tamanho = quadro.size(); //tamanho do quadro
	flag = 1; //interrupção do loop

	while(flag){

		if( ( pow(2,i) ) == tamanho || ( pow(2,i) ) > tamanho){ // descobre o número de bits de controle, maior ou igual a uma potência de 2
			flag = 0; //interrompe o loop
			potencia = i+1; //define o número de bits de controle
		}

		i++; //incrementa i para aumentar o número de bits de controle caso não seja suficiente
	}

///////////////////////////// Posição dos bits de de controle e de mensagem no quadro final //////////////////////////////////

	Quadro vetor_controle; // o tipo quadro é só porque é um vetor de booleanos
	Quadro final; //quadro com controle e mensagem

	aux = 0; j = 0;
	
	for(i=1; i < tamanho + potencia + 1; i++){ // valor dos bits de controle, vetor começa na "posição 1", por isso i = 1 e i < ... +1

		if( i == (pow(2,aux)) ){ // insere bit de contole

			final.push_back(0); // bit de controle, valor é irrelevante agora
			aux++; // prepara pro próximo bit de contole
		}

		else { // insere bit de mensagem
			final.push_back(quadro[j]); //insere bit de mensagem com valor correto
			j++; // prepara para o próximo bit de mensagem
		}
	}		

/////////////////////////////// Valor dos bits de controle e mensagem final ///////////////////////////////////////////////////
	
	tamanho = final.size(); // tamanho do quadro final a ser enviado

	j = 0; aux = 0;

	for(i = 1; i < tamanho + 1; i++) { // vou percorrer o vetor final para atualizar os valores de bits de controle 

		if( i == pow(2,j) ){ // descobre se é bit de controle

			j++;// pepara para pegar o próximo bit de controle
			l = i; // auxiliar para decidir quais bits devem ser considerados naquele bit de controle

			for(k = 1; k <= l; k++){ // coleto os bits relevantes para o bit de controle

/* trabalho como se fossem números inteiros e somo, os bits relevantes são o próprio bit de controle 
e os bits de mensagem à seguir, o valor inicial de todos os bits de controle é zero para permitir a soma */

				if(k == l){ // verifica se é inicio de uma sequência de bits relevantes
					for( m = k; m < k+i; m++ ){

						aux += final[k-1]; // vetores começam em zero, mas k começou em 1, -1 é pra corrigir a posição
						//pega as sequencias de bits relevantes
					}

					l += pow(2,i); //incrementa a condição de parada para o início da próxima sequência de bits relevantes

				}

				if(l > tamanho + 1)break; // acabou o quadro, para de procurar bits
			}
			aux = (aux%2); // aux é inteiro, isso pega o resto da divisão por 2 para decidir se é um bit 1 ou 0
			final[i-1] = aux; // atualiza o bit de controle, no início tinha valor zero
			aux = 0; // reinicia aux
		}	
	}
}

/////// Fim da codificação de Hamming ///////////////////////////////////////////////////////////////////////////////////////
