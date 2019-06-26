#include "catch2.hpp"
#include "controlador_de_erro.hpp"

TEST_CASE("TControladorCodigoHamming::controlarErros (8 bits)") {
    ControladorCodigoDeHamming controlador;
    Quadro quadro; // [0, 1, 1, 0, 1, 1, 1, 1]
    quadro.push_back(0);
    quadro.push_back(1);
    quadro.push_back(1);
    quadro.push_back(0);
    quadro.push_back(1);
    quadro.push_back(1);
    quadro.push_back(1);
    quadro.push_back(1);
    Quadro hamming_quadro; // [1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1]
    hamming_quadro.push_back(1);
    hamming_quadro.push_back(1);
    hamming_quadro.push_back(0);
    hamming_quadro.push_back(1);
    hamming_quadro.push_back(1);
    hamming_quadro.push_back(1);
    hamming_quadro.push_back(0);
    hamming_quadro.push_back(0);
    hamming_quadro.push_back(1);
    hamming_quadro.push_back(1);
    hamming_quadro.push_back(1);
    hamming_quadro.push_back(1);
    SECTION("adicionarControle") {
        CHECK(controlador.adicionarControle(quadro) == hamming_quadro);
    }
} 