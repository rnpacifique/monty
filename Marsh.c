#include "monty.h"
/**
 * swap - Switches the positions of the
 * two topmost elements in the stack
 * @stack: stack Pointer
 * @line_number: The line number of the executing line
 *
 * Return: void
 */

void swap(my_stack_t **stack, unsigned int line_number)
{
	my_stack_t *top = (*stack);
	my_stack_t *following = top->next;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L %u: can't swap, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	top->next = following->next;
	top->prev = following;
	following->prev = NULL;
	following->prev = top;
	following->next->prev = top;
	if (top == (*stack))
	{
		(*stack) = following;
	}
}
