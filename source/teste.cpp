/*
	C�lculo do fatorial
	0! = 1! = 1
	3! = 3 * 2 * 1 = 6
	4! = 4 * 3 * 2 * 1 = 24
	5! = 5 * 4 * 3 * 2 * 1 = 120
*/

#include <iostream>
#include <vector>

using namespace std;

class GeradorDeQuadros{
    private:
        vector<bool> fluxo;
        
    public:
        vector<bool> gerarQuadro(int tamanhoQuadro){
	        for(int i = 0; i < tamanhoQuadro; i++){
                fluxo.push_back(rand() % 2);
             }
            return fluxo;
        }
    
};

// Classes que implementam a interface ICodificadorDeBits
class CodificadorManchester {
    private:
        vector<bool> fluxo;

   public:
      vector<bool> codificar(const fluxo&){
         cout << fluxo << endl;
		 return fluxo;
      }

    //   Quadro decodificar(const vector<bool>){
         
    //   }
};

int main(int argc, char *argv[]){
	GeradorDeQuadros gerador;
	vector<bool> fluxo = gerador.gerarQuadro(10);

	CodificadorManchester cod;
	// vector<int> vect{ false, true, false, true, true, false, true, false}; 
	int num;

    for (int i = 0; i<  1000; i ++) {
		if(i %60){
        	cout << i%60 << endl; 
		}
	}

	// fluxo.push_back(1);
	// fluxo.push_back(1);
	// fluxo.push_back(0);
	// fluxo.push_back(0);
	// fluxo.push_back(1);
 	unsigned int A = 0x01; // 00000001
 	unsigned int B = 0x03; // 00000011
	// int num, fat = 1;
	
	// cout << "Digite um numero: ";
	// cin >> num;
	
	// for(int i = 1; i < num ; i++)
	// 	fat = fat * (i + 1);
	// cout << "Fatorial: " << fat << endl;

		// clock_t t;
		// t = clock();
		// printf ("Calculating...\n");
		// t = clock() - t;
		// printf ("It took me %lu clicks (%f seconds).\n",t,((float)t)/10000);
		// return 0;
	//  cout << (A ^ B) << endl;
	//  cout << fluxo[0] << endl;

    
		// return 0;
	return 0;
}