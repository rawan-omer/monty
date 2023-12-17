#include "monty.h"

/**
 * sub - sub top 2 elements in stack
 * @stack: head of stack
 * @num: input line number
 **/
void sub(stack_t **stack, unsigned int num)
{
	stack_t *top = *stack;

	if (!(*stack) || !((*stack)->prev))
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", num);
		exit(EXIT_FAILURE);
	}

	(top->prev)->n = (top->prev)->n - top->n;
	pop(stack, num);
}

/**
 * mul - mul the top 2 elements in stack
 * @stack: head of stack
 * @num: input line number
 **/
void mul(stack_t **stack, unsigned int num)
{
	stack_t *top = *stack;

	if (!(*stack) || !((*stack)->prev))
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", num);
		exit(EXIT_FAILURE);
	}
	(top->prev)->n = (top->prev)->n * top->n;
}

/**
 * divi - divide the top 2 elements in the stack
 * @stack: head of stack
 * @num: input line number
 **/
void divi(stack_t **stack, unsigned int num)
{
	stack_t *r = *stack;

	if (!(*stack) || !((*stack)->prev))
	{
	fprintf(stderr, "L%u: can't div, stack too short\n", num);
	exit(EXIT_FAILURE);
	}

	if (r->n == 0)
	{
	fprintf(stderr, "L%u: division by zero\n", num);
	exit(EXIT_FAILURE);
	}
	r->prev->n = r->prev->n / r->n;
	pop(stack, num);
}

/**
 * mod - modify the top 2 elements in the stack
 * @stack: stack head
 * @num: input line number
 **/
void mod(stack_t **stack, unsigned int num)
{
	stack_t *r = *stack;

	if (!(*stack) || !((*stack)->prev))
	{
	fprintf(stderr, "L%u: can't mod, stack too short\n", num);
	exit(EXIT_FAILURE);
	}
	if (r->n == 0)
	{
	fprintf(stderr, "L%u: division by zero\n", num);
	exit(EXIT_FAILURE);
	}
	r->prev->n = r->prev->n % r->n;
	pop(stack, num);
}
