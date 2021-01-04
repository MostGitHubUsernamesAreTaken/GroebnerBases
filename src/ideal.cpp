#include "ideal.hpp"

using GiNaC::lcm;
using GiNaC::const_iterator;
using GiNaC::is_a;
using GiNaC::ex_to;
using std::next;
using std::any_of;

multinomial leading_term(const multinomial& p){
  // returns the leading term according to the monomial ordering of the variables
  indet_set vars = find_indet_set(p);

  if (vars.size() == 0){
    return p;
  } else{
    multinomial p_exp = p.expand(); // GiNaC's lcoeff doesn't work with unexpanded inputs
    const indeterminate x = *(vars.begin());
    return leading_term(p_exp.lcoeff(x))*pow(x, p_exp.degree(x));
  }
}

monomial leading_monomial(const multinomial& p){
  indet_set vars = find_indet_set(p);
  if (vars.size() == 0){
    return 1;
  } else{
    multinomial p_exp = p.expand(); // GiNaC's lcoeff doesn't work with unexpanded inputs
    const indeterminate x = *(vars.begin());
    return leading_monomial(p_exp.lcoeff(x))*pow(x, p_exp.degree(x));
  }
}

multinomial leading_coeff(const multinomial& p){
  // returns the leading term according to the monomial ordering of the variables
  indet_set vars = find_indet_set(p);

  if (vars.size() == 0){
    return p;
  } else{
    multinomial p_exp = p.expand(); // GiNaC's lcoeff doesn't work with unexpanded inputs
    const indeterminate x = *(vars.begin());
    return leading_coeff(p_exp.lcoeff(x));
  }
}

multinomial rem(const multinomial& numerator, const multinomial& denominator){
  // perform multinomial division and return the remainder
  multinomial res = numerator;
  multinomial divisor = leading_term(denominator);
  multinomial lead = leading_term(res);
  while(res != 0 && is_multinomial(lead/divisor)){
    res -= lead/divisor*denominator;
    res = res.expand(); // need a simplifying step
    lead = leading_term(res);
  }
  return res.expand();
}

bool leading_monomial_divisor(const multinomial& p, const multinomial& q){
  monomial p_lt = leading_monomial(p);
  monomial q_lt = leading_monomial(q);
  return rem(p_lt, q_lt) == 0;
}

bool is_inferior_ideal_element(const multinomial& p, const ideal& I){
  return any_of(I.begin(), I.end(), [p](multinomial q){return leading_monomial_divisor(p, q);});
}

multinomial reduce(const multinomial& p, const ideal& G){
  multinomial res = p;
  for(ideal::const_iterator iter = G.begin(); iter != G.end(); ++iter){
    res = rem(res, *iter);
  }
  return res;
}

multinomial s_polynomial(const multinomial& p, const multinomial& q){
  multinomial the_lcm = lcm(leading_monomial(p), leading_monomial(q));
  multinomial res = the_lcm/leading_term(p)*p - the_lcm/leading_term(q)*q;
  return res.expand();
}

multinomial normalise(const multinomial& p){
  // normalisation of Groeber basis
  if (is_a<field_element>(p))
    return 1;
  else
    return (p/leading_coeff(p)).expand();
}

void buchbergers_algorithm(ideal& F){
  // Updates F to a reduced Groebner basis using Buchberger's algorithm,
  // NB: A reduced Groebner basis is unique for any given ideal and monomial ordering.
  ideal G;

  transform(F.begin(), F.end(), F.begin(), normalise);

  do {
    G = F;
    for(ideal::const_iterator i = G.begin(); i != prev(G.end()); ++i){
      for(ideal::const_iterator j = next(i); j != G.end(); ++j){
        multinomial s = s_polynomial(*i, *j);
        if (reduce(s, F) != 0 && find(F.begin(), F.end(), s)==F.end()){
          F.push_back(s);
        }
      }
    }

  } while (G != F);

  // reduce result
  transform(F.begin(), F.end(), F.begin(), normalise);

  ideal::iterator i = F.begin();
  while(i != F.end()){
    ideal::iterator j = next(i);
    while(j != F.end()){

      if (leading_monomial_divisor(*j, *i)){
        j = F.erase(j);

        continue;
      }else if (leading_monomial_divisor(*i, *j)){

        i = F.erase(i);
        j = next(i);
        continue;
      }
      j++;
    }
    i++;
  }
}
