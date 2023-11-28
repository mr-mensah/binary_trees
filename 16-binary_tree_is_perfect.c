#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * beg_height - function finds beg height of a binary tree
 * @tree: tree
 * Return: height of tree
*/
size_t beg_height(const binary_tree_t *tree)
{
	size_t left_height = 0;

	if (tree == NULL)
		return (0);
	if (tree->left)
		left_height = beg_height(tree->left) + 1;
	return (left_height);
}

/**
 * end_height - function finds end height of a binary tree
 * @tree: tree
 * Return: height of tree
*/
size_t end_height(const binary_tree_t *tree)
{
	size_t right_height = 0;

	if (tree == NULL)
		return (0);
	if (tree->right)
		right_height = end_height(tree->right) + 1;
	return (right_height);
}

/**
 * branch - function that counts the branch in a binary tree
 * @tree: tree
 * Return: 0
*/
size_t branch(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (!tree->right && !tree->left)
		return (1);
	return (branch(tree->right) + branch(tree->left));
}


/**
 * tree_nodes - function that counts the nodes with at least 1 child
 * @tree: tree
 * Return: count
*/
size_t tree_nodes(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (tree_nodes(tree->right) + tree_nodes(tree->left) + 1);
}

/**
 * binary_tree_is_perfect - function that checks if a binary tree is perfect
 * @tree: tree
 * Return: 0
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int count_tree_node, count_tree_leave, n_nodes;

	if (!tree)
		return (0);
	count_tree_leave = branch(tree);
	count_tree_node = tree_nodes(tree);
	n_nodes = (2 * count_tree_leave) - 1;
return ((n_nodes == count_tree_node) && (end_height(tree) == beg_height(tree)));
}
