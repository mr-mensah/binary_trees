#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_size - function that measures the size of a binary tree
 * @tree: tree
 * Return: width
*/
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t width;

	width = 1;
	if (!tree)
		return (0);
	width = binary_tree_size(tree->right) + binary_tree_size(tree->left) + 1;
	return (width);
}
