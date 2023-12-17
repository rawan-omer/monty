#include "monty.h"

/**
 * pchar - print the top char in stack
 * @stack: head of stack
 * @line_num: the line number 
 */
void pchar(stack_t **stack, unsigned int line_num)
{
	if (!(*stack))
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_num);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*stack)->n);
}

/**
 * pstr - print string from top of the stack
 * @stack: head of stack
 * @line_number: the line number
 */
void pstr(stack_t **stack, unsigned int line_num)
{
	stack_t *cur = *stack;

	while (cur != NULL && cur->n != 0 && cur->n >= 0 && cur->n <= 127)
	{
		printf("%c", cur->n);
		cur = cur->next;
	}
	(void)line_num;
	printf("\n");
}

/**
 * rotl - rotate stack
 * @stack: head of stack
 * @line_number: the line number
 */
void rotl(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp, *end;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		tmp = *stack;
		end = *stack;

		while (end->next != NULL)
			end = end->next;

		*stack = tmp->next;
		tmp->next = NULL;
		end->next = tmp;
	}
	(void)line_num;
}

/**
 * comment - Check comment in line
 * @l: line
 * Return: 1 (comment), 0 otherwise
 */
int comment(char *l)
{
	while (*l)
	{
		if (*l == '#')
			return 1;
		if (!isspace(*l))
			return 0;
		l++;
	}
	return 0;
}
