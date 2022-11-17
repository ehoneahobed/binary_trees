#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the
 *					right-child of another node
 *
 * @parent: is a pointer to the node to insert the right-child in
 * @value: is the value to store in the new node
 *
 * Description: If parent already has a right-child, the new node
 *				must take its place, and the old right-child must
 *				be set as the right-child of the new node.
 *
 * Return: a pointer to the created node, or
 *			NULL on failure or
 *			if parent is NULL
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *newNode;

	/* return NULL if parent is NULL */
	if (parent == NULL)
	{
		return (NULL);
	}

	/* create new node */
	newNode = (binary_tree_t *)malloc(sizeof(binary_tree_t));
	if (newNode == NULL)
	{
		return (NULL);
	}

	/* assign values to the new node */
	newNode->parent = parent;
	newNode->n = value;
	newNode->left = NULL;

	/* check if parent has a right child or not */
	if (parent->right == NULL)
	{
		/* set parent right to new node if it was empty */
		parent->right = newNode;
	}
	else
	{
		/* assign newnode right to the parent's initial right*/
		newNode->right = parent->right;
		/* update the parent of the current newNode right */
		newNode->right->parent = newNode;

		/* set parent righ to new node */
		parent->right = newNode;
	}

	return (newNode);
}
