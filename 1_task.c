#include "monty.h"

/**
 * pint -  prints the top of the stack
 * @stack: the top of the stac
 * @num: integer in the structure
 * Return: void
 **/
void print(stack_t **stack, unsigned int num)
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
 **/
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
 **/
void nop(stack_t **stack, unsigned int num)
{
	(void)stack;
	(void)num;
}
