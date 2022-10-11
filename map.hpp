#include <iostream>
#include <limits>
#include <cmath>
#include <memory>
#include "pair.hpp"

namespace ft {
	template <
		class Key,
		class T,
		class Compare = std::less<Key>,
		class Allocator = std::allocator<ft::pair<const Key, T> > >
	class map {
		public:
			typedef Key											key_type;
			typedef T											mapped_type;
			typedef ft::pair<const Key, T>						value_type;
			typedef Compare										key_compare;
			typedef Allocator									allocator_type;
			typedef value_type									&reference;
			typedef const value_type									&const_reference;
//			typedef typename Allocator::reference				reference;
//			typedef typename Allocator::const_reference			const_reference;
			typedef std::size_t									size_type;
			typedef std::ptrdiff_t								difference_type;
			typedef value_type									*pointer;
			typedef const value_type									*const_pointer;
//			typedef typename Allocator::pointer					pointer;
//			typedef typename Allocator::const_pointer			const_pointer;
		private:
			struct Node {
				bool			end;
				value_type		pair;
				int				height;
				Node			*parent;
				Node			*left;
				Node			*right;
			};

			//////////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////////////////////////////////////////////

	template <class U>	
	class MapIt {
		friend class map<Key, T, Compare, Allocator>;

			public:
				typedef U										value_type;
				typedef value_type								*pointer;
				typedef value_type								&reference;
				typedef std::ptrdiff_t							difference_type;
				typedef std::bidirectional_iterator_tag			iterator_category;


				Node	*_p;
				Compare	_comp;

			public:

				MapIt() {_p = NULL;}
				MapIt(Node *node) {_p = node;}
				~MapIt() {};
				MapIt &operator=(const MapIt &it) {
					_p = it._p;
					return *this;
				};
				MapIt(const MapIt &it) {*this = it;}

				reference operator*() {return _p->pair;}
				pointer operator->() {if (_p->end) {return NULL;} return &(_p->pair);}
				const pointer operator->() const {if (_p->end) {return NULL;} return &(_p->pair);}
				Node *base() {return _p;}
				const Node *base() const {return _p;}

				MapIt &operator++() {
					Node	*tmp = _p;
					if (tmp->right)
						_p = minValueNode(tmp->right);
					else if (!tmp->parent)
						_p = NULL;
					else if (tmp->parent && tmp == tmp->parent->left)
						_p = tmp->parent;
					else {
//						while (tmp->parent && tmp->parent->pair.first <= _p->pair.first)
						while (tmp->parent && _comp(tmp->parent->pair.first, _p->pair.first))
							tmp = tmp->parent;
//						if (tmp->parent && tmp->parent->pair.first > _p->pair.first)
						if (tmp->parent && !_comp(tmp->parent->pair.first, _p->pair.first))
							_p = tmp->parent;
						else 
							_p = tmp->right;
					}
					return *this;
				};
				MapIt &operator--() {
					Node	*tmp = _p;
					if (tmp->left)
						_p = maxValueNode(tmp->left);
					else if (!tmp->parent)
						_p = NULL;
					else if (tmp->parent && tmp == tmp->parent->right)
						_p = tmp->parent;
					else {
//						while (tmp->parent && tmp->parent->pair.first >= _p->pair.first)
						while (tmp->parent && !_comp(tmp->parent->pair.first, _p->pair.first))
							tmp = tmp->parent;
//						if (tmp->parent && tmp->parent->pair.first < _p->pair.first)
						if (tmp->parent && _comp(tmp->parent->pair.first, _p->pair.first))
							_p = tmp->parent;
						else 
							_p = tmp->left;
					}
					return *this;
				};
				MapIt operator++(int) {MapIt tmp(*this); operator++(); return tmp;}
				MapIt operator--(int) {MapIt tmp(*this); operator--(); return tmp;}
			
				MapIt &operator+=(int n) {for (int i = 0; i < n; i++) {operator++();} return *this;}
				MapIt &operator-=(int n) {for (int i = 0; i < n; i++) {operator--();} return *this;}

