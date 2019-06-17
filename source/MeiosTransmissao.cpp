#include <iostream>
#include "meio_fisico.hpp"

using namespace std;
 
class ICamadaFisicaReceptora; // Classe declarada em interfaces_comunicacao.hpp
class ICamadaFisicaTransmissora; // Classe declarada em interfaces_comunicacao.hpp

class Cabos: public MeioFisico{
    
   public:
        double taxaDeErro(double taxa) { 
            cout << taxa << endl;
            return taxa;
        }

        void configCamadaFisicaReceptora(ICamadaFisicaReceptora* camadaReceptora){
            cout << camadaReceptora << endl;
        }
        
        void transmitir(FluxoDeBits& fluxoDeBits){
            cout << fluxoDeBits << endl;
        }
};
 
int main(void) {
    Cabos cab;
    FluxoDeBits *fluxo;
    
    fluxo.push_back(1);
    fluxo.push_back(0);
    fluxo.push_back(1);
    //  1, 0, 1, 0, 1, 0, 0, 0, 1, 1 ,0  {true, false, true};

    cab.taxaDeErro(2);
    cab.configCamadaFisicaReceptora(cab.camada_fisica_receptora);
    cab.transmitir(fluxo);

   return 0;
}