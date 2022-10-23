#include "vector.hpp"
#include <vector>
using namespace ft;
int main(void) {
	vector<std::string>	v;
	v.assign(10, "salut");
	v.insert(++v.begin(), "nono");
	for (vector<std::string>::iterator it = v.begin(); it != v.end(); ++it) {
		std::cout << *it;
	}
	std::cout << std::endl;

	return  0;
	
}
