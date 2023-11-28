#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * binary_tree_rotate_right - function that performs a right-rotation on a tree
 * @tree: tree
 * Return: rotation
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *my_left;

	if (!tree || !tree->left)
		return (NULL);
	my_left = tree->left;
	if (my_left->right)
		my_left->right->parent = tree;
	tree->left = my_left->right;
	my_left->parent = tree->parent;
	if (!tree->parent)
	{}
	else if (tree == tree->parent->right)
		tree->parent->right = my_left;
	else
		tree->parent->left = my_left;
	tree->parent = my_left;
	my_left->right = tree;
	return (my_left);
}

