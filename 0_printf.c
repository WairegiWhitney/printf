
#include "main.h"

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

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			chars_count++;
		}
		else
		{
			format++;

			if (*format == '\0')
				break;

			if (*format == 'c')
			{
				char c = va_arg(my_args_list, int);

				write(1, &c, 1);
				chars_count++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(my_args_list, char *);
				int str_len = 0;

				while (str[str_len] != '\0')
				{
					str_len++;
				}

				write(1, str, str_len);
				chars_count += str_len;
			}
			else if (*format == '%')
			{
				write(1, format, 1);
				chars_count++;
			}
		}

		format++;
	}

	va_end(my_args_list);
	return (chars_count);
}
