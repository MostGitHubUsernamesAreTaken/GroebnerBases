#include "monomial.hpp"

bool lexicographical(const monomial& x, const monomial& y){
  return x.get_name() < y.get_name();
}
