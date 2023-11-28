/**
 * binary_tree_is_complete - function that checks if a binary tree is complete
 * @tree: tree
 * Return: 0
*/
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int ecount;
	int bcount;


	ecount = 0;
	bcount = 0;
	if (!tree)
		return (0);
	if (tree->left)
		bcount = 1 + binary_tree_is_complete(tree->left);
	if (tree->right)
		ecount = 1 + binary_tree_is_complete(tree->right);
	return (ecount == bcount);
}
