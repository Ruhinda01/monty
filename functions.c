#include "monty.h"
/**
 * checkInt - checks if it is an integer
 * @str: string
 * Return: 0 if not found and 1 if found
 */
int checkInt(char *str)
{
	if (*str == '\0')
		return (0);
	if (*str == '-' || *str == '+')
		str++;
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
		{
			printf("Invalid character: %c\n", *str);
			return (0);
		}
		str++;
	}
	return (1);
}
/**
 * tokenise - tokenises the line read from the file
 * @line: line read from the file
 * @lineNo: line number read
 * Return: pointer
 */
char *tokenise(char *line, unsigned int lineNo)
{
	char *token;
	char *dls = "\n ";
	char *digit;

	token = strtok(line, dls);
	if (token == NULL)
		return (NULL);
	digit = strtok(NULL, dls);
	if (digit == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", lineNo);
		exit(EXIT_FAILURE);
	}
	printf("Token: %s, Digit: %s\n", token, digit);
	if (checkInt(digit) != 0)
		number = atoi(digit);
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", lineNo);
		exit(EXIT_FAILURE);
	}
	return (token);
}
