#pragma once

#include "multinomial.hpp"

multinomial s_polynomial(const multinomial&, const multinomial&, bool monomial_ordering(const monomial&, const monomial&));

void buchbergers_algorithm(ideal&, bool monomial_ordering(const monomial&, const monomial&) = lexicographical_ordering);
