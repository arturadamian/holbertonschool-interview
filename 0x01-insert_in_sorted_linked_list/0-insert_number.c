#include<stdio.h>
#include<stdlib.h>
#include"lists.h"


/**
 * insert_node - inserts a number into a sorted singly linked list.
 * @head: pointer to the linked list
 * @number: the value of a new node
 * Return: the address of the new node, or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
		listint_t *current;
		listint_t *new;

		if (head == NULL)
			return (NULL);
		new = malloc(sizeof(*new));
		if (new == NULL)
				return (NULL);
		current = *head;
		new->n = number;

		if (current->n > new->n)
		{
				new->next = current;
		}
		while (current != NULL)
		{
				if ((current->next->n > new->n) || (current->next == NULL))
						{
								new->next = current->next;
								current->next = new;
								break;
						}
						current = current->next;
		}
		return (new);
}
