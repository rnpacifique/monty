#include "monty.h"

/**
 * pchar - Prints char
 * @stack: the stack pointer
 * @line_number: The line number of the executing line
 *
 * Return: void
 */

void pchar(my_stack_t **stack, unsigned int line_number)
{
	int data;

	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't pchar,stack is empty\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	data = (*stack)->n;

	if (data < 0 || data > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", data);
}
