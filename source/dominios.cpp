#include "dominios.hpp"

std::ostream& operator<< (std::ostream& out, std::vector<Bit>& v) {
  out << '{';
  for (int i = 0; i < v.size(); ++i) {
      out << ' ' << v[i] << ' ';
  }
  return out << '}';
}