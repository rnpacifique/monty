#include "monty.h"
/**
* read_file - persing lines from the file
* @filename: file to read name
* @stack: Pointer 
* Return: void
*/

int read_file(char *filename, my_stack_t **stack)
{
	char *trimmed_line, *line = NULL;
	ssize_t n_read;
	size_t n = 0;
	FILE *makefile = fopen(filename, "r");
	unsigned int line_number = 0;

	if (makefile == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		return (EXIT_FAILURE);
	}
	while ((n_read = getlines(&line, &n, makefile)) != -1)
	{
		line_number++;
		if (line[n_read - 1] == '\n' && n_read > 0)
			line[n_read - 1] = '\0';
		if (line[n_read - 2] == '$')
			line[n_read - 2] = ' ';
		trimmed_line = trim_whitespace(line);
		if (n_read == 0 || *trimmed_line == '\0' || trimmed_line == NULL)
		{
			free(trimmed_line);
			return (EXIT_FAILURE);
		}
		else
		{
			if (trimmed_line[0] != '#')
			{
				if (parser(&trimmed_line, &line_number, stack) != 0)
				{
					free(trimmed_line);
					return (EXIT_FAILURE);
				}
			}
		}
	}
	free(trimmed_line);
	fclose(makefile);
	return (0);
}
