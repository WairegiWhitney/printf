#include "main.h"

/**
 * stringfromint - change integer to string
 * @no: integer
 * @str: string
 * Return: void
 */
void stringfromint(int no, char *str)
{
	int i = 0;
	int negtrue = 0;
	int end;

	if (no == 0)
	{
		str[i++] = '0';
		return;
	}
	if (no < 0)
	{
		negtrue++;
		no = -no;
	}
	while (no)
	{
		str[i++] = no % 10 + '0';
		no /= 10;
	}

	if (negtrue)
		str[i++] = '-';

	str[i] = '\0';
	end = i - 1;
	rev_string(str, end);
}
