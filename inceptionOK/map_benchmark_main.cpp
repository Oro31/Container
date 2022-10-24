#include "vector.hpp"
#include "map.hpp"
#include "stack.hpp"
#include <vector>
#include <iostream>
#include <iterator>
#include <map>

using namespace ft;

int main()
{

    // empty map container
    map<int, int> gquiz1;

    // insert elements in random order
    gquiz1.insert(pair<int, int>(1, 40));
    gquiz1.insert(pair<int, int>(21, 40));
    gquiz1.insert(pair<int, int>(39, 40));
    gquiz1.insert(pair<int, int>(38, 40));
    gquiz1.insert(pair<int, int>(37, 40));
    gquiz1.insert(pair<int, int>(36, 40));
    gquiz1.insert(pair<int, int>(35, 40));
    gquiz1.insert(pair<int, int>(34, 40));
    gquiz1.insert(pair<int, int>(33, 40));
    gquiz1.insert(pair<int, int>(32, 40));
    gquiz1.insert(pair<int, int>(31, 40));
    gquiz1.insert(pair<int, int>(30, 40));
    gquiz1.insert(pair<int, int>(29, 40));
    gquiz1.insert(pair<int, int>(28, 40));
    gquiz1.insert(pair<int, int>(27, 40));
    gquiz1.insert(pair<int, int>(26, 40));
    gquiz1.insert(pair<int, int>(25, 40));
    gquiz1.insert(pair<int, int>(24, 40));
    gquiz1.insert(pair<int, int>(23, 40));
    gquiz1.insert(pair<int, int>(22, 40));
    gquiz1.insert(pair<int, int>(20, 40));
    gquiz1.insert(pair<int, int>(19, 40));
    gquiz1.insert(pair<int, int>(18, 40));
    gquiz1.insert(pair<int, int>(17, 40));
    gquiz1.insert(pair<int, int>(16, 40));
    gquiz1.insert(pair<int, int>(15, 40));
    gquiz1.insert(pair<int, int>(14, 40));
    gquiz1.insert(pair<int, int>(13, 40));
    gquiz1.insert(pair<int, int>(12, 40));
    gquiz1.insert(pair<int, int>(11, 40));
    gquiz1.insert(pair<int, int>(10, 40));
    gquiz1.insert(pair<int, int>(9, 40));
    gquiz1.insert(pair<int, int>(8, 40));
    gquiz1.insert(pair<int, int>(2, 30));
    gquiz1.insert(pair<int, int>(3, 60));
    gquiz1.insert(pair<int, int>(4, 20));
    gquiz1.insert(pair<int, int>(5, 50));
    gquiz1.insert(pair<int, int>(6, 50));

      gquiz1[7]=10;     // another way of inserting a value in a map

	  for (int i = 40; i < 100000; ++i) {
		gquiz1.insert(pair<int, int>(i, i + 5));
	  }

    // printing map gquiz1
    map<int, int>::iterator itr;
    std::cout << "\nThe map gquiz1 is : \n";
    std::cout << "\tKEY\tELEMENT\n";
    for (itr = gquiz1.begin(); itr != gquiz1.end(); ++itr) {
        std::cout << '\t' << itr->first << '\t' << itr->second
             << '\n';
    }
    std::cout << std::endl;

    // assigning the elements from gquiz1 to gquiz2
    map<int, int> gquiz2(gquiz1.begin(), gquiz1.end());

    // print all elements of the map gquiz2
    std::cout << "\nThe map gquiz2 after"
         << " assign from gquiz1 is : \n";
    std::cout << "\tKEY\tELEMENT\n";
    for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) {
        std::cout << '\t' << itr->first << '\t' << itr->second
             << '\n';
    }
    std::cout << std::endl;

    // remove all elements up to
    // element with key=3 in gquiz2
    std::cout << "\ngquiz2 after removal of"
            " elements less than key=3 : \n";
    std::cout << "\tKEY\tELEMENT\n";
    gquiz2.erase(gquiz2.begin(), gquiz2.find(3));
    for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) {
        std::cout << '\t' << itr->first << '\t' << itr->second
             << '\n';
    }

    // remove all elements with key = 4
    int num;
    num = gquiz2.erase(4);
    std::cout << "\ngquiz2.erase(4) : ";
    std::cout << num << " removed \n";
    std::cout << "\tKEY\tELEMENT\n";
    for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) {
        std::cout << '\t' << itr->first << '\t' << itr->second
             << '\n';
    }

    std::cout << std::endl;

    // lower bound and upper bound for map gquiz1 key = 5
    std::cout << "gquiz1.lower_bound(5) : "
         << "\tKEY = ";
    std::cout << gquiz1.lower_bound(5)->first << '\t';
    std::cout << "\tELEMENT = " << gquiz1.lower_bound(5)->second
         << std::endl;
    std::cout << "gquiz1.upper_bound(5) : "
         << "\tKEY = ";
    std::cout << gquiz1.upper_bound(5)->first << '\t';
    std::cout << "\tELEMENT = " << gquiz1.upper_bound(5)->second
         << std::endl;

    return 0;
}
