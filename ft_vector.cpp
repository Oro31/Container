#include <memory>
#include <ft_vector.hpp>

namespace ft {
	template<class T, class Allocator>
	template<class InputIterator>
	Vector<T, Allocator>::Vector(InputIterator first, InputIterator last,
			const allocator_type& alloc = allocator_type()) {
	}

	Vector<T, Allocator>::~Vector() {
		allocator_type.deallocate(allocatpr_type, pointer, buffer_size);
		allocator_type.deallocate(allocatpr_type, const_pointer, buffer_size);
//		allocator_type.destroy(this, std::distance(this->begin(), this->end());
	}

	Vector<T, Allocator>::&operator=(const Vector &other) {
		buffer_size = std::distance(other.begin(), other.end());
		buffer_start = other.begin();
		current_end = other.end();
		end_of_buffer = buffer_start + buffer_size;
		return *this;
	}

	void	Vector<T, Allocator>::assign(size_type count, const T &value) {
		for (int i = 0; i < count; i++) {
			this->at(i) = value;
		}
	}

	template<class InputIt>
	void	Vector<T, Allocator>::assign(InputIt first, InputIt last) {
		int j = 0;
		for (InputIt it = first; it != last; it++) {
			this->at(j) = it;
			j++;
		}
	}

	allocator_type	Vector<T, Allocator>::get_allocator() const {
		return allocator_type;
	}

	reference	Vector<T, Allocator>::at(size_type pos) {
		if (pos > buffer_size) {throw std::out_of_range("bad argument");}
		return *(buffer_start + pos);
	}

	const_reference	Vector<T, Allocator>::at(size_type pos) const {
		if (pos > current_end) {throw std::out_of_range("bad argument");}
		return *(buffer_start + pos);
	}

	reference	Vector<T, Allocator>::operator[](size_type pos) {
		return *(buffer_start + pos);
	}

	const_reference	Vector<T, Allocator>::operator[](size_type pos) const {
		return *(buffer_start + pos);
	}

	reference	Vector<T, Allocator>::front() {
		return *(buffer_start);
	}

	const_reference	Vector<T, Allocator>::front() const {
		return *(buffer_start);
	}

	reference	Vector<T, Allocator>::back() {
		return *(current_end);
	}

	const_reference	Vector<T, Allocator>::back() const {
		return *(current_end);
	}

	T	Vector<T, Allocator>::*data() {
		return buffer_start;
	}

	const T	Vector<T, Allocator>::*data() const {
		return buffer_start;
	}

	iterator	Vector<T, Allocator>::begin() {
		return	buffer_start;
	}

	const_iterator	Vector<T, Allocator>::begin() const {
		return	buffer_start;
	}

	iterator	Vector<T, Allocator>::end() {
		return	current_end;
	}

	const_iterator	Vector<T, Allocator>::end() const {
		return	current_end;
	}

	reverse_iterator	Vector<T, Allocator>::rbegin() {
		return	current_end;
	}

	const_reverse_iterator	Vector<T, Allocator>::rbegin() const {
		return	current_end;
	}

	reverse_iterator	Vector<T, Allocator>::rend() {
		return	buffer_start;
	}

	const_reverse_iterator	Vector<T, Allocator>::rend() const {
		return	buffer_start;
	}

	bool	Vector<T, Allocator>::empty() const {
		return buffer_start == current_end;
	}

	size_type	Vector<T, Allocator>::size() const {
		return	current_end - buffer_start;
	}

	size_type	Vector<T, Allocator>::max_size() const {
		return	std::numeric_limits<difference_type>::max();
	}

	void	Vector<T, Allocator>::reserve(size_type new_cap) {
		if (new_cap < buffer_size
				|| new_cap > this->max_size())
			throw std::length_error("bad argument");
		iterator	old_start = buffer_start;
		iterator	old_end = current_end;

		buffer_start = the_allocator.allocate(new_cap + DEFAULT_CUSHION);

		iterator	start = buffer_start;
		iterator	end = current_end;

		buffer_size = new_cap + DEFAULT_CUSHION;
		end_of_buffer = buffer_start + buffer_size;

		for (current_end = buffer_start; start != finish;
			   current_end++, start++) {
			the_allocator.construct(current_end, *start);
		}
		std::unique(begin(), end());
		iterator	it = buffer_start;
		while (old_start != old_end) {
			*it = *old_start;
			it++;
			old_start++;
		}
	}

	size_type	Vector<T, Allocator>::capacity() const {
		return buffer_size;
	}

	void	Vector<T, Allocator>::clear() {
		iterator	end = current_end;

		for (iterator start = buffer_start; start != end; start++) {
			the_allocator.destroy(start);
		}
	}

	iterator	Vector<T, Allocator>::insert(iterator pos, const T &value) {
		iterator	end = current_end;

		if (buffer_size == current_end - buffer_start) {
			this->reserve(buffer_size * 2);
		}
		iterator it = buffer_start;
	   	while (it != pos) {
			it++;
		}
		T	tmp(*it);
		*it = value;
		while (it != current_end) {
			it++;
			T	ttmp(*it)
			*it = tmp;
			tmp = ttmp;
		}
		current_end++;
		*current_end = *it;
		*it = tmp;
	}

	void	Vector<T, Allocator>::insert(iterator pos, size_type count, const T &value) {
		if (buffer_size <= current_end - buffer_start + count) {
			this->reserve((buffer_size + count) * 2);
		}
		while (count > 0) {
			this->insert(pos, value);
			pos++;
			count--;
		}
	}

	template<class InputIt>
	void	Vector<T, Allocator>::insert(itearator pos, iterator first, iterator last) {
		if (buffer_size <= current_end - buffer_start + last - first) {
			this->reserve((buffer_size + last - first) * 2);
		}
		while (first != last) {
			this->insert(pos, *first);
			pos++;
			first++;
		}
	}

	iterator	Vector<T, Allocator>::erase(iterator pos) {
		iterator it = buffer_start;
	   	while (it != pos) {
			it++;
		}
		while (it != current_end) {
			T	tmp(*(it + 1));
			*it = tmp;
			it++;
		}
		current_end--;
	}

	iterator	Vector<T, Allocator>::erase(iterator first, iterator last) {
		for (int i = last - first; i > 0; i--) {
			this->erase(first);
		}
	}

	void	Vector<T, Allocator>::push_back(const T &value) {
		if (buffer_size == current_end - buffer_start) {
			this->reserve(buffer_size * 2);
		}
		current_end++;
		*current_end = value;
	}

	void	Vector<T, Allocator>::pop_back(const T &value) {
		current_end--;
	}

	void	Vector<T, Allocator>::resize(size_type count) {
		if (count <= current_end - buffer_start) {
			while (current_end - buffer_start > count) {
				current_end--;
			}
		} else {
			this->reserve(count - (current_end - buffer_start));
		}
	}

	void	Vector<T, Allocator>::swap(Vector &other) {
		size_type	old_bsize = buffer_size;
		iterator	old_start = buffer_start;
		iterator	old_end = current_end;
		iterator	old_eob = end_of_buffer;

		buffer_size = other.buffer_size;
		buffer_start = other.buffer_start;
		current_end = other.current_end;
		end_of_buffer = other.end_of_buffer;

		other.buffer_size = old_bsize;
		other.buffer_start = old_start;
		other.current_end = old_end;
		other.end_of_buffer = old_eob;
	}
}
