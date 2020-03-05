#include"lists.h"


/**
 * is_palindrome - checks if the linked list is a palindrom
 * with the help of the recursion function
 * @head: pointer to the list
 *
 * Return: 0 - false or 1 - true
 **/
int is_palindrome(listint_t **head)
{
				listint_t *tail;
		unsigned int idx;

		tail = *head;
		idx = 0;
		if (!head)
			return (0);
		if (!*head)
			return (1);
		return (recursion(head, tail));
}

/**
 * recursion - on the way back checking elements with another pointer
 * that starts moving from the head,
 * @head: pointer to the list
 * @tail: pointer to the head of the list
 *
 * Return: 0 - false or 1 - true
 **/
int recursion(listint_t **head, listint_t *tail)
{
		if (!tail)
			return (1);
		if (!recursion(head, tail->next))
			return (0);
		int answer = (tail->n == (*head)->n);
		*head = (*head)->next;
		return (answer);
}

