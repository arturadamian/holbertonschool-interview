#include "lists.h"

/**
* check_cycle - checks if alinked list has a cycle
* @head: pointer to a linked list
*
* Return: 0 if false or 1 if true
**/
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *tortuga = head;
	listint_t *rabbit = head;

	if (!head)
		return (NULL);
	while (tortuga->next && rabbit->next->next)
	{
		tortuga = tortuga->next;
		rabbit = rabbit->next->next;
		if (tortuga == rabbit)
		{
			tortuga = head;
			while (tortuga != rabbit)
			{
				tortuga = tortuga->next;
				rabbit = rabbit->next;
			}
			return (rabbit);
		}
	}
	return (NULL);
}
