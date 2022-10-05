#include "../MapIterator.hpp"

int main() {
	ft::MapIt<ft::pair<int, char>>	bestHeight(ft::make_pair<int, char>(1, 'a'));
	bestHeight.insert(ft::make_pair<int, char>(4, 'd'));
	bestHeight.insert(ft::make_pair<int, char>(-5, 'W'));
	bestHeight.insert(ft::make_pair<int, char>(-2, 'Y'));
	bestHeight.erase(4);
	bestHeight.print();
	return 0;
}