				MapIt operator+(int n) const {MapIt r(*this); r+=n; return r;}
				MapIt operator-(int n) const {MapIt r(*this); r-=n; return r;}

				template<class Iterator>
					friend bool operator!=(const Iterator &lhs, const Iterator &rhs);
				template<class Iterator>
					friend bool operator==(const Iterator &lhs, const Iterator &rhs);
	};
	////////////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////////////
	
				static void printNode(Node *node, std::string str, Node *end) {
					std::cout << "\nfrom " << str;
					std::cout << ": root = " << node;
					if (node) {
						if (node->end) {std::cout << "\nthis is the end, my only friend, the end...\n";}
						std::cout << ": first = " << node->pair.first
							<< ", \nparent = " << node->parent;
						if (node->parent) {std::cout << ": parent->first = " << node->parent->pair.first;}
						std::cout << ", \nright = " << node->right;
						if (node->right && node->right != end) {std::cout << ": right->first = " << node->right->pair.first;}
						std::cout << ", \nleft = " << node->left;
						if (node->left) {std::cout << ": left->first = " << node->left->pair.first;}
					}
					std::cout << std::endl;
				};

///////////////////////////************************////////////////////////////////


				int max(int a, int b) {
					return (a > b) ? a : b;
				};

				int height(Node *node) {
					if (!node) {return 0;}
					return node->height;
				};

				void UpdateHeight(Node *root) {
					if (root) {
						int h = 1;
						if (root->left)
							h = root->left->height + 1;
						if (root->right)
							h = max(h, root->right->height + 1);
						root->height = h;
					}
				}

				void getMaxHeight(Node *root, int *height) {
					if (!root) {return ;}
					getMaxHeight(root->left, height);
					if (root->height > *height) {*height = root->height;}
					getMaxHeight(root->right, height);
				};

				static Node *minValueNode(Node *node) {
					Node	*current = node;
					while (current && current->left != NULL)
						current = current->left;
					return current;
				};

				static Node *maxValueNode(Node *node) {
					Node	*current = node;
					while (current && current->right != NULL && !current->right->end)
						current = current->right;
					return current;
				};

				Node *newNode() {
					Node	*ret = _allocNode.allocate(1);
					ret->end = false;
					ret->height = 1;
//					_allocNode.construct(&ret->pair, value_type());
					ret->parent = NULL;
					ret->left = NULL;
					ret->right = NULL;
					return ret;
				}

				Node *newNode(value_type &pr) {
					Node	*ret = _allocNode.allocate(1);
					ret->end = false;
					ret->height = 1;
					_alloc.construct(&ret->pair, pr);
					ret->parent = NULL;
					ret->left = NULL;
					ret->right = NULL;
					return ret;
				}

///////////////////////////************************////////////////////////////////


				Node *LLR(Node *root) {
					Node *tmpNode = root->left;
					root->left = tmpNode->right;
					if (tmpNode->right)
						tmpNode->right->parent = root;
					tmpNode->right = root;
					tmpNode->parent = root->parent;
					root->parent = tmpNode;
//					if (tmpNode->parent && root->pair.first < tmpNode->parent->pair.first)
					if (tmpNode->parent && _comp(root->pair.first, tmpNode->parent->pair.first))
						tmpNode->parent->left = tmpNode;
					else {
						if (tmpNode->parent)
							tmpNode->parent->right = tmpNode;
					}
					root = tmpNode;
					UpdateHeight(root->left);
					UpdateHeight(root->right);
					UpdateHeight(root);
					UpdateHeight(root->parent);
					return root;
				}

				Node *RRR(Node *root) {
					Node *tmpNode = root->right;
					root->right = tmpNode->left;
					if (tmpNode->left)
						tmpNode->left->parent = root;
					tmpNode->left = root;
					tmpNode->parent = root->parent;
					root->parent = tmpNode;
//					if (tmpNode->parent && root->pair.first < tmpNode->parent->pair.first)
					if (tmpNode->parent && _comp(root->pair.first, tmpNode->parent->pair.first))
						tmpNode->parent->left = tmpNode;
					else {
						if (tmpNode->parent)
							tmpNode->parent->right = tmpNode;
					}
					root = tmpNode;
					UpdateHeight(root->left);
					UpdateHeight(root->right);
					UpdateHeight(root);
					UpdateHeight(root->parent);
					return root;
				}

