#include "binary_trees.h"
#include <stdio.h>

/**
 * binary_tree_insert_left - nserts a node as the left-child of another node
 * @parent: pointer to the node to insert the left-child in
 * @value: value to store in the new node
 *
 * Return: pointer to created node, or NULL on failure
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new, *left;

	if (parent == NULL)
		return (NULL);
	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (NULL);
	left = parent->left;
	new = binary_tree_node(parent, value);
	new->left = left;
	if (left != NULL)
		left->parent = new;
	parent->left = new;
	return (new);
}
