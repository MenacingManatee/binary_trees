#include "binary_trees.h"

/**
 * half_nodes - counts the nodes with only one child
 * @tree: pointer to the root node of the tree to measure the size
 *
 * Return: the size of a binary tree, or 0 on failure
 */
size_t half_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (0);
	if ((tree->left && !tree->right) || (!tree->left && tree->right))
		return (1);
	return ((half_nodes(tree->left)) + (
			half_nodes(tree->right)));
}
/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 0 if not full, 1 if full
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (half_nodes(tree) != 0)
		return (0);
	return (1);
}
