#ifndef MONTY_H
#define MONTY_H

#define _POSIX_C_SOURCE 200809
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

extern int r;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void (*opcodeFunc(char *opcode, unsigned int line))(stack_t **, unsigned int);
char **splitStrings(char *s, char *d);
int count_words(char *str);
void push(stack_t **stack, unsigned int line_num);
void pall(stack_t **stack, unsigned int line_num);
void pop(stack_t **stack, unsigned int line_num);
void add(stack_t **stack, unsigned int line_num);
void exe_file(char **argv);
void free_stack(stack_t **stack);
void pint(stack_t **stack, unsigned int num);
void swap(stack_t **stack, unsigned int num);
void nop(stack_t **stack, unsigned int num);
void sub(stack_t **stack, unsigned int num);
void mul(stack_t **stack, unsigned int num);


static const instruction_t instructions[] = {
	{"push", push},
	{"pall", pall},
	{"pop", pop},
	{"add", add},
	{"pint", pint},
	{"swap", swap},
	{"nop", nop},
	{NULL, NULL}
};

#endif
