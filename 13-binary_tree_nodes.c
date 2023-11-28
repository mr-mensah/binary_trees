#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_nodes -  function that counts the nodes in a binary tree
 * @tree: tree
 * Return: count
*/
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	int count;

	count = 0;
	if (!tree)
		return (0);
	if (tree->left || tree->right)
	{
		count = 1 + binary_tree_nodes(tree->right) + binary_tree_nodes(tree->left);
	}
	return (count);
}
