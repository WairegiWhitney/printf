
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
	int buffer_indx=0;
	int delete_string = 0;

	if (format == NULL)
		return (-1);
	va_start(my_args_list, format);

	for (; *format != '\0'; format++)
	{
		if (*format != '%')
		{
			buffer[buffer_indx++]=*format;
			chars_count++;
			if (buffer_indx==BUFF_SIZE)
            {
                write(1,buffer,buffer_indx);
				for (;delete_string <= _strlen(buffer); delete_string++)
					buffer[delete_string] = '\0';
            }
		}
		else
		{
			format++;
			if (*format == 'c')
			{
				char c = va_arg(my_args_list, int);

				buffer[buffer_indx++]=c;
				chars_count++;
				if (buffer_indx==BUFF_SIZE)
            {
                write(1,buffer,buffer_indx);
				for (;delete_string <= _strlen(buffer); delete_string++)
					buffer[delete_string] = '\0';
            }
			}
			else if (*format == 's')
			{
			int str_length=0;

            char *str = va_arg(my_args_list, char *);
			while (str[str_length] != '\0')
				{
					buffer[buffer_indx++]=str[str_length];
					if (buffer_indx==BUFF_SIZE)
					{
						write(1,buffer,buffer_indx);
						for (;delete_string <= _strlen(buffer); delete_string++)
							buffer[delete_string] = '\0';
					}
				
					chars_count++;
					str_length++;
				}

			}
			else if ((*format == 'd') || (*format == 'i'))
			{
				int str_length=0;
				int num = va_arg(my_args_list, int);
				char str[100];
				int no = num;
				stringfromint(no, str);
				
                while (str[str_length] != '\0'){
					buffer[buffer_indx++]=str[str_length];
					chars_count ++;
					str_length++;

					if (buffer_indx==BUFF_SIZE)
						{
							write(1,buffer,buffer_indx);
							for (;delete_string <= _strlen(buffer); delete_string++)
								buffer[delete_string] = '\0';
						}
                }
			}
			else if (*format == 'b')
			{
				/*int str_length=0;*/
				
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
				buffer[buffer_indx++]=*format;
				chars_count++;
				if (buffer_indx==BUFF_SIZE)
            {
                write(1,buffer,buffer_indx);
				for (;delete_string <= _strlen(buffer); delete_string++)
					buffer[delete_string] = '\0';
            }
			}
		}
	}
	if(buffer_indx>0){
        write(1,buffer,buffer_indx);
        buffer_indx=0;
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
 * @chars_count: number of chars printed
 * Return: void
*/
void dec2binstring(unsigned int no, int *chars_count, char *buffer, int *buffer_indx)
{
	int i = 0;
	int end;
	char str[100];
	int str_length  = 0;
	int delete_string = 0;

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

	while (str[str_length] != '\0'){
					buffer[(*buffer_indx)++]=str[str_length];
					
					str_length++;

					if ((*buffer_indx)==BUFF_SIZE)
						{
							write(1,buffer,(*buffer_indx));
							for (;delete_string <= _strlen(buffer); delete_string++)
								buffer[delete_string] = '\0';
						}
                }

}

/**
 * dec2octalstring - change integer to octal as a string,
 * increment printf chars_count, print output to stdout
 * @no: integer to change
 * @chars_count: number of chars printed
 * Return: void
*/
void dec2octalstring(unsigned int no, int *chars_count, char *buffer, int *buffer_indx)
{
	char str[100];

	int i = 0;
	int end;
	int str_length = 0;
	int delete_string = 0;

	if (no == 0)
	{
		str[i++] = '0';
		return;
	}
	while (no)
	{
		str[i++] = no % 8 + '0';
		no /= 8;
	}


	str[i] = '\0';
	end = i - 1;
	rev_string(str, end);
	*chars_count += _strlen(str);

	while (str[str_length] != '\0'){
					buffer[(*buffer_indx)++]=str[str_length];
					
					str_length++;

					if ((*buffer_indx)==BUFF_SIZE)
						{
							write(1,buffer,(*buffer_indx));
							for (;delete_string <= _strlen(buffer); delete_string++)
								buffer[delete_string] = '\0';
						}
                }

}

/**
 * dec2HEXstring - change integer to hex(in capital letters) as a string,
 * increment printf chars_count, print output to stdout
 * @no: integer to change
 * @chars_count: number of chars printed
 * Return: void
*/
void dec2HEXstring(unsigned int no, int *chars_count, char *buffer, int *buffer_indx)
{
	int i = 0;
	int number;
	int end;
	char str[100];
	int delete_string = 0;

	int str_length = 0;
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
			str[i++] = number + 55;
		no /= 16;
	}


	str[i] = '\0';
	end = i - 1;
	rev_string(str, end);
	*chars_count += _strlen(str);


	while (str[str_length] != '\0'){
		buffer[(*buffer_indx)++]=str[str_length];
					
		str_length++;

		if ((*buffer_indx)==BUFF_SIZE)
						{
							write(1,buffer,(*buffer_indx));
							for (;delete_string <= _strlen(buffer); delete_string++)
								buffer[delete_string] = '\0';
						}
                }

}

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

	while (str[str_length] != '\0'){
					buffer[(*buffer_indx)++]=str[str_length];
					
					str_length++;

					if ((*buffer_indx)==BUFF_SIZE)
						{
							write(1,buffer,(*buffer_indx));
							for (;delete_string <= _strlen(buffer); delete_string++)
								buffer[delete_string] = '\0';
						}
                }

}

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


	while (str[str_length] != '\0'){
					buffer[(*buffer_indx)++]=str[str_length];
					
					str_length++;

					if ((*buffer_indx)==BUFF_SIZE)
						{
							write(1,buffer,(*buffer_indx));
							for (;delete_string <= _strlen(buffer); delete_string++)
								buffer[delete_string] = '\0';
						}
                }

}


/**
 *rev_string - reverses string
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

/*
int main(void)
{
	int no = 700;

	_printf("Integer = %d, String = %s\n", no, "hello");
	_printf("Hello, World!\n");
	_printf("Hlo, %s!\n", "World");
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


*/

/*
int main() {
    char myString[] = "Hello, World!";
	int delete_string = 0;

    printf("Original String: %s\n", myString);

	for (;delete_string <= _strlen(buffer); delete_string++)
					buffer[delete_string] = '\0';
    

    printf("Modified String: %s: with lenght %d", myString, _strlen(myString));

    return 0;
}
*/
