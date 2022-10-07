#include "../newMap.hpp"

int main() {
	ft::map<int, char>	t;
	std::cout << "\tstep insert\n";
	std::cout << t.insert(ft::make_pair<int, char>(5, 'E')).second;
	std::cout << "\tstep\n";
	std::cout << t.insert(ft::make_pair<int, char>(1, 'A')).second;
	std::cout << "\tstep\n";
	std::cout << t.insert(ft::make_pair<int, char>(11, 'K')).second;
	std::cout << "\tstep\n";
	std::cout << t.insert(ft::make_pair<int, char>(25, 'O')).second;
	std::cout << "\tstep\n";
	std::cout << t.insert(ft::make_pair<int, char>(51, 'Z')).second;
	std::cout << "\tstep\n";
	std::cout << t.insert(ft::make_pair<int, char>(50, 'W')).second;
	std::cout << "\tstep\n";
	std::cout << t.insert(ft::make_pair<int, char>(-1, 'z')).second;
	std::cout << "\tstep\n";
	std::cout << t.insert(ft::make_pair<int, char>(12, 'L')).second;
	std::cout << "\tstep acces\n";
	std::cout << t.count(11) << std::endl;
	std::cout << "\tstep\n";
	std::cout << t[11] << std::endl;
	std::cout << "\tstep\n";
	t.printmap();
	std::cout << "\tstep\n";
	std::cout << t.size();
	std::cout << "\tstep iter construct\n";
	std::cout << t.end().base();
	std::cout << "\tstep\n";
	ft::map<int, char>	m(t.begin(), t.end());
	std::cout << "\tstep\n";
	m.printmap();
	std::cout << "\tstep\n";
	ft::map<int, char>	v;
	std::cout << "\tstep iter insert\n";
	v.insert(m.begin(), m.end());
	std::cout << "\tstep\n";
	v.printmap();
	std::cout << "\tstep\n";
	for (ft::map<int, char>::iterator it = (--v.end()); it != v.begin(); it--) {
		std::cout << it->first << std::endl;
	}
	std::cout << "\tstep erase\n";
	ft::map<int, char>::iterator	itb = v.begin();
	ft::map<int, char>::iterator	ite = v.end();
	std::cout << "\tstep\n";
	v.erase(itb, ite);
	std::cout << "\tstep\n";
	v.printmap();
	std::cout << "\tstep insert\n";
	std::cout << v.insert(ft::make_pair<int, char>(5, 'E')).second;
	std::cout << "\tstep insert\n";
	std::cout << v.insert(ft::make_pair<int, char>(15, 'P')).second;
	std::cout << "\tstep\n";
	v.printmap();
	return 0;
}
