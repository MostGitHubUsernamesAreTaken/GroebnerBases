#ifndef GUARD_multinomial_h
#define GUARD_multinomial_h

#include <vector>
#include <stdexcept>

#include "ginac/ginac.h"

class multinomial {
public:
  typedef std::vector<GiNaC::symbol> var_container;
  // constructor:
  multinomial();
  multinomial(const GiNaC::ex&, const var_container&);

  // access to data structure
  var_container vars() const {return variables;}
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
  var_container variables;
};

bool lexicographical_ordering(const GiNaC::symbol& x, const GiNaC::symbol& y);

#endif
