#pragma once

#include <string>
#include <vector>
#include <bitset>
#include <iostream>

class Mensagem : public std::string {};

/** @brief Bit � tipo de dado que pode ser 0 ou 1. */
typedef bool Bit;

/** @brief Quadro é o tipo de dado que representa um vetor de Bits na camada de
 *  Enlace. */
class Quadro : public std::vector<Bit>{};

/** @brief FluxoDeBits pe o tipo de dado que representa um vetor de Bits na
 * camada física. */
class FluxoDeBits : public std::vector<Bit>{};

std::ostream& operator<< (std::ostream out, std::vector<Bit>& v) {
  out << '{';
  for (int i = 0; i < v.size(); ++i) {
      out << ' ' << v[i] << ' ';
  }
  return out << '}';
}