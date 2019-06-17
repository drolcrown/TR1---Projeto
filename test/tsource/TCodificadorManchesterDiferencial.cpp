#define CATCH_CONFIG_MAIN  // Provide a main() // Only do this in one .cpp file.

#include "catch2.hpp"
#include "codificador_de_bits.hpp"

TEST_CASE("CodificadorManchesterDiferencial") {
  Quadro quadro;
  quadro.push_back(0);
  quadro.push_back(1);
  quadro.push_back(0);
  quadro.push_back(0);
  quadro.push_back(1);
  SECTION ("codificar") {
    CodificadorManchesterDiferencial codificador;
    FluxoDeBits fluxo_esperado;
    fluxo_esperado.push_back(0);
    fluxo_esperado.push_back(1);
    fluxo_esperado.push_back(1);
    fluxo_esperado.push_back(0);
    fluxo_esperado.push_back(1);
    fluxo_esperado.push_back(0);
    fluxo_esperado.push_back(1);
    fluxo_esperado.push_back(0);
    fluxo_esperado.push_back(0);
    fluxo_esperado.push_back(1);
    CHECK(fluxo_esperado == codificador.codificar(quadro));
  } // SECTION
} // TEST_CASE
