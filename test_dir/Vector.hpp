#include <memory>
#include "ft_reverse_iterator.hpp"
#include "ft_iterator_traits.hpp"

namespace ft {
	template <class T, class Allocator = std::allocator<T>>
	class Vector {
			class MyIterator {
				public:
					typedef T	value_type;
					typedef T	*pointer;
					typedef T	&reference;
					typedef std::ptrdiff_t	difference_type;
					typedef std::random_acces_iterator_tag	iterator_category;

					MyIterator() : v(nullptr), i(0) {};
					MyIterator(Vector<T> *v, int i) : v(v), i(i) {};

					reference operator*() {return (*v)[i];};
					const reference operator*() const {return (*v)[i];};
					pointer operator->() {return &((*v)[i]);};
					const pointer operator->() const {return &((*v)[i]);};
					reference operator[](int m) {return (*v)[i + m];};
					const reference operator[](int m) const {return (*v)[i];};

					MyIterator &operator++() {++i; return *this;};
					MyIterator &operator--() {--i; return *this;};
					MyIterator operator++(int) {MyIterator r(*this); ++i; return r;};
					MyIterator operator--(int) {MyIterator r(*this); --i; return r;};

					MyIterator &operator+=(int n) {i += n; return *this;};
					MyIterator &operator-=(int n) {i -= n; return *this;};

					MyIterator operator+(int n) const {MyIterator r(*this); return r += n;};
					MyIterator operator-(int n) const {MyIterator r(*this); return r -= n;};

					difference_type operator-(MyIterator const &r) const {return i - r.i;};
					bool operator<(MyIterator const &r) const {return i < r.i;};
					bool operator<=(MyIterator const &r) const {return i <= r.i;};
					bool operator>(MyIterator const &r) const {return i > r.i;};
					bool operator>=(MyIterator const &r) const {return i >= r.i;};
					bool operator!=(const MyIterator &r) const {return i != r.i;};
					bool operator==(const MyIterator &r) const {return i == r.i;};

				private:
					Vector<T>	*v;
					int			i;
			};

		public:
			typedef T											value_type;
			typedef Allocator									allocator_type;
			typedef value_type									&reference;
			typedef const value_type							&const_reference;
			typedef value_type									*pointer;
			typedef const value_type							*const_pointer;
			typedef MyIterator									iterator;
			typedef const MyIterator							const_iterator;
			typedef ft::reverse_iterator<iterator>				reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;
			typedef std::ptrdiff_t								difference_type;
			typedef std::size_t									size_type;

		protected:
			Allocator	the_allocator;

		private:
			size_type	buffer_size;
			iterator	buffer_start;
			iterator	current_end;
			iterator	end_of_buffer;

		public:
			iterator	begin() {return buffer_start;}}
			iterator	end() {return current_end;}}
	};

}
