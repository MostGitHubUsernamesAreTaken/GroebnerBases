#include "multinomial.hpp"

using GiNaC::info_flags;
using GiNaC::ex;
using std::domain_error;

multinomial::multinomial(const ex& expr){
  if(!is_multinomial(expr))
    throw domain_error("Not a multinomial over the rationals.");
  //expression = expr;

}

bool is_multinomial(const ex& expr){
  return expr.info(info_flags::rational_polynomial);
}
