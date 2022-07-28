#include <memory>

namespace ft {
	template <class T1, class T2>
	class pair {
			typedef T1	first_type;
			typedef T2	second_type;

		public:
			first_type	first;
			second_type	second;

			pair() : first(0), second(0) {};
			pair(const T1 &x, const T2 &y) : first(x), second(y) {};
			pair &operator=(const pair &other) {this->first = other.first; this->second = other.second;};
			pair(const pair &p) {*this = p;};
			template<class U1, class U2>
			pair(const pair<U1, U2> &p) {pair(p.first, p.second);};
			pair make_pair(T1 t, T2 u) {return pair(t, u);};
	};

	template<class T1, class T2>
	bool operator==(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	};
	template<class T1, class T2>
	bool operator!=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
		return !(lhs == rhs);
	};
	template <class T1, class T2>
	bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second);
	};
	template <class T1, class T2>
	bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return !(rhs<lhs);
	};
	template <class T1, class T2>
	bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return rhs<lhs;
	};
	template <class T1, class T2>
	bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return !(lhs<rhs);
	};
}
