#include "monty.h"

/**
 * push_stack - push an element to the stack
 * @stack: stack pointer
 * @line_num: number of line
 */
void push_stack(stack_t **stack, unsigned int line_num)
{
	int data;
	stack_t *new;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_num);
		exit(EXIT_FAILURE);
	}

	data = atoi((*stack)->opcode);
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
	*stack = new_node;
}

/**
 * pall_stack - print stack elements
 * @stack: stack pointer
 * @line_num: number of line
 */
void pall_stack(stack_t **stack, unsigned int line_num)
{
	stack_t *current_node = *stack;

	(void)line_num;

	while (current_node != NULL)
	{
		printf("%d\n", current_node->n);
		current_node = current_node->next;
	}
}

void pop_stack()
{

}
/**
 * add_top - adds the top two elements of the stack.
 * @stack: stack pointer
 * @line_num: number of line
 */
void add_top(stack_t **stack, unsigned int line_num)
{
	stack_t *t = *stack;

	if (t == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	(t->prev)->n = t->n + (t->prev)->n;
	pop_stack(stack, line_num);
}


