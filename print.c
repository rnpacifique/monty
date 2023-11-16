#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * pint - Prints the element situated at the stack's apex
 * @stack: stack pointer
 * @line_number: The current line's number in execution
 *
 * Return: void
 */

void pint(my_stack_t **stack, unsigned int line_number)
{
	if ((*stack) != NULL)
	{
		printf("%d\n", (*stack)->n);
	}
	else
		fprintf(stderr, "L%u: can't pint, stack is empty.\n", line_number);
}
