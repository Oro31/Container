#include <iostream>
#include <iterator>

class MyIterator : public std::iterator<std::random_acces_iterator_tag, T, Distance = std::ptrdiff_t, Pointer = T*, Reference = T&> {
		T	*p;
	public:
		MyIterator(T *x) : p(x) {}
		MyIterator(const MyIterator &mit) : p(mit.p) {}
		MyIterator	&operator++() {++p; return *this;}
		MyIterator	operator++(T) {
			MyIterator tmp(*this); operator++(); return tmp;
		}
		bool	operator==(const MyIterator &rhs) const {return p==rhs.p;}
		bool	operator!=(const MyIterator &rhs) const {return p!=rhs.p;}
		T		&operator*() {return *p;}
}
