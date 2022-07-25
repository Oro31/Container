#include <iostream>
#include <iterator>

class MyIterator : public std::iterator<std::random_acces_iterator_tag, T, Distance = std::ptrdiff_t, Pointer = T*, Reference = T&> {
		T	*p;
	public:
		MyIterator(T *x) : p(x) {}
		MyIterator(const MyIterator &mit) : p(mit.p) {}
		MyIterator	&operator++() {++p; return *this;}
		MyIterator	operator++(int) {
			MyIterator tmp(*this); ++(*this); return tmp;
		}
		bool	operator==(const MyIterator &rhs) const {return p==rhs.p;}
		bool	operator!=(const MyIterator &rhs) const {return !(*this == rhs);}
		T		&operator*() {return *p;}
}
