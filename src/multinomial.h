#ifndef GUARD_multinomial_h
#define GUARD_multinomial_h

#include <vector>
#include <stdexcept>

#include "ginac/ginac.h"

// typedefs
typedef GiNaC::symbol variable_type;
typedef std::vector<variable_type> variable_container;

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
  // multinomial lt() const;

  // overloads
  template <class T> multinomial operator*(const T&);

private:
  GiNaC::ex expression;
  // choose std::list over GiNaC's lst
  variable_container variables;
};

bool lexicographical_ordering(const variable_type& x, const variable_type& y);

#endif
