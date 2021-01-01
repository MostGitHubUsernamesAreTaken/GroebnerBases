#include "monomial.hpp"

monomial(const multinomial&);



bool is_monomial(const multinomial& p);

bool lexicographical(const monomial& p, const monomial& q){
  return p.get_name() < q.get_name();
}
