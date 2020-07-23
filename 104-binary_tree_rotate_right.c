#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a left-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 *
 * Return: pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *right;

	if (tree == NULL || tree->left == NULL)
		return (NULL);
	right = tree->left->right;
	tree->left->parent = NULL;
	tree->parent = tree->left;
	tree->left = right;
	tree->parent->right = tree;
	if (right != NULL)
		right->parent = tree;
	return (tree->parent);
}
