#include "map.hpp"

using namespace ft;

int main() {
	std::cout << "guten tag" << std::endl;
	map<int, char> bestHeight;
	bestHeight.insert(make_pair<int, char>(1, 'a'));
	bestHeight.insert(make_pair<int, char>(4, 'd'));
	bestHeight.insert(make_pair<int, char>(5, 'e'));
	bestHeight.insert(make_pair<int, char>(6, 'f'));
	bestHeight.insert(make_pair<int, char>(2, 'b'));
	bestHeight.insert(make_pair<int, char>(3, 'c'));
	std::cout << "before erase: \n";
	bestHeight.print();
	bestHeight.clear();
	std::cout << "after erase: \n";
	bestHeight.print();
//	bestHeight.erase((--bestHeight.end()), bestHeight.end());
//	std::cout << "after it erase: \n";
//	std::cout << "\tsize = " << bestHeight.size() << std::endl;
//	bestHeight.print();
	/*
	bestHeight.clear();
	std::cout << "after clear: \n";
	bestHeight.print();
	*/
	return 0;
}
