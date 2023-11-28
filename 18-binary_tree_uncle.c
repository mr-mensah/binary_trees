#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_uncle - function that finds the uncle of a tree
 * @node: node
 * Return: exparent
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *exparent;

	if (!node || !node->parent || !node->parent->parent)
		return (NULL);
	exparent =  node->parent->parent;

	if (!exparent->left || !exparent->right)
		return (NULL);
	if (exparent->left == node->parent)
		return (exparent->right);
	return (exparent->left);
}
