#include "binary_trees.h"
#include <stdio.h>

/**
 * binary_tree_rotate_left - function that performs a left-rotation on a tree
 * @tree: tree
 * Return: rotation
*/
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *my_right;

	if (!tree || !tree->right)
		return (NULL);

	my_right = tree->right;
	tree->right = my_right->left;
	my_right->parent = tree->parent;
	if (!tree->parent)
	{
	}
	else if (tree == tree->parent->right)
		tree->parent->right = my_right;
	else
		tree->parent->left = my_right;
	tree->parent = my_right;
	my_right->left = tree;

	return (my_right);
}
