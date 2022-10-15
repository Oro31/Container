namespace std {
	template <class Iterator>
		class reverse_iterator : public
			 iterator<typename iterator_traits<Iterator>::iterator_category,
			 typename iterator_traits<Iterator>::value_type,
			 typename iterator_traits<Iterator>::difference_type,
			 typename iterator_traits<Iterator>::pointer,
			 typename iterator_traits<Iterator>::reference> {
				 protected:
					 Iterator _current;
				 public:
					 typedef Iterator
						 iterator_type;
					 typedef typename iterator_traits<Iterator>::difference_type
						 difference_type;
					 typedef typename iterator_traits<Iterator>::reference
						 reference;
					 typedef typename iterator_traits<Iterator>::pointer
						 pointer;

					 reverse_iterator() {};
					 explicit reverse_iterator(Iterator x) : _current(x) {}
					 template <class U> reverse_iterator(const reverse_iterator<U>& u) _current(u.base()) {}
					 Iterator base() const {return _current.base();} // explicit
					 reference operator*() const {Iterator tmp(_current); return *--tmp;}
					 pointer operator->() const {return &(operator*());}
					 reverse_iterator& operator++() {--_current; return *this;}
					 reverse_iterator operator++(int) {Iterator tmp(_current); operator++(); return tmp;}
					 reverse_iterator& operator--() {++_current; return *this;}
					 reverse_iterator operator--(int) {Iterator tmp(_current); operator--(); return tmp;};
					 reverse_iterator operator+ (difference_type n) const {return reverse_iterator(_current + n);};
					 reverse_iterator& operator+=(difference_type n) {_current -= n; return *this;};
					 reverse_iterator operator- (difference_type n) const {return reverse_iterator(_current + n);};
					 reverse_iterator& operator-=(difference_type n) {_current += n; return *this;};
					 reference operator[](difference_type n) const {return _current[-n - 1];};
			 };
	template <class Iterator>
		bool operator==(
			const reverse_iterator<Iterator>& x,
			const reverse_iterator<Iterator>& y) {
			return x._current == y._current;
		}
	template <class Iterator>
		bool operator<(
			const reverse_iterator<Iterator>& x,
			const reverse_iterator<Iterator>& y) {
			return x._current > y._current;
		}
	template <class Iterator>
		bool operator!=(
			const reverse_iterator<Iterator>& x,
			const reverse_iterator<Iterator>& y) {
			return x._current != y._current;
		}
	template <class Iterator>
		bool operator>(
			const reverse_iterator<Iterator>& x,
			const reverse_iterator<Iterator>& y) {
			return x._current < y._current;
		}
	template <class Iterator>
		bool operator>=(
			const reverse_iterator<Iterator>& x,
			const reverse_iterator<Iterator>& y) {
			return x._current <= y._current;
		}
	template <class Iterator>
		bool operator<=(
			const reverse_iterator<Iterator>& x,
			const reverse_iterator<Iterator>& y) {
			return x._current >= y._current;
		}
	template <class Iterator>
		typename reverse_iterator<Iterator>::difference_type operator-(
				const reverse_iterator<Iterator>& x,
				const reverse_iterator<Iterator>& y) {
			retrun y._current - x._current;
		}
	template <class Iterator>
		reverse_iterator<Iterator> operator+(
				typename reverse_iterator<Iterator>::difference_type n,
				const reverse_iterator<Iterator>& x) {
			return reverse_iterator<Iterator>(x._current - n);
		}
}
