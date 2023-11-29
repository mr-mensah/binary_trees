#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * avl_insert - function that inserts a value in the Tree
 * @tree: tree
 * @value: value
 *
 * Return: node
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	int changes = 0;
	avl_t *node = bst_insert(tree, value);

	changes = binary_tree_balance(*tree);

	if (changes > 1 && value < node->left->n)
		return (binary_tree_rotate_right(node));
	if (changes < -1 && value > node->right->n)
		return (binary_tree_rotate_left(node));
	if (changes > 1 && value > node->left->n)
	{
		node->left = binary_tree_rotate_left(node->left);
		return (binary_tree_rotate_right(node));
	}
	if (changes < -1 && value < node->right->n)
	{
		node->right = binary_tree_rotate_right(node->right);
		return (binary_tree_rotate_left(node));
	}

	return (node);
}

/**
 * bst_insert - function that inserts a value in an AVL Tree
 * @tree: tree
 * @value: value
 * Return: first
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *temp = *tree;
	bst_t *last = NULL;
	bst_t *first = binary_tree_node(NULL, value);

	if (*tree == NULL)
		*tree = first;

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

	if (last == NULL)
		last = first;
	else if (value < last->n)
	{
		last->left = first;
		first->parent = last;
	}
	else
	{
		last->right = first;
		first->parent = last;
	}

	return (first);
}
