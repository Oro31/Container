#include <memory>
#include <iostream>
#include "VecIterator.hpp"

namespace ft {
	template <class T, class Allocator = std::allocator<T>>
	class vector {
		public:
			typedef typename Allocator::reference				&reference;
			typedef typename Allocator::const_reference			&const_reference;
			typedef VecIterator<T>								iterator;
			typedef const VecIterator<T>						const_iterator;
			typedef std::size_t									size_type;
			typedef std::ptrdiff_t								difference_type;
			typedef T											value_type;
			typedef Allocator									allocator_type;
			typedef typename Allocator::pointer					pointer;
			typedef typename Allocator::const_pointer			const_pointer;
			typedef std::reverse_iterator<iterator>				reverse_iterator;
			typedef std::reverse_iterator<const_iterator>		const_reverse_iterator;

		protected:
			Allocator	the_allocator;

		private:
			iterator	buffer_start;
			iterator	current_end;
			iterator	end_of_buffer;

		public:

			//
			//construct/copy/destroy
			//
			//
			explicit vector(const allocator_type &alloc = allocator_type()) :
				buffer_start(0), current_end(0), end_of_buffer(0) {};
			//
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
			//
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
			};
			//
			vector(const vector<T, Allocator> &other) {
				*this = other;
			};
			//
			~vector() {
				for (iterator it = buffer_start; it != current_end; it++) {
					the_allocator.destroy(it.base());
				}
				the_allocator.deallocate(buffer_start.base(),
						end_of_buffer.base() - buffer_start.base());
			};
			//
			vector &operator=(const vector<T, Allocator> &other) {
				iterator	first = other.begin();
				size_type	buf_size = other.capacity();
				the_allocator = other.get_allocator();
				buffer_start = the_allocator.allocate(buf_size);
				end_of_buffer = buffer_start + buf_size;
				for (current_end = buffer_start; first != other.end(); current_end++, first++) {
					the_allocator.construct(current_end.base(), *first);
				}
				return *this;
			};
			//
			template<class InputIt>
				void assign(InputIt first, InputIt last) {
					if (last - first > this->capacity()) {this->reserve(last - first);}
					for (iterator it = buffer_start; it != current_end; it++) {
						it->~value_type();
					}
					current_end = buffer_start;
					for (iterator it = first; it != last; it++) {
						the_allocator.construct(current_end.base(), *it);
						current_end++;
					}
				};
			//
			void assign(size_type n, const T &value) {
				if (n > this->capacity()) {this->reserve(n);}
				for (iterator it = buffer_start; it != current_end; it++) {
					it->~value_type();
				}
				current_end = buffer_start;
				for (size_type i = 0; i < n; i++) {
					the_allocator.construct(current_end.base(), value);
					current_end++;
				}
			};
			//
			allocator_type get_allocator() const {return the_allocator;};

			//
			//iterators//
			//
			
			iterator				begin() {return buffer_start;};
			const_iterator			begin() const {return buffer_start;};
			iterator				end() {return current_end;};
			const_iterator			end() const {return current_end;};
			reverse_iterator		rbegin() {return current_end;};
			const_reverse_iterator	rbegin() const {return current_end;};
			reverse_iterator		rend() {return buffer_start;};
			const_reverse_iterator	rend() const {return buffer_start;};

			//
			//capacity//
			//
			
			size_type	size() const {return current_end - buffer_start;};
			//
			size_type	max_size() const {return the_allocator.max_size();};
			//
			void		resize(size_type sz, T c = T()) {
				if (sz <= this->size()) {
					for (size_type i = this->size(); i > sz; i--) {
						current_end--;
						current_end->~value_type();
					}
				} else {
					if (sz > this->capacity()) {
						this->reserve(sz);
					}
					for (iterator last = buffer_start + sz; current_end != last; current_end++) {
						the_allocator.construct(current_end.base(), c);
					}
				}
			};
			//
			size_type capacity() const {return end_of_buffer - buffer_start;};
			//
			bool empty() {return !(current_end - buffer_start);};
			//
			void reserve(size_type new_cap) {
				if (new_cap > this->capacity()) {
					T	p(*this);
					this->~vector();
					buffer_start = the_allocator.allocate((this->capacity() + 1) * new_cap * 2);
					end_of_buffer = buffer_start + (new_cap * 2);
					current_end = buffer_start;
					for (iterator it = p.buffer_start; it != p.current_end; it++, current_end++) {
						the_allocator.construct(current_end.base(), *it);
					}
				}
			};

			//
			//element acces//
			//
			
			reference operator[] (size_type pos) {
				return *(buffer_start + pos);
			};
			//
			const_reference operator[] (size_type pos) const {
				return *(buffer_start + pos);
			};
			//
			reference at(size_type pos) {
				if ((buffer_start + pos).base() - current_end.base() >= 0) {
					throw std::out_of_range("out of range");
				}
				return *(buffer_start + pos);
			};
			//
			const_reference at(size_type pos) const {
				if ((buffer_start + pos).base() - current_end.base() >= 0) {
					throw std::out_of_range("out of range");
				}
				return *(buffer_start + pos);
			};
			//
			reference	front() {
				return *(buffer_start);
			};
			//
			const_reference	front() const {
				return *(buffer_start);
			};
			//
			reference	back() {
				return *(current_end - 1);
			};
			//
			const_reference	back() const {
				return *(current_end - 1);
			};

