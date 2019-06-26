#include "controlador_de_erro.hpp"
#include <cmath>

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

    int diferenca_entre_quadros = crc.size() - quadro.size();

    if(diferenca_entre_quadros >= -8){
        //Preenche quadro_completo com zeros para completar as posicoes
        for(int i = 0; i < crc.size(); i++){
            quadro_completo.push_back(0);
        }
    }else{
        //Nao acontece nada 
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

    cout << "CRC calculado: ";
    for(int i = 0; i < CRC.size() - quadro_completo.size(); i++){
        cout << CRC[i+40];
    }

    cout << endl;

    //Junta o quadro com o CRC
    for(int i = quadro_completo.size(); i < CRC.size(); i++){

        quadro_completo.push_back(CRC[i]);
    }

    cout << endl;

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

    cout << endl;

    int tam_quadro_recebido = quadro.size();
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
            cout<<"Quadro com erro!";
            for(int i = quadro_recebido.size(); i >= 9; i--){
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

// ControladorCodigoHamming ///////////////////////////////////////////////////

Quadro ControladorCodigoDeHamming::adicionarControle(const Quadro& quadro) {
	Quadro quadro_controlado = quadro;
	quadro_controlado = this->shiftRight(quadro_controlado); // [0] ++ quadro_controlado
	quadro_controlado = this->moverBitsDados(quadro_controlado);
	quadro_controlado = this->adicionarBitsParidade(quadro_controlado);
	quadro_controlado = this->shiftLeft(quadro_controlado); // remover shiftRight
	return quadro_controlado;
}

Quadro ControladorCodigoDeHamming::shiftRight(const Quadro& quadro) {
	Quadro shifted;
	shifted.push_back(0);
	for (int i = 0; i < quadro.size(); ++i) {
		shifted.push_back(quadro[i]);
	}
	return shifted;
}

Quadro ControladorCodigoDeHamming::shiftLeft(const Quadro& quadro) {
	Quadro shifted;
	for (int i = 1; i < quadro.size(); ++i) {
		shifted.push_back(quadro[i]);
	}
	return shifted;
}

Quadro ControladorCodigoDeHamming::moverBitsDados(const Quadro& quadro) {
	Quadro movidos;
	int proxima_potencia2 = 1; // Quarda a próxima potência de 2;
	int idx_quadro = 0; // Guarda o índice do último bit de quadro adicionado a movidos.
	while (idx_quadro != quadro.size()) {
		if (movidos.size() == proxima_potencia2) {
			movidos.push_back(0);
			proxima_potencia2 = proxima_potencia2 * 2;
		} else {
			movidos.push_back(quadro[idx_quadro]);
			idx_quadro = idx_quadro + 1;
		}
	}
	return movidos;
}

Quadro ControladorCodigoDeHamming::adicionarBitsParidade(const Quadro& quadro) {
	Quadro hamming = quadro;
	for (int potencia2 = 1; potencia2 < quadro.size(); potencia2 = potencia2 * 2) {
		hamming[potencia2] = this->bitParidade(potencia2, quadro);
	}
	return hamming;
}

Bit ControladorCodigoDeHamming::bitParidade(int potencia2, const Quadro &quadro) {
	Bit bit_paridade = 0;
	for (int idx = potencia2 + 1; idx < quadro.size(); ++idx) {
		if ((potencia2 & idx) != 0) { // and bit a bit
			bit_paridade = bit_paridade xor quadro[idx];
		}
	}
	return bit_paridade;
}

Quadro ControladorCodigoDeHamming::controlarErros(const Quadro& hamming_recebido) {
    Quadro quadro_recebido = this->shiftLeft(this->removerBitsParidade(this->shiftRight(hamming_recebido)));
    Quadro hamming_teorico = this->adicionarControle(quadro_recebido);
    std::vector<int> paridades_divergentes = this->indicesDosBitsParidadeDiferentes(hamming_recebido, hamming_teorico);
    if (paridades_divergentes.size() > 0) {
        std::cout << "Quadro com erro!" << '\n';
        return this->corrigirQuadro(quadro_recebido, paridades_divergentes);
    }
    return quadro_recebido;
}

Quadro ControladorCodigoDeHamming::removerBitsParidade(const Quadro& quadro) {
    Quadro sem_bits_paridade;
    int proxima_potencia2 = 1;
    for (int idx = 0; idx < quadro.size(); ++idx) {
        if (idx == proxima_potencia2) {
            proxima_potencia2 = proxima_potencia2 * 2;
        } else {
            sem_bits_paridade.push_back(quadro[idx]);
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
    int bit_errado = 0;
    for (int i = 0; i < paridades_divergentes.size(); ++i) {
        bit_errado = bit_errado + paridades_divergentes[i];
    }
    Quadro corrigido = this->moverBitsDados(this->shiftRight(quadro));
    corrigido[bit_errado] = !corrigido[bit_errado];
    corrigido = this->removerBitsParidade(corrigido);
    corrigido = this->shiftLeft(corrigido);
    return corrigido;
}

    // //////////// Codificação de Hamming ///////////////////////////////////////////////////////////////////////////////////////
    // Quadro ControladorCodigoDeHamming::adicionarControle(const Quadro& quadro){

    // 	int i,j,k,l,m, aux, tamanho, potencia;
    // 	bool flag;

    // //////////////////////////// Número de Bits de controle ///////////////////////////////////////////////////////////////////

    // 	i = 0; // auxiliar do loop
    // 	tamanho = quadro.size(); //tamanho do quadro
    // 	flag = 1; //interrupção do loop

    // 	while(flag){

    // 		if( ( pow(2,i) ) == tamanho || ( pow(2,i) ) > tamanho){ // descobre o número de bits de controle, maior ou igual a uma potência de 2
    // 			flag = 0; //interrompe o loop
    // 			potencia = i+1; //define o número de bits de controle
    // 		}

    // 		i++; //incrementa i para aumentar o número de bits de controle caso não seja suficiente
    // 	}

    // ///////////////////////////// Posição dos bits de de controle e de mensagem no quadro final //////////////////////////////////

    // 	Quadro vetor_controle; // o tipo quadro é só porque é um vetor de booleanos
    // 	Quadro final; //quadro com controle e mensagem

    // 	aux = 0; j = 0;

    // 	for(i=1; i < tamanho + potencia + 1; i++){ // valor dos bits de controle, vetor começa na "posição 1", por isso i = 1 e i < ... +1

    // 		if( i == (pow(2,aux)) ){ // insere bit de contole

    // 			final.push_back(0); // bit de controle, valor é irrelevante agora
    // 			aux++; // prepara pro próximo bit de contole
    // 		}

    // 		else { // insere bit de mensagem
    // 			final.push_back(quadro[j]); //insere bit de mensagem com valor correto
    // 			j++; // prepara para o próximo bit de mensagem
    // 		}
    // 	}

    // /////////////////////////////// Valor dos bits de controle e mensagem final ///////////////////////////////////////////////////

    // 	tamanho = final.size(); // tamanho do quadro final a ser enviado

    // 	j = 0; aux = 0;

    // 	for(i = 1; i < tamanho + 1; i++) { // vou percorrer o vetor final para atualizar os valores de bits de controle

    // 		if( i == pow(2,j) ){ // descobre se é bit de controle

    // 			j++;// pepara para pegar o próximo bit de controle
    // 			l = i; // auxiliar para decidir quais bits devem ser considerados naquele bit de controle

    // 			for(k = 1; k <= l; k++){ // coleto os bits relevantes para o bit de controle

    // /* trabalho como se fossem números inteiros e somo, os bits relevantes são o próprio bit de controle
    // e os bits de mensagem à seguir, o valor inicial de todos os bits de controle é zero para permitir a soma */

    // 				if(k == l){ // verifica se é inicio de uma sequência de bits relevantes
    // 					for( m = k; m < k+i; m++ ){

    // 						aux += final[k-1]; // vetores começam em zero, mas k começou em 1, -1 é pra corrigir a posição
    // 						//pega as sequencias de bits relevantes
    // 					}

    // 					l += pow(2,i); //incrementa a condição de parada para o início da próxima sequência de bits relevantes

    // 				}

    // 				if(l > tamanho + 1)break; // acabou o quadro, para de procurar bits
    // 			}
    // 			aux = (aux%2); // aux é inteiro, isso pega o resto da divisão por 2 para decidir se é um bit 1 ou 0
    // 			final[i-1] = aux; // atualiza o bit de controle, no início tinha valor zero
    // 			aux = 0; // reinicia aux
    // 		}
    // 	}
    // 	return final;
    // }

    // /////// Fim da codificação de Hamming ///////////////////////////////////////////////////////////////////////////////////////

    // Quadro ControladorCodigoDeHamming::controlarErros(const Quadro& quadro){

    // 	int i,j,k,l,m, aux, tamanho, potencia;
    // 	bool flag;

    // //////////////////////////// Número de Bits de controle ///////////////////////////////////////////////////////////////////

    // 	i = 0; // auxiliar do loop
    // 	tamanho = quadro.size(); //tamanho do quadro
    // 	flag = 1; //interrupção do loop

    // 	while(flag){

    // 		if( ( pow(2,i) ) > tamanho){ // descobre o número de bits de controle, maior a uma potência de 2 quer dizer q já ultrapassou o limite
    // 			flag = 0; //interrompe o loop
    // 			potencia = i; //desobre o número de bits de controle existentes no quadro
    // 			// OBS: não precisa do +1, pq só interrompe dps de passar
    // 		}

    // 		i++; //incrementa i para aumentar o número de bits de controle caso não seja suficiente
    // 	}

    // 	///// Recálculo dos bits de controle ///////////////////////////////////////////////////////////

    // 	j = 0; aux = 0;

    // 	for(i = 1; i < tamanho + 1; i++) { // vou percorrer o quadro para recalcular os valores de bits de controle

    // 		if( i == pow(2,j) ){ // descobre se é bit de controle

    // 			j++;// pepara para pegar o próximo bit de controle
    // 			l = i; // auxiliar para decidir quais bits devem ser considerados naquele bit de controle

    // 			for(k = 1; k <= l; k++){ // coleto os bits relevantes para o bit de controle

    // 				if(k == l){ // verifica se é inicio de uma sequência de bits relevantes
    // 					for( m = k; m < k+i; m++ ){

    // 						aux += quadro[k-1]; // vetores começam em zero, mas k começou em 1, -1 é pra corrigir a posição
    // 						//pega as sequencias de bits relevantes

    // 						/* trabalho como se fossem números inteiros e somo,
    // 						os bits relevantes são o próprio bit de controle e os bits de mensagem à seguir,
    // 						o valor inicial dos bits de controle foi calculado na codificação de hamming */
    // 					}

    // 					l += pow(2,i); //incrementa a condição de parada para o início da próxima sequência de bits relevantes

    // 				}

    // 				if(l > tamanho + 1)break; // acabou o quadro, para de procurar bits
    // 			}

    // 			aux = (aux%2); // aux é inteiro, isso pega o resto da divisão por 2 para decidir se é um bit 1 ou 0
    // 			quadro[i-1] 	= aux; // atualiza o bit de controle, se n tiver erros todos eles serão zero
    // 			aux = 0; // reinicia aux
    // 		}
    // 	}

    // 	////////////// Leitura do quadro pós recalculo dos bits de controle/////////////////////////////

    // 	j = 0; aux = 0;

    // 	for( i = 1; i < tamanho +1; i++){ // +1 pq usamos pow pra identificar bits de controle

    // 		if(pow(2,j) == i){ // acha bit de controle

    // 			if(quadro[i-1] == 1) { // lê bit de controle, -1 é a correção da posição no vetor

    // 				cout << "Erro detectado pelo bit de controle C" << i << "\n"; //printa o controle que marca erro
    // 				aux += i; // aux vai somar os valores de bit de controle que marcam erro pra identificar o bit errado
    // 			}

    // 			j++; // prepara para pegar o próximo bit de controle
    // 		}
    // 	}

    // 	j = 0; flag = 1;

    // 	if(aux != 0){ //caso erro seja detectado

    // 		cout << "O bit errado é o bit número "<< aux << "que é um bit de "; // a partir daki até o fim do if acima é opcional e perda de tempo pra explicar, mas eu fiz mesmo assim

    // 		for(i = 0; i < aux; i++){
    // 			if(pow(2,i) == aux){ //erro no bit de controle
    // 				cout << "controle \n";
    // 				flag = 0; // impede o próximo print
    // 			}
    // 			else if(pow(2,i) > aux) break;// se não for um bit de controle interrompe antes do fim do loop para poupar tempo
    // 		}

    // 		if(flag) cout<< "mensagem \n"; //erro no bit de mensagem

    // 	} // fim da perda de tempo inútil que eu fiz pq quiz.

    // 	////// print do quadro corrigido com bits de controle ainda ////
    // 	for(i=0; i < tamanho; i++){
    // 		cout << " " << quadro[i] << " ";
    // 	}

    // 	cout << "\n"; // fim fo print do quadro com bits de controle

    // 	///////////// Mensagem no lado do receptor já corrigida e sem bits de controle ///////////////

    // 	Quadro final; // mensagem no lado do receptor
    // 	j= 0 ;

    // 	for( i = 1 ; i < tamanho + 1 ; i++){
    // 		if(pow(2,j) != i){ //só põe se não for bit de controle
    // 			final.push_back(quadro[i-1]); // -1 é correção de posição
    // 		}
    // 		else{ j++;} // passa pro próximo bit de controle
    // 	}

    // 	return final; //retornei o que recebi corrigido em até 1 bit

    // }

    /// fim da decodificação de hamming ////////////////////////////////////////////////////////////
