#include "monty.h"
/**
 * push - push an element to the stack
 * @stack: stack pointer
 * @line_num: number of line
 */
void push(stack_t **stack, unsigned int line_num)
{
	stack_t *new;
	char *data_str;
	int data = 0;
	size_t i;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_num);
		exit(EXIT_FAILURE);
	}

	data_str = strtok(NULL, " \t\n");
	if (data_str == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_num);
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < strlen(data_str); i++)
	{
		if (!isdigit(data_str[i]) && data_str[i] != '-')
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_num);
			exit(EXIT_FAILURE);
		}
	}
	data = atoi(data_str);

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = data;
	new->prev = NULL;
	new->next = *stack;

	if (*stack != NULL)
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
 * add - adds the top two elements of the stack.
 * @stack: stack pointer
 * @line_num: number of line
 */
void add(stack_t **stack, unsigned int line_num)
{
	stack_t *t = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	(t->prev)->n = t->n + (t->prev)->n;
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
