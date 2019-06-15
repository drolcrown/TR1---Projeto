#pragma once

#include <string>
#include <vector>
#include <bitset>

using namespace std;

class Mensagem : std::string {};

/** @brief Bit � tipo de dado que pode ser 0 ou 1. */
typedef bool Bit;

/** @brief Quadro é o tipo de dado que representa um vetor de Bits na camada de
 *  Enlace. */
class Quadro : public std::vector<Bit>{};

/** @brief FluxoDeBits pe o tipo de dado que representa um vetor de Bits na
 * camada física. */
class FluxoDeBits : public std::vector<Bit>{};