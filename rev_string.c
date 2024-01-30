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
