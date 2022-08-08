#include <iostream>
#include "vector.hpp"

int	main(void) {
	try {
		ft::vector<std::string>	v(5);
		for (ft::vector<std::string>::iterator it = v.begin();
				it != v.end(); it++) {
			std::cout << "out: " << *it << "." << std::endl;
		}
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
