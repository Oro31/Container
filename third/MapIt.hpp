#include <iostream>
#include <bits/stdc++.h>
#include <memory>
#include "pair.hpp"

namespace ft {
	/*,
			  class Compare = std::less<Key>>,
			  class Allocator = std::allocator<std::pair<const Key, T>
				>*/
//	template <class Key, class T>	
	template <class T>	
	class MapIt {
			public:
				typedef T										value_type;
				typedef typename value_type::first_type			key_type;
				typedef typename value_type::second_type		mapped_type;
				typedef value_type								*pointer;
				typedef value_type								&reference;
				typedef std::ptrdiff_t							difference_type;
				typedef std::bidirectional_iterator_tag			iterator_category;

			private:
				struct Node {
					bool			end;
					value_type		pair;
					int				height;
					struct Node		*parent;
					struct Node		*left;
					struct Node		*right;

					Node() {
						end = false;
						pair = T();
						height = 1;
						parent = NULL;
						left = NULL;
						right = NULL;
					};

					Node(value_type pr) {
						end = false;
						pair = pr;
						height = 1;
						parent = NULL;
						left = NULL;
						right = NULL;
					};
					Node(Node *node) {
						end = node->end;
						pair = ft::make_pair(node->pair.first, node->pair.second);
						height = node->height;
						parent = node->parent;
						left = node->left;
						right = node->right;
					};
				};
				void printNode(Node *node, std::string str) {
					std::cout << "from: " << str;
					if (node) {std::cout << ": first = " << node->pair.first;}
					std::cout << ": root = " << node
						<< ", parent = " << node->parent
						<< ", right = " << node->right
						<< ", left = " << node->left << std::endl;
				}

				Node	*_root;
//				Compare	_comp;

			public:

				MapIt() {_root = NULL;};
				MapIt(value_type pair) {_root = newNode(pair);};
				~MapIt() {};
				template<class Iterator>
				MapIt(const Iterator &it) {*this = it;};

				MapIt(Node *node) {
					_root = node;
				};

//				MapIt &operator=(const pointer it) {root->pair = it; return *this;};
				MapIt &operator=(const MapIt &it) {
					_root = it._root;
//					_root->end = it._root->end;
//					_root->pair = make_pair(it->first, it->second);
//					_root->height = it._root->height;
//					_root->parent = it._root->parent;
//					_root->left = it._root->left;
//					_root->right = it._root->right;
					return *this;
				};
				MapIt(const MapIt &it) {*this = it;};

				reference operator*() {return _root->pair;};
				pointer operator->() {return &(_root->pair);};
				const pointer operator->() const {return _root->pair;};
				Node *base() {return _root;};
				const Node *base() const {return _root;};

				MapIt &operator++() {
					std::cout << "before ope++: " << "root = " << _root << ", parent = " << _root->parent << ", right = " << _root->right << ", left = " << _root->left << std::endl;
					_root = getNextNode(_root);
					std::cout << "ope++: " << "root = " << _root << ", parent = " << _root->parent << ", right = " << _root->right << ", left = " << _root->left << std::endl;
					return *this;
				};
				MapIt &operator--() {
					std::cout << "before ope--: " << "root = " << _root << ", parent = " << _root->parent << ", right = " << _root->right << ", left = " << _root->left << std::endl;
					_root = getPrevNode(_root);
					std::cout << "ope--: " << "root = " << _root << ", parent = " << _root->parent << ", right = " << _root->right << ", left = " << _root->left << std::endl;
					return *this;
				};
				MapIt operator++(int) {MapIt tmp(*this); operator++(); return tmp;};
				MapIt operator--(int) {MapIt tmp(*this); operator--(); return tmp;};
				
				MapIt &operator+=(int n) {for (int i = 0; i < n; i++) {operator++();} return *this;};
				MapIt &operator-=(int n) {for (int i = 0; i < n; i++) {operator--();} return *this;};

				mapped_type &operator[](key_type k) {return this->find(k)->second;};
				MapIt operator+(int n) const {MapIt r(*this); r+=n; return r;};
				MapIt operator-(int n) const {MapIt r(*this); r-=n; return r;};

				int max(int a, int b) {
					return (a > b) ? a : b;
				};

				int height(Node *node) {
					if (!node) {return 0;}
					return node->height;
				};

				Node *newNode(value_type &pair) {
					return new Node(pair);
				};

				void getMaxHeight(Node *root, int *height) {
					if (!root) {return ;}
					getMaxHeight(root->left, height);
					if (root->height > *height) {*height = root->height;}
					getMaxHeight(root->right, height);
				};

