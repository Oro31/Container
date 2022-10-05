#include "map.hpp"

int main() {
	ft::map<int, char>	bestHeight;
	std::cout << "\tfrom main: " << "empty map created\n";
	bestHeight.insert(ft::make_pair<int, char>(1, 'a'));
	std::cout << "\tfrom main: " << "inserted one element\n";
	bestHeight.insert(ft::make_pair<int, char>(4, 'd'));
	bestHeight.insert(ft::make_pair<int, char>(5, 'e'));
	bestHeight.insert(ft::make_pair<int, char>(6, 'f'));
	bestHeight.insert(ft::make_pair<int, char>(2, 'b'));
	bestHeight.insert(ft::make_pair<int, char>(3, 'c'));
	bestHeight.print();
	ft::map<int, char>	testMap(bestHeight.begin(), bestHeight.end());
	std::cout << "\tfrom main: " << "inputIt constructor succeed\n";
	ft::map<int, char>	copyMap(testMap);
	std::cout << "\tfrom main: " << "cpoyed map into map\n";
	ft::map<int, char>::iterator	itl = testMap.lower_bound(5);
	ft::map<int, char>::iterator	itu = testMap.upper_bound(5);
	std::cout << "\tfrom main: " << itl->second << itu->second << std::endl;
	for (ft::map<int, char>::iterator it = copyMap.begin(); it.base() != copyMap.end().base(); it++) {
		std::cout << "\tfrom main: " << "it = " << it->second << std::endl;
	}
	std::cout << "\tfrom main: " << "end loop\n";
	for (ft::map<int, char>::iterator it = testMap.begin(); it.base() != testMap.end().base(); it++) {
		std::cout << "\tfrom main: " << "it = " << it[it->first] << std::endl;
	}
	std::cout << "\tfrom main: " << "end loop\n";
	testMap.insert(ft::make_pair<int, char>(7, 'g'));
	for (ft::map<int, char>::iterator it = testMap.begin(); it.base() != testMap.end().base(); it++) {
		std::cout << "\tfrom main: " << "it = " << it->second << std::endl;
	}
	std::cout << "\tfrom main: " << "end loop\n";
	testMap.insert(ft::make_pair<int, char>(8, 'h'));
	for (ft::map<int, char>::iterator it = testMap.begin(); it.base() != testMap.end().base(); it++) {
		std::cout << "from main: " << "it = " << it->second << std::endl;
	}
	std::cout << "from main: " << "end loop\n";
	testMap.insert(ft::make_pair<int, char>(9, 'i'));
	std::cout << "from main: " << testMap.size() << std::endl;
	testMap.print();
	return 0;
}
