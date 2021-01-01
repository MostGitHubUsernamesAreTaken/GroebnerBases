#include "ideal.hpp"

using GiNaC::lcm;
using GiNaC::const_iterator;
using GiNaC::is_a;
using std::next;

multinomial lead_term(const multinomial& p) {
  // returns the leading term according to the monomial ordering of the variables
  variable_container vars = indets(p);
  const indeterminate x = *(vars.begin());

  if (vars.size() == 1){
    return (p.lcoeff(x))*pow(x, p.degree(x));
  } else{
    return lead_term(p.lcoeff(x))*pow(x, p.degree(x));
  }
}

monomial leading_monomial(const multinomial& p){
  multinomial p0 = lead_term(p);
  field_element coeff = 1;
  for (const_iterator i = p0.begin(); i != p0.end(); ++i){
    if (is_a<field_element>(*i)){
      coeff *= *i;
    }
  }
  return p0/coeff;
}

multinomial rem(const multinomial& numerator, const multinomial& denominator){
  // perform multinomial division and return the remainder
  multinomial res = numerator;
  multinomial divisor = lead_term(denominator);
  multinomial lead = lead_term(res);
  while(is_multinomial(lead/divisor)){
    res -= lead/divisor*denominator;
    lead = lead_term(res);
  }
  return res;
}

multinomial reduce(const multinomial& p, const ideal& G){
  multinomial res = p;
  for(ideal::iterator iter = G.begin(); iter != G.end(); ++iter){
    res = rem(res, *iter);
  }
  return res;
}

multinomial s_polynomial(const multinomial& p, const multinomial& q){
  multinomial the_lcm = lcm(leading_monomial(p), leading_monomial(q));
  return the_lcm/lead_term(p)*p - the_lcm/lead_term(q)*q;
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
