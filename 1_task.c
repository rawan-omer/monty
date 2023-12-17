#include "monty.h"
 
/**
 * pint -  print top of stack
 * @stack: head of stack
 * @num: input line number
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
	}
}

/**
 * swap - swap top 2 elements
 * @stack: head of stack
 * @num: input line number
 */
void swap(stack_t **stack, unsigned int num)
{
	int tmp;

	if (!(*stack) || !((*stack)->prev))
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", num);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->n;
	(*stack)->n = (*stack)->prev->n;
	(*stack)->prev->n = tmp;

	(void)num;
}

/**
 * nop - do nothing
 * @stack: head of stack
 * @num: input line number
 */

void nop(stack_t **stack, unsigned int num)
{
	(void)stack;
	(void)num;
}
