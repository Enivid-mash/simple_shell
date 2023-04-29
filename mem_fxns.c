#include "main.h"

/**
 * my_realloc - Reallocating memory.
 * @ptr: Previous memory block
 * @old_size: former memory size
 * @new_size: new memory size
 *
 * Return: Pointer to new memory.
 **/
void *my_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *result;

	if (new_size == old_size)
		return (ptr);
	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}
	result = malloc(new_size);
	if (result == NULL)
		return (NULL);
	if (ptr == NULL)
	{
		array_populate(result, '\0', new_size);
		free(ptr);
	}
	else
	{
		my_memcpy(result, ptr, old_size);
		free(ptr);
	}
	return (result);
}

/**
 * my_memset - set memory with cons. bytes
 * @s: Memory block
 * @n: bytes
 * @byt: Constant byte
 *
 * Return: Pointer to character.
 **/
char *my_memset(char *s, char byt, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = byt;
	}
	return (s);
}

/**
 * my_free_data - free data
 * @data: data structure
 *
 * Return: +ve on success, -ve otherwise
 **/
int my_free_data(sh_t *data)
{
	free((*data).line);
	(*data).line = NULL;
	free((*data).args);
	(*data).args = NULL;
	free((*data).cmd);
	(*data).cmd = NULL;
	free((*data).error_msg);
	(*data).error_msg = NULL;

	return (0);
}

/**
 * my_memcpy - Copies memory block
 * @dest: destination memory block
 * @src: source memory block
 * @n: byte quantity
 *
 * Return: Pointer to destination memory.
 **/
char *my_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}
