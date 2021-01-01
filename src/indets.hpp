#pragma once

#include "multinomial.hpp"

class indets_visitor : public multinomial, public GiNaC::visitor, public indeterminate::visitor
{
public:
  const variable_container& get_result() const {return l;}

private:
   variable_container l;

    void visit(const indeterminate& i)
    {
        l.insert(i);
    }
};

variable_container indets(const multinomial& p)
{
    indets_visitor v;
    p.traverse(v);
    return v.get_result();
}
