#include "dominios.hpp"

class GeradorDeQuadros{
    private:
        FluxoDeBits fluxo;
        
    public:
        FluxoDeBits gerarQuadro(int tamanhoQuadro){
	        for(int i = 0; i < tamanhoQuadro; i++){
                fluxo.push_back(rand() % 2);
            }
            return fluxo;
        }
    
};