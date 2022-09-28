#include "map.hpp"
#include <list>

using namespace ft;

int main() {
	std::list<pair<int, int> > lst;
    unsigned int lst_size = 7;
    for (unsigned int i = 0; i < lst_size; ++i) {
        lst.push_back(pair<int, int>((lst_size - i), i));
        std::cout << lst_size - i << '\n';
    }

    map<int, int> mplst(lst.begin(), lst.end());
    map<int, int>::iterator itlst = mplst.begin(), itelst = mplst.end();

    std::cout << "\t-- TEEEEST --" << std::endl;
    std::cout << "end = " << (--(--itelst))->first << '\n';
//    std::cout << "end = " << (--(--itelst))->first << '\n';
    ++(++itelst);
	std::cout << "ca va crahser\n";
    map<int, int> mp_rangelst(itlst, --(--itelst));
    std::cout << "\t-- TEEEEST --" << std::endl;
    for (map<int, int>::iterator it = mp_rangelst.begin(); it != mp_rangelst.end(); it++)
        std::cout << it->second << ", ";

    for (int i = 0; itlst != itelst; itlst++)
        itlst->second = ++i * 5;
	return 0;
}
