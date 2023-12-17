#include "monty.h"

/**
 * stack - Sets the format to a stack
 * @stack: the head of stack
 * @line_num: the line number
 */
void stack(stack_t **stack, unsigned int line_num)
{
	(void)stack;
	(void)line_num;
}

/**
 * queue - Sets the format to a queue
 * @stack: the head of stack
 * @line_num: the line number
 */
void queue(stack_t **stack, unsigned int line_num)
{
	stack_t *current = *stack;
	stack_t *prev = NULL;
	stack_t *next;

	while (current)
	{
		next = current->next;
		current->next = prev;
		current->prev = next;
		prev = current;
		current = next;
	}

	*stack = prev;
	(void)line_num;
}
