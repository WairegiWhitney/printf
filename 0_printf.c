
#include "main.h"
int _strlen(char *s);
void stringfromint(int no, char *str);
void dec2binstring(unsigned int no, char *str, int *chars_count);
void rev_string(char *s, int b);


/**
 * _printf - Custom implementation of printf function
 * @format: The format string
 * ...: Variable arguments
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	int chars_count = 0;
	va_list my_args_list;

	if (format == NULL)
		return (-1);
	va_start(my_args_list, format);

	for (; *format != '\0'; format++)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			chars_count++;
		}
		else
		{
			format++;
			if (*format == 'c')
			{
				char c = va_arg(my_args_list, int);

				write(1, &c, 1);
				chars_count++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(my_args_list, char *);

				write(1, str, _strlen(str));
				chars_count += _strlen(str);
			}
			else if ((*format == 'd') || (*format == 'i'))
			{
				int num = va_arg(my_args_list, int);
				char str[100];
				int no = num;

				stringfromint(no, str);
				write(1, str, _strlen(str));
				chars_count += _strlen(str);
			}
			else if (*format == 'b')
			{
				unsigned int num = va_arg(my_args_list, unsigned int);
				char str[100];
				int no = num;

				dec2binstring(no, str, &chars_count);
			}
			else if (*format == '%')
			{
				write(1, format, 1);
				chars_count++;
			}
		}
	}
	va_end(my_args_list);
	return (chars_count);
}



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

/**
 * dec2binstring - change integer to binary as a string,
 * increment printf chars_count, print output to stdout
 * @no: integer to change
 * @str: string which is the binary code
 * Return: void
*/
void dec2binstring(unsigned int no, char *str, int *chars_count)
{
	int i = 0;
	int end;

	if (no == 0)
	{
		str[i++] = '0';
		return;
	}
	while (no)
	{
		str[i++] = no % 2 + '0';
		no /= 2;
	}


	str[i] = '\0';
	end = i - 1;
	rev_string(str, end);
	*chars_count += _strlen(str);
	write(1, str, _strlen(str));
}



/**
 * rev_string - reverses string
 * @s: character pointer
 * @b: size of string
 * Return: void
 */
void rev_string(char *s, int b)
{
	int i = 0;

	while (i < b)
	{
		char temp = *(s + i);
		*(s + i) = *(s + b);
		*(s + b) = temp;
		i++;
		b--;
	}
}

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
