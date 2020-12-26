#include "multinomial.h"

using GiNaC::info_flags;
using GiNaC::symbol;
using std::domain_error;

multinomial::multinomial(){
  variables = std::vector<symbol>();
  expression = 0;
}

multinomial::multinomial(const GiNaC::ex& expr, const std::vector<symbol>& vars){
  if(!expr.info(info_flags::rational_polynomial))
    throw domain_error("Not a multinomial over the rationals.");

  // put variables into lexicographical ordering
  variables = vars;
  sort(variables.begin(), variables.end(), lexicographical_ordering);
  expression = expr;
}

bool lexicographical_ordering(const symbol& x, const symbol& y){
  return x.get_name() < y.get_name();
}
