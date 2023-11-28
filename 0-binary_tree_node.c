#include "binary_trees.h"

/**
 * binary_tree_node - function that creates a binary tree node
 * @parent: parent node
 * @value: value
 *
 * Return: new node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *newval;

	newval = malloc(sizeof(binary_tree_t));
	if (!newval)
		return (NULL);
	newval->n = value;
	newval->parent = parent;
	newval->left = NULL;
	newval->right = NULL;
	return (newval);
}
