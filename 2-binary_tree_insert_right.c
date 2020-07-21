#include "binary_trees.h"
#include <stdio.h>

/**
 * binary_tree_insert_right - inserts a node as the right-child of another node
 * @parent: pointer to the node to insert the right-child in
 * @value: value to store in the new node
 *
 * Return: pointer to created node, or NULL on failure
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new, *right;

	if (parent == NULL)
		return (NULL);
	right = parent->right;
	new = binary_tree_node(parent, value);
	new->right = right;
	if (right != NULL)
		right->parent = new;
	parent->right = new;
	return (new);
}
