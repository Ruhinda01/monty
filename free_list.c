#include "monty.h"
/**
 * free_list - frees the list
 * @head:pointer to the first item in the list
 * Return: nothing
 */
void free_list(stack_t *head)
{
	stack_t *next;

	while (head)
	{
		next = head->next;
		free(head);
		head = next;
	}
}
