#include <iostream>
#include <bits/stdc++.h>
#include <memory>

struct Node {
	int	key;
	int	height;
	struct Node	*left;
	struct Node	*right;
};

int max(int a, int b) {
	return (a > b) ? a : b;
};

int height(Node *N) {
	if (!N) {return 0;}
	return N->height;
};

Node *newNode(int key) {
	Node	*tmp = (Node *) malloc(sizeof(Node));
	tmp->height = 1;
	tmp->key = key;
	tmp->left = NULL;
	tmp->right = NULL;
	return tmp;
};

Node *rightRotate(Node *y) {
	Node	*x = y->left;
	Node	*T2 = x->right;

	x->right = y;
	y->left = T2;

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

	x->height = max(height(x->left),
			height(x->right)) + 1;
	y->height = max(height(y->left),
			height(y->right)) + 1;

	return y;
};

int getBalance(Node *N) {
	if (!N) {return 0;}
	return height(N->left) - height(N->right);
};


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

	return node;
};

void preOrder(Node *root) {
	if (!root) {return;}
	std::cout << root->key << " ";
	preOrder(root->left);
	preOrder(root->right);
}

void inorderTree(Node *root) {
	if (!root) {return;}
	inorderTree(root->left);
	std::cout << "inorder root->key = " << root->key << std::endl;
	inorderTree(root->right);
};

Node *minValueNode(Node *node) {
	Node	*current = node;
	while (current && current->left != NULL) {current = current->left;}
	return current;
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

int	main() {
	int	tab[5];
	int	mtab[5];
	for (int i = 0; i < 5; i++) {mtab[i] = i - 5; tab[i] = i;}
	Node	*root = NULL;
	for (int i = 0; i < 5; i++) {
		root = insertVal(root, tab[i]);
		root = insertVal(root, mtab[i]);
	}
	preOrder(root);
	root = deleteNode(root, 1);
	std::cout << "\nafter deleted 1" << std::endl;
	preOrder(root);
	return 0;
}
