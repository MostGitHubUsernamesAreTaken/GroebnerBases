#pragma once

#include <vector>
#include <set>
#include <stdexcept>

#include "ginac/ginac.h"

// typedefs
typedef GiNaC::symbol indeterminate;
typedef std::set<indeterminate> variable_container;

class multinomial : public GiNaC::ex {
public:
  // constructor:
  multinomial() {};
  multinomial(const GiNaC::ex&);

  // access to data structure
  variable_container vars() const;

  // leading monomial under lexicographical ordering
  // leading term under lexicographical ordering
  multinomial lt() const;
};

bool is_multinomial(const GiNaC::ex& input);

multinomial rem(const multinomial&, const multinomial&);
