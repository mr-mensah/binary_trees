#include "binary_trees.h"

/**
 * binary_tree_insert_left - function that inserts a node left of another node
 * @parent: parent
 * @value: value
 * Return: new val
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *newval;

	if (!parent)
		return (NULL);

	newval = malloc(sizeof(binary_tree_t));
	if (!newval)
		return (NULL);

	newval->n = value;
	newval->parent = parent;
	newval->right = NULL;
	newval->left = parent->left;
	parent->left = newval;
	if (newval->left)
		newval->left->parent = newval;
	return (newval);
}
