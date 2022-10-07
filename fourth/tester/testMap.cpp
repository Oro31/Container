#include "../newMap.hpp"

int main() {
	ft::map<int, char>	t;
	std::cout << "\tstep\n";
	t.printmap();
	t.insert(ft::make_pair<int, char>(5, 'E'));
	std::cout << "\tstep\n";
	t.printmap();
	t.insert(ft::make_pair<int, char>(1, 'A'));
	std::cout << "\tstep\n";
	t.printmap();
	t.insert(ft::make_pair<int, char>(11, 'K'));
	std::cout << "\tstep\n";
	t.printmap();
	t.insert(ft::make_pair<int, char>(25, 'O'));
	std::cout << "\tstep\n";
	t.printmap();
	std::cout << t[11] << std::endl;
	std::cout << "\tstep\n";
	t.printmap();
	std::cout << "\tstep\n";
	std::cout << t.size();
	std::cout << "\tstep\n";
	ft::map<int, char>	m(t.begin(), t.end());
	std::cout << "\tstep\n";
	m.printmap();
	return 0;
}
