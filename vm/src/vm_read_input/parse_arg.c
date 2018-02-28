/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct_magic_value.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdubinki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 12:50:43 by vdubinki          #+#    #+#             */
/*   Updated: 2018/02/14 12:50:47 by vdubinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_structs.h"
#include "read_input.h"

t_list		*parse_args(int argc, char **argv)
{
	t_list	*args;

	(void)argc;
	args = get_list_from_args(argv);
	if (!args_is_valid(args))
	{
		ft_lstdel(&args, args_deleter);
		return (0);
	}
	return (args);
}

t_list *get_list_from_args(char **argv)
{
	t_list		*args;
	int			option_idx;

	args = 0;
	while (*++argv)
	{
		option_idx = -1;
		while (g_options[++option_idx].label)
			if (!ft_strcmp(g_options[option_idx].label, *argv))
			{
				if (g_options[option_idx].value && *(argv + 1))
					add_arg(&args, g_options[option_idx].label, *++argv);
				else
					add_arg(&args, g_options[option_idx].label, 0);
				break ;
			}
		if (option_idx != OPTIONS_NUMBER)
			continue ;
		add_arg(&args, "player", *argv);
	}
	return (args);
}

int 		args_is_valid(t_list *args)
{
	if (!check_players_numbers(args) ||
		!check_options(args) ||
		!check_numbers(args) ||
		exist_dublicate_numbers(args) ||
		!check_players(args))
		return (0);
	return (1);
}

void		add_arg(t_list **args, char *label, char *value)
{
	t_arg	*arg;

	arg = malloc(sizeof(t_arg));
	arg->flag = label;
	arg->value = value;
	ft_lstappend(args, ft_lstnew(&arg, sizeof(t_arg *)));
}

unsigned 	get_players_number(t_list *args)
{
	unsigned	players_number;
	t_arg		*arg;

	players_number = 0;
	while (args)
	{
		arg = lst_get_arg(args);
		if (!ft_strcmp(arg->flag, "player"))
			players_number++;
		args = args->next;
	}
	return (players_number);
}

int 		check_players_numbers(t_list *args)
{
	unsigned 	players_number;

	players_number = get_players_number(args);
	if (players_number == 0)
	{
		print_usage();
		return (0);
	}
	if (players_number > MAX_PLAYERS)
	{
		ft_putendl("Too many champions");
		return (0);
	}
	return (1);
}

int 		is_value_option(t_arg *arg)
{
	int 	option_idx;

	option_idx = -1;
	while (g_options[++option_idx].label)
		if (!ft_strcmp(g_options[option_idx].label, arg->flag))
			if (g_options[option_idx].value)
				return (1);
	return (0);
}

int 		check_options(t_list *args)
{
	t_arg	*arg;

	while (args)
	{
		arg = lst_get_arg(args);
		if (is_value_option(arg) && !arg->value)
		{
			print_usage();
			return (0);
		}
		args = args->next;
	}
	return (1);
}

int 		check_numbers(t_list *args)
{
	t_arg	*curr;
	t_arg	*next;

	while (args)
	{
		curr = lst_get_arg(args);
		next = 0;
		if (args->next)
			next = lst_get_arg(args->next);
		if (!ft_strcmp(curr->flag, "-n"))
			if (!(next && !ft_strcmp(next->flag, "player")))
			{
				print_usage();
				return (0);
			}
		args = args->next;
	}
	return (1);
}

int 		exist_dublicate_numbers(t_list *args)
{
	t_arg	*arg;

	while (args)
	{
		arg = lst_get_arg(args);
		if (!ft_strcmp(arg->flag, "-n"))
			if (number_is_duplicated(args->next, arg))
			{
				ft_putendl("Invalid number");
				return (1);
			}
		args = args->next;
	}
	return (0);
}

int 		number_is_duplicated(t_list *args, t_arg *number)
{
	t_arg	*arg;

	while (args)
	{
		arg = lst_get_arg(args);
		if (!ft_strcmp(arg->flag, "-n"))
			if (!ft_strcmp(number->value, arg->value))
				return (1);
		args = args->next;
	}
	return (0);
}

int 		is_directory(int fd)
{
	char 	buff;
	int 	ret;

	ret = read(fd, &buff, 1);
	lseek(fd, 0, SEEK_SET);
	if (ret < 0)
		return (1);
	return (0);
}

int 		is_correct_file(char *file)
{
	int 	fd;

	if ((fd = open(file, O_RDONLY)) == -1)
		return (0);
	if (is_directory(fd))
		return (0);
	return (1);
}

int 		check_players(t_list *args)
{
	t_arg	*arg;

	while (args)
	{
		arg = lst_get_arg(args);
		if (!ft_strcmp(arg->flag, "player"))
			if (!is_correct_file(arg->value))
			{
				ft_printf("Can't read source file %s\n", arg->value);
				return (0);
			}
		args = args->next;
	}
	return (1);
}
