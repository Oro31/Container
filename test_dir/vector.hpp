#include <memory>
//#include "ft_reverse_iterator.hpp"
#include "ft_iterator_traits.hpp"

namespace ft {
	template<class T>
	class MyIterator {
		public:
			typedef T	value_type;
			typedef T	*pointer;
			typedef T	&reference;
			typedef std::ptrdiff_t	difference_type;
			typedef std::random_access_iterator_tag	iterator_category;

			MyIterator() : p(0) {};
			MyIterator(T *x) : p(x) {};
			MyIterator(const MyIterator &mit) {*this = mit;};
			MyIterator &operator++() {++p; return *this;};
			MyIterator operator++(int) {MyIterator tmp(*this); operator++(); return tmp;};
			MyIterator operator+(int n) const {MyIterator r(*this); for(int i=0; i<n; i++) {r++;} return r;};
			MyIterator &operator=(const pointer it) {p = it; return *this;};
			bool operator==(const MyIterator &rhs) const {return p==rhs.p;};
			bool operator!=(const MyIterator &rhs) const {return p!=rhs.p;};
			T &operator*() {return *p;};
			const pointer base() const {return p;};

		private:
			pointer	p;
	};

	template <class T, class Allocator = std::allocator<T>>
	class vector {
		public:
			typedef T											value_type;
			typedef Allocator									allocator_type;
			typedef value_type									&reference;
			typedef const value_type							&const_reference;
			typedef value_type									*pointer;
			typedef const value_type							*const_pointer;
			typedef MyIterator<T>								iterator;
			typedef const MyIterator<T>							const_iterator;
			typedef std::reverse_iterator<iterator>				reverse_iterator;
			typedef std::reverse_iterator<const_iterator>		const_reverse_iterator;
			typedef std::ptrdiff_t								difference_type;
			typedef std::size_t									size_type;

		protected:
			Allocator	the_allocator;

		private:
//			size_type	buffer_size;
			iterator	buffer_start;
			iterator	current_end;
			iterator	end_of_buffer;

		public:
			iterator	begin() {return buffer_start;};
			iterator	end() {return current_end;};

			explicit vector(const allocator_type &alloc = allocator_type()) : buffer_start(0),
				current_end(0), end_of_buffer(0) {};
			explicit vector(size_type n, const value_type &val) {
				T	*p = the_allocator.allocate(n * 2);
				iterator	al(p);
				buffer_start = al;
				end_of_buffer = buffer_start;
				for (int i = 0; i < n * 2; i++) {
					end_of_buffer++;
					std::cout << (unsigned long)*end_of_buffer << "\n";
				}
				current_end = buffer_start;
				for (int i = 0; i < n; i++) {
					the_allocator.construct(current_end.base(), val);
					current_end++;
					std::cout << (unsigned long)*current_end << "\n";
				}
			};
			reference at(size_type pos) {
				std::cout << (unsigned long)*buffer_start
					<< "\n"
					<< (unsigned long)*(buffer_start + pos)
					<< "\n"
					<< (unsigned long)*current_end
					<< "\n"
					<< (unsigned long)*end_of_buffer
					<< std::endl;
				if ((unsigned long)*(buffer_start + pos) > (unsigned long)*current_end) {
					throw "out of range";
				}
				return *(buffer_start + pos);
			};
/*			template<class InputIterator>
			vector(InputIterator first, InputIterator last,
					const allocator_type &alloc = allocator_type()) {
				
			}*/
	};

}
