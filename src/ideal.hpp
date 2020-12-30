#pragma once

#include "multinomial.hpp"

class ideal{

};




void buchbergers_algorithm(ideal&, bool monomial_ordering(const monomial&, const monomial&) = lexicographical);
