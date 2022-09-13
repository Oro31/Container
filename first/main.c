#include <iostream>
#include "vector.hpp"
#include <vector>

int	main(void) {
	//ft
	try {
		std::cout << "ft:" << std::endl;
		//default constructor
		std::cout << "default constructor\n";
		std::cout << "ft::vector<std::string> t;" << std::endl;
		ft::vector<std::string> t;
//		std::cout << "out: t.front() = " << t.front() << "." << std::endl;
//		std::cout << "out: t.back() = " << t.back() << "." << std::endl;
		std::cout << "out: t.capacity() = " << t.capacity() << "." << std::endl;
		std::cout << "out: t.size() = " << t.size() << "." << std::endl;
		std::cout << "out: t.empty() = " << t.empty() << "." << std::endl;
		std::cout << "out: t.max_size() = " << t.max_size() << "." << std::endl;
//		std::string	str = "salut";
		//reserve
		std::cout << "reserve\n";
		std::cout << "t.reserve(10);" << std::endl;
		t.reserve(10);
		std::cout << "out: t.front() = " << t.front() << "." << std::endl;
		std::cout << "out: t.back() = " << t.back() << "." << std::endl;
		std::cout << "out: t.capacity() = " << t.capacity() << "." << std::endl;
		std::cout << "out: t.size() = " << t.size() << "." << std::endl;
		std::cout << "out: t.empty() = " << t.empty() << "." << std::endl;
		std::cout << "out: t.max_size() = " << t.max_size() << "." << std::endl;
		//assign
		std::cout << "assign\n";
		std::cout << "t.assign(10, ''salut'');" << std::endl;
		t.assign(10, "salut");
		std::cout << "out: t.front() = " << t.front() << "." << std::endl;
		std::cout << "out: t.back() = " << t.back() << "." << std::endl;
		std::cout << "out: t.capacity() = " << t.capacity() << "." << std::endl;
		std::cout << "out: t.size() = " << t.size() << "." << std::endl;
		std::cout << "out: t.empty() = " << t.empty() << "." << std::endl;
		std::cout << "out: t.max_size() = " << t.max_size() << "." << std::endl;
		//push back
		std::cout << "push back" << std::endl;
		std::cout << "t.push_back(''bon dia'');" << std::endl;
		t.push_back("bon dia");
		std::cout << "out: t.front() = " << t.front() << "." << std::endl;
		std::cout << "out: t.back() = " << t.back() << "." << std::endl;
		std::cout << "out: t.capacity() = " << t.capacity() << "." << std::endl;
		std::cout << "out: t.size() = " << t.size() << "." << std::endl;
		std::cout << "out: t.empty() = " << t.empty() << "." << std::endl;
		std::cout << "out: t.max_size() = " << t.max_size() << "." << std::endl;
		//pop back
		std::cout << "pop back" << std::endl;
		std::cout << "t.pop_back();" << std::endl;
		t.pop_back();
		std::cout << "out: t.front() = " << t.front() << "." << std::endl;
		std::cout << "out: t.back() = " << t.back() << "." << std::endl;
		std::cout << "out: t.capacity() = " << t.capacity() << "." << std::endl;
		std::cout << "out: t.size() = " << t.size() << "." << std::endl;
		std::cout << "out: t.empty() = " << t.empty() << "." << std::endl;
		std::cout << "out: t.max_size() = " << t.max_size() << "." << std::endl;
		//insert
		std::cout << "insert\n";
		std::cout << "t.insert((t.begin() + 2), ''guten tag'');" << std::endl;
		t.insert((t.begin() + 2), "guten tag");
		std::cout << "out: t.at(0) = " << t.at(0) << "." << std::endl;
		std::cout << "out: t.at(1) = " << t.at(1) << "." << std::endl;
		std::cout << "out: t.at(2) = " << t.at(2) << "." << std::endl;
		std::cout << "out: t.at(3) = " << t.at(3) << "." << std::endl;
		std::cout << "out: t.front() = " << t.front() << "." << std::endl;
		std::cout << "out: t.back()  = " << t.back() << "." << std::endl;
		std::cout << "out: t.capacity() = " << t.capacity() << "." << std::endl;
		std::cout << "out: t.size() = " << t.size() << "." << std::endl;
		std::cout << "out: t.empty() = " << t.empty() << "." << std::endl;
		std::cout << "out: t.max_size() = " << t.max_size() << "." << std::endl;
		//resize
		std::cout << "resize\n"
			<< "t.resize(3);" << std::endl;
		t.resize(3);
		std::cout << "out: t.front() = " << t.front() << "." << std::endl;
		std::cout << "out: t.back()  = " << t.back() << "." << std::endl;
		std::cout << "out: t.capacity() = " << t.capacity() << "." << std::endl;
		std::cout << "out: t.size() = " << t.size() << "." << std::endl;
		std::cout << "out: t.capacity() = " << t.capacity() << "." << std::endl;
		std::cout << "out: t.size() = " << t.size() << "." << std::endl;
		std::cout << "out: t.empty() = " << t.empty() << "." << std::endl;
		std::cout << "out: t.max_size() = " << t.max_size() << "." << std::endl;
		//default value of size n constructor
		std::cout << "default value and size n constructor\n"
			<< "ft::vector<std::string>	v(5);" << std::endl;
		ft::vector<std::string>	v(5);
		//assign with InputIt
		std::cout << "assign" << std::endl;
		v.assign(t.begin(), t.end());
		//assignment operator overload
		std::cout << "assignment operator overload" << std::endl;
		ft::vector<std::string> u = v;
		for (int i = 0; i < u.size(); i++) {
			//at
			std::cout << "at" << std::endl;
			try {
				std::cout << "out: " << u.at(i) << "." << std::endl;
			} catch (const std::exception &e) {
				std::cerr << e.what() << std::endl;
			}
		}
		for (int i = 0; i < u.size(); i++) {
			//acces operator overload
			std::cout << "acces operator overload" << std::endl;
			std::cout << "out: " << u[i] << "." << std::endl;
		}
		std::cout << "fin" << std::endl;
		//constructor with InputIt
		ft::vector<std::string>	w(v.begin(), v.end());
		for (int i = 0; i < 5; i++) {
			std::cout << "out: " << w.at(i) << "." << std::endl;
		}
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		std::cout << "std\n";
		std::cout << "default constructor\n";
		std::cout << "std::vector<std::string> t;" << std::endl;
		std::vector<std::string> t;
//		std::cout << "out: t.front() = " << t.front() << "." << std::endl; (segfault)
//		std::cout << "out: t.back() = " << t.back() << "." << std::endl; (segfault)
		std::cout << "out: t.capacity() = " << t.capacity() << "." << std::endl;
		std::cout << "out: t.size() = " << t.size() << "." << std::endl;
		std::cout << "out: t.empty() = " << t.empty() << "." << std::endl;
		std::cout << "out: t.max_size() = " << t.max_size() << "." << std::endl;
		std::cout << "reserve\n";
		std::cout << "t.reserve(10);" << std::endl;
		t.reserve(10);
		std::cout << "out: t.front() = " << t.front() << "." << std::endl;
		std::cout << "out: t.back() = " << t.back() << "." << std::endl;
		std::cout << "out: t.capacity() = " << t.capacity() << "." << std::endl;
		std::cout << "out: t.size() = " << t.size() << "." << std::endl;
		std::cout << "out: t.empty() = " << t.empty() << "." << std::endl;
		std::cout << "out: t.max_size() = " << t.max_size() << "." << std::endl;
		//assign
		std::cout << "assign\n";
		std::cout << "t.assign(10, ''salut'');" << std::endl;
		t.assign(10, "salut");
		std::cout << "out: t.front() = " << t.front() << "." << std::endl;
		std::cout << "out: t.back() = " << t.back() << "." << std::endl;
		std::cout << "out: t.capacity() = " << t.capacity() << "." << std::endl;
		std::cout << "out: t.size() = " << t.size() << "." << std::endl;
		std::cout << "out: t.empty() = " << t.empty() << "." << std::endl;
		std::cout << "out: t.max_size() = " << t.max_size() << "." << std::endl;
		//push back
		std::cout << "push back" << std::endl;
		std::cout << "t.push_back(''bon dia'');" << std::endl;
		t.push_back("bon dia");
		std::cout << "out: t.front() = " << t.front() << "." << std::endl;
		std::cout << "out: t.back() = " << t.back() << "." << std::endl;
		std::cout << "out: t.capacity() = " << t.capacity() << "." << std::endl;
		std::cout << "out: t.size() = " << t.size() << "." << std::endl;
		std::cout << "out: t.empty() = " << t.empty() << "." << std::endl;
		std::cout << "out: t.max_size() = " << t.max_size() << "." << std::endl;
		//pop back
		std::cout << "pop back" << std::endl;
		std::cout << "t.pop_back();" << std::endl;
		t.pop_back();
		std::cout << "out: t.front() = " << t.front() << "." << std::endl;
		std::cout << "out: t.back() = " << t.back() << "." << std::endl;
		std::cout << "out: t.capacity() = " << t.capacity() << "." << std::endl;
		std::cout << "out: t.size() = " << t.size() << "." << std::endl;
		std::cout << "out: t.empty() = " << t.empty() << "." << std::endl;
		std::cout << "out: t.max_size();" << t.max_size() << "." << std::endl;
		//insert
		std::cout << "insert\n";
		std::cout << "t.insert((t.begin() + 3), ''guten tag'');" << std::endl;
		t.insert((t.begin() + 3), "guten tag");
		std::cout << "out: t.at(0) = " << t.at(0) << "." << std::endl;
		std::cout << "out: t.at(1) = " << t.at(1) << "." << std::endl;
		std::cout << "out: t.at(2) = " << t.at(2) << "." << std::endl;
		std::cout << "out: t.at(3) = " << t.at(3) << "." << std::endl;
		std::cout << "out: t.front() = " << t.front() << "." << std::endl;
		std::cout << "out: t.back()  = " << t.back() << "." << std::endl;
		std::cout << "out: t.capacity() = " << t.capacity() << "." << std::endl;
		std::cout << "out: t.size() = " << t.size() << "." << std::endl;
		std::cout << "out: t.empty() = " << t.empty() << "." << std::endl;
		std::cout << "out: t.max_size() = " << t.max_size() << "." << std::endl;
		//resize
		std::cout << "resize\n"
			<< "t.resize(3);" << std::endl;
		t.resize(3);
		std::cout << "out: t.front() = " << t.front() << "." << std::endl;
		std::cout << "out: t.back()  = " << t.back() << "." << std::endl;
		std::cout << "out: t.capacity() = " << t.capacity() << "." << std::endl;
		std::cout << "out: t.size() = " << t.size() << "." << std::endl;
		std::cout << "out: t.capacity() = " << t.capacity() << "." << std::endl;
		std::cout << "out: t.size() = " << t.size() << "." << std::endl;
		std::cout << "out: t.empty() = " << t.empty() << "." << std::endl;
		std::cout << "out: t.max_size() = " << t.max_size() << "." << std::endl;
		//default value of size n constructor
		std::cout << "default value and size n constructor\n"
			<< "ft::vector<std::string>	v(5);" << std::endl;
		std::vector<std::string>	v(5);
		//assign with InputIt
		std::cout << "assign" << std::endl;
		v.assign(t.begin(), t.end());
		//assignment operator overload
		std::cout << "assignment operator overload" << std::endl;
		std::vector<std::string> u = v;
		for (int i = 0; i < 20; i++) {
			//at
			std::cout << "at" << std::endl;
			try {
				std::cout << "out: " << u.at(i) << "." << std::endl;
			} catch (const std::exception &e) {
				std::cerr << e.what() << std::endl;
			}
		}
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
