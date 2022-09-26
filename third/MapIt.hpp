#include <iostream>
#include <bits/stdc++.h>
#include <memory>

namespace ft {
	template <class Key, class T>
//			  class Compare = std::less<Key>,
//			  class Allocator = std::allocator<std::pair<const Key, T>>
		class MapIt {
			public:
				typedef std::pair<Key, T>						value_type;
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
						pair = std::pair<Key, T>();
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
				};

				Node	*_root;

			public:

				MapIt() {_root = NULL;};
				MapIt(value_type pair) {_root = newNode(pair);};
				~MapIt() {};

				MapIt(Node *node) {
					_root = node;
				};

//				MapIt &operator=(const pointer it) {root->pair = it; return *this;};
				MapIt &operator=(const MapIt &it) {
					_root = it._root;
					_root->end = it._root->end;
					_root->pair = it._root->pair;
					_root->height = it._root->height;
					_root->parent = it._root->parent;
					_root->left = it._root->left;
					_root->right = it._root->right;
					return *this;
				};
				MapIt(const MapIt &it) {*this = it;};

				reference operator*() {return *(_root->pair);};
				pointer operator->() {return &(_root->pair);};
				const pointer operator->() const {return _root->pair;};
				Node *base() {return _root;};
				const Node *base() const {return _root;};

				MapIt &operator++() {_root = getNextNode(_root); return *this;};
				MapIt &operator--() {_root = getPrevNode(_root); return *this;};
				MapIt operator++(int) {MapIt tmp(*this); operator++(); return tmp;};
				MapIt operator--(int) {MapIt tmp(*this); operator--(); return tmp;};
				
				MapIt &operator+=(int n) {for (int i = 0; i < n; i++) {operator++();} return *this;};
				MapIt &operator-=(int n) {for (int i = 0; i < n; i++) {operator--();} return *this;};

				T &operator[](Key k) {return this->find(k)->second;};
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
					if (!node)
						return NULL;
					Node	*tmp = node;
					if (tmp->left)
						return maxValueNode(tmp->left);
					if (tmp->parent && tmp == tmp->parent->right)
						return tmp->parent;
					if (!tmp->parent)
						return NULL;
					while (tmp->parent && tmp->parent->pair.first < node->pair.first)
						tmp = tmp->parent;
					if (tmp->pair.first == this->minValueKey(node))
						return NULL;
					return tmp->parent;
				};

				Node *getNextNode(Node *node) {
					if (!node)
						return NULL;
					Node	*tmp = node;
					if (tmp->right)
						return minValueNode(tmp->right);
					if (tmp->parent && tmp == tmp->parent->left)
						return tmp->parent;
					if (!tmp->parent)
						return NULL;
					while (tmp->parent && tmp->parent->pair.first < node->pair.first)
						tmp = tmp->parent;
					return tmp->parent;
				};

				Node *rightRotate(Node *y) {
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

					return x;
				};

				Node *leftRotate(Node *x) {
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


				Node *deleteNode(Node *root, Key k) {
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
				void searchIt(MapIt *ret, Node *node, Key k) {
					if (!node)
						return ;
					else if (node->pair.first == k)
						ret->_root = node;
					searchIt(ret, node->left, k);
					searchIt(ret, node->right, k);
				}
				Key minValueKey(Node *node) {
					Node	*current = node;
					while (current && current->left != NULL)
						current = current->left;
					return current->pair.first;
				};
				Key maxValueKey(Node *node) {
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
					if (tmp && tmp->right && tmp->right->end) {
						tmp->right->end = false;
						tmp->right = NULL;
					}
				}
				MapIt getEnd() {
					Node *tmp = this->maxValueNode(_root);
					if (tmp->right && tmp->right->end)
						return MapIt(tmp->right);
					Node *end = new Node();
					end->end = true;
					tmp->right = end;
					end->parent = tmp;
					return MapIt(end);
				};
				void print() {this->inOrderTree(_root);};
				void erase(Key k) {_root = deleteNode(_root, k);};
				MapIt find(Key k) {
					MapIt	ret;
					searchIt(&ret, _root, k);
					return ret;
				};
		};
}
