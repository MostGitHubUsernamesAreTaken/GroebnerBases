#include "multinomial.hpp"

using GiNaC::info_flags;
using GiNaC::symbol;
using std::domain_error;

multinomial::multinomial(const GiNaC::ex& expr){
  if(!is_multinomial(expr))
    throw domain_error("Not a multinomial over the rationals.");
  //expression = expr;

}

bool is_multinomial(const GiNaC::ex& input){
  return input.info(info_flags::rational_polynomial);
}

//
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

multinomial rem(const multinomial& numerator, const multinomial& denominator){
  return multinomial(GiNaC::rem(numerator, denominator, x));
}
