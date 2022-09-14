#include <iostream>
#include <memory>

struct Node {
	int	data;
	struct Node	*left;
	struct Node	*right;
};

Node newNode(int x) {
	Node	*tmp = malloc(sizeof(Node));
	tmp->data = x;
	tmp->left = NULL;
	tmp->right = NULL;
}

int	main() {
	Node	*root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
}
