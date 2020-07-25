#include "binary_trees.h"

/**
 * binary_tree_is_leaf - checks if a node is a leaf
 * @node: pointer to the node to check
 *
 * Return: 1 if node is a leaf, otherwise 0
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	if (node->left == NULL && node->right == NULL)
		return (1);
	return (0);
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
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 0 on failure or if not complete, 1 if complete
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (half_nodes(tree) > 1)
		return (0);
	if (tree_height(tree->left) == tree_height(tree->right) &&
	    half_nodes(tree) == 0)
		return (1);
	return (0);
}