				Node *LRR(Node *root) {
					root->left = RRR(root->left);
					return LLR(root);
				}

				Node *RLR(Node *root) {
					root->right = LLR(root->right);
					return RRR(root);
				}

				Node *Balance(Node *root) {
					int firstheight = 0;
					int secondheight = 0;
					if (root->left)
						firstheight = root->left->height;
					if (root->right)
						secondheight = root->right->height;
					if (abs(firstheight - secondheight) == 2) {
						if (firstheight < secondheight) {
							int rightheight1 = 0;
							int rightheight2 = 0;
							if (root->right->right)
								rightheight2 = root->right->right->height;
							if (root->right->left)
								rightheight1 = root->right->left->height;
							if (rightheight1 > rightheight2)
								root = RLR(root);
							else
								root = RRR(root);
						} else {
							int leftheight1 = 0;
							int leftheight2 = 0;
							if (root->left->right)
								leftheight2 = root->left->right->height;
							if (root->left->left)
								leftheight1 = root->left->left->height;
							if (leftheight1 > leftheight2)
								root = LLR(root);
							else
								root = LRR(root);
						}
					}
					return root;
				}

				Node *Insert(Node *root,
									Node *parent, value_type &pair){
					if (!root) {
						root = newNode(pair);
						root->parent = parent;
//					} else if (root->pair.first > pair.first) {
					} else if (!_comp(root->pair.first, pair.first)) {
						root->left = Insert(root->left, root, pair);
						int firstHeight = 0;
						int secondHeight = 0;

						if (root->left)
							firstHeight = root->left->height;
						if (root->right)
							secondHeight = root->right->height;
						if (abs(firstHeight - secondHeight) == 2) {
							if (root->left && pair.first < root->left->pair.first)
								root = LLR(root);
							else
								root = LRR(root);
						}
//					} else if (root->pair.first < pair.first) {
					} else if (_comp(root->pair.first, pair.first)) {
						root->right = Insert(root->right, root, pair);
						int firstHeight = 0;
						int secondHeight = 0;

						if (root->left)
							firstHeight = root->left->height;
						if (root->right)
							secondHeight = root->right->height;
						if (abs(firstHeight - secondHeight) == 2) {
							if (root->right && pair.first < root->right->pair.first)
								root = RLR(root);
							else
								root = RRR(root);
						}
					}
					UpdateHeight(root);
					return root;
				}

///////////////////////////************************////////////////////////////////


				Node *Delete(Node *root, const value_type &pr) {
					if (root) {
						if (root->pair.first == pr.first) {
							if (!root->right && root->left) {
								if (root->parent) {
//									if (root->parent->pair.first < root->pair.first)
									if (_comp(root->parent->pair.first, root->pair.first))
										root->parent->right = root->left;
									else
										root->parent->left = root->left;
									UpdateHeight(root->parent);
								}
								root->left->parent = root->parent;
								root->left = Balance(root->left);
								Node *tmpNode = root->left;
								_alloc.destroy(&(root->pair));
								_allocNode.deallocate(root, 1);
								root = NULL;
								return tmpNode;
							} else if (!root->left && root->right) {
								if (root->parent) {
//									if (root->parent->pair.first < root->pair.first)
									if (_comp(root->parent->pair.first, root->pair.first))
										root->parent->right = root->right;
									else
										root->parent->left = root->right;
									UpdateHeight(root->parent);
								}
								root->right->parent = root->parent;
								root->right = Balance(root->right);
								Node *tmpNode = root->right;
								_alloc.destroy(&(root->pair));
								_allocNode.deallocate(root, 1);
								root = NULL;
								return tmpNode;
							} else if (!root->left && !root->right) {
//								if (root->parent->pair.first < root->pair.first)
								if (_comp(root->parent->pair.first, root->pair.first))
									root->parent->right = NULL;
								else
									root->parent->left = NULL;
								if (root->parent)
									UpdateHeight(root->parent);
								_alloc.destroy(&(root->pair));
								_allocNode.deallocate(root, 1);
								root = NULL;
								return NULL;
							} else {
								Node *tmpNode = root;
								tmpNode = tmpNode->right;
								while (tmpNode->left)
									tmpNode = tmpNode->left;
								value_type val = ft::make_pair(tmpNode->pair.first, tmpNode->pair.second);
								root->right = Delete(root->right, tmpNode->pair);
								_alloc.construct(&(root->pair), val);
								root = Balance(root);
							}
//						} else if (root->pair.first < pr.first) {
						} else if (_comp(root->pair.first, pr.first)) {
							root->right = Delete(root->right, pr);
							root = Balance(root);
//						} else if (root->pair.first > pr.first) {;
						} else if (_comp(root->pair.first, pr.first)) {
							root->left = Delete(root->left, pr);
							root = Balance(root);
						}
						if (root)
							UpdateHeight(root);
					}
					return root;
				}

///////////////////////////************************////////////////////////////////


