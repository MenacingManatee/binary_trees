#include "binary_trees.h"
#include <stdio.h>

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
