#include <set>
#include <iostream>

#include "GroebnerConfig.hpp"
#include "src/monomial.hpp"

using std::cout;
using std::endl;

int main(int argc, char* argv[]){
	// report version
	cout << "Groebner basis calculator version " << Groebner_VERSION_MAJOR << "."
						<< Groebner_VERSION_MINOR << endl;
	cout << "BEWARE: In C++ 2*x^2 means (2*x)^2 so ALWAYS use parentheses around powers 2*(x^2)." << endl;

	GiNaC::symbol x("x"), y("y"), z("z");
	GiNaC::ex poly;

	for (int i=0; i<3; ++i)
			poly += GiNaC::factorial(i+16)*GiNaC::pow(x,i)*GiNaC::pow(y,2-i);

	std::cout << poly << std::endl;

	multinomial X = poly;

	cout << X << endl;
	cout << indets(X) << endl;

	multinomial P1 = GiNaC::pow(x, 2) - y;
	multinomial P2 = GiNaC::pow(x, 3) - x + GiNaC::pow(x+y+z, 4);

	indet_lst I1 = indets(P1);
	indet_lst I2 = indets(P2);

	cout << I1 <<" " << I2 << endl;
	cout << is_monomial(P1) << endl;

	lexicographical(x*y*z, pow(x, 2)*y);

	cout <<"some orderings..." << lexicographical(x, y) << endl;
	cout <<"some orderings..." << lexicographical(y, y) << endl;
	cout <<"some orderings..." << lexicographical(y, x) << endl;
	cout <<"some orderings..." << lexicographical(y, pow(z, 2)) << endl;

	indet_set s1 = find_indet_set(P1);
	indet_set s2 = find_indet_set(P2);

	for(auto k : s1)
		cout << k << endl;

	for(auto k : s2)
		cout << k << endl;

	std::cout << x*2 << 2*x << std::endl;
	//
	// std::set<indeterminate> my_set;
	// my_set.insert(x);
	// cout << my_set.size() << endl;

	return 0;
}
