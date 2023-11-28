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
	size_t end_height = 0, beg_height = 0;

	if (tree == NULL)
		return (0);
	if (tree->right)
		end_height = binary_tree_height(tree->right) + 1;
	if (tree->left)
		left_height = binary_tree_height(tree->left) + 1;
	if (end_height > left_height)
		return (end_height);
	return (left_height);
}
