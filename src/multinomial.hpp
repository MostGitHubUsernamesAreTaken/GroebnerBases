#pragma once

#include "ginac/ginac.h"

// For a first version add simple typedefs
typedef GiNaC::symbol indeterminate;
typedef GiNaC::ex multinomial;

bool is_multinomial(const GiNaC::ex& input);