				Node *minValueNode(Node *node) {
					Node	*current = node;
					while (current && current->left != NULL)
						current = current->left;
					return current;
				};

				Node *maxValueNode(Node *node) {
					Node	*current = node;
					while (current && current->right != NULL && !current->right->end)
						current = current->right;
					return current;
				};

				Node *getPrevNode(Node *node) {
					printNode(node, "gp");
					if (!node)
						return NULL;
					Node	*tmp = node;
					if (tmp->left) {
						std::cout << "from getPrev1: " << maxValueNode(tmp->left) << std::endl;
						return maxValueNode(tmp->left);
					}
					if (!tmp->parent)
						return NULL;
					if (tmp->parent && tmp == tmp->parent->right) {
						std::cout << "from getPrev2: " << tmp->parent << std::endl;
						return tmp->parent;
					}
					if (tmp->parent && tmp->parent->parent) {
						std::cout << "from getPrev3: " << tmp->parent->parent << std::endl;
						return tmp->parent->parent;
					}
//					while (tmp->parent && tmp->parent->pair.first < node->pair.first)
//						tmp = tmp->parent;
//					if (tmp->pair.first == this->minValueKey(node))
//						return NULL;
					std::cout << "from getPrev4: " << tmp->left << std::endl;
//					return tmp->parent;
					return tmp->left;
				};

				Node *getNextNode(Node *node) {
					printNode(node, "gn");
					if (!node)
						return NULL;
					Node	*tmp = node;
					if (tmp->right) {
						std::cout << "from getNext1: " << minValueNode(tmp->right) << std::endl;
						return minValueNode(tmp->right);
					}
					if (!tmp->parent)
						return NULL;
					if (tmp->parent && tmp == tmp->parent->left) {
						std::cout << "from getNext2: " << tmp->parent << std::endl;
						return tmp->parent;
					}
					if (tmp->parent && tmp->parent->parent) {
						std::cout << "from getNext3: " << tmp->parent->parent << std::endl;
						return tmp->parent->parent;
					}
//					while (tmp->parent && tmp->parent->pair.first < node->pair.first)
//						tmp = tmp->parent;
//					if (tmp->pair.first == this->minValueKey(node))
//						return NULL;
//					return tmp->parent;
					std::cout << "from getNext4: " << tmp->right << std::endl;
					return tmp->right;
				};

				Node *rightRotate(Node *y) {
					printNode(y, "rr");
					Node	*x = y->left;
					Node	*T2 = x->right;

					x->right = y;
					y->left = T2;
					y->parent = x;
					x->parent = NULL;

					y->height = max(height(y->left),
							height(y->right)) + 1;
					x->height = max(height(x->left),
							height(x->right)) + 1;
					printNode(y, "rr");

					return x;
				};

				Node *leftRotate(Node *x) {
					printNode(x, "lr");
					Node	*y = x->right;
					Node	*T2 = y->left;

					y->left = x;
					x->right = T2;
					x->parent = y;
					y->parent = NULL;

					x->height = max(height(x->left),
							height(x->right)) + 1;
					y->height = max(height(y->left),
							height(y->right)) + 1;
					printNode(x, "lr");

					return y;
				};

				int getBalance(Node *node) {
					if (!node) {return 0;}
					return height(node->left) - height(node->right);
				};

				Node *insertVal(Node *node, value_type pair) {
					if (!node) {return newNode(pair);}
					if (pair.first < node->pair.first) {
						node->left = insertVal(node->left, pair);
					} else if (pair.first > node->pair.first) {
						node->right = insertVal(node->right, pair);
					} else {return node;}

					node->height = 1 + max(height(node->left),
							height(node->right));

					int	balance = getBalance(node);

					if (balance > 1 && pair.first < node->left->pair.first) {return rightRotate(node);}
					if (balance < -1 && pair.first > node->right->pair.first) {return leftRotate(node);}
					if (balance > 1 && pair.first > node->left->pair.first) {
						node->left = leftRotate(node->left);
						return rightRotate(node);
					}
					if (balance < -1 && pair.first < node->right->pair.first) {
						node->right = rightRotate(node->right);
						return leftRotate(node);
					}
					if (node->left) {node->left->parent = node;}
					if (node->right) {node->right->parent = node;}

					return node;
				};

				void inOrderTree(Node *root) {
					if (!root) {return;}
					inOrderTree(root->left);
					std::cout << "inorder root->key = " << root->pair.first << std::endl;
					inOrderTree(root->right);
				};


