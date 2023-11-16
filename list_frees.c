#include "monty.h"

/**
  *free_stack - The stack is released upon program termination.
  *@stack: the stack head
  */
void free_stack(my_stack_t **stack)
{
	my_stack_t *current;

	if ((*stack) != NULL)
	{
		while (*stack != NULL)
		{
			current = (*stack);
			(*stack) = (*stack)->next;
			free(current);
		}
	}
}
