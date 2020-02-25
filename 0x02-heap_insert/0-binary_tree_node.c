#include <stdlib.h>
#include "binary_trees.h"
/**
 * binary_tree_node - creates a binary tree node
 *
 * Return: a pointer to a new node or NULL
 */


heap_t *binary_tree_node(heap_t *parent, int value)
{
    heap_t *new;

    new = malloc(sizeof(heap_t));
    if (new == NULL)
        return (NULL);

    new->n = value;
    new->left = NULL;
    new->right = NULL;
    new->parent = parent;

    return (new);
}
