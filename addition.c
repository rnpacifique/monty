#include "monty.h"
/**
 * add - Add the elements in the stack 
 * and append the result to the stack
 * @stack: stack
 * @line_number: The line number of the opcode
 *
 * Return: void
 */

void add(my_stack_t **stack, unsigned int line_number)
{
	my_stack_t *top = *stack;
	my_stack_t *following = top->next;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L %u: can't add, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	following->n += top->n;
	following->prev = NULL;
	(*stack) = following;
	free(top);
}
