#include "binary_trees.h"

size_t tree_height(const binary_tree_t *tree);
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
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 0 if not full, 1 if full
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (half_nodes(tree) != 0)
		return (0);
	if ((tree->left && !tree->right) || (!tree->left && tree->right))
		return (0);
	if (tree_height(tree->left) != tree_height(tree->right))
		return (0);
	return (1);
}
/**
 * tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height.
 *
 * Return: Height of the tree, or 0 on failure
 */
size_t tree_height(const binary_tree_t *tree)
{
	size_t count1, count2;

	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);
	count1 = tree_height(tree->left);
	count2 = tree_height(tree->right);
	if (count1 > count2)
		return (count1 + 1);
	return (count2 + 1);
}
