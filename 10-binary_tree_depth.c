#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * binary_tree_depth -function that measures depth of a node in a binary tree
 * @tree: tree
 * Return: depth
*/
size_t binary_tree_depth(const binary_tree_t *tree)
{
	int depth = 0;

	if (!tree)
		return (0);
	if (tree->parent)
	{
		depth = (binary_tree_depth(tree->parent)) + 1;
	}
	return (depth);
}
