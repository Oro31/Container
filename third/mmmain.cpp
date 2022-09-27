#include "map.hpp"
#include <list>

int main() {
	std::list<std::pair<int, int> > lst;
    unsigned int lst_size = 7;
    for (unsigned int i = 0; i < lst_size; ++i) {
        lst.push_back(std::pair<int, int>((lst_size - i), i));
        std::cout << lst_size - i << '\n';
    }

    ft::map<int, int> mplst(lst.begin(), lst.end());
    ft::map<int, int>::iterator itlst = mplst.begin(), itelst = mplst.end();

    std::cout << "\t-- TEEEEST --" << std::endl;
    std::cout << "end = " << (--(--itelst))->first << '\n';
    ++(++itelst);
    ft::map<int, int> mp_rangelst(itlst, --(--itelst));
    std::cout << "\t-- TEEEEST --" << std::endl;

    for (int i = 0; itlst != itelst; itlst++)
        itlst->second = ++i * 5;
	return 0;
}
