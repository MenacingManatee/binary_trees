#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height.
 *
 * Return: Height of the tree, or 0 on failure
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t count1, count2;

	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);
	count1 = binary_tree_height(tree->left);
	count2 = binary_tree_height(tree->right);
	if (count1 > count2)
		return (count1 + 1);
	return (count2 + 1);
}
