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
  FluxoDeBits fluxo_de_bits;
  fluxo_de_bits.push_back(0);
  fluxo_de_bits.push_back(1);
  fluxo_de_bits.push_back(1);
  fluxo_de_bits.push_back(0);
  fluxo_de_bits.push_back(1);
  fluxo_de_bits.push_back(0);
  fluxo_de_bits.push_back(1);
  fluxo_de_bits.push_back(0);
  fluxo_de_bits.push_back(0);
  fluxo_de_bits.push_back(1);
  SECTION ("codificar") {
    CodificadorManchesterDiferencial codificador;
    CHECK(fluxo_de_bits == codificador.codificar(quadro));
  } // SECTION
  SECTION("decodificar") {
    CodificadorManchesterDiferencial codificador;
    CHECK(quadro == codificador.decodificar(fluxo_de_bits));
  }
} // TEST_CASE
