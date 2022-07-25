#include <iostream>
#include <algorithm>
#include <ft_reverse_iterator.hpp>

namespace ft {
	reverse_iterator<Iter>::reverse_iterator() {

	}

	template<class U>
	reverse_iterator	&operator=(const reverse_iterator<U> &other) {
		return *this;
	}
}
