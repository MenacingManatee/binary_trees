#include "binary_trees.h"

/**
 * height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height.
 *
 * Return: Height of the tree, or 0 on failure
 */
size_t height(const binary_tree_t *tree)
{
	size_t count1, count2;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (0);
	count1 = height(tree->left);
	count2 = height(tree->right);
	if (count1 > count2)
		return (count1 + 1);
	return (count2 + 1);
}
/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 *
 * Return: balance of the tree
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left, right;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL)
		left = -1;
	else
		left = height(tree->left);
	if (tree->right == NULL)
		right = -1;
	else
		right = height(tree->right);
	return (left - right);
}
/**
 * avl_check - recursively checks if all nodes are avl trees
 * @tree: pointer to node to check
 *
 * Return: zero if valid, nonzero if invalid
 */
int avl_check(const binary_tree_t *tree)
{
	int balance, a, b;

	if (tree == NULL)
		return (0);
	balance = binary_tree_balance(tree);
	if (balance > 1 || balance < -1)
		return (1);
	a = avl_check(tree->left);
	b = avl_check(tree->right);
	return (a + b);
}
/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (!avl_check(tree))
		return (1);
	return (0);
}
