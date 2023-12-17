#include "monty.h"

/**
 * main - entry point
 * @ac: the number of arguments
 * @av: list of arguments
 * Return: integer
 */
int main(int ac, char **av)
{
	if (ac != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", av[0]);
		exit(EXIT_FAILURE);
	}

	execute(av);

	return (EXIT_SUCCESS);
}
