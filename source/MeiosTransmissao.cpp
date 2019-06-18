#include "meio_fisico.hpp"
#include "interfaces_comunicacao.hpp"

using namespace std;

class Cabos: public MeioFisico{
    
   public:
        double taxaDeErro(double taxa) { 
            cout << taxa << endl;
            return taxa;
        }

        void configCamadaFisicaReceptora(ICamadaFisicaReceptora* camadaReceptora){
            this->camada_fisica_receptora = camadaReceptora;
            cout << "Receptor Configurado" << endl;
        }
        
        void transmitir(FluxoDeBits& fluxoDeBits){
           this->camada_fisica_receptora->receber(fluxoDeBits);
            cout << "Fluxo Transmitido" << endl;
        }
};