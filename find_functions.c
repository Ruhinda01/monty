#include "monty.h"
/**
 * findFunc - finds the function based off the instructions
 * @token: token to be checked;
 * @lineNo: line number
 * @h: pointer to the first on the linked list
 * Return: nothing
 */
void findFunc(char *token, unsigned int lineNo, stack_t **h)
{
	int i;
	instruction_t operation[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	i = 0;
	while (operation[i].opcode != NULL)
	{
		if (strcmp(operation[i].opcode, token) == 0)
		{
			operation[i].f(h, lineNo);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", lineNo, token);
	exit(EXIT_FAILURE);
}
