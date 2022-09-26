#include "map.hpp"

int main() {
	ft::MapIt<int, char>	bestHeight(std::make_pair<int, char>(1, 'a'));
	bestHeight.insert(std::make_pair<int, char>(4, 'd'));
	bestHeight.insert(std::make_pair<int, char>(5, 'e'));
	bestHeight.insert(std::make_pair<int, char>(6, 'f'));
	bestHeight.insert(std::make_pair<int, char>(2, 'b'));
	bestHeight.insert(std::make_pair<int, char>(3, 'c'));
	bestHeight.print();
	ft::map<int, char>	testMap(bestHeight.find(1), bestHeight.find(6));
	for (ft::map<int, char>::iterator it = testMap.begin(); it.base() != testMap.end().base(); it++) {
		std::cout << "it = " << it[it->first] << std::endl;
		it.print();
	}
	std::cout << "end loop\n";
	testMap.insert(std::make_pair<int, char>(7, 'g'));
	for (ft::map<int, char>::iterator it = testMap.begin(); it.base() != testMap.end().base(); it++) {
		std::cout << "it = " << it->second << std::endl;
		it.print();
	}
	testMap.insert(std::make_pair<int, char>(8, 'h'));
	for (ft::map<int, char>::iterator it = testMap.begin(); it.base() != testMap.end().base(); it++) {
		std::cout << "it = " << it->second << std::endl;
		it.print();
	}
	testMap.insert(std::make_pair<int, char>(9, 'i'));
	testMap.print();
//	std::cout << bestHeight.find(bestHeight.minValueKey(bestHeight.base()))->second << std::endl;
//	std::cout << testMap.begin()->second << std::endl;
//	ft::map<int, char>::iterator last = testMap.end();
//	std::cout << "addr last =  " << testMap.find(5).base() << std::endl;
//	std::cout << "addr end = " << testMap.end().base() << std::endl;
//	std::cout << testMap.end().base() << std::endl;
/*
	std::cout << last.base() << std::endl;
	--last;
	std::cout << last.base() << std::endl;
	--last;
	std::cout << last.base() << std::endl;
	std::cout << testMap.end().base() << std::endl;
	--last;
	std::cout << "end has been called = " << last.base() << std::endl;
	--last;
	std::cout << "end has been decremented" << std::endl;
	std::cout << last->first << std::endl;
	*/
//	bestHeight.print();
/*	std::cout << "wait for it \n";
	ft::MapIt<int, char>	begin = bestHeight.find(1);
	std::cout << begin->second << std::endl;
	begin.print();
	begin++;
	std::cout << begin->second << std::endl;
	begin.print();
	begin++;
	std::cout << begin->second << std::endl;
	begin.print();
	begin++;
	std::cout << begin->second << std::endl;
	begin.print();
	std::cout << "succes \n";
	ft::MapIt<int, char>	end = bestHeight.find(6);
	std::cout << end->second << std::endl;
	std::cout << "let's create a map" << std::endl;
	ft::map<int, char>	testMap(begin, end);
	std::cout << "let's print" << std::endl;
	std::cout << testMap.begin()->second << std::endl;
	testMap.begin().print();
//	ft::map<int, char>	testMap;
	std::cout << "let's insert" << std::endl;
	testMap.insert(begin, end);
	testMap.begin().print();
	std::cout << testMap.begin()->second << std::endl;
	std::cout << testMap.end()->second << std::endl;
	std::cout << testMap.empty() << std::endl;
	std::cout << testMap.size() << std::endl;
	std::cout << testMap.max_size() << std::endl;
	ft::MapIt<int, char>	res = bestHeight.find(3);
	std::cout << res->second << std::endl;
	std::cout << testMap.begin()->second << std::endl;
	*/
//	testMap.erase(testMap.begin(), res);
//	std::cout << testMap[3] << std::endl;
	return 0;
}
