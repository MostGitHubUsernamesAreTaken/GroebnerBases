#pragma once

#include <set>
#include "multinomial.hpp"

typedef std::set<multinomial> ideal;

multinomial reduce(const multinomial&, const ideal&);

multinomial s_polynomial(const multinomial&, const multinomial&, bool monomial_ordering(const monomial&, const monomial&));

void buchbergers_algorithm(ideal&, bool monomial_ordering(const monomial&, const monomial&));
