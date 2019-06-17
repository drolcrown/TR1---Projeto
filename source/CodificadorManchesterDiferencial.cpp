#include "codificador_de_bits.hpp"
#include <vector> //para fazer um quadro teste

FluxodeBits CodificadorManchesterDiferencial::codificar(const Quadro& quadro)
{
	// 0 = mantem (ou seja copia o anterior) e 1 = troca (em relação ao anterior)

	bool aux = 0; //auxiliar vai ser o bit atual iniciado em zero, 
	//o trabalho do bit atual é se o bit do vetor quadro for 0 ele mantém e é inserido na saida
	// se for 1 ele troca e é inserido na saída
	//assim a saída é um vetor de mesmo tamanho do quadro feito de bits aux

	vector<bool> quadro1; //quadro teste

	vector<bool> quadro_saida;//saida da codificação

	quadro1.push_back(0); quadro1.push_back(1); quadro1.push_back(1); quadro1.push_back(1);
	quadro1.push_back(0); quadro1.push_back(0); quadro1.push_back(1); quadro1.push_back(0);
	//quadro teste: 01110010

	int i;

	for (auto i = quadro1.begin(); i != quadro1.end(); ++i){

		if(*i = 0){
			quadro_saida.push_back(aux); //se é zero manda o bit atual
		}

		else if (*i = 1){
			aux = !aux; // inverte o bit atual e insere
			quadro_saida.push_back(aux);
		}

		else{
			cout <<"Algo de errado nao esta certo\n" // era pra ser só 0 e 1, algo tá muito errado
		}

	}

	for (auto i = quadro_saida.begin(); i != quadro_saida.end(); ++i){
		cout << *i << " "; //imprime a saída... supostamente
	}

	//passar o quadro_saida para o lugar certo

};