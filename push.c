#include "monty.h"

/**
 * push - puts elements to the list
 * @head: head
 *@line_number:  error line
 *@data: stack added data
 * Return: success return 0 or  -1 fail
 */

void push(my_stack_t **head, unsigned int line_number, char *data)
{
	my_stack_t *new_node = malloc(sizeof(my_stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error during allocation\n");
		free_stack(head);
		exit(EXIT_FAILURE);
	}
	if (isinteger(data))
	{
		int n = (strcmp(data, "0") == 0) ? 0 : atoi(data);

		if ((*head) == NULL)
		{
			new_node->n = n;
			new_node->next = NULL;
			new_node->prev = NULL;
			(*head) = new_node;
		}
		else
		{
			new_node->n = n;
			new_node->next = (*head);
			(*head)->prev = new_node;
			(*head) = new_node;
		}
	}
	else
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_stack(head);
		exit(EXIT_FAILURE);
	}
}
