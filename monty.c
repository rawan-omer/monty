#include "monty.h"

/**
 * main - files interpreter
 * @argc: the number of arguments
 * @argv: The arguments
 * Return: integer
 */
int main(int argc, char **argv)
{
	if (argc != 2)
	error1();
	open(argv);
	return (0);
}
