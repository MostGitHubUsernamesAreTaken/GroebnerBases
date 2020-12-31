#pragma once

#include <set>
#include "multinomial.hpp"
#include "monomial.hpp"

typedef std::set<multinomial> ideal;

multinomial reduce(const multinomial&, const ideal&);

multinomial s_polynomial(const multinomial&, const multinomial&);

void buchbergers_algorithm(ideal&, bool monomial_ordering(const monomial&, const monomial&));
