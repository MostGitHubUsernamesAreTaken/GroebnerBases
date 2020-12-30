#pragma once

#include <set>
#include "multinomial.hpp"

typedef std::set<multinomial> ideal;

void buchbergers_algorithm(ideal&, bool monomial_ordering(const monomial&, const monomial&) = lexicographical);
