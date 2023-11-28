#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * bst_insert - function that inserts a value in a Binary Search Tree
 * @tree: tree
 * @value: value
 * Return: fresh
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *temp = NULL;
	bst_t *last = NULL;
	bst_t *fresh = NULL;

	if (!tree)
		return (NULL);
	if (*tree == NULL)
		return (*tree = binary_tree_node(NULL, value));

	temp = *tree;
	while (temp)
	{
		last = temp;
		if (value < temp->n)
			temp = temp->left;
		else if (value > temp->n)
			temp = temp->right;
		else if (value == temp->n)
			return (NULL);
	}

	fresh = binary_tree_node(NULL, value);
	if (last == NULL)
		last = fresh;
	else if (value < last->n)
	{
		last->left = fresh;
		fresh->parent = last;
	}
	else
	{
		last->right = fresh;
		fresh->parent = last;
	}

	return (fresh);
}
