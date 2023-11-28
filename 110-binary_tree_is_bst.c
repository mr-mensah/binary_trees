#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * tree_help - function that helps main function
 * @tree: tree
 * @min: minimum
 * @max: maximum
 * Return: 0
 */
int tree_help(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	return (tree_help(tree->left, min, tree->n - 1) &&
		tree_help(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_is_bst - function that checks if a binary tree is a valid BST
 * @tree: tree
 *
 * Return: 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (tree_help(tree, INT_MIN, INT_MAX));
}