				void inOrderTree(Node *root) {
					if (!root || root == _end) {return;}
					inOrderTree(root->left);
					printNode(root, "inorder: ", _end);
					inOrderTree(root->right);
				};

				Node *searchIt(Node *node, value_type &pr) {
					if (!node || node == _end)
						return NULL;
					else if (node != _end && node->pair.first < pr.first)
						return searchIt(node->right, pr);
					else if (node != _end && node->pair.first > pr.first)
						return searchIt(node->left, pr);
					else
						return node;
				}

///////////////////////////************************////////////////////////////////

				void delEnd() {
					if (_end) {
						if (_end->parent)
							_end->parent->right = NULL;
					}
				}

				void getEnd() {
					if (!_end)
						_end = newNode();
					_end->end = true;
					_end->right = NULL;
					_end->left = NULL;
					_end->parent = maxValueNode(_root);
					if (_end->parent)
						_end->parent->right = _end;

				};

				/////////////////////////////////////////////////////////////////////
				/////////////////////////////////////////////////////////////////////
				/////////////////////////////////////////////////////////////////////
				/////////////////////////////////////////////////////////////////////
				/////////////////////////////////////////////////////////////////////
				/////////////////////////////////////////////////////////////////////

		public:
			typedef MapIt<value_type>					iterator;
			typedef const MapIt<value_type>			const_iterator;
			typedef std::reverse_iterator<iterator>				reverse_iterator;
			typedef std::reverse_iterator<const_iterator>		const_reverse_iterator;

		private:
			Node		*_root;
			Node		*_end;
			size_type	_size;
			key_compare	_comp;
			Allocator	_alloc; // use it to construct and deallocate
			typename allocator_type::template rebind<Node>::other	_allocNode; //use it only to allocate 1 Node

	class value_compare
	: public std::binary_function<value_type,value_type,bool> {
		friend class map;
		protected:
			Compare comp;
			value_compare(Compare c) : comp(c) {}
		public:
			bool operator()(const value_type& x, const value_type& y) const {
				return comp(x.first, y.first);
			}
	};
	// 23.3.1.1 construct/copy/destroy:

