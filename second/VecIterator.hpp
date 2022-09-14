#include <memory>

namespace ft {
	template<class T>
	class VecIterator {
		public:
			typedef T	value_type;
			typedef value_type	*pointer;
			typedef value_type	&reference;
			typedef std::ptrdiff_t	difference_type;
			typedef std::random_access_iterator_tag	iterator_category;

			VecIterator() : p(0) {};
			explicit VecIterator(pointer x) : p(x) {};
			~VecIterator() {};

			VecIterator &operator=(const pointer it) {p = it; return *this;};
			VecIterator &operator=(const VecIterator &mit) {p = mit.p; return *this;};
			VecIterator(const VecIterator &mit) {*this = mit;};

			reference operator*() {return *p;};
//			const reference operator*() const {return *p;};
			pointer operator->() {return p;};
			const pointer operator->() const {return p;};
			pointer base() {return p;};
			const pointer base() const {return p;};


			VecIterator &operator++() {p++; return *this;};
			VecIterator &operator--() {p--; return *this;};
			VecIterator operator++(int) {VecIterator tmp(*this); p++; return tmp;};
			VecIterator operator--(int) {VecIterator tmp(*this); p--; return tmp;};

			VecIterator &operator+=(int n) {for (int i = 0; i < n; i++) {p++;} return *this;};
			VecIterator &operator-=(int n) {for (int i = 0; i < n; i++) {p--;} return *this;};
			reference operator[](size_t n) {return *(p + n);};

			VecIterator operator+(int n) const {VecIterator r(*this); r+=n; return r;};
			VecIterator operator-(int n) const {VecIterator r(*this); r-=n; return r;};
			difference_type operator-(VecIterator const &second) const {
				return (this->base() - second.base());
			};

			template<class Iterator>
			friend bool operator==(const Iterator &lhs, const Iterator &rhs);
			template<class Iterator>
			friend bool operator!=(const Iterator &lhs, const Iterator &rhs);
			template<class Iterator>
			friend bool operator>(const Iterator &lhs, const Iterator &rhs);
			template<class Iterator>
			friend bool operator>=(const Iterator &lhs, const Iterator &rhs);
			template<class Iterator>
			friend bool operator<(const Iterator &lhs, const Iterator &rhs);
			template<class Iterator>
			friend bool operator<=(const Iterator &lhs, const Iterator &rhs);

		private:
			pointer	p;
	};

	template<class Iterator>
		bool operator==(const Iterator &lhs, const Iterator &rhs) {return lhs.p==rhs.p;};
	template<class Iterator>
		bool operator!=(const Iterator &lhs, const Iterator &rhs) {return lhs.p!=rhs.p;};
	template<class Iterator>
		bool operator>(const Iterator &lhs, const Iterator &rhs) {return lhs.p>rhs.p;};
	template<class Iterator>
		bool operator>=(const Iterator &lhs, const Iterator &rhs) {return lhs.p>=rhs.p;};
	template<class Iterator>
		bool operator<(const Iterator &lhs, const Iterator &rhs) {return lhs.p<rhs.p;};
	template<class Iterator>
		bool operator<=(const Iterator &lhs, const Iterator &rhs) {return lhs.p<=rhs.p;};
}
