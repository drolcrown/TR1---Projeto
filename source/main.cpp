#include "sistema_comunicacao.hpp"

int main() {
    // Instanciar sistema com codificador binario sem taxa de erros no meio fisico
    // SistemaDeComunicacao sistema_de_comunicacao = SistemaDeComunicacao();
    
    //Instanciar sistema passando codificador e taxa de erros como parametros
    // CodificadorBinario codificador;
    // double taxaDeErro = 20.0;
    // SistemaDeComunicacao sistema_de_comunicacao = SistemaDeComunicacao(codificador, taxaDeErro /** taxa de erro do Meio Fisico**/);


    //Lista de tuplas contendo todos os meio fisicos e todos os codificadores
    std::vector<std::tuple<ICodificadorDeBits*, std::string>> codificadores = {
        {new CodificadorBinario(), "Codificador Binario"}, 
        {new CodificadorManchester(), "Codificador Manchester"}, 
        {new CodificadorManchesterDiferencial(), "Codificador Manchester Diferencial"}
    };
    std::vector<std::tuple<MeioFisico*, std::string>> meios = {
        {new FibraOtica(), "Fibra Otica"}, {new RedeSemFio(), "Rede Sem Fio"}, {new FioTrancado(), "Fio Trançado"}
    };

    for (int i = 0; i < codificadores.size() ; i++){
        for (int j = 0; j < meios.size() ; j++){
            //Instanciar sistema passando codificador e tipo de meio fisico como parametros
            SistemaDeComunicacao sistema_de_comunicacao = SistemaDeComunicacao(*std::get<0>(codificadores[i]), *std::get<0>(meios[j]) /** taxa de erro do Meio Fisico**/);    
            std::cout  << esc::color::foreground::BRIGHT_YELLOW 
            << "Codificador: " << std::get<1>(codificadores[i]) << "\nMeio Fisico: " << std::get<1>(meios[j])
            << esc::RESET << std::endl;
            sistema_de_comunicacao.run();
        }
    }
    
    return 0;
}

