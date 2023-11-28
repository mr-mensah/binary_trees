#include "binary_trees.h"

/**
 * binary_tree_insert_right - function that inserts node right of another node
 * @parent: parent
 * @value: value
 * Return: new val
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *newval;

	if (!parent)
		return (NULL);

	newval = malloc(sizeof(binary_tree_t));
	if (!newval)
		return (NULL);

	newval->n = value;
	newval->parent = parent;
	newval->left = NULL;
	newval->right = parent->right;
	parent->right = newval;
	if (newval->right)
		newval->right->parent = newval;
	return (newval);
}
