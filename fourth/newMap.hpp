#include <iostream>
#include <memory>
#include "pair.hpp"

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
			typedef std::size_t									size_type;
			typedef std::ptrdiff_t								difference_type;
			typedef typename Allocator::pointer					pointer;
			typedef typename Allocator::const_pointer			const_pointer;
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
//				Compare	_comp;

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
				pointer operator->() {return &(_p->pair);}
				const pointer operator->() const {return _p->pair;}
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
					else if (tmp->parent && tmp->parent->parent)
						_p = tmp->parent->parent;
					else 
						_p = tmp->right;
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
					else if (tmp->parent && tmp->parent->parent)
						_p = tmp->parent->parent;
					else
						_p = tmp->left;
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
	
				static void printNode(Node *node, std::string str) {
					std::cout << "\nfrom " << str;
					std::cout << ": root = " << node;
					if (node) {
						std::cout << ": first = " << node->pair.first
							<< ", \nparent = " << node->parent;
						if (node->parent) {std::cout << ": parent->first = " << node->parent->pair.first;}
						std::cout << ", \nright = " << node->right;
						if (node->right) {std::cout << ": right->first = " << node->right->pair.first;}
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
					ret->pair = value_type();
					ret->parent = NULL;
					ret->left = NULL;
					ret->right = NULL;
					return ret;
				}

				Node *newNode(value_type &pr) {
					Node	*ret = _allocNode.allocate(1);
					ret->end = false;
					ret->height = 1;
					_allocNode.construct(&ret->pair, pr);
					ret->parent = NULL;
					ret->left = NULL;
					ret->right = NULL;
					return ret;
				}

///////////////////////////************************////////////////////////////////


				/*
				Node *getPrevNode(Node *node) {
					if (!node)
						return NULL;
					Node	*tmp = node;
					if (tmp->left)
						return maxValueNode(tmp->left);
					if (!tmp->parent)
						return NULL;
					if (tmp->parent && tmp == tmp->parent->right)
						return tmp->parent;
					if (tmp->parent && tmp->parent->parent)
						return tmp->parent->parent;
					return tmp->left;
				};

				Node *getNextNode(Node *node) {
					if (!node)
						return NULL;
					Node	*tmp = node;
					std::cout << "gnn: " << tmp << "parent = " << tmp->parent->left << std::endl;
					if (tmp->right)
						return minValueNode(tmp->right);
					if (!tmp->parent)
						return NULL;
					if (tmp->parent && tmp == tmp->parent->left)
						return tmp->parent;
					if (tmp->parent && tmp->parent->parent)
						return tmp->parent->parent;
					return tmp->right;
				};
				*/

///////////////////////////************************////////////////////////////////


				Node *LLR(Node *root) {
					Node *tmpNode = root->left;
					root->left = tmpNode->right;
					if (tmpNode->right)
						tmpNode->right->parent = root;
					tmpNode->right = root;
					tmpNode->parent = root->parent;
					root->parent = tmpNode;
					if (tmpNode->parent && root->pair.first < tmpNode->parent->pair.first)
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
					if (tmpNode->parent && root->pair.first < tmpNode->parent->pair.first)
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
									Node *parent, value_type pair){
					if (!root) {
						root = newNode(pair);
						root->parent = parent;
					} else if (root->pair.first > pair.first) {
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
					} else if (root->pair.first < pair.first) {
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


				Node *Delete(Node *root, value_type pr) {
					if (root) {
						if (root->pair.first == pr.first) {
							if (!root->right && root->left) {
								if (root->parent) {
									if (root->parent->pair.first < root->pair.first)
										root->parent->right = root->left;
									else
										root->parent->left = root->left;
									UpdateHeight(root->parent);
								}
								root->left->parent = root->parent;
								root->left = Balance(root->left);
								return root->left;
							} else if (!root->left && root->right) {
								if (root->parent) {
									if (root->parent->pair.first < root->pair.first)
										root->parent->right = root->right;
									else
										root->parent->left = root->right;
									UpdateHeight(root->parent);
								}
								root->right->parent = root->parent;
								root->right = Balance(root->right);
								return root->right;
							} else if (!root->left && !root->right) {
								if (root->parent->pair.first < root->pair.first)
									root->parent->right = NULL;
								else
									root->parent->left = NULL;
								if (root->parent)
									UpdateHeight(root->parent);
								root = NULL;
								return NULL;
							} else {
								Node *tmpNode = root;
								tmpNode = tmpNode->right;
								while (tmpNode->left)
									tmpNode = tmpNode->left;
								value_type val = tmpNode->pair;
								root->right = Delete(root->right, tmpNode->pair.first);
								root->pair = val;
								root = Balance(root);
							}
						} else if (root->pair.first < pr.first) {
							root->right = Delete(root->right, pr.first);
							root = Balance(root);
						} else if (root->pair.first > pr.first) {
							root->left = Delete(root->left, pr.first);
							root = Balance(root);
						}
						if (root)
							UpdateHeight(root);
					}
					return root;
				}

///////////////////////////************************////////////////////////////////


				void inOrderTree(Node *root) {
					if (!root) {return;}
					inOrderTree(root->left);
					printNode(root, "inorder: ");
					inOrderTree(root->right);
				};

				Node *searchIt(Node *node, value_type &pr) {
					if (!node)
						return NULL;
					else if (node->pair.first < pr.first)
						return searchIt(node->right, pr);
					else if (node->pair.first > pr.first)
						return searchIt(node->left, pr);
					else
						return node;
				}

///////////////////////////************************////////////////////////////////

				void delEnd() {
					if (_end) {
						_end->parent->right = NULL;
						_allocNode.destroy(&_end->pair);
						_allocNode.deallocate(_end, 1);
						_end = NULL;
					}
				}

				void getEnd() {
					if (!_end) {
						_end = newNode();
						_end->end = true;
						_end->parent = maxValueNode(_root);
						if (_end->parent)
							_end->parent->right = _end;
					}
				};

				/////////////////////////////////////////////////////////////////////
				/////////////////////////////////////////////////////////////////////
				/////////////////////////////////////////////////////////////////////
				/////////////////////////////////////////////////////////////////////
				/////////////////////////////////////////////////////////////////////
				/////////////////////////////////////////////////////////////////////

			typedef MapIt<value_type>					iterator;
			typedef const MapIt<value_type>			const_iterator;
			typedef std::reverse_iterator<iterator>				reverse_iterator;
			typedef std::reverse_iterator<const_iterator>		const_reverse_iterator;

		private:
			Node		*_root;
			Node		*_end;
			size_type	_size;
			Allocator	_alloc; // use it to construct and deallocate
//			key_compare	_comp;
			typename allocator_type::template rebind<Node>::other	_allocNode; //use it only to allocate 1 Node

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
				const Allocator& = Allocator()) : _root(NULL), _end(NULL), _size(0) {};
		template <class InputIterator>
			map(InputIterator first, InputIterator last,
					const Compare& comp = Compare(), const Allocator& = Allocator()) : _root(NULL), _end(NULL), _size(0) {
				std::cout << "inputIt constructor\n";;
				for (InputIterator it = first; it != last; it++) {
					std::cout << "it: " << it->first << std::endl;
					insert(ft::make_pair(it->first, it->second));
				}
				getEnd();
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
		iterator begin() {iterator	tmp(minValueNode(_root)); return tmp;};
//		const_iterator begin() const {return _root.find(_root.minValueNode(_root.base()));};
//		iterator end() {iterator	tmp(maxValueNode(_root)); return tmp;};
		iterator end() {getEnd(); return _end;};
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
		T& operator[](const key_type &x) {return find(x)->second;};
		// modifiers:
		ft::pair<iterator, bool> insert(const value_type &val) {
			bool b = false;
			value_type	x = ft::make_pair<key_type, mapped_type>(val.first, val.second);
			if (!searchIt(_root, x)) {
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
			return this->insert(x).first;
		};
		template <class InputIterator>
			void insert(InputIterator first, InputIterator last) {
				for (iterator it = first; it != last; it++) {
					this->insert(it.base()->pair);
				}
			};
		/*
		void erase(iterator position) {
			delEnd(_end);
			erase(position->first);
			std::cout << _size << std::endl;
			if (_size > 0)
				_end = getEnd();
		};
		size_type erase(const key_type& x) {
			size_type	ret = 0;
			value_type	tmp = ft::make_pair<key_type, mapped_type>(x, mapped_type());
			iterator	res = _root.find(tmp);
			if (res.base()) {delEnd(_end); erase(tmp); ret++; _size--;}
			_end = _root.getEnd();
			return ret;
		};
		void erase(iterator first, iterator last) {
			for (iterator it = first; it != --last; it++) {
				erase(it);
			}
		};
		*/
//		void swap(map<Key,T,Compare,Allocator>&);
		void clear() {
			std::cout << "clear started\n";
			this->erase(this->begin(), this->end());
		};
		// observers:
		void printmap() {this->inOrderTree(_root);}
		/*
		key_compare key_comp() const;
		value_compare value_comp() const;
		// 23.3.1.3 map operations:
		// */
		iterator find(const key_type& x) {
			value_type	pr = ft::make_pair<key_type, mapped_type>(x, mapped_type());
			printNode(_root, "from find: ");
			iterator	res(searchIt(_root, pr));
			std::cout << "find " << res.base() << std::endl;
			return res;
		};
//		const_iterator find(const key_type& x) const;
		size_type count(const key_type& x) {
			size_type	res = 0;
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
