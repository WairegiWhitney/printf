#include "main.h"


/**
 * print_unsigned_int - print unsigned int
 * @no: integer to change
 * @chars_count: number of chars printed
 * Return: void
 */
void print_unsigned_int(int no, int *chars_count, char *buffer, int *buffer_indx)
{
	char str[100];
	int str_length = 0;
	int delete_string = 0;

	if (no < 0)
		no = -no;
	if (no == 0)
	{
		str[0] = '0';
		str[1] = '\0';
	}
	else
	{
		stringfromint(no, str);
	}

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