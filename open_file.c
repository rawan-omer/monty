#include "monty.h"

int r;
/**
 * opcodeFunc - retrieves the function pointer with a given opcode
 * @op: the codes
 * @line: line to read
 * Return: void  or null
 */
void (*opcodeFunc(char *op, unsigned int l))(stack_t **, unsigned int)
{
	int n;
	char **tok = splitStrings(op, " \n\t");

	if (tok && tok[1])
		r = atoi(tok[1]);

	for (n = 0; instructions[n].opcode != NULL; n++)
	{
		if (strcmp(op, instructions[n].opcode) == 0)
		{
			free(tok);
			return (instructions[n].f);
		}
	}

	free(tok);
	(void)l;
	return (NULL);
}

/**
 * splitStrings - string split function
 * @str: input string
 * @d: input delimiter
 * Return: string array splited
 */
char **splitStrings(char *str, char *d)
{
	char **str_split = NULL;
	int n = 0, count = 0;

	count = count_fun(str);

	str_split = malloc(sizeof(char *) * (count + 1));
	if (!(str_split))
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	str_split[0] = strtok(str, d);

	if (!(str_split[0]))
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(str_split);
		exit(EXIT_FAILURE);
	}

	for (n = 1; n < count; n++)
		str_split[n] = strtok(NULL, d);

	return (str_split);
}

/**
 * count_fun - counts words based on delimiters
 * @s: input string 
 * Return: words num in input string
 */

int count_fun(char *s)
{
	unsigned int i = 0;
	int on_of = OUT;

	while (*s)
	{
	if (*s == ' ' || *s == '\n' || *s == '\t' ||
	*s == ':' || *s == '=')
	on_of = OUT;
	else if (on_of == OUT)
	{
	on_of = IN;
	++i;
	}
	++s;
	}
	return (i);
}
