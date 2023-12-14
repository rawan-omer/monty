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

		if (opcode != NULL && opcode[0] != '#')
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
