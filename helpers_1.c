#include "main.h"


/**
 * my_strcpy - makes a copy of string
 * @source: source
 * @dest: destination
 *
 * Return: Pointer to destination.
 **/
char *my_strcpy(char *dest, char *source)
{
	int i;

	for (i = 0; source[i] != '\0'; i++)
	{
		dest[i] = source[i];
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * my_isalpha - chechks for alphabet
 * @c: Character
 *
 * Return: 1 on success, 0 otherwise
 **/
int my_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (SUCCESS);
	return (FAIL);
}

/**
 * my_itoa - Changes int to
 * @n: size
 *
 * Return: Pointer to null string.
 **/
char *my_itoa(unsigned int n)
{
	char *s;
	int i = 0;
	int len = 0;

	len = my_intlen(n);
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	*s = '\0';
	while (n / 10)
	{
		s[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}

	s[i] = (n % 10) + '0';
	reverse_arr(s, len);
	s[i + 1] = '\0';

	return (s);
}
/**
 * my_atoi - Changes a character to integer
 * @c: Character
 *
 * Return: Integer
 **/
int my_atoi(char *c)
{
	int sign = 1;
	unsigned int val = 0;

	if (c == NULL)
		return (0);
	while (*c)
	{
		if (*c == '-')
			sign *= (-1);
		else
			val = (val * 10) + (*c - '0');
		c++;
	}
	return (sign * val);
}

/**
 * my_intlen - Finds the number of integer
 * @num: number
 *
 * Return: length of integer
 **/
int my_intlen(int num)
{
	int len = 0;

	while (num != 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}
