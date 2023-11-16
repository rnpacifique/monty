#include "monty.h"

/**
 * getlines - Read lines from a file
 * @lineptr: Pointer to the line
 * @n: Size of the line buffer
 * @stream: File to read from
 *
 * Return: Number of characters read, -1 on error or EOF
 */
ssize_t getlines(char **lineptr, size_t *n, FILE *stream)
{
	size_t i = 0;
	int c;
	size_t  new_size = *n + 128;
	char new_ptr[1024];

	if (*lineptr == NULL || *n == 0)
	{
		*n = 128;
		*lineptr = malloc(*n);
		if (*lineptr == NULL)
			return (-1);
	}
	if (*lineptr != NULL)
	{
		while ((c = fgetc(stream)) != EOF)
		{
			if (i == *n - 1)
			{
				/*Resize the buffer if neededi*/
				/*size_t new_size = *n + 128;*/
				/*char *new_ptr = realloc(*lineptr, new_size);*/

				if (new_ptr == NULL)
					return (-1);
				*lineptr = new_ptr;
				*n = new_size;
			}
			(*lineptr)[i++] = c;
			if (c == '\n')
			{
				(*lineptr)[i] = '\0';
				return (i);
			}
		}
	}
	if (i == 0)
		return (-1);
	(*lineptr)[i] = '\0';
	return (i);
}
