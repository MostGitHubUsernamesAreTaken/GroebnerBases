#include "ideal.hpp"

void buchbergers_algorithm(ideal& F, bool monomial_ordering(const monomial& x1, const monomial& x2)){
  // Updates F to a reduced Groebner basis using Buchberger's algorithm,
  // NB: A reduced Groebner basis is unique for any given ideal and monomial ordering.
  ideal G;
  do {
    G = F;
    for(ideal::iterator i = F.begin(); i != F.end(); ++i){
      for(ideal::iterator j = i + 1; j != F.end(); ++j){
        multinomial s = s_polynomial(*i, *j, monomial_ordering);
        if (s.reduce(G) != 0)
          F.insert(s);
      }
    }
  } while (G != F);
}