			//
			//element acces//
			//
			
			void	push_back(const T &x) {
				if (this->size() == this->capacity) {this->reserve(1);}
				*current_end = x;
				current_end++;
			};
			//
			void	pop_back() {
				current_end--;
				*current_end->~value_type();
			};
			//
			iterator	insert(iterator position, const T &x) {
				size_type	pos = position - buffer_start;
				T	p(*this);
				if (this->size() == this->capacity) {this->reserve(1);}
				(buffer_start + (pos - 1))->~value_type();
				the_allocator.construct((buffer_start + (pos - 1)).base(), x);
				current_end++;
				for (iterator it = buffer_start + pos; it != current_end; it++) {
					*it = *(p.buffer_start + (pos - 1));
					p.buffer_start++;
				}
				return (buffer_start + (pos - 1));
			};
			//
			template<class InputIt>
				void	insert(iterator position, InputIt first, InputIt last) {
					size_type	pos = position - buffer_start;
					T	p(*this);
					if (this->size() + (last - first) >= this->capacity) {this->reserve(last - first);}
					(buffer_start + (pos - 1))->~value_type();
					p.buffer_start = p.buffer_start + ((position - buffer_start) - 1);
					(buffer_start + (pos - 1))->~value_type();
					size_type	i = 0;
					while (first != last) {
						*(buffer_start + (pos + (i - 1))) = *first;
						i++;
						first++;
					}
					current_end = current_end + (last - first);
					size_type	r = p.size() - pos;
					for (size_type j = 0; j < r; j++ ) {
						*current_end = *(p.buffer_start + (pos + j));
						position++;
					}
				};
			//
			iterator	erase(iterator position) {
				if (position < buffer_start || position >= current_end) {
					return buffer_start;
				}
				iterator	it = buffer_start;
				while (it != position) {it++;}
				it->~value_type();
				while (it != current_end) {
					*it = *(it + 1);
					it++;
				}
				current_end--;
				return (position + 1);
			};
			//
			iterator	erase(iterator first, iterator last) {
				if (last < buffer_start || first > current_end) {
					return (current_end - 1);
				}
				iterator	it = buffer_start;
				if (first >= buffer_start) {
					while (it != first) {it++;}
				}
				size_type	n = 0;
				//it == (first || b_start)
				while (it != last && it != current_end) {
					it->~value_type();
					it++;
					n++;
				}
				//it == (last || current_end)
				while (it != current_end) {
					*first = *it;
					it++;
					first++;
				}
				current_end = current_end - n;
				return (first + n);
			};
			//
			void	swap(vector<T, Allocator> &other) {
				iterator	old_begin = buffer_start;
				iterator	old_end = current_end;
				iterator	old_end_of_buf = end_of_buffer;

				buffer_start = other.buffer_start;
				current_end = other.current_end;
				end_of_buffer = other.end_of_buffer;
				other.buffer_start = old_begin;
				other.current_end = old_end;
				other.end_of_buffer = old_end_of_buf;
			};
			//
			void	clear() {
				for (iterator it = this->end(); it != buffer_start; it--) {
					it->~value_type();
					current_end--;
				}
				buffer_start->~value_type();
			};
	};

	//
	//non-member operator
	//

	template <class T, class Allocator>
		bool	operator==(const vector<T, Allocator> &x,
					const vector<T, Allocator> &y) {
			VecIterator<T>	itx = x.begin();
			VecIterator<T>	ity = y.begin();
			while (itx != x.end() && ity != y.end()) {
				if (*itx != *ity) {
					return false;
				}
				itx++, ity++;
			}
			return true;
		};
	//
	template <class T, class Allocator>
		bool	operator<(const vector<T, Allocator> &x,
					const vector<T, Allocator> &y) {
			VecIterator<T>	itx = x.begin();
			VecIterator<T>	ity = y.begin();
			while (itx != x.end() && ity != y.end()) {
				if (*itx >= *ity) {
					return false;
				}
				itx++, ity++;
			}
			return true;
		};
	//
	template <class T, class Allocator>
		bool	operator!=(const vector<T, Allocator> &x,
					const vector<T, Allocator> &y) {
			return !(x == y);
		};
	//
	template <class T, class Allocator>
		bool	operator>(const vector<T, Allocator> &x,
					const vector<T, Allocator> &y) {
			return (!(x < y) && x != y);
		};
	//
	template <class T, class Allocator>
		bool	operator>=(const vector<T, Allocator> &x,
					const vector<T, Allocator> &y) {
			return !(x < y);
		};
	//
	template <class T, class Allocator>
		bool	operator<=(const vector<T, Allocator> &x,
					const vector<T, Allocator> &y) {
			return !(x > y);
		};
}
