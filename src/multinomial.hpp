#pragma once

#include <set>
#include <stdexcept>

#include "ginac/ginac.h"

// typedefs
typedef GiNaC::symbol indeterminate;
typedef std::set<indeterminate> variable_container;
typedef GiNaC::numeric field_element;

class multinomial : public GiNaC::ex {
public:
  // constructor:
  multinomial() {};
  multinomial(const GiNaC::ex&);
};

bool is_multinomial(const GiNaC::ex& input);
