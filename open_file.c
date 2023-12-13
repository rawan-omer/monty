#include "monty.h"

/**
 * exe_file - Opens, reads, and executes Monty bytecode file
 * @fname: monty file name
 */
void exe_file(const char *fname)
{
	FILE *file = fopen(fname, "r");
	if (file == NULL) 
	{
		fprintf(stderr, "Error: Can't open file %s\n", fname);
		exit(EXIT_FAILURE);
	}
	stack_t *stack = NULL;
	char *line = NULL;
	unsigned int line_num = 1;
	size_t len = 0, i = 0;

	while (getline(&line, &len, file) != -1)
	{
		char *opcode = strtok(line, " \t\n");
		if (opcode != NULL && opcode[0] != '#')
		{
			for (; i < sizeof(instructions) / 
			sizeof(instruction_t); i++)
				if (strcmp(opcode, instructions[i].opcode) == 0)
				{
					instructions[i].f(&stack, line_num);
					break;
				}
		}
		line_num++;
	}
	free(line);
	fclose(file);
	free_stack(stack);
}