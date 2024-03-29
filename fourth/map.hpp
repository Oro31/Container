#include <iostream>
#include <memory>
#include "MapIt.hpp"

namespace ft {
	template <
		class Key,
		class T,
		class Compare = std::less<Key>,
		class Allocator = std::allocator<ft::pair<Key, T>>
	>
	class map {
		public:
			typedef Key											key_type;
			typedef T											mapped_type;
			typedef ft::pair<Key, T>						value_type;
			typedef Compare										key_compare;
			typedef Allocator									allocator_type;
			typedef typename Allocator::reference				reference;
			typedef typename Allocator::const_reference			const_reference;
			typedef ft::MapIt<value_type>					iterator;
			typedef const ft::MapIt<value_type>			const_iterator;
			typedef std::size_t									size_type;
			typedef std::ptrdiff_t								difference_type;
			typedef typename Allocator::pointer					pointer;
			typedef typename Allocator::const_pointer			const_pointer;
			typedef std::reverse_iterator<iterator>				reverse_iterator;
			typedef std::reverse_iterator<const_iterator>		const_reverse_iterator;

		private:
			iterator	_root;
			iterator	_end;
			size_type	_size;
			Allocator	_alloc; // use it to construct and deallocate
//			key_compare	_comp;
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
				const Allocator& = Allocator()) : _root(), _end(), _size() {};
		template <class InputIterator>
			map(InputIterator first, InputIterator last,
					const Compare& comp = Compare(), const Allocator& = Allocator()) {
				_size = 0;
				for (InputIterator it = first; it != last; it++) {
					_size++; //if it->_root->_pair doesn't belong to this
					_root.insert(ft::make_pair(it->first, it->second));
				}
				_end = _root.getEnd();
			};
		map(map<Key,T,Compare,Allocator>& other) {
			*this = other;
		};
		~map() {};
		map<Key,T,Compare,Allocator> &operator=(map<Key,T,Compare,Allocator>& other) {
			this->insert(other.begin(), other.end());
			return *this;
		};
		// iterators:
		iterator begin() {return _root.find(_root.minValueKey(_root.base()));};
//		const_iterator begin() const {return _root.find(_root.minValueNode(_root.base()));};
		iterator end() {return _end;};
//		const_iterator end() const {return _root.getEnd();};
//		reverse_iterator rbegin() {return _root.maxValueNode(&(_root._root));};
//		const_reverse_iterator rbegin() const {return _root.maxValueNode(&(_root._root));};
//		reverse_iterator rend() {return _root.minValueNode(&(_root._root));};
//		const_reverse_iterator rend() const {return _root.minValueNode(&(_root._root));};
		// capacity:
		bool empty() const {return _size == 0;};
		size_type size() const {return _size;};
		size_type max_size() const {return _alloc.max_size();};
		// 23.3.1.2 element access:
		T& operator[](const key_type &x) {return _root.find(x)->first;};
		// modifiers:
		ft::pair<iterator, bool> insert(const value_type &x) {
			bool b = false;
			iterator	res = _root.find(x.first);
			if (!(res.base())) {_root.delEnd(); _root.insert(x); b = true; _size++;}
			_end = _root.getEnd();
			return ft::make_pair(_root.find(x.first), b);
		};
		iterator insert(iterator position, const value_type& x) {
			return this->insert(x).first;
		};
		template <class InputIterator>
			void insert(InputIterator first, InputIterator last) {
				for (iterator it = first; it != last; it++) {
					this->insert(it.base()->pair);
				}
			};
		void erase(iterator position) {
			_root.delEnd();
			_root.erase(position->first);
			_size--;
			std::cout << _size << std::endl;
			if (_size > 0)
				_end = _root.getEnd();
		};
		size_type erase(const key_type& x) {
			size_type	ret = 0;
			iterator	res = _root.find(x);
			if (res.base()) {_root.delEnd(); _root.erase(x); ret++; _size--;}
			_end = _root.getEnd();
			return ret;
		};
		void erase(iterator first, iterator last) {
			for (iterator it = first; it != --last; it++) {
				std::cout << it.base() << std::endl;
				it.print();
				this->erase(it);
			}
		};
//		void swap(map<Key,T,Compare,Allocator>&);
		void clear() {
			std::cout << "clear started\n";
			this->erase(this->begin(), this->end());
		};
		// observers:
		void print() {_root.print();}
		/*
		key_compare key_comp() const;
		value_compare value_comp() const;
		// 23.3.1.3 map operations:
		// */
		iterator find(const key_type& x) {
			return _root.find(x);
		};
//		const_iterator find(const key_type& x) const;
		size_type count(const key_type& x) {
			return _root.find(x).base() != NULL;
		};
		iterator lower_bound(const key_type& x) {
			iterator	ret = this->begin();
			while (ret != this->end() && ret->first < x)
				ret++;
			return ret;
		};
//		const_iterator lower_bound(const key_type& x) const;
		iterator upper_bound(const key_type& x) {
			iterator	ret = this->begin();
			while (ret != this->end() && ret->first <= x)
				ret++;
			return ret;
		};
//		const_iterator upper_bound(const key_type& x) const;
		/*		
		pair<iterator,iterator> equal_range(const key_type& x);
		pair<const_iterator,const_iterator> equal_range(const key_type& x) const;
		*/
	};
/*
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
}
