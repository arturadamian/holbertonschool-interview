#include"lists.h"

int is_palindrome(listint_t **head)
{
		listint_t *cur;
		unsigned int len;
		int idx = 1;
		int flag = 0;

		if (!head)
				return (0);
		if (!*head)
				return (1);
		cur = *head;
		len = 1;
		while (cur->next)
		{
				len++;
				cur = cur->next;
		}
		int arr[len / 2];

		cur = *head;
		while (cur->next)
		{
				if (flag == 0)
						arr[idx] = cur->n;
				if (idx == len / 2)
						flag = 1;
				cur = cur->next;
				if (flag == 1 && cur->n == arr[idx])
						idx--;
				else if (flag == 0)
						 idx++;
				else
						return (0);
		}
		return (1);
}

