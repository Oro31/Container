#include <memory>

namespace ft {
	template<class Key, class T>
	class MapIterator {
		public:
			typedef pair<const Key, T>				value_type;
			typedef value_type						*pointer;
			typedef value_type						&reference;
			typedef std::ptrdiff_t					difference_type;
			typedef std::bidirectional_iterator_tag	iterator_category;

			MapIterator() : p(0) {};
			explicit MapIterator(pointer x) : p(x) {};
			~MapIterator() {};

			MapIterator &operator=(const pointer it) {p = it; return *this;};
			MapIterator &operator=(const MapIterator &mit) {p = mit.p; return *this;};
			MapIterator(const MapIterator &mit) {*this = mit;};

			reference operator*() {return *p;};
			pointer operator->() {return p;};
			const pointer operator->() const {return p;};
			pointer base() {return p;};
			const pointer base() const {return p;};


			MapIterator &operator++() {p++; return *this;};
			MapIterator &operator--() {p--; return *this;};
			MapIterator operator++(int) {MapIterator tmp(*this); p++; return tmp;};
			MapIterator operator--(int) {MapIterator tmp(*this); p--; return tmp;};

			MapIterator &operator+=(int n) {for (int i = 0; i < n; i++) {p++;} return *this;};
			MapIterator &operator-=(int n) {for (int i = 0; i < n; i++) {p--;} return *this;};
			reference operator[](size_t n) {return *(p + n);};

			MapIterator operator+(int n) const {MapIterator r(*this); r+=n; return r;};
			MapIterator operator-(int n) const {MapIterator r(*this); r-=n; return r;};
			difference_type operator-(MapIterator const &second) const {
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
