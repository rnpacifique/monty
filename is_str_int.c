#include "monty.h"
/**
 * isinteger - Verifies whether the string is an integer
 * @str: the string to be checked
 *
 * Return: true if success or falseif fails
 */
bool isinteger(const char *str)
{
	if (*str == '-')
	{
		str++; /* Skip optional minus sign*/
	}

	if (*str == '\0')
	{
		return (false); /*Empty string or just a minus sign*/
	}

	while (*str)
	{
		if (*str < '0' || *str > '9')
	{
			return (false); /*Non-digit character found*/
		}
		str++;
	}

	return (true);
}
