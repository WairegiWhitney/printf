#include "main.h"

/**
 * _strlen - length of string
 * @s: string input
 * Return: int
 */
int _strlen(char *s)
{
	int i = 0;

	while (*s != '\0')
	{
		i++;
		s++;
	}

	return (i);
}
