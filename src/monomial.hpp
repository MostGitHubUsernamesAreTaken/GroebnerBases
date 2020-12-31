#pragma once

#include "multinomial.hpp"

class monomial : public multinomial{
  monomial() {};
  monomial(const multinomial&);
};

monomial leading_monomial(const multinomial&);

bool is_monomial(const multinomial&);

bool lexicographical(const monomial&, const monomial&);

bool degree_reverse_lexicographical(const monomial&, const monomial&);
