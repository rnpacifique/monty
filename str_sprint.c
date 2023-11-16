#include "monty.h"

/**
 * split_string - Function that divides a string based on a provided delimiter
 * @str: The string slated for splitting.
 * @delim: used delim
 * Return: array
 */

char *split_string(char *str, const char *delim)
{
	static char *last_pos;
	char *start;

	/* Verify whether the str is NULL. */
	if (str != NULL)
		last_pos = str;

	/* verfy if last_pos is still NULL */
	if (last_pos == NULL || *last_pos == '\0')
		return (NULL);

	/* show the first token */
	while (*last_pos != '\0' && strchr(delim, *last_pos) != NULL)
		last_pos++;

	/* Check if there are no tokens left */
	if (*last_pos == '\0')
		return (NULL);

	/* Update the start position */
	start = last_pos;

	/* show the end of the token */
	while (*last_pos != '\0' && strchr(delim, *last_pos) == NULL)
		last_pos++;

	/* Null-terminate the token */
	if (*last_pos != '\0')
	{
		*last_pos = '\0';
		last_pos++;
	}

	return (start);
}
