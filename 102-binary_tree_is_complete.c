#include "binary_trees.h"
#include <stdio.h>

/**
 * tree_help - function that helps
 * @tree: tree
 * @index: index
 * @size: size
 * Return: null
 */
int tree_help(const binary_tree_t *tree, size_t index, size_t size)
{
	if (!tree)
		return (1);

	if (index >= size)
		return (0);

	return (tree_help(tree->left, 2 * index + 1, size) &&
		tree_help(tree->right, 2 * index + 2, size));
}

/**
 * tree_width - function that checks the size of a binary tree
 * @tree: tree
 *
 * Return: size
 */
size_t tree_width(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (tree_width(tree->left) +
		tree_width(tree->right) + 1);
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: tree
 * Return: 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size;

	if (!tree)
		return (0);
	size = tree_width(tree);

	return (tree_help(tree, 0, size));
}
