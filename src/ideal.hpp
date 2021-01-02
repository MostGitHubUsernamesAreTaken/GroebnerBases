#pragma once

#include <set>

#include "monomial.hpp"

typedef GiNaC::numeric field_element;
typedef std::set<multinomial> ideal;

multinomial lead_term(const multinomial& p);

monomial leading_monomial(const multinomial&);

multinomial rem(const multinomial&, const multinomial&);

multinomial reduce(const multinomial&, const ideal&);

multinomial s_polynomial(const multinomial&, const multinomial&);

void buchbergers_algorithm(ideal&, bool monomial_ordering(const monomial&, const monomial&));
