
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
