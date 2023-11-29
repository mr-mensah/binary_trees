#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * bst_search - function that searches for a value in a Binary Search Tree
 * @tree: tree
 * @value: value
 * Return: null
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *nodes = (bst_t *)tree;

	if (!tree)
		return (NULL);

	while (nodes)
	{
		if (value == nodes->n)
			return (nodes);
		if (value < nodes->n)
			nodes = nodes->left;
		else if (value > nodes->n)
			nodes = nodes->right;
	}

	return (NULL);
}
