#include "shell.h"

/**
 * _myhistory - displays the history list, one command by line, preceded
 *              with line numbers, starting at 0.
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *
 *  Return: Always 0
 */

int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - sets alias to string
 * @info: parameter struct
 * @s: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */

int unset_alias(info_t *info, char *s)
{
	char *pr, ch;
	int i;

	pr = _strchr(s, '=');
	if (!pr)
		return (1);
	ch = *pr;
	*pr = 0;
	i = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, s, -1)));
	*pr = ch;
	return (i);
}

/**
 * set_alias - sets alias to string
 * @info: parameter struct
 * @s: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */

int set_alias(info_t *info, char *s)
{
	char *pr;

	pr = _strchr(s, '=');
	if (!pr)
		return (1);
	if (!*++pr)
		return (unset_alias(info, s));

	unset_alias(info, s);
	return (add_node_end(&(info->alias), s, 0) == NULL);
}

/**
 * print_alias - prints an alias string
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */

int print_alias(list_t *node)
{
	char *pr = NULL, *b = NULL;

	if (node)
	{
		pr = _strchr(node->str, '=');

		for (b = node->str; b <= pr; b++)
		_putchar(*b);
		_putchar('\'');
		_puts(pr + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - mimics the alias builtin (man alias)
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *
 *  Return: Always 0
 */

int _myalias(info_t *info)
{
	int i = 0;
	char *pr = NULL;

	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;

		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}

	for (i = 1; info->argv[i]; i++)
	{
		pr = _strchr(info->argv[i], '=');

		if (pr)
		{
			set_alias(info, info->argv[i]);
		}
		else
		{
			print_alias(node_starts_with(info->alias, info->argv[i], '='));
		}
	}

	return (0);
}
