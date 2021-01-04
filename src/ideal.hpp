#pragma once

#include <unordered_set>
#include <algorithm>

#include "monomial.hpp"

typedef GiNaC::numeric field_element;
typedef std::vector<multinomial> ideal;

multinomial leading_term(const multinomial&);

monomial leading_monomial(const multinomial&);

multinomial leading_coeff(const multinomial&);

bool leading_monomial_divisor(const multinomial& p, const multinomial& q);

bool is_inferior_ideal_element(const multinomial&, const ideal&);

multinomial normalise(const multinomial&);

multinomial rem(const multinomial&, const multinomial&);

multinomial reduce(const multinomial&, const ideal&);

multinomial s_polynomial(const multinomial&, const multinomial&);

void buchbergers_algorithm(ideal&);
