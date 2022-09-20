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
	ft::MapIt<int, char>	end = bestHeight.find(6);
	std::cout << begin->second << end->second;
	std::cout << "let's create a map" << std::endl;
//	ft::map<int, char>	testMap(begin, end);
	ft::map<int, char>	testMap;
	testMap.insert(begin, end);
	std::cout << testMap.begin()->second << std::endl;
	std::cout << testMap.end()->second << std::endl;
	std::cout << testMap.empty() << std::endl;
	std::cout << testMap.size() << std::endl;
	std::cout << testMap.max_size() << std::endl;
	ft::MapIt<int, char>	res = bestHeight.find(3);
	std::cout << res->second << std::endl;
	std::cout << testMap.erase(9) << std::endl;
//	std::cout << testMap[3] << std::endl;
	return 0;
}
