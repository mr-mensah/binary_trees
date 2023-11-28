#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * size - function that finds the size of a tree
 * @tree: tree
 * Return: size
 */
size_t size(binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + size(tree->left) + size(tree->right));
}

/**
 * change - function that changes
 * @tree: tree
 * @array: array
 * @j: j
 */
void change(binary_tree_t *tree, int *array, int j)
{
	if (!tree)
		return;
	array[j] = tree->n;
	if (tree->left)
		change(tree->left, array, 2 * j + 1);
	if (tree->right)
		change(tree->right, array, 2 * j + 2);
}

/**
 * binary_tree_levelorder - function that goes through level-order traversal
 * @tree: tree
 * @func: function
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int size, j;
	int *array;

	if (!tree || !func)
		return;
	j = 0;
	size = size((binary_tree_t *)tree);
	array = malloc(size * sizeof(int));
	change((binary_tree_t *)tree, array, 0);

	while (j < size)
	{
		func(array[j]);
		j++;
	}
	free(array);
}
