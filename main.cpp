#include <iostream>
#include <string>
#include "GroebnerConfig.hpp"
#include "src/ideal.hpp"

using std::cout;
using std::endl;

int main(int argc, char* argv[]){
	// report version
	cout << "Groebner basis calculator version " << Groebner_VERSION_MAJOR << "."
						<< Groebner_VERSION_MINOR << endl;
	cout << "BEWARE: In C++ 2*x^2 means (2*x)^2 so ALWAYS use parentheses around powers 2*(x^2)." << endl;
	cout << "BEWARE: Do not input unexpanded forms e.g. (x+y)^4" << endl;

	return 0;
}
