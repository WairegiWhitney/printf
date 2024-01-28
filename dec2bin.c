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

