#include <iostream>
#include <bits/stdc++.h>
#include <memory>
#include "pair.hpp"

namespace ft {
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
					value_type		pair;
					int				height;
					struct Node		*parent;
					struct Node		*left;
					struct Node		*right;
					Node() {
						pair = T();
						height = 1;
						parent = NULL;
						left = NULL;
						right = NULL;
					};
					Node(value_type pr) {
						pair = pr;
						height = 1;
						parent = NULL;
						left = NULL;
						right = NULL;
					};
					Node(Node *node) {
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
						<< ", parent = " << node->parent;
					if (node->parent) {std::cout << "parent->first = " << node->parent->pair.first << std::endl;}
					std::cout << ", right = " << node->right;
					if (node->right) {std::cout << "right->first = " << node->right->pair.first << std::endl;}
					std::cout << ", left = " << node->left;
					if (node->left) {std::cout << "left->first = " << node->left->pair.first << std::endl;}
					else 
						std::cout << std::endl;
				}

				Node	*_root;
//				Compare	_comp;

			public:

				MapIt() {_root = NULL;};
				MapIt(Node *node) : _root(node) {};
				MapIt(value_type pair) {_root = newNode(NULL, pair);};
				~MapIt() {};
				template<class Iterator>
				MapIt(const Iterator &it) {*this = it;};


				MapIt &operator=(const MapIt &it) {
					_root = it._root;
					return *this;
				};
				MapIt(const MapIt &it) {*this = it;};

				reference operator*() {return _root->pair;};
				pointer operator->() {return &(_root->pair);};
				const pointer operator->() const {return _root->pair;};
				Node *base() {return _root;};
				const Node *base() const {return _root;};

				/*
				MapIt &operator++() {
					_root = getNextNode(_root);
					return *this;
				};
				MapIt &operator--() {
					_root = getPrevNode(_root);
					return *this;
				};
				MapIt operator++(int) {MapIt tmp(*this); operator++(); return tmp;};
				MapIt operator--(int) {MapIt tmp(*this); operator--(); return tmp;};
				
				MapIt &operator+=(int n) {for (int i = 0; i < n; i++) {operator++();} return *this;};
				MapIt &operator-=(int n) {for (int i = 0; i < n; i++) {operator--();} return *this;};

				mapped_type &operator[](key_type k) {return this->find(k)->second;};
				MapIt operator+(int n) const {MapIt r(*this); r+=n; return r;};
				MapIt operator-(int n) const {MapIt r(*this); r-=n; return r;};
				*/

				int max(int a, int b) {
					return (a > b) ? a : b;
				};

				int height(Node *node) {
					if (!node) {return 0;}
					return node->height;
				};

				void printOrder(struct Node *root) {
					if (root)
						std::cout << "Node: " << root->pair.first << std::endl;
					if (root->parent)
						std::cout << "Parent: " << root->parent->pair.first << std::endl;
					if (root->left)
						printOrder(root->left);
					if (root->right)
						printOrder(root->right);
				}



				void UpdateHeight(struct Node *root) {
					if (root) {
						int val = 1;
						if (root->left)
							val = root->left->height + 1;
						if (root->right)
							val = max(val, root->right->height + 1);
						root->height = val;
					}
				}

				struct Node *newNode(struct Node *parent, value_type pair) {
					struct Node *root;
					root = new struct Node;
					root->height= 1;
					root->left = NULL;
					root->right = NULL;
					root->parent = parent;
					root->pair = pair;
					return root;
				}

				struct Node *LLR(struct Node *root) {
					struct Node *tmpNode = root->left;
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

				struct Node *RRR(struct Node *root) {
					struct Node *tmpNode = root->right;
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

				struct Node *LRR(struct Node *root) {
					root->left = RRR(root->left);
					return LLR(root);
				}

				struct Node *RLR(struct Node *root) {
					root->right = LLR(root->right);
					return RRR(root);
				}

				struct Node *Balance(struct Node *root) {
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

				struct Node *Insert(struct Node *root,
									struct Node *parent, value_type pair){
					if (!root) {
						root = new struct Node;
						root->height= 1;
						root->left = NULL;
						root->right = NULL;
						root->parent = parent;
						root->pair = pair;
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

				struct Node *Delete(struct Node *root, key_type key) {
					if (root) {
						if (root->pair.first == key) {
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
								struct Node *tmpNode = root;
								tmpNode = tmpNode->right;
								while (tmpNode->left)
									tmpNode = tmpNode->left;
								value_type val = tmpNode->pair;
								root->right = Delete(root->right, tmpNode->pair.first);
								root->pair = val;
								root = Balance(root);
							}
						} else if (root->pair.first < key) {
							root->right = Delete(root->right, key);
							root = Balance(root);
						} else if (root->pair.first > key) {
							root->left = Delete(root->left, key);
							root = Balance(root);
						}
						if (root)
							UpdateHeight(root);
					}
					return root;
				}
///////////////////////////************************////////////////////////////////
				void print() {this->printOrder(_root);};
				void insert(value_type pr) {_root = Insert(_root, NULL, pr);};
				void erase(key_type k) {_root = Delete(_root, k);};
				/*
				MapIt find(key_type k) {
					MapIt	ret;
					searchIt(&ret, _root, k);
					return ret;
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
					if (tmp->right && tmp->right->end) {
						return MapIt(tmp->right);
					}
					Node *end = new Node();
					end->end = true;
					tmp->right = end;
					end->parent = tmp;
					return MapIt(end);
				};
				*/
				template<class Iterator>
					friend bool operator!=(const Iterator &lhs, const Iterator &rhs);
				template<class Iterator>
					friend bool operator==(const Iterator &lhs, const Iterator &rhs);
				/*
				template<class Iterator>
					friend bool operator>(const Iterator &lhs, const Iterator &rhs);
				template<class Iterator>
					friend bool operator>=(const Iterator &lhs, const Iterator &rhs);
				template<class Iterator>
					friend bool operator<(const Iterator &lhs, const Iterator &rhs);
				template<class Iterator>
					friend bool operator<=(const Iterator &lhs, const Iterator &rhs);
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
}
