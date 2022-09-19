#include "tree.hpp"

int	main() {
	int	tab[5];
	int	mtab[5];
	for (int i = 0; i < 5; i++) {mtab[i] = i - 5; tab[i] = i;}
	Node	*root = NULL;
	for (int i = 0; i < 5; i++) {
		root = insertVal(root, mtab[i]);
		std::cout << "inserted " << mtab[i] << std::endl;
		root = insertVal(root, tab[i]);
		std::cout << "inserted " << tab[i] << std::endl;
	}
	std::cout << "/////////result//////////" << std::endl;

	Node *search = NULL;
	searchNode(root, &search, 2);
	if (search)
		std::cout << "root.search(2) = " << search->key << std::endl;
	int mh = 0;
	getMaxHeight(root, &mh) ;
	std::cout << "max height = " << mh << std::endl;
	std::cout << "\n////////////max and min///////////" << std::endl;
	Node	*next = maxValueNode(root);
	std::cout << "max = " << next->key << std::endl;
	next = minValueNode(root);
	std::cout << "min = " << next->key << std::endl;
	std::cout << "\n////////////++ope///////////" << std::endl;
	while (next) {std::cout << "++" << next->key << std::endl;next = getNextNode(next);}
	std::cout << "\n////////////inorder///////////" << std::endl;
	inOrderTree(root);
	return 0;
}
