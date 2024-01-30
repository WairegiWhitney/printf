#include "main.h"

/**
 * dec2hexstring - change integer to hex(in small letters) as a string,
 * increment printf chars_count, print output to stdout
 * @no: integer to change
 * @chars_count: number of chars printed
 * Return: void
 */
void dec2hexstring(unsigned int no, int *chars_count, char *buffer, int *buffer_indx)
{
	int i = 0;
	int number;
	int end;
	char str[100];
	int str_length = 0;
	int delete_string = 0;

	if (no == 0)
	{
		str[i++] = '0';
		return;
	}
	while (no)
	{
		number = no % 16;
		if (number < 10)
			str[i++] = number + '0';
		else
			str[i++] = number + 87;
		no /= 16;
	}

	str[i] = '\0';
	end = i - 1;
	rev_string(str, end);
	*chars_count += _strlen(str);

	while (str[str_length] != '\0')
	{
		buffer[(*buffer_indx)++] = str[str_length];
		str_length++;
		if ((*buffer_indx) == BUFF_SIZE)
		{
			write(1, buffer, (*buffer_indx));
			for (; delete_string <= _strlen(buffer); delete_string++)
				buffer[delete_string] = '\0';
		}
	}
}
