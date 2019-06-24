 #include "controlador_de_erro.hpp"

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

    if(diferenca_entre_quadros >= 1){
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
            cout<<"Quadro com problemas!";
            for(int i = quadro_recebido.size(); i >= 9; i--){
                quadro_transmitido.pop_back();
            }
            return quadro_transmitido;
        }
    }

    for(int i = quadro_recebido.size(); i >= 9; i--){

        quadro_transmitido.pop_back();

    }

    return quadro_transmitido;

}