#include <iostream>

#include "GroebnerConfig.h"
#include "src/multinomial.h"

int main(int argc, char* argv[]){
	if (argc < 2) {
	// report version
	std::cout << argv[0] << " Version " << Groebner_VERSION_MAJOR << "."
						<< Groebner_VERSION_MINOR << std::endl;
	std::cout << "Usage: " << argv[0] << " number" << std::endl;
	return 1;
}

	GiNaC::symbol x("x"), y("y");
	GiNaC::ex poly;

	for (int i=0; i<3; ++i)
			poly += GiNaC::factorial(i+16)*GiNaC::pow(x,i)*GiNaC::pow(y,2-i);

	std::cout << poly << std::endl;
	return 0;
}
