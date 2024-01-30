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
	int charc = 0;
	va_list my_args_list;
	char bufer[1020];
	int buferi = 0;

	if (format == NULL)
		return (-1);
	va_start(my_args_list, format);
	for (; *format != '\0'; format++)
	{
		if (*format != '%')
		{
			bufer[buferi++] = *format;
			charc++;
			checkbuffer(bufer, &buferi);
		}
		else
		{
			format++;
			if (*format == 'c')
			{
				char c = va_arg(my_args_list, int);

				bufer[buferi++] = c;
				charc++;
				checkbuffer(bufer, &buferi);
			}
			else if (*format == 's')
			{
				int str_length = 0;
				char *str = va_arg(my_args_list, char *);

				while (str[str_length] != '\0')
				{
					bufer[buferi++] = str[str_length];
					checkbuffer(bufer, &buferi);
					charc++;
					str_length++;
				}
			}
			else if ((*format == 'd') || (*format == 'i'))
			{
				int str_length = 0;
				int num = va_arg(my_args_list, int);
				char str[100];
				int no = num;

				stringfromint(no, str);
				while (str[str_length] != '\0')
				{
					bufer[buferi++] = str[str_length];
					charc++;
					str_length++;
					checkbuffer(bufer, &buferi);
				}
			}
			else if (*format == 'b')
				dec2binstring(va_arg(my_args_list, unsigned int), &charc, bufer, &buferi);
			else if (*format == 'u')
				print_unsigned_int(va_arg(my_args_list, int), &charc, bufer, &buferi);
			else if (*format == 'o')
				dec2octalstring(va_arg(my_args_list, unsigned int), &charc, bufer, &buferi);
			else if (*format == 'x')
				dec2hexstring(va_arg(my_args_list, unsigned int), &charc, bufer, &buferi);
			else if (*format == 'X')
				dec2HEXstring(va_arg(my_args_list, unsigned int), &charc, bufer, &buferi);
			else if (*format == '%')
			{
				bufer[buferi++] = *format;
				charc++;
				checkbuffer(bufer, &buferi);
			}
		}
	}
	if (buferi > 0)
	{
		write(1, bufer, buferi);
		buferi = 0;
	}
	va_end(my_args_list);
	return (charc);
}


/**
 * checkbuffer - check if buffer is full, if so, print and reset
 * @buffer: buffer to check
 * @buffer_indx: index of buffer
 * Return: void
*/
void checkbuffer(char *buffer, int *buffer_indx)
{
	int delete_string = 0;

	if ((*buffer_indx) == BUFF_SIZE)
	{
		write(1, buffer, (*buffer_indx));
		for (; (delete_string) <= _strlen(buffer); (delete_string)++)
			buffer[(delete_string)] = '\0';
	}
}
