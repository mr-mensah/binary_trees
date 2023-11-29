#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * array_to_bst - function that builds a Binary Search Tree from an array
 * @array: array
 * @size: size
 * Return: 0
 */
bst_t *array_to_bst(int *array, size_t size)
{
	unsigned int j;
	bst_t *sea = NULL;

	for (j = 0; j < size; j++)
		bst_insert(&sea, array[j]);

	return (sea);
}
