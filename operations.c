#include "monty.h"
/**
 * push - inserts at the beginning
 * @stack: list
 * @line_number: line number
 * Return: nothing
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;
	(void) line_number;

	ptr = malloc(sizeof(stack_t));
	if (ptr == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	printf("Pushing %d onto the stack\n", number);
	ptr->n = number;
	ptr->prev = NULL;
	ptr->next = NULL;
	printf("ptr: %p, stack: %p\n", (void *)ptr, (void *)stack);
	ptr->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = ptr;
	*stack = ptr;
	printf("New top of the stack: %p\n", (void *)*stack);
}
/**
 * pall - prints all the values on the stack
 * @stack: list
 * @line_number: line number
 * Return: nothing
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;
	(void) line_number;
	
	if (stack == NULL || *stack == NULL)
		return;
	ptr = *stack;
	while (ptr != NULL)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}
