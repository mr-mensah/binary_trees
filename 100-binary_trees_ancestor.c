#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * deep_node - the inside node
 * @node: node
 * Return: deep_node
*/
size_t deep_node(const binary_tree_t *node)
{
	int depth = 0;

	if (!node)
		return (0);
	if (node->parent)
	{
		depth = deep_node(node->parent) + 1;
	}
	return (depth);
}

/**
 * binary_trees_ancestor - function that finds the lowest ancestor of a tree
 * @first: first
 * @second: second
 * Return: null
*/
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
const binary_tree_t *second)
{
	int first_depth, sec_depth;

	if (!first || !second)
		return (NULL);

	first_depth = deep_node(first);
	sec_depth = deep_node(second);
	while (first_depth > sec_depth)
	{
		first = first->parent;
		first_depth--;
	}
	while (sec_depth > first_depth)
	{
		second = second->parent;
		sec_depth--;
	}
	while (first && second)
	{
		if (first == second)
			return ((binary_tree_t *)first);
		first = first->parent;
		second = second->parent;
	}
	return (NULL);
}
