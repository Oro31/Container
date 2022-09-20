#include <iostream>
#include <memory>
#include "ft_map_it.hpp"

namespace ft {
	template <
		class Key,
		class T,
		class Compare = std::less<Key>,
		class Allocator = std::allocator<std::pair<const Key, T>>
	>
	class map {
		public:
			typedef Key											key_type;
			typedef T											mapped_type;
			typedef std::pair<const Key, T>						value_type;
			typedef Compare										key_compare;
			typedef Allocator									allocator_type;
			typedef typename Allocator::reference				reference;
			typedef typename Allocator::const_reference			const_reference;
			typedef ft::MapIt<Key, T>								iterator;
			typedef const ft::MapIt<Key, T>							const_iterator;
			typedef std::size_t									size_type;
			typedef std::ptrdiff_t								difference_type;
			typedef typename Allocator::pointer					pointer;
			typedef typename Allocator::const_pointer			const_pointer;
			typedef std::reverse_iterator<iterator>				reverse_iterator;
			typedef std::reverse_iterator<const_iterator>		const_reverse_iterator;

		private:
			iterator	_itAlone;
			size_type	_size;
			Allocator	_alloc; // use it to construct and deallocate
//			Node		*_root;
//			key_compare	_comp;
//			size_type	_size;
//			typename allocator_type::template rebind<Node>::other	_allocNode; //use it only to allocate 1 Node

/*	class value_compare
	: public binary_function<value_type,value_type,bool> {
		friend class map;
		protected:
			Compare comp;
			value_compare(Compare c) : comp(c) {}
		public:
			bool operator()(const value_type& x, const value_type& y) const {
				return comp(x.first, y.first);
			}
	};
*/	
	// 23.3.1.1 construct/copy/destroy:

	public:
		explicit map(const Compare& comp = Compare(),
				const Allocator& = Allocator()) : _itAlone(0), _size(0) {};
		template <class InputIterator>
			map(InputIterator first, InputIterator last,
					const Compare& comp = Compare(), const Allocator& = Allocator()) {
				_size = 0;
				for (iterator it = first; it.base() != last.base(); it++) {
					_size++; //if it->_root->_pair doesn't belong to this
					_itAlone.insert(std::make_pair(it->first, it->second));
				}
			};
		/*
		map(const map<Key,T,Compare,Allocator>& other) {
			*this = other;
		};
		~map() {};
		map<Key,T,Compare,Allocator> &operator=(const map<Key,T,Compare,Allocator>& other) {
			_size = other._size;
			_itAlone = other._itAlone;
			return *this;
		};
		// iterators:
		*/
		iterator begin() {return _itAlone.minValueNode(_itAlone.base());};
//		const_iterator begin() const {return _itAlone.minValueNode(&(_itAlone._root));};
		iterator end() {return _itAlone.maxValueNode(_itAlone.base());};
//		const_iterator end() const {return _itAlone.maxValueNode(&(_itAlone._root));};
//		reverse_iterator rbegin() {return _itAlone.maxValueNode(&(_itAlone._root));};
//		const_reverse_iterator rbegin() const {return _itAlone.maxValueNode(&(_itAlone._root));};
//		reverse_iterator rend() {return _itAlone.minValueNode(&(_itAlone._root));};
//		const_reverse_iterator rend() const {return _itAlone.minValueNode(&(_itAlone._root));};
		// capacity:
		
		bool empty() const {return _size == 0;};
		size_type size() const {return _size;};
		size_type max_size() const {return _alloc.max_size();};
		// 23.3.1.2 element access:
		T& operator[](const key_type &x) {return _itAlone[x];};
		// modifiers:
		/*
		pair<iterator, bool> insert(const value_type& x) {
			Node *result = NULL;
			searchNode(_root, &result, x);
			if (!result) {
				_root = insertVal(_root, x);
				searchNode(_root, &result, x.first)
			}
			return result.key;
		};
		iterator insert(iterator position, const value_type& x);
		template <class InputIterator>
			void insert(InputIterator first, InputIterator last);
		void erase(iterator position);
		size_type erase(const key_type& x);
		void erase(iterator first, iterator last);
		void swap(map<Key,T,Compare,Allocator>&);
		void clear();
		// observers:
		key_compare key_comp() const;
		value_compare value_comp() const;
		// 23.3.1.3 map operations:
		iterator find(const key_type& x);
		const_iterator find(const key_type& x) const;
		size_type count(const key_type& x) const;
		iterator lower_bound(const key_type& x);
		const_iterator lower_bound(const key_type& x) const;
		iterator upper_bound(const key_type& x);
		const_iterator upper_bound(const key_type& x) const;
		pair<iterator,iterator>
		equal_range(const key_type& x);
		pair<const_iterator,const_iterator>
			equal_range(const key_type& x) const;
	};

template <class Key, class T, class Compare, class Allocator>
bool operator==(const map<Key,T,Compare,Allocator>& x,
		const map<Key,T,Compare,Allocator>& y);
template <class Key, class T, class Compare, class Allocator>
bool operator< (const map<Key,T,Compare,Allocator>& x,
		const map<Key,T,Compare,Allocator>& y);
template <class Key, class T, class Compare, class Allocator>
bool operator!=(const map<Key,T,Compare,Allocator>& x,
		const map<Key,T,Compare,Allocator>& y);
template <class Key, class T, class Compare, class Allocator>
bool operator> (const map<Key,T,Compare,Allocator>& x,
		const map<Key,T,Compare,Allocator>& y);
template <class Key, class T, class Compare, class Allocator>
bool operator>=(const map<Key,T,Compare,Allocator>& x,
		const map<Key,T,Compare,Allocator>& y);
template <class Key, class T, class Compare, class Allocator>
bool operator<=(const map<Key,T,Compare,Allocator>& x,
		const map<Key,T,Compare,Allocator>& y);
// specialized algorithms:
template <class Key, class T, class Compare, class Allocator>
void swap(map<Key,T,Compare,Allocator>& x,
		map<Key,T,Compare,Allocator>& y);

}
*/
	};
}
