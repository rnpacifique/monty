#include "monty.h"
/**
 * main - Entry Point
 * @argc: The number of arguments passed
 * @argv: The arguments passed
 *
 * Return: 0 success otherwise -1
 */
int main(int argc, char *argv[])
{
	my_stack_t *stack = NULL;
	/*char *tokens [2];*/

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	if (read_file(argv[1], &stack) != 0)
	{
		free_stack(&stack);
		return (EXIT_FAILURE);
	}
	free_stack(&stack);

	/*free(tokens);*/
	return (0);
}
