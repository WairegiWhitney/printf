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
	char buffer[1020];
	int buffer_indx = 0;
	int delete_string = 0;

	if (format == NULL)
		return (-1);
	va_start(my_args_list, format);
	for (; *format != '\0'; format++)
	{
		if (*format != '%')
		{
			buffer[buffer_indx++] = *format;
			chars_count++;
			if (buffer_indx == BUFF_SIZE)
			{
				write(1, buffer, buffer_indx);
				for (; delete_string <= _strlen(buffer); delete_string++)
					buffer[delete_string] = '\0';
			}
		}
		else
		{
			format++;
			if (*format == 'c')
			{
				char c = va_arg(my_args_list, int);

				buffer[buffer_indx++] = c;
				chars_count++;
				if (buffer_indx == BUFF_SIZE)
				{
					write(1, buffer, buffer_indx);
					for (; delete_string <= _strlen(buffer); delete_string++)
						buffer[delete_string] = '\0';
				}
			}
			else if (*format == 's')
			{
				int str_length = 0;

				char *str = va_arg(my_args_list, char *);
				while (str[str_length] != '\0')
				{
					buffer[buffer_indx++] = str[str_length];
					if (buffer_indx == BUFF_SIZE)
					{
						write(1, buffer, buffer_indx);
						for (; delete_string <= _strlen(buffer); delete_string++)
							buffer[delete_string] = '\0';
					}

					chars_count++;
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
					buffer[buffer_indx++] = str[str_length];
					chars_count++;
					str_length++;

					if (buffer_indx == BUFF_SIZE)
					{
						write(1, buffer, buffer_indx);
						for(; delete_string <= _strlen(buffer); delete_string++)
							buffer[delete_string] = '\0';
					}
				}
			}
			else if (*format == 'b')
			{
				unsigned int num = va_arg(my_args_list, unsigned int);

				dec2binstring(num, &chars_count, buffer, &buffer_indx);
			}
			else if (*format == 'u')
			{
				int num = va_arg(my_args_list, int);

				print_unsigned_int(num, &chars_count, buffer, &buffer_indx);
			}
			else if (*format == 'o')
			{
				unsigned int num = va_arg(my_args_list, unsigned int);

				dec2octalstring(num, &chars_count, buffer, &buffer_indx);
			}
			else if (*format == 'x')
			{
				unsigned int num = va_arg(my_args_list, unsigned int);

				dec2hexstring(num, &chars_count, buffer, &buffer_indx);
			}
			else if (*format == 'X')
			{
				unsigned int num = va_arg(my_args_list, unsigned int);

				dec2HEXstring(num, &chars_count, buffer, &buffer_indx);
			}
			else if (*format == '%')
			{
				buffer[buffer_indx++] = *format;
				chars_count++;
				if (buffer_indx == BUFF_SIZE)
				{
					write(1, buffer, buffer_indx);
					for (; delete_string <= _strlen(buffer); delete_string++)
						buffer[delete_string] = '\0';
				}
			}
		}
	}
	if (buffer_indx > 0)
	{
		write(1, buffer, buffer_indx);
		buffer_indx = 0;
	}
	va_end(my_args_list);
	return (chars_count);
}

int main(void)
{
	int no = 700;

	_printf("Integer = %d, String = %s\n", no, "hello");
	_printf("Hello, World!\n");
	_printf("Hello, %s!\n", "World");
	_printf("Hello, %c!\n", 'W');
	_printf("Hello, %%!\n");
	_printf("integer = %i\n", 100);
	_printf("binary: %b\n", 10);
	_printf("unsigned int: %u\n", -890);
	_printf("octal: %o\n", 10);
	_printf("hex: %x\n", 100);
	_printf("HEX: %X\n", 100);
	return (0);
}
