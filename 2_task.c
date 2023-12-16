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
                fprintf(stderr, "L%u: can't sub, stack too short\n", line);
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
                fprintf(stderr, "L%u: can't mul, stack too short\n", line);
                exit(EXIT_FAILURE);
        }
        (top->prev)->n = (top->prev)->n * top->n;
}
