#include "multinomial.hpp"

using GiNaC::info_flags;
using GiNaC::ex;

bool is_multinomial(const ex& expr){
  return expr.info(info_flags::rational_polynomial);
}
