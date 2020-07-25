#include "binary_trees.h"

/**
 * bst_search - searches for a value in a Binary Search Tree
 * @tree: pointer to the root node of the BST to search
 * @value: value to search in the tree
 *
 * Return: pointer to the node containing a value equal to value
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	const bst_t *tmp = tree;

	if (tree == NULL)
		return (NULL);
	while (tmp != NULL && tmp->n != value)
	{
		if (value > tmp->n)
			tmp = tmp->right;
		else if (value < tmp->n)
			tmp = tmp->left;
	}
	return ((void *)tmp);
}
