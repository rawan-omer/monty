#include "monty.h"

/**
 * sub - sub top two elements in stack
 * @stack: the top element of the stack
 * @num: integer value in the structure
 * Return: void
 **/
void sub(stack_t **stack, unsigned int num)
{
        stack_t *top = *stack;

        if (*stack == NULL || (*stack)->prev == NULL)
        {
                fprintf(stderr, "L%u: can't sub, stack too short\n", num);
                exit(EXIT_FAILURE);
        }

        (top->prev)->n = (top->prev)->n - top->n;
        pop(stack, num);
}

/**
 * mul - mul the top two elements in stack
 * @stack: the top of the stack
 * @num: integer value in stack
 * Return: void
 **/
void mul(stack_t **stack, unsigned int num)
{
        stack_t *top = *stack;

        if (*stack == NULL || (*stack)->prev == NULL)
        {
                fprintf(stderr, "L%u: can't mul, stack too short\n", num);
                exit(EXIT_FAILURE);
        }
        (top->prev)->n = (top->prev)->n * top->n;
}

/**
 * divi - divide the top two elements in the stack
 * @stack: element at the top of the stack (head)
 * @num: integer value in stack
 * Return: void
 **/
void divi(stack_t **stack, unsigned int num)
{
	stack_t *r = *stack;

	if (!(*stack)|| !((*stack)->prev))
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
 * mod - modify the top two elements in the stack
 * @stack: the top of the stack
 * @num: integer value in stack
 * Return: void
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
