#include "binary_trees.h"
#include <stdio.h>

/**
 * print_tier - performs a function on each level of a binary tree
 * @tree: pointer to the root node of the tree to traverse
 * @tier: level to perform the function on
 * @func: pointer to a function to call for each node.
 *
 */
void print_tier(const binary_tree_t *tree, int tier, void (*func)(int))
{
	if (tree == NULL)
		return;
	if (tier == 0)
		func(tree->n);
	else if (tier > 0)
	{
		print_tier(tree->left, tier - 1, func);
		print_tier(tree->right, tier - 1, func);
	}
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
 * binary_tree_levelorder - goes through a binary tree using level-order
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int depth, i;

	if (tree == NULL || func == NULL)
		return;
	depth = tree_height(tree);
	for (i = 0; i <= depth; i++)
		print_tier(tree, i, func);
}
