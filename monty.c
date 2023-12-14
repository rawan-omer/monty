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
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
	}
	exe_file(argv[1]);
	return (0);
}
