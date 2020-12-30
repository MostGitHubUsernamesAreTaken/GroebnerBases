#pragma once

#include <vector>
#include <stdexcept>

#include "ginac/ginac.h"

// typedefs
typedef GiNaC::symbol indeterminate;
typedef std::vector<indeterminate> variable_container;

class multinomial {
public:
  // constructor:
  multinomial();
  multinomial(const GiNaC::ex&, const variable_container&);

  // access to data structure
  variable_container vars() const {return variables;}
  GiNaC::ex expr() const {return expression;}

  // leading monomial under lexicographical ordering
  // multinomial lm() const;
  // leading term under lexicographical ordering
  multinomial lt() const;

  // overloads
  multinomial operator*(const multinomial& factor){
    expression *= factor.expr();
    return multinomial(expression, variables);
  };

private:
  GiNaC::ex expression;
  variable_container variables;
};

bool lexicographical_ordering(const monomial& x, const monomial& y);

multinomial s_polynomial(const multinomial&, const multinomial&, bool monomial_ordering(const monomial&, const monomial&));
