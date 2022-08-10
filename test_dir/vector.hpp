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
			MyIterator(pointer x) : p(x) {};
			MyIterator &operator=(const pointer it) {p = it; return *this;};
			MyIterator(const MyIterator &mit) {*this = mit;};

			reference operator*() {return *p;};
			const reference operator*() const {return *p;};
			pointer operator->() {return p;};
//			const pointer operator->() const {return p;};
			pointer base() {return p;};
			const pointer base() const {return p;};

//			value_type &operator=(const reference other) {*this = other; return *this;};

			MyIterator &operator++() {++p; return *this;};
			MyIterator &operator--() {--p; return *this;};
			MyIterator operator++(int) {MyIterator tmp(*this); operator++(); return tmp;};
			MyIterator operator--(int) {MyIterator tmp(*this); operator--(); return tmp;};

			MyIterator operator+=(int n) const {MyIterator r(p); for(int i=0; i<n; i++) {r++;} return r;};
			MyIterator operator-=(int n) const {MyIterator r(p); for(int i=0; i<n; i++) {r--;} return r;};
			reference operator[](size_t n) {p += n; return *p;};

			MyIterator operator+(int n) const {MyIterator r(*this); r+=n; return r;};
			MyIterator operator-(int n) const {MyIterator r(*this); r-=n; return r;};
			difference_type operator-(MyIterator const &second) const {
				return (this->base() - second.base());
			};

			bool operator==(const MyIterator &rhs) const {return p==rhs.p;};
			bool operator!=(const MyIterator &rhs) const {return p!=rhs.p;};
			bool operator>(const MyIterator &rhs) const {return p>rhs.p;};
			bool operator>=(const MyIterator &rhs) const {return p>=rhs.p;};
			bool operator<(const MyIterator &rhs) const {return p<rhs.p;};
			bool operator<=(const MyIterator &rhs) const {return p<=rhs.p;};

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
			explicit vector(size_type n, const value_type &val = value_type(),
					const allocator_type &alloc = allocator_type()) {
				T	*p = the_allocator.allocate(n * 2);
				iterator	al(p);
				buffer_start = al;
				end_of_buffer = buffer_start;
				for (int i = 0; i < n * 2; i++) {
					end_of_buffer++;
				}
				current_end = buffer_start;
				for (int i = 0; i < n; i++) {
					the_allocator.construct(current_end.base(), val);
					current_end++;
				}
			};
			template<class InputIterator>
			vector(InputIterator first, InputIterator last,
					const allocator_type &alloc = allocator_type()) : buffer_start(0),
		current_end(0), end_of_buffer(0) {
				size_t	buf_size = last - first;
				the_allocator = alloc;
				buffer_start = the_allocator.allocate(buf_size);
				end_of_buffer = buffer_start + buf_size;
				for (current_end = buffer_start; first != last; current_end++, first++) {
					the_allocator.construct(current_end, *first);
				}
//				std::unique(begin(), end());
			};
			~vector() {
				for (iterator it = buffer_start; it != current_end; it++) {
					the_allocator.destroy(it.base());
				}
				the_allocator.deallocate(buffer_start.base(), end_of_buffer.base() - buffer_start.base());
			};
			reference at(size_type pos) {
				if ((buffer_start + pos).base() - current_end.base() >= 0) {
					throw "out of range";
				}
				return *(buffer_start + pos);
			};
	};

}
