#include "shell.h"

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
