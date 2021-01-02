#pragma once

#include "ginac/ginac.h"

// For a first version add a simple typedef
typedef GiNaC::ex multinomial;

bool is_multinomial(const GiNaC::ex& input);
