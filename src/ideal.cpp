#include "ideal.hpp"

multinomial multinomial::reduce(ideal& G){

}

multinomial s_polynomial(const multinomial& p, const multinomial& q, bool monomial_ordering(const monomial& x1, const monomial& x2)){
  multinomial lcm = least_common_multiple(p.lm(monomial_ordering), q.lm(monomial_ordering));
  return lcm/p.lt(monomial_ordering)*p - lcm/q.lt(monomial_ordering)*q;
}

void buchbergers_algorithm(ideal& F, bool monomial_ordering(const monomial& x1, const monomial& x2)){
  // Updates F to a reduced Groebner basis using Buchberger's algorithm,
  // NB: A reduced Groebner basis is unique for any given ideal and monomial ordering.
  ideal G;
  do {
    G = F;
    for(ideal::const_iterator i = F.begin(); i != F.end(); ++i){
      for(ideal::const_iterator j = i + 1; j != F.end(); ++j){
        multinomial s = s_polynomial(*i, *j, monomial_ordering);
        if (s.reduce(G) != 0)
          F.push_back(s);
      }
    }
  } while (G != F);
}
