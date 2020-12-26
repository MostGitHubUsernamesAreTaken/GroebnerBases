#ifndef GUARD_multinomial_h
#define GUARD_multinomial_h

#include <vector>
#include <stdexcept>

#include "ginac/ginac.h"

class multinomial {
public:
  // constructor:
  multinomial();
  multinomial(const GiNaC::ex&, const std::vector<GiNaC::symbol>&);

  // access to data structure
  std::vector<GiNaC::symbol> vars() const {return variables;}
  GiNaC::ex expr() const {return expression;}

  // leading monomial under lexicographical ordering
  // GiNaC::ex lm() const;
  // leading term under lexicographical ordering
  // GiNaC::ex lt() const;

private:
  GiNaC::ex expression;
  // choose std::list over GiNaC's lst
  std::vector<GiNaC::symbol> variables;
};

bool lexicographical_ordering(const GiNaC::symbol& x, const GiNaC::symbol& y);

#endif
