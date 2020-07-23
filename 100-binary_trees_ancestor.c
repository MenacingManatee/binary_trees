#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: pointer to the lowest common ancestor node of the two given nodes
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	const binary_tree_t *tmp, *tmp2;

	for (tmp = first; tmp != NULL; tmp = tmp->parent)
		for (tmp2 = second; tmp2 != NULL; tmp2 = tmp2->parent)
		{
			if (tmp == tmp2)
				return ((binary_tree_t *)tmp);
		}
	return (NULL);
}
