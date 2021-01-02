#pragma once

#include <unordered_set>

#include "multinomial.hpp"

typedef GiNaC::symbol indeterminate;

// Define a type to hold a set of indets, sorted
typedef GiNaC::lst indet_lst;
class indets_visitor : public multinomial, public GiNaC::visitor, public indeterminate::visitor
{
public:
  const indet_lst& get_result() {
        l.sort();
        l.unique(); // removes consecutive equal elements => sort first
        return l;}

private:
  indet_lst l;

  void visit(const indeterminate& i){
    l.append(i);
  }
};

indet_lst indets(const multinomial&);
