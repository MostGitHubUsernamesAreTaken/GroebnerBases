#pragma once
#include <set>
#include <string>
// #include <cstddef>

#include "indets.hpp"

// as with multinomial, use a typedef for first version
typedef multinomial monomial;

bool is_monomial(const multinomial&);

struct lexicographical_compare final
{
  bool operator() (const indeterminate& left, const indeterminate& right) const
  {
    return left.get_name() < right.get_name();
  }
};

typedef std::set<indeterminate, lexicographical_compare> indet_set;

indet_set find_indet_set(const multinomial&);

bool lexicographical(const monomial&, const monomial&);

// bool degree_reverse_lexicographical(const monomial&, const monomial&);
