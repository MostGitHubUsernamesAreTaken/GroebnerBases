#include "multinomial.h"

using GiNaC::info_flags;
using GiNaC::symbol;
using std::domain_error;

multinomial::multinomial(){
  variables = variable_container();
  expression = 0;
}

multinomial::multinomial(const GiNaC::ex& expr, const variable_container& vars){
  if(!expr.info(info_flags::rational_polynomial))
    throw domain_error("Not a multinomial over the rationals.");

  // put variables into lexicographical ordering
  variables = vars;
  sort(variables.begin(), variables.end(), lexicographical_ordering);
  expression = expr;
}

bool lexicographical_ordering(const variable_type& x, const variable_type& y){
  return x.get_name() < y.get_name();
}

// multinomial multinomial::lt() const{
//   // returns the leading term according to the monomial ordering of the variables
//   const symbol x = variables.front();
//   if (variables.size() == 1){
//     return multinomial(expression.lcoeff(x)*pow(x, expression.degree(x)), variables);
//   } else{
//     var_container remaining_variables = variables;
//     remaining_variables.erase(variables.begin());
//     return multinomial(multinomial(expression.lcoeff(x), remaining_variables)*pow(x, expression.degree(x)), variables);
//   }
// }
