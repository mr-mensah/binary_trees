#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * bt_help - function that finds binary tree available
 * @tree: tree
 * @min: minimum
 * @max: maximum
 *
 * Return: 0
 */
int bt_help(const binary_tree_t *tree, int min, int max)
{
	int beg_path, end_path;

	if (!tree)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);

	beg_path = tree->left ? 1 + bt_height(tree->left) : 0;
	end_path = tree->right ? 1 + bt_height(tree->right) : 0;

	if (abs(beg_path - end_path) > 1)
		return (0);

	return (bt_help(tree->left, min, tree->n - 1) &&
		bt_help(tree->right, tree->n + 1, max));
}

/**
 * bt_height - function that measures the height of a binary tree
 * @tree: tree
 *
 * Return: 0
 */
size_t bt_height(const binary_tree_t *tree)
{
	size_t beg_height = 0;
	size_t end_height = 0;

	if (!tree)
		return (0);

	beg_height = tree->left ? 1 + bt_height(tree->left) : 0;
	end_height = tree->right ? 1 + bt_height(tree->right) : 0;
	return (beg_height > end_height ? beg_height : end_height);
}

/**
 * binary_tree_is_avl - finds if a binary tree is an avl
 * @tree: pointer to the root node of the tree
 *
 * Return: 1 if tree is avl
 *         0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (bt_help(tree, INT_MIN, INT_MAX));
}

