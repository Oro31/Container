#ifndef TREE_HPP
# define TREE_HPP

# include <iostream>
# include <bits/stdc++.h>
# include <memory>

struct Node {
	int	key;
	int	height;
	struct Node	*parent;
	struct Node	*left;
	struct Node	*right;
};

int	max(int a, int b);
int	height(Node *node);
int	getBalance(Node *node);

void	getMaxHeight(Node *root, int *height);
void	inOrderTree(Node *node);
void	searchNode(Node *root, Node **result, int key);

Node	*newNode(int key);
Node	*minValueNode(Node *node);
Node	*maxValueNode(Node *node);
Node	*getNextNode(Node *node);
Node	*rightRotate(Node *y);
Node	*leftRotate(Node *x);
Node	*insertVal(Node *node, int key);
Node	*deleteNode(Node *root, int key);

#endif
