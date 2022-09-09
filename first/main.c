#include <iostream>
#include "vector.hpp"
#include <vector>

int	main(void) {
	try {
		ft::vector<std::string> t;
		t.reserve(10);
		std::cout << "out: " << t.capacity() << "." << std::endl;
		std::cout << "out: " << t.size() << "." << std::endl;
		std::cout << "out: " << t.empty() << "." << std::endl;
		std::cout << "out: " << t.max_size() << "." << std::endl;
		ft::vector<std::string>	v(5);
		std::cout << "out: " << v.capacity() << "." << std::endl;
		std::cout << "out: " << v.size() << "." << std::endl;
		std::cout << "out: " << v.empty() << "." << std::endl;
		std::fill(v.begin(), v.end(), "yo");
		ft::vector<std::string> u = v;
		for (int i = 0; i < 5; i++) {
			std::cout << "out: " << u.at(i) << "." << std::endl;
		}
		ft::vector<std::string>	w(v.begin(), v.end());
		for (int i = 0; i < 5; i++) {
			std::cout << "out: " << w.at(i) << "." << std::endl;
		}
//		ft::vector<int>	x(100, 1);
//		for (int i = 0; i < 100; i++) {
//			std::cout << "out: " << x.at(i) << "." << std::endl;
//		}
//		ft::vector<std::string>	v(5);
		ft::vector<std::string>::iterator it = v.begin();
		*it = "lu";
		for (int i = 0; i < 5; i++) {
			std::cout << "out: " << w.at(i) << "." << std::endl;
		}
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		std::vector<std::string>	v;
//		std::vector<std::string>	v(5);
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
