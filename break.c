#include "shell.h"

/**
 * is_cmd - determines if it is an executable command
 * @info: the info struct
 * @p: path
 *
 * Return: 1 if true, 0 otherwise
 */

int is_cmd(info_t *info, char *p)
{
	struct stat st;

	(void)info;
	if (!p || stat(p, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}

	return (0);
}

/**
 * dup_chars - character duplication
 * @str: PATH string
 * @y: start index
 * @z: stop index
 *
 * Return: pointer to new buffer
 */

char *dup_chars(char *str, int y, int z)
{
	static char buf[1024];
	int i = 0, k = 0;

	for (k = 0, i = y; i < z; i++)
		if (str[i] != ':')
			buf[k++] = str[i];

	buf[k] = 0;

	return (buf);
}

/**
 * find_path - checks for cmd in the PATH string
 * @info: the info struct
 * @str: the PATH string
 * @cmd: the cmd to find
 *
 * Return: full path of cmd if found or NULL
 */

char *find_path(info_t *info, char *str, char *cmd)
{
	int i = 0, c = 0;
	char *path;

	if (!str)
		return (NULL);

	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}

	while (1)
	{
		if (!str[i] || str[i] == ':')
		{
			path = dup_chars(str, c, i);

			if (!*path)
				_strcat(path, cmd);

			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}

			if (is_cmd(info, path))
				return (path);

			if (!str[i])
				break;

			c = i;
		}

		i++;
	}

	return (NULL);
}
