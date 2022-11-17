#include "binary_trees.h"

/**
 * binary_tree_insert_left -  inserts a node as the left-child of another node
 *
 * @parent: is a pointer to the node to insert the left-child in
 * @value:  is the value to store in the new node
 *
 * Description - If parent already has a left-child, the new node must
 *				take its place, and the old left-child must be set as
 *				the left-child of the new node.
 *
 * Return: a pointer to the created node, or NULL on failure or if
 *			parent is NULL
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	/* create a new node */
	binary_tree_t *newNode;

	newNode = (binary_tree_t *)malloc(sizeof(binary_tree_t));
	if (newNode == NULL || parent == NULL)
	{
		return (NULL);
	}
	else
	{
		newNode->n = value;
		newNode->parent = parent;
		newNode->right = NULL;
	}

	/* check if left of parent doesn't exist and insert a new node into it*/
	if (parent->left == NULL)
	{
		parent->left = newNode;
	}
	else /* if it has a left child, then we want to */
	{
		/* 1. set the newnode left to the parent's left*/
		newNode->left = parent->left;
		/* 2. reset the parent of the current newNode left */
		newNode->left->parent = newNode;

		/* 3. set the left child of the parent to new node */
		parent->left = newNode;
	}

	/* return new node */
	return (newNode);
}
