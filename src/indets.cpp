#include "indets.hpp"

indet_lst indets(const multinomial& p)
{
    indets_visitor v;
    p.traverse(v);
    return v.get_result();
}
