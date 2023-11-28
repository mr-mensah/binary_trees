#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * binary_tree_height - function that measures the height of a binary tree
 * @tree: tree
 * Return: height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t beg_height = 0;
	size_t end_height = 0;

	if (!tree)
		return (0);

	beg_height = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	end_height = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (beg_height > end_height ? beg_height : end_height);
}
