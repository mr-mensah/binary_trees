#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * small_val - function that brings the smallest node from a BST
 * @root: root
 * Return: smallest
 */
bst_t *small_val(bst_t *root)
{
	bst_t *sma = root;

	while (sma->left)
		sma = sma->left;

	return (sma);
}

/**
 * bst_remove - function that removes a node from a Binary Search Tree
 * @root: root
 * @value: value
 * Return: root
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp = NULL;

	if (!root)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (!root->left)
		{
			temp = root->right;
			free(root);
			return (temp);
		}
		else if (!root->right)
		{
			temp = root->left;
			free(root);
			return (temp);
		}
		temp = small_val(root->right);
		root->n = temp->n;
		root->right = bst_remove(root->right, temp->n);
	}
	return (root);
}

