#include <iostream>

#if STD
#include <vector>
#define NAMESPACE "std"
	namespace ft = std;
#else
#define NAMESPACE "ft"
#include "vector.hpp"
#endif

template<class T>
void whatAboutVec(ft::vector<T> &t) {
	std::cout << "out: t.capacity() = " << t.capacity() << "." << std::endl;
	std::cout << "out: t.size() = " << t.size() << "." << std::endl;
	std::cout << "out: t.empty() = " << t.empty() << "." << std::endl;
	std::cout << "out: t.max_size() = " << t.max_size() << "." << std::endl;
}

int	main(void) {
	try {
		std::cout << NAMESPACE << std::endl;
		//default constructor
		std::cout << "default constructor\nft::vector<std::string> t;" << std::endl;
		ft::vector<std::string> t;
		whatAboutVec(t);
		std::cout << "out: t.max_size() = " << t.max_size() << "." << std::endl;
//		std::string	str = "salut";
		//reserve
		std::cout << "reserve\nt.reserve(10);" << std::endl;
		t.reserve(10);
		std::cout << "out: t.front() = " << t.front() << "." << std::endl;
		std::cout << "out: t.back() = " << t.back() << "." << std::endl;
		whatAboutVec(t);
		//assign
		std::cout << "assign\nt.assign(10, ''salut'');" << std::endl;
		t.assign(10, "salut");
		std::cout << "out: t.front() = " << t.front() << "." << std::endl;
		std::cout << "out: t.back() = " << t.back() << "." << std::endl;
		whatAboutVec(t);
		std::cout << "out: t.max_size() = " << t.max_size() << "." << std::endl;
		//push back
		std::cout << "push back\nt.push_back(''bon dia'');" << std::endl;
		t.push_back("bon dia");
		std::cout << "out: t.front() = " << t.front() << "." << std::endl;
		std::cout << "out: t.back() = " << t.back() << "." << std::endl;
		whatAboutVec(t);
		std::cout << "out: t.max_size() = " << t.max_size() << "." << std::endl;
		//pop back
		std::cout << "pop back\nt.pop_back();" << std::endl;
		t.pop_back();
		std::cout << "out: t.front() = " << t.front() << "." << std::endl;
		std::cout << "out: t.back() = " << t.back() << "." << std::endl;
		whatAboutVec(t);
		std::cout << "out: t.max_size() = " << t.max_size() << "." << std::endl;
		//insert
		std::cout << "insert\nt.insert((t.begin() + 2), ''guten tag'');" << std::endl;
		t.insert((t.begin() + 2), "guten tag");
		std::cout << "out: t.at(0) = " << t.at(0) << "." << std::endl;
		std::cout << "out: t.at(1) = " << t.at(1) << "." << std::endl;
		std::cout << "out: t.at(2) = " << t.at(2) << "." << std::endl;
		std::cout << "out: t.at(3) = " << t.at(3) << "." << std::endl;
		std::cout << "out: t.front() = " << t.front() << "." << std::endl;
		std::cout << "out: t.back()  = " << t.back() << "." << std::endl;
		whatAboutVec(t);
		std::cout << "out: t.max_size() = " << t.max_size() << "." << std::endl;
		//resize
		std::cout << "resize\nt.resize(3);" << std::endl;
		t.resize(3);
		std::cout << "out: t.front() = " << t.front() << "." << std::endl;
		std::cout << "out: t.back()  = " << t.back() << "." << std::endl;
		whatAboutVec(t);
		std::cout << "out: t.max_size() = " << t.max_size() << "." << std::endl;
		//default value of size n constructor
		std::cout << "default value and size n constructor\n"
			<< "ft::vector<std::string>	v(5);" << std::endl;
		ft::vector<std::string>	v(5);
		whatAboutVec(v);
		//assign with InputIt
		std::cout << "assign\nt.assign(t.begin(), t.end())" << std::endl;
		v.assign(t.begin(), t.end());
		whatAboutVec(v);
		//assignment operator overload
		std::cout << "assignment operator overload\nft::vector<std::string> u = v;" << std::endl;
		ft::vector<std::string> u = v;
		whatAboutVec(u);
		std::cout << "at" << std::endl;
		std::cout << "u.at(i); (i < w.size())" << std::endl;
		for (int i = 0; i < u.size(); i++) {
			//at
			try {
				std::cout << "out: " << u.at(i) << "." << std::endl;
			} catch (const std::exception &e) {
				std::cerr << e.what() << std::endl;
			}
		}
		std::cout << "acces operator overload" << std::endl;
		std::cout << "u[i]; (i < u.size())" << std::endl;
		for (int i = 0; i < u.size(); i++) {
			//acces operator overload
			std::cout << "out: " << u[i] << "." << std::endl;
		}
		//constructor with InputIt
		std::cout << "constructor with InputIt\nft::vector<std::string>	w(v.begin(), v.end());" << std::endl;
		ft::vector<std::string>	w(v.begin(), v.end());
		whatAboutVec(w);
		std::cout << "w.at(i); (i < w.size())" << std::endl;
		for (int i = 0; i < w.size(); i++) {
			std::cout << "out: " << w.at(i) << "." << std::endl;
		}
		std::cout << "fin" << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}
