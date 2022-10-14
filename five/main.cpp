#include "map.hpp"

int main() {
	ft::map<int, std::string>	fMap;
	fMap.insert(ft::make_pair(5, "Elo"));
	fMap.insert(ft::make_pair(8, "Ju"));
	fMap.insert(ft::make_pair(10, "Mir"));
	fMap.insert(ft::make_pair(11, "Na"));
	fMap.erase(fMap.begin(), fMap.end());
	for (ft::map<int, std::string>::iterator it = fMap.begin(); it != fMap.end(); it++)
		std::cout << it->first << std::endl;
	std::cout << "end of map\n";
	std::cout << fMap.size() << std::endl;
//	fMap.printmap();
//	for (ft::map<int, std::string>::iterator it = --(--(--fMap.end())); it != fMap.end(); it++) {
//		std::cout << it->first << std::endl;
//	}
//	fMap.erase(--(--fMap.end()));
//	fMap.printmap();
	/*
	fMap.erase(--(--(--fMap.end())), fMap.end());
	std::cout << fMap.size() << std::endl;
	std::cout << "print map : \n";
	for (ft::map<int, std::string>::iterator it = fMap.begin(); it != fMap.end(); it++)
		std::cout << it->first << std::endl;
	std::cout << "end of map\n";
//	fMap.printmap();
//	*/
	return 0;

}
