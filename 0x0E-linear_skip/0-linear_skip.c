#include "search.h"


skiplist_t *linear_skip(skiplist_t *list, int value)
{
		skiplist_t *skip;

		if (!list)
			return (NULL);
		skip = list;
		while (skip->express)
		{
			printf("Value checked at index [%zu] = [%i]\n",
				skip->express->index, skip->express->n);
			if (skip->express->n > value)
			{
				printf("Value found between indexes [%zu] and [%zu]\n",
					skip->index, skip->express->index);
				break;
			}
			skip = skip->express;
		}
		if (!skip->express)
		{
			list = skip;
			while (list->next)
				list = list->next;
			printf("Value found between indexes [%zu] and [%zu]\n",
				skip->index, list->index);
		}
		list = skip;
		while (list != skip->express)
		{
			printf("Value checked at index [%zu] = [%i]\n",
				list->index, list->n);
			if (list->n == value)
				break;
			list = list->next;
		}
		if (list != skip->express)
			return (list);
		return (NULL);
}
