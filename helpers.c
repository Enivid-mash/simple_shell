#include "main.h"

/**
 * my_strcat - Concatenates strings
 * @first: destination
 * @second: source
 *
 * Return: 0 or 1
 **/
char *my_strcat(char *first, char *second)
{
	char *result;
	int len1, len2;
	int i = 0;
	int j = 0;

	len2 = my_strlen(second);
	len1 = my_strlen(first);
	result = malloc((len1 + len2 + 2) * sizeof(char));
	if (!result)
		return (NULL);
	*result = '\0';
	while (first[j])
		result[i++] = first[j++];
	result[i++] = '/';
	j = 0;
	while (second[j])
		result[i++] = second[j++];
	result[i] = '\0';
	return (result);
}

/**
 * my_strlen - determines string length
 * @str: string
 *
 * Return: 0 or 1
 **/
int my_strlen(char *str)
{
	int len;

	for (len = 0; str[len]; len++)
		;
	return (len);
}

/**
 * my_strcmp - Compares strings
 * @s1: string one
 * @s2: string two
 *
 * Return: 0 or 1
 **/
int my_strcmp(char *s1, char *s2)
{
	int i;
	int cmp = 0;

	if (s1 == NULL || s2 == NULL)
		return (1);
	for (i = 0; s1[i]; i++)
	{
		if (s1[i] != s2[i])
		{
			cmp = s1[i] - s2[i];
			break;
		}
		else
			continue;
	}
	return (cmp);
}
/**
 * my_strchr - Finds a character in a string
 * @str: string
 * @c: the character
 *
 * Return: 0 or 1.
 **/
char *my_strchr(char *str, char c)
{
	char *ptr;

	if (str == NULL)
		return (NULL);
	for (ptr = str; *ptr; ptr++)
	{
		if (*ptr == c)
			return (ptr);
	}

	return (NULL);
}

/**
 * my_strdup - Dupicates a string.
 * @str: string.
 *
 * Return: char pointer
 **/
char *my_strdup(char *str)
{
	char *dupl;

	if (str == NULL)
		return (NULL);

	dupl = malloc(my_strlen(str) + 1);

	if (dupl == NULL)
		return (NULL);

	my_strcpy(dupl, str);

	return (dupl);
}
