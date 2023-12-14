#include "monty.h"

/**
 * exe_file - Opens, reads, and executes Monty bytecode file
 * @fname: Monty file name
 */
void exe_file(const char *fname)
{
	size_t len = 0, i;
	unsigned int line_num = 1;
	char *line = NULL;
	stack_t *stack = NULL;
	FILE *file = fopen(fname, "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", fname);
		exit(EXIT_FAILURE);
	}


	while (getline(&line, &len, file) != -1)
	{
		char *opcode = strtok(line, " \t\n");


		if (opcode != NULL && opcode[0] != '#' && *opcode != '\0')
		{
			int found = 0;

			for (i = 0; instructions[i].opcode != NULL; i++)
			{
				if (strcmp(opcode, instructions[i].opcode) == 0)
				{

					instructions[i].f(&stack, line_num);
					found = 1;
					break;
				}
			}

			if (!found)
			{
				fprintf(stderr, "L%u: unknown instruction %s\n", line_num, opcode);
				exit(EXIT_FAILURE);
			}
		}
		line_num++;
	}

	free(line);
	fclose(file);
	free_stack(stack);
}

/**
 * opcodeFunc - retrieves the function pointer with a given opcode
 * @op: the codes
 * @line: line to read
 * Return: void  or null
 */
void (*opcodeFunc(char *op, unsigned int line))(stack_t **, unsigned int)
{
	int i = 0;
	char **tokens = NULL;

	tokens = splitStrings(op, "\n\t\r ");

	if (tokens && tokens[1])
		r = atoi(tokens[1]);

	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(op, instructions[i].opcode) == 0)
		{
			free(tokens);
			return (instructions[i].f);
		}
	}

	free(tokens);
	(void)line;
	return (NULL);
}

/**
 * splitStrings - Splits an input string into words
 * @s: The string to be split to words
 * @d: the delimiter
 * Return: array of strings representing the words or null
 */
char **splitStrings(char *s, char *d)
{
	int i = 0, cword = 0;
	char **splited_words = NULL;

	cword = count_words(s);

	splited_words = malloc(sizeof(char *) * (cword + 1));
	if (splited_words == NULL)
	{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
	}

	splited_words[0] = strtok(s, d);

	if (splited_words[0] == NULL)
	{
	fprintf(stderr, "Error: malloc failed\n");
	free(splited_words);
	exit(EXIT_FAILURE);
	}

	for (i = 1; i < cword; i++)
		splited_words[i] = strtok(NULL, d);

	return (splited_words);
}

#define OUT 0
#define IN 1

/**
 * count_words - function that counts words depending on delimiters
 * @str: string to be evaluated.
 * Return: number of words in the string.
 */

int count_words(char *str)
{
	int state = OUT;
	unsigned int i = 0;

	while (*str)
	{
	if (*str == ' ' || *str == '\n' || *str == '\t' ||
	*str == ':' || *str == '=')
	state = OUT;
	else if (state == OUT)
	{
	state = IN;
	++i;
	}
	++str;
	}
	return (i);
}
