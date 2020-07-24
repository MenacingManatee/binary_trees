#include "binary_trees.h"
#include <stdio.h>

/**
 * tree_check - recursively checks if a binary tree is a valid BST
 * @tree:  pointer to the root node of the tree to check
 *
 * Return: 0 if not valid, nonzero if valid
 */
int tree_check(const binary_tree_t *tree)
{
	int a, b;

	if (tree == NULL)
		return (1);
	if (tree->left)
		if (tree->n < tree->left->n)
		{
			return (0);
		}

	if (tree->right)
		if (tree->n > tree->right->n)
		{
			return (0);
		}

	if (tree->parent)
		if (tree->n > tree->parent->n && tree->parent->right != tree)
		{
			return (0);
		}

	a = tree_check(tree->left);
	b = tree_check(tree->right);
	if (a == 0 || b == 0)
		return (0);
	return (1);
}
/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (tree_check(tree) ? 1 : 0);
}
