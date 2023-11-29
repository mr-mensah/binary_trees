#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * bt_help - function that helpsfind the tree
 * @tree: tree
 * @min: minimum
 * @max: maximum
 *
 * Return: 1 if tree is avl
 *         0 otherwise
 */
int bt_help(const binary_tree_t *tree, int min, int max)
{
	int beg_path, end_path;

	if (!tree)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);

	beg_path = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	end_path = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	if (abs(beg_path - end_path) > 1)
		return (0);

	return (bt_help(tree->left, min, tree->n - 1) &&
		bt_help(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_height - function that measures the height of a BT
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

/**
 * binary_tree_is_avl -  function that checks if a binary tree is a valid Tree
 * @tree: tree
 *
 * Return: help
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (bt_help(tree, INT_MIN, INT_MAX));
}

