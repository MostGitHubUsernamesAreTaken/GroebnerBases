#include "monomial.hpp"

using GiNaC::is_a;
using GiNaC::ex_to;
using GiNaC::add;
using std::string;
using std::set;

bool is_monomial(const multinomial& p){
  // p must be a multinomial so we only need to check if it is a sum
  return !is_a<add>(p);
}

indet_set find_indet_set(const multinomial& p){
  indet_lst p_lst = indets(p);
  indet_set res;
  for(indet_lst::const_iterator i = p_lst.begin(); i != p_lst.end(); ++i){
    indeterminate x = ex_to<indeterminate>(*i);
    res.insert(x);
  }
  return res;
}

bool lexicographical(const monomial& p, const monomial& q){
  // return true if p > q by the lexicographical ordering and false otherwise
  multinomial diff = p - q;
  indet_set diff_indets = find_indet_set(diff);
  if (diff_indets.size() == 0){
    return diff > 0;
  }

  indeterminate x = *(diff_indets.begin());
  return lexicographical(diff.lcoeff(x), 0);

}
