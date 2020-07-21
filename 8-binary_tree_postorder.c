#include "binary_trees.h"

void traverse(const binary_tree_t *tree, void (*func)(int));
/**
 * binary_tree_postorder - goes through a binary tree using post-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 *
 * Return: Void
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;
	traverse(tree, func);
}
/**
 * traverse - traverses a binary tree, performing a function on the nodes
 * @tree: pointer to the current node
 * @func: function to perform
 */
void traverse(const binary_tree_t *tree, void (*func)(int))
{
	if (tree != NULL)
	{
		traverse(tree->left, func);
		traverse(tree->right, func);
		func(tree->n);
	}
}
