#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the leaves of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 *
 * Return: the size of a binary tree, or 0 on failure
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (0);
	return (1 + (binary_tree_nodes(tree->left)) + (
			binary_tree_nodes(tree->right)));
}
