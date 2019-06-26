#include "catch2.hpp"
#include "controlador_de_erro.hpp"

TEST_CASE("TControladorBitParidadeImpar::adicionarControle") {
  ControladorBitParidadeImpar controlador_de_erro;
  Quadro quadro;
  quadro.push_back(0);
  quadro.push_back(1);
  quadro.push_back(0);
  SECTION("Bit paridade == 0") {
    Quadro novo_quadro = controlador_de_erro.adicionarControle(quadro);
    quadro.push_back(0);
    CHECK(novo_quadro == quadro);
  }
  SECTION("Bit paridade == 1") {
    quadro.push_back(1);
    Quadro novo_quadro = controlador_de_erro.adicionarControle(quadro);
    quadro.push_back(1);
    CHECK(novo_quadro == quadro);
  }
}

TEST_CASE("TControladorBitParidadeImpar::control") {
  ControladorBitParidadeImpar controlador;
  Quadro quadro;
  quadro.push_back(0);
  quadro.push_back(1);
  SECTION("Bit paridade == 0") {
    Quadro recebido = quadro;
    recebido.push_back(0);
    CHECK(controlador.controlarErros(recebido) == quadro);
  }
  quadro.push_back(1);
  SECTION("Bit paridade == 1") {
    Quadro recebido = quadro;
    recebido.push_back(1);
    CHECK(controlador.controlarErros(recebido) == quadro);
  }
}
