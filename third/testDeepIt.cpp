#include "map.hpp"

int main() {
	ft::MapIt<int, char>	bestHeight(std::make_pair<int, char>(1, 'a'));
	bestHeight.insert(std::make_pair<int, char>(4, 'd'));
	bestHeight.insert(std::make_pair<int, char>(5, 'e'));
	bestHeight.insert(std::make_pair<int, char>(6, 'f'));
	bestHeight.insert(std::make_pair<int, char>(2, 'b'));
	bestHeight.insert(std::make_pair<int, char>(3, 'c'));
	bestHeight.print();
	ft::MapIt<int, char>	begin = bestHeight.find(1);
	std::cout << "guten tag" << std::endl;
	begin.print();
	return 0;
}
