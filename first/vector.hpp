#include <memory>
#include <iostream>
#include "VecIterator.hpp"

namespace ft {
	template <class T, class Allocator = std::allocator<T>>
	class vector {
		public:
			typedef T											value_type;
			typedef Allocator									allocator_type;
			typedef value_type									&reference;
			typedef const value_type							&const_reference;
			typedef value_type									*pointer;
			typedef const value_type							*const_pointer;
			typedef VecIterator<T>								iterator;
			typedef const VecIterator<T>						const_iterator;
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
//			const iterator	cbegin() const {return buffer_start;};
//			const iterator	cend() const {return current_end;};

			vector() : buffer_start(0), current_end(0), end_of_buffer(0) {};
			explicit vector(const allocator_type &alloc = allocator_type()) :
				buffer_start(0), current_end(0), end_of_buffer(0) {};
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
					const_reference tmp = *first;
					the_allocator.construct(current_end.base(), tmp);
				}
//				std::unique(begin(), end());
			};
			vector &operator=(vector &other) {
				iterator	first = other.begin();
				size_t	buf_size = other.end() - other.begin();
				the_allocator = other.get_allocator();
				buffer_start = the_allocator.allocate(buf_size);
				end_of_buffer = buffer_start + buf_size;
				for (current_end = buffer_start; first != other.end(); current_end++, first++) {
					the_allocator.construct(current_end.base(), *first);
				}
				return *this;
//				vector<value_type> v(vector<iterator>(other.begin(), other.end()));
			}
			vector(vector &other) {
				*this = other;
			};
			~vector() {
				for (iterator it = buffer_start; it != current_end; it++) {
					the_allocator.destroy(it.base());
				}
				the_allocator.deallocate(buffer_start.base(), end_of_buffer.base() - buffer_start.base());
			};
			allocator_type get_allocator() const {return the_allocator;};
			reference at(size_type pos) {
				if ((buffer_start + pos).base() - current_end.base() >= 0) {
					throw std::out_of_range("out of range");
				}
				return *(buffer_start + pos);
			};
			size_type capacity() {return end_of_buffer - buffer_start;};
			size_type size() {return current_end - buffer_start;};
	};

}
