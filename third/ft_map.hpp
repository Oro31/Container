#include <iostream>
#include <bits/stdc++.h>
#include <memory>
#include "tree.hpp"

namespace ft {
	template <
		class Key,
			  class T,
			  class Compare = std::less<Key>,
			  class Allocator = std::allocator<std::pair<const Key, T>>
		>
		class map {
			public:
				typedef Key										key_type;
				typedef T										mapped_type;
				typedef pair<const Key, T>						value_type;
				typedef Compare									key_compare;
				typedef Allocator								allocator_type;
				typedef typename Allocator::reference			reference;
				typedef typename Allocator::const_reference		const_reference;
				typedef MapIterator<value_type>					iterator;
				typedef const MapIterator<calue_type>			const_iterator;
				typedef std::size_t								size_type;
				typedef std::ptrdiff_t							difference_type;
				typedef typename Allocator::pointer				pointer;
				typedef typename Allocator::const_pointer		const_pointer;
				typedef std::reverse_iterator<iterator>			revers_iterator;
				typedef std::const_reverse_iterator<iterator>	const_reverse_iterator;

			private:
				struct Node {
					value_type		_pair;
					int				_height;
					struct Node		*parent;
					struct Node		*left;
					struct Node		*right;
				};
				Node	*root;
				Node	*tmp;

				int max(int a, int b) {
					return (a > b) ? a : b;
				};

				int height(Node *node) {
					if (!node) {return 0;}
					return node->height;
				}

				Node *newNode(int key) {
					Node	*tmp = (Node *) malloc(sizeof(Node));
					tmp->height = 1;
					tmp->key = key;
					tmp->left = NULL;
					tmp->right = NULL;
					tmp->parent = NULL;
					return tmp;
				}

				void getMaxHeight(Node *root, int *height) {
					if (!root) {return ;}
					getMaxHeight(root->left, height);
					if (root->height > *height) {*height = root->height;}
					getMaxHeight(root->right, height);
				}

				Node *minValueNode(Node *node) {
					Node	*current = node;
					while (current && current->left != NULL) {current = current->left;}
					return current;
				}

				Node *maxValueNode(Node *node) {
					Node	*current = node;
					while (current && current->right != NULL) {current = current->right;}
					return current;
				}

				Node *getNextNode(Node *node) {
					if (!node) {return NULL;}
					Node	*tmp = node;
					if (tmp->right) {
						return minValueNode(tmp->right);
					}
					if (tmp->parent && tmp == tmp->parent->left) {
						return tmp->parent;
					}
					if (!tmp->parent)
						return NULL;
					while (tmp->parent && tmp->parent->key < node->key) {
						tmp = tmp->parent;
					}
					return tmp->parent;
				}

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
				}

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
				}

				int getBalance(Node *node) {
					if (!node) {return 0;}
					return height(node->left) - height(node->right);
				}

				Node *insertVal(Node *node, int key) {
					if (!node) {return newNode(key);}
					if (key < node->key) {
						node->left = insertVal(node->left, key);
					} else if (key > node->key) {
						node->right = insertVal(node->right, key);
					} else {return node;}

					node->height = 1 + max(height(node->left),
							height(node->right));

					int	balance = getBalance(node);

					if (balance > 1 && key < node->left->key) {return rightRotate(node);}
					if (balance < -1 && key > node->right->key) {return leftRotate(node);}
					if (balance > 1 && key > node->left->key) {
						node->left = leftRotate(node->left);
						return rightRotate(node);
					}
					if (balance < -1 && key < node->right->key) {
						node->right = rightRotate(node->right);
						return leftRotate(node);
					}
					if (node->left) {node->left->parent = node;}
					if (node->right) {node->right->parent = node;}

					return node;
				}

				void inOrderTree(Node *root) {
					if (!root) {return;}
					inOrderTree(root->left);
					std::cout << "inorder root->key = " << root->key << std::endl;
					inOrderTree(root->right);
				};


				Node *deleteNode(Node *root, int key) {
					if (!root) {return root;}
					if (key < root->key) {
						root->left = deleteNode(root->left, key);
					} else if (key > root->key) {
						root->right = deleteNode(root->right, key);
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
							root->key = tmp->key;
							root->right = deleteNode(root->right, tmp->key);
						}
					}
					if (!root) {return root;}
					root->height = 1 + max(height(root->left),
											height(root->right));

					int balance = getBalance(root);
					if (balance > 1 && getBalance(root->left) >= 0) {return rightRotate(root);}
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
				}

				void searchNode(Node *root, Node **result, int key) {
					if (!root) {return ;}
					else if (root->key == key) {*result = root; return ;}
					std::cout << "search...\n";
					searchNode(root->left, result, key);
					searchNode(root->right, result, key);
				}
		}
}
