#include "monty.h"
/**
 * main - main function
 * @ac: argument count
 * @av: arguments
 * Return: 0 if success and 1 if fail
 */
int main(int ac, char *av[])
{
	FILE *filep;
	char *line = NULL;
	char *token = NULL;
	stack_t *h;
	ssize_t read;
	size_t i = 0;
	unsigned int lineNo = 1;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		filep = fopen(av[1], "r");
		if (filep == NULL)
		{
			fprintf(stderr, "Error: Can't open file %s\n", av[1]);
			exit(EXIT_FAILURE);
		}
		else
		{
			while((read = getline(&line, &i, filep)) != -1)
			{
				token = tokenise(line, lineNo);
				if (token == NULL)
					return (1);
				else
					findFunc(token, lineNo, &h);
			}
			free(line);
			free_list(h);
			fclose(filep);
		}
	}
	return (0);
}
