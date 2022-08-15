#include <iostream>
#include "vector.hpp"
#include <vector>

int	main(void) {
	try {
		ft::vector<std::string>	v(5);
		std::fill(v.begin(), v.end(), "yo");
		ft::vector<std::string>::iterator it = v.begin();
		*it = "lu";
		for (ft::vector<std::string>::iterator i = v.begin();
				i != v.end(); ++i) {
			std::cout << "out: " << *i << "." << std::endl;
		}
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		std::vector<std::string>	v(5);
		std::fill(v.begin(), v.end(), "yo");
		std::vector<std::string>::iterator it = v.begin();
		*it = "lu";
		for (std::vector<std::string>::iterator i = v.begin();
				i != v.end(); ++i) {
			std::cout << "out: " << *i << "." << std::endl;
		}
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