	public:
		explicit map(const Compare& comp = Compare(),
				const Allocator& alloc = Allocator()) : _root(NULL), _end(NULL), _size(0), _comp(comp), _alloc(alloc) {getEnd();};
		template <class InputIterator>
		map(InputIterator first, InputIterator last,
				const Compare& comp = Compare(),
				const Allocator& alloc = Allocator()) :
				_root(NULL), _end(NULL), _size(0), _comp(comp), _alloc(alloc) {
			for (InputIterator it = first; it != last; it++) {
				insert(ft::make_pair(it->first, it->second));
			}
			getEnd();
		};
		map(const map& other) {
			*this = other;
		};
		~map() {
			this->clear();
			if (_root) {
				_alloc.destroy(&(_root->pair));
				_allocNode.deallocate(_root, 1);
			}
			_allocNode.deallocate(_end, 1);
		};
		map &operator=(const map& other) {
			this->clear();
			this->insert(other.begin(), other.end());
			return *this;
		};
		allocator_type get_allocator() const {return _alloc;}
		// iterators:
		iterator begin() {if (_size == 0) {return iterator(_end);} iterator	tmp(minValueNode(_root)); return tmp;};
		const_iterator begin() const {if (_size == 0) {return const_iterator(_end);} const_iterator tmp(minValueNode(_root)); return tmp;};
		iterator end() {return iterator(_end);};
		const_iterator end() const {return const_iterator(_end);};
//		reverse_iterator rbegin() {return _root.maxValueNode(&(_root._root));};
//		const_reverse_iterator rbegin() const {return _root.maxValueNode(&(_root._root));};
//		reverse_iterator rend() {return _root.minValueNode(&(_root._root));};
//		const_reverse_iterator rend() const {return _root.minValueNode(&(_root._root));};
		// capacity:
		bool empty() const {return _size == 0;};
		size_type size() const {return _size;};
		size_type max_size() const {/*return _alloc.max_size();*/return std::numeric_limits<difference_type>::max();};
		// 23.3.1.2 element access:
		T& operator[](const key_type &x) {return find(x)->second;};
		T& at(const Key &x) {
			if (find(x).base()) {return find(x)->second;}
			throw std::out_of_range("no element finded");
		};
		// modifiers:
		ft::pair<iterator, bool> insert(const value_type &val) {
			bool b = false;
			value_type	x = ft::make_pair<key_type, mapped_type>(val.first, val.second);
			if (!find(x.first).base()) {
				delEnd();
				_root = Insert(_root, NULL, x);
				getEnd();
				b = true;
				_size++;
			}
			iterator	res(searchIt(_root, x));
			return ft::make_pair(res, b);
		};
		iterator insert(iterator position, const value_type& x) {
			(void)position;
			return this->insert(x).first;
		};
		template <class InputIterator>
			void insert(InputIterator first, InputIterator last) {
				for (iterator it = first; it != last; it++) {
					this->insert(*it);
				}
			};
		void erase(iterator position) {
			if (_size > 1)
				_root = Delete(_root, *position);
			else if (_size == 1) {
				_alloc.destroy(&(_root->pair));
				_allocNode.deallocate(_root, 1);
				_root = NULL;
			} else
				_root = NULL;
			if (_size > 0)
				_size--;
			getEnd();
		};
		size_type erase(const key_type& x) {
			size_type	ret = 0;
			if (find(x).base()) {
				erase(find(x));
			}
			return ret;
		};
		void erase(iterator first, iterator last) {
			iterator	tmp;
			while (first != last) {
				tmp = first++;
				erase(tmp);
			}
		};
		void swap(map &other) {
			map	tmpMap = other;
			other = *this;
			*this = tmpMap;
		};
		void clear() {
			this->erase(this->begin(), this->end());
		};
		// observers:
//		void printmap() {this->inOrderTree(_root);}
		key_compare key_comp() const {return _comp;};
		value_compare value_comp() const {return value_comp(_comp);};
		// 23.3.1.3 map operations:
		// */
		iterator find(const Key &x) {
			value_type	pr = ft::make_pair<key_type, mapped_type>(x, mapped_type());
			iterator	res(searchIt(_root, pr));
			return res;
		};
		const_iterator find(const key_type& x) const {
			value_type	pr = ft::make_pair<key_type, mapped_type>(x, mapped_type());
			const_iterator	res(searchIt(_root, pr));
			return res;
		};
		size_type count(const Key &x) const {
			size_type	res = 0;
			if (find(x).base()) {res++;}
			return res;
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
	template<class Iterator>
		bool operator!=(const Iterator &lhs, const Iterator &rhs) {
			return lhs.base() != rhs.base();
		}
	template<class Iterator>
		bool operator==(const Iterator &lhs, const Iterator &rhs) {
			return !(lhs != rhs);
		}
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
