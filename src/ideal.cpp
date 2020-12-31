#include "ideal.hpp"

using GiNaC::lcm;
using std::next;

multinomial reduce(const multinomial& p, const ideal& G){
  multinomial res = p;
  for(ideal::iterator iter = G.begin(); iter != G.end(); ++iter){
    res = rem(res, *iter);
  }
  return res;
}

multinomial s_polynomial(const multinomial& p, const multinomial& q){
  multinomial the_lcm = lcm(leading_monomial(p), leading_monomial(q));
  return the_lcm/p.lt()*p - the_lcm/q.lt()*q;
}

void buchbergers_algorithm(ideal& F, bool monomial_ordering(const monomial& x1, const monomial& x2) = lexicographical){
  // Updates F to a reduced Groebner basis using Buchberger's algorithm,
  // NB: A reduced Groebner basis is unique for any given ideal and monomial ordering.
  ideal G;
  do {
    G = F;
    for(ideal::iterator i = F.begin(); i != F.end(); ++i){
      for(ideal::iterator j = next(i); j != F.end(); ++j){
        multinomial s = s_polynomial(*i, *j);
        if (reduce(s, G) != 0)
          F.insert(s);
      }
    }
  } while (G != F);
}