				Node *deleteNode(Node *root, key_type k) {
					if (!root) {return root;}
					if (k < root->pair.first) {
						root->left = deleteNode(root->left, k);
					} else if (k > root->pair.first) {
						root->right = deleteNode(root->right, k);
					} else {
						if (!root->left || !root->right) {
							Node	*tmp = root->left ? root->left : root->right;
							if (!tmp) {
								tmp = root;
								root = NULL;
							} else {
								*root = *tmp;
							}
							free(tmp);
						} else {
							Node	*tmp = minValueNode(root->right);
							root->pair = tmp->pair;
							root->right = deleteNode(root->right, tmp->pair.first);
						}
					}
					if (!root) {return root;}
					root->height = 1 + max(height(root->left),
											height(root->right));

					int balance = getBalance(root);
					if (balance > 1 && getBalance(root->left) >= 0) {
						return rightRotate(root);
					}
					if (balance > 1 && getBalance(root->left) < 0) {
						root->left = leftRotate(root->left);
						return rightRotate(root);
					}
					if (balance < -1 && getBalance(root->right) <= 0) {return leftRotate(root);}
					if (balance < -1 && getBalance(root->right) > 0) {
						root->right = rightRotate(root->right);
						return leftRotate(root);
					}
					return root;
				};
				void searchIt(MapIt *ret, Node *node, key_type k) {
					if (!node)
						return ;
					else if (node->pair.first == k)
						ret->_root = node;
					searchIt(ret, node->left, k);
					searchIt(ret, node->right, k);
				}
				key_type minValueKey(Node *node) {
					Node	*current = node;
					while (current && current->left != NULL)
						current = current->left;
					return current->pair.first;
				};
				key_type maxValueKey(Node *node) {
					Node	*current = node;
					while (current && current->right != NULL && !current->right->end)
						current = current->right;
					return current->pair.first;
				};
///////////////////////////************************////////////////////////////////
				void insert(value_type pr) {
					_root = insertVal(_root, pr);
				};
				void delEnd() {
					Node *tmp = this->maxValueNode(_root);
					std::cout << tmp << std::endl;
					if (tmp && tmp->right && tmp->right->end) {
						tmp->right->end = false;
						tmp->right = NULL;
					}
				}
				MapIt getEnd() {
					Node *tmp = this->maxValueNode(_root);
					std::cout << "max = " << tmp << std::endl;
					if (tmp->right && tmp->right->end)
						return MapIt(tmp->right);
					Node *end = new Node();
					end->end = true;
					tmp->right = end;
					end->parent = tmp;
					std::cout << "return = " << end << std::endl;
					return MapIt(end);
				};
				void print() {this->inOrderTree(_root);};
				void erase(key_type k) {_root = deleteNode(_root, k);};
				MapIt find(key_type k) {
					MapIt	ret;
					searchIt(&ret, _root, k);
					return ret;
				};
				template<class Iterator>
					friend bool operator!=(const Iterator &lhs, const Iterator &rhs);
				template<class Iterator>
					friend bool operator==(const Iterator &lhs, const Iterator &rhs);
				template<class Iterator>
					friend bool operator>(const Iterator &lhs, const Iterator &rhs);
				template<class Iterator>
					friend bool operator>=(const Iterator &lhs, const Iterator &rhs);
				template<class Iterator>
					friend bool operator<(const Iterator &lhs, const Iterator &rhs);
				template<class Iterator>
					friend bool operator<=(const Iterator &lhs, const Iterator &rhs);
		};
			template<class Iterator>
				bool operator!=(const Iterator &lhs, const Iterator &rhs) {
//					std::cout << lhs.base() << "!= " << rhs.base();
					return lhs.base()->pair.first != rhs.base()->pair.first; //lhs != rhs;
				}
			template<class Iterator>
				bool operator<(const Iterator &lhs, const Iterator &rhs) {
					return lhs.base()->pair.first < rhs.base()->pair.first;
				}
			template<class Iterator>
				bool operator==(const Iterator &lhs, const Iterator &rhs) {
					return lhs == rhs;
				}
			template<class Iterator>
				bool operator>(const Iterator &lhs, const Iterator &rhs) {
					return lhs != rhs && !(lhs < rhs);
				}
			template<class Iterator>
				bool operator>=(const Iterator &lhs, const Iterator &rhs) {
					return lhs > rhs && lhs == rhs;
				}
			template<class Iterator>
				bool operator<=(const Iterator &lhs, const Iterator &rhs) {
					return lhs < rhs && lhs == rhs;
				}
}
