#include "codificador_de_bits.hpp"
#include <vector> //para fazer um quadro teste

FluxodeBits CodificadorManchester::codificar(const Quadro& quadro) {

	// 0 = 01 e 1 = 10 ,vetor tem o dobro do tamanho
	/*vector<bool> quadro1; //quadro teste

	vector<bool> quadro_saida;//saida da codificação

	quadro1.push_back(0); quadro1.push_back(1); quadro1.push_back(1); quadro1.push_back(1);
	quadro1.push_back(0); quadro1.push_back(0); quadro1.push_back(1); quadro1.push_back(0);

	//quadro teste: 01110010 */

	int i,aux = 0;
	FluxodeBits fluxo;
	fluxo.reserve(2*quadro.size());


	for (int i = 0; i < quadro.size(); ++i){

		if(quadro[i] == 0){
			fluxo.push_back(0); fluxo.push_back(1);//se é 0 manda 01
		}

		else if (quadro[i] == 1){
			fluxo.push_back(1); fluxo.push_back(0);//se é 1 manda 10
		}

		else{
			cout <<"Algo de errado nao esta certo\n" // era pra ser só 0 e 1, algo tá muito errado
		}

	}

	for (i = 0; i < fluxo.size(); ++i){
		cout << fluxo[i] << " "; //imprime a saída... supostamente
	}

	cout << "\n";
};