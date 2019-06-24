#include "dominios.hpp"

std::ostream& operator<< (std::ostream& out,const std::vector<Bit>& v) {
  out << '[';
  for (int i = 0; i < v.size(); ++i) {
      out << v[i] << (i == v.size() - 1 ? "" : ", ") ;
  }
  return out << ']';
}