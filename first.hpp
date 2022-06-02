#include <memory>

namespace ft {
	template <class T, class Allocator = std::allocator<T>>
	class set {
		public:
			typedef Allocator							allocator_type;
			typedef typename Allocator::size_type		size_type;
			typedef typename Allocator::difference_type	difference_type;
			typedef typename Allocator::reference		reference;
			typedef typename Allocator::const_reference	const_reference;

			typedef Allocator::pointer			iterator;
			typedef Allocator::const_pointer	iterator;

		protected:
			Allocator	the_allocator;

		private:
			size_type	buffer_size;
			iterator	buffer_start;
			iterator	current_end;
			iterator	end_of_buffer;

		public:
			template<class Iterator>
			set(Iterator start, Iteartor finish,
					Allocator alloc = Allocator());
			iterator	begin() {return buffer_start;}}
			iterator	end() {return current_end;}}
	};
	template<class T, class Allocator>
	template<class Iterator>
	set<T, Allocator>::set(Iterator start, Iterator finish,
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
