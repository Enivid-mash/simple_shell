#include "main.h"

/**
 * _strlen - calculates string length
 * @s: pointer to string
 * Return: length of the string
 **/
int _strlen(const char *s)
{
	int n;

	for (n = 0; s[n]; n++)
		;
	return (n);
}

/**
 * _strcmp - compares 2 strings
 * @s1: pointer to string 1
 * @s2: pointer to string 2
 * Return: negive s1 < s2, 0 if s1 = s2
 */
int _strcmp(char *s1, char *s2)
{
	int i;
	int j = 0;
	int s2_len = _strlen(s2);
	int s1_len = _strlen(s1);

	if (s1_len != s2_len)
		return (1);
	for (i = 0; i < s1_len; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (j);
}
