#include "controlador_de_erro.hpp"

Quadro ControladorCRC :: adicionarControle(const Quadro &quadro){

    std::vector<bool> crc = {1,0,1,1};
    Quadro quadro_completo = quadro; //Quadro que vai receber a sequencia de 0's
 
    Quadro CRC = quadro_completo;
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

    cout << endl;

    return quadro_completo; 


}

Quadro ControladorCRC::controlarErros(const Quadro &quadro){

    std::vector<bool> crc = {1,0,1,1};

    Quadro quadro_original = quadro;
    Quadro quadro_modificavel = quadro;

    int tam_quadro_recebido = quadro.size();
    int tam_CRC = crc.size();

    //Realiza a operacao de divisao
    for(int i = 0; i <= quadro_modificavel.size() - tam_CRC; ){
        for(int j = 0; j < tam_CRC; j++)
            quadro_modificavel[i + j] = quadro_modificavel[i+j] == crc[j]? 0:1; //XOR
        for(; i < quadro_modificavel.size() && quadro_modificavel[i] != 1; i++);//Condicao de iteracao do i
    }
    
    for(int i = 0; i < quadro_modificavel.size(); i++){
        
        if(quadro_modificavel[i] == 0){
            continue;
        }else{
            cout<<"Quadro com problemas!";
            exit;
        }
    }

    for(int i = quadro_modificavel.size(); i >= 9; i--){
        
        quadro_original.pop_back();
    
    }

    return quadro_original;

}