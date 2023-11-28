#include "binary_trees.h"
#include <stdlib.h>

/**
 * sizes - function that finds the size of a tree
 * @tree: tree
 * Return: size
 */
size_t sizes(binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + sizes(tree->left) + sizes(tree->right));
}

/**
 * changers - function that changes
 * @tree: tree
 * @array: array
 * @j: j
 */
void changers(binary_tree_t *tree, int *array, int j)
{
	if (!tree)
		return;
	array[j] = tree->n;
	if (tree->left)
		changers(tree->left, array, 2 * j + 1);
	if (tree->right)
		changers(tree->right, array, 2 * j + 2);
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
	size = sizes((binary_tree_t *)tree);
	array = malloc(size * sizeof(int));
	changers((binary_tree_t *)tree, array, 0);

	while (j < size)
	{
		func(array[j]);
		j++;
	}
	free(array);
}
