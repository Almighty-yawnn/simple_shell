#include "shell.h"

/**
 * _strcpy - A custom implementation of a string copy
 * @d: pointer to the destination buffer
 * @s: pointer to the source string
 * Return: The original address of the destination buffer
 */

char *_strcpy(char *d, char *s)
{
	int i;
	char *res;

	res = d;
	i = 0;
	while (s[i] != '\0')
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (res);
}

/**
 * _strdup - A custom implementation of a string duplicate
 * @s: A pointer to the source string
 * Return: The original address of the destination buffer
 */

char *_strdup(char *s)
{
	size_t l = 0;
	char *temp, *d, *res;

	if (s == NULL)
		return (NULL);
	temp = s;
	while (*temp != '\0')
	{
		l++;
		temp++;
	}

	d = malloc(sizeof(char *) * (l + 1));
	if (d == NULL)
	{
		return (NULL);
	}
	res = d;
	while (*s != '\0')
	{
		*d = *s;
		d++;
		s++;
	}
	*d = '\0';
	return (res);
}

/**
 * _strchr - A custom implementation of a string character
 * @s: A pointer to the source string
 * @c: The character to be found in a given string
 * Return: NULL
 */

char *_strchr(char  *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return (s);
		s++;
	}
	return (NULL);
}

/**
 * _strcmp - A custom implementation of string compare
 * @s1: The pointer to the first string to be compared
 * @s2: The pointer to second string to be compared
 * Return: The difference between the first and second string
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
			return (0);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
 * _strcat - A custom implementation of string concatenate
 * @d: A pointer to the destination string
 * @s: A pointer to the source
 * Return: Original destination
 */

char *_strcat(char *d, char *s)
{
	char *original_dest = d;

	while (*d != '\0')
	{
		d++;
	}
	while (*s != '\0')
	{
		*d = *s;
		d++;
		s++;
	}
	*d = '\0';
	return (original_dest);
}
