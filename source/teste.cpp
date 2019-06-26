#include <math.h>

void teste(int tamanho){
    int potencia = 1;
    
    for (int i =0; pow(2, i) <= tamanho; i++ ){
        potencia = i+1;
    }

    int aux, soma = 0;
    for (int i =1; i < potencia; i++ ){
        aux = i;
        soma = 0;
        for(int j =0; j < aux; j+=aux){
            if(j >= aux){
                // soma+= bit[j];
                aux += i;
            }
        }
    }
}