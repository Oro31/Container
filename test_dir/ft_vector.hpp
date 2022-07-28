#include <memory>
#include "ft_reverse_iterator.hpp"
#include "ft_iterator_traits.hpp"

namespace ft {
	template <class T, class Allocator = std::allocator<T>>
	class Vector {
		public:
			typedef T											value_type;
			typedef Allocator									allocator_type;
			typedef value_type									&reference;
			typedef const value_type							&const_reference;
			typedef value_type									*pointer;
			typedef const value_type							*const_pointer;
			typedef MyIterator<value_type>						iterator;
			typedef MyConstIterator<value_type>					const_iterator;
			typedef ft::reverse_iterator<iterator>					reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;
			typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;
			typedef typename difference_type::size_t						size_type;

		protected:
			Allocator	the_allocator;

		private:
			size_type	buffer_size;
			iterator	buffer_start;
			iterator	current_end;
			iterator	end_of_buffer;

		public:
			template<class Iterator>
			Vector(Iterator start, Iteartor finish,
					Allocator alloc = Allocator());
			iterator	begin() {return buffer_start;}}
			iterator	end() {return current_end;}}
	};
	template<class T, class Allocator>
	template<class Iterator>
	Vector<T, Allocator>::Vector(Iterator start, Iterator finish,
			Allocator alloc)
		: buffer_size(finish-start + DEFAULT_CUSHION),
		  buffer_start(0),
		  current_end(0), end_of_buffer(0) {
			  the_allocator = alloc;

			  buffer_start = the_allocator.allocate(buffer_size);
			  end_of_buffer = buffer_start + buffer_size;

			  for (current_end = buffer_start; start != finish;
					  current_end++, start ++) {
				  the_allocator.construct(current_end, *start);
			  }
			  std::unique(begin(), end());
	}
}
