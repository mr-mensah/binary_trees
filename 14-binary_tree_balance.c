#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * binary_height - binary_height of a binary tree
 * @tree: tree
 * Return: max_height
*/
size_t binary_height(const binary_tree_t *tree)
{
	size_t beg_height, end_height, max_height;

	if (!tree)
		return (0);
	if (tree->left)
		beg_height = 1 + binary_height(tree->left);
	else
		beg_height = 0;
	if (tree->right)
		end_height = 1 + binary_height(tree->right);
	else
		end_height = 0;
	if (beg_height > end_height)
		max_height = beg_height;
	else
		max_height = end_height;
	return (max_height);
}

/**
 * binary_tree_balance - function that measures the balance factor of a tree
 * @tree: tree
 * Return: null
*/
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t beg_height, end_height;

	if (!tree)
		return (0);
	if (tree->left)
		beg_height = 1 + binary_height(tree->left);
	else
		beg_height = 0;
	if (tree->right)
		end_height = 1 + binary_height(tree->right);
	else
		end_height = 0;
	return (beg_height - end_height);
}
