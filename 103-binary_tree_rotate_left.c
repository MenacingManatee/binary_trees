#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 *
 * Return: pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *left;

	if (tree == NULL || tree->right == NULL)
		return (NULL);
	left = tree->right->left;
	tree->right->parent = NULL;
	tree->parent = tree->right;
	tree->right = left;
	tree->parent->left = tree;
	if (left != NULL)
		left->parent = tree;
	return (tree->parent);
}
