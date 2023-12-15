#include "monty.h"

/**
 * exe_file - reads and open a file
 * @argv: comand line argument list
 */
void exe_file(char **argv)
{
	FILE *fh = NULL;
	size_t leng = 0;
	int l = 1;
	char *fname = argv[1], *buffer = NULL, *token = NULL;
	stack_t *stack = NULL;
	void (*f)(stack_t **stack, unsigned int line_number);

	fh = fopen(argv[1], "r");
	if (fh == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", fname);
		exit(EXIT_FAILURE);
	}

	for (l = 1; getline(&buffer, &leng, fh) != -1; l++)
	{
		f = opcodeFunc(buffer, l);
		if (f == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n",
			l, strtok(buffer, " "));
			exit(EXIT_FAILURE);
		}
		else
			f(&stack, l);
	}

	fclose(fh);
	free(buffer);
	free_stack(&stack);
	(void)token;
}

/**
 * pint -  prints the top of the stack
 * @stack: the top of the stac
 * @num: integer in the structure
 * Return: void
 */
void pint(stack_t **stack, unsigned int num)
{
	stack_t *t = *stack;

	(void)num;
	if (t)
		printf("%d\n", t->n);
	else
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", num);
		exit(EXIT_FAILURE);
	}
}

/**
 * swap - swaps the top 2 elements in the stack
 * @stack: the top of the stack
 * @num: integer in the structure
 * Return: void
 */
void swap(stack_t **stack, unsigned int num)
{
	int i;

	if (!(*stack) || !((*stack)->prev))
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", num);
		exit(EXIT_FAILURE);
	}


	i = (*stack)->n;
	(*stack)->n = (*stack)->prev->n;
	(*stack)->prev->n = i;

	(void)num;
}

/**
 * nop - do nothing
 * @stack: the top of the stack (head)
 * @num: number in the structure
 * Return: void
 */
void nop(stack_t **stack, unsigned int num)
{
	(void)stack;
	(void)num;
}
