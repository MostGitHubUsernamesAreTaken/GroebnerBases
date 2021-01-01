#include <iostream>

#include "GroebnerConfig.hpp"
#include "src/ideal.hpp"

using std::cout;
using std::endl;

int main(int argc, char* argv[]){
	// report version
	cout << "Groebner basis calculator version " << Groebner_VERSION_MAJOR << "."
						<< Groebner_VERSION_MINOR << endl;
	cout << "BEWARE: In C++ 2*x^2 means (2*x)^2 so ALWAYS use parentheses around powers 2*(x^2)." << endl;

	GiNaC::symbol x("x"), y("y");
	GiNaC::ex poly;

	for (int i=0; i<3; ++i)
			poly += GiNaC::factorial(i+16)*GiNaC::pow(x,i)*GiNaC::pow(y,2-i);

	std::cout << poly << std::endl;

	std::cout << x*2 << 2*x << std::endl;
	return 0;
}
