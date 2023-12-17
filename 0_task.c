#include "monty.h"

/**
 * execute - fun to open and read files
 * @av: list of arguments
 **/
void execute(char **av)
{
	int n = 1;
	FILE *file = NULL;
	size_t i = 0;
	char *tmp = NULL, *var = NULL;
	stack_t *stack = NULL;
	void (*f)(stack_t **stack, unsigned int line_num);

	file = fopen(av[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	for (n = 1; getline(&tmp, &i, file) != -1; n++)
	{
	f = opcodeFunc(tmp, n);
	if (!f)
	{
	fprintf(stderr, "L%d: unknown instruction %s\n", n, strtok(tmp, " "));
	exit(EXIT_FAILURE);
	}
	else
	f(&stack, n);
	}

	fclose(file);
	free(tmp);
	free_stack(&stack);
	(void)var;
}

/**
 * push - push an element to the stack
 * @stack: stack pointer
 * @line_num: number of line
 */
void push(stack_t **stack, unsigned int line_num)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = r;
	new->prev = NULL;
	new->next = *stack;

	if (*stack)
		(*stack)->prev = new;

	*stack = new;
	(void)line_num;
}
/**
 * pall - print stack elements
 * @stack: stack pointer
 * @line_num: number of line
 */
void pall(stack_t **stack, unsigned int line_num)
{
	stack_t *current_node = *stack;

	(void)line_num;

	while (current_node != NULL)
	{
		printf("%d\n", current_node->n);
		current_node = current_node->next;
	}
}
/**
 * pop - removes the top element
 * @stack: stack pointer
 * @line_num: number of line
 */
void pop(stack_t **stack, unsigned int line_num)
{
	stack_t *top;

	(void) line_num;
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}
	top = *stack;
	*stack = top->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(top);
}
/**
 * add - adds top elements of stack
 * @stack: stack pointer
 * @line_num: number of line
 */
void add(stack_t **stack, unsigned int line_num)
{
	stack_t *t = *stack;
	stack_t *second = t->next;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	second->n += t->n;
	pop(stack, line_num);
}
/**
 * free_stack - free stack
 * @stack: stack pointer
 */
void free_stack(stack_t **stack)
{
	stack_t *current = *stack, *next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}
