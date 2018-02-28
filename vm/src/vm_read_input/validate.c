/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdubinki <vdubinki@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 11:51:00 by vdubinki          #+#    #+#             */
/*   Updated: 2018/02/15 11:51:00 by vdubinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_structs.h"
#include "vm.h"
#include "read_input.h"

t_input_data	*read_input_data(int argc, char **argv)
{
	t_input_data	*input_data;

	if (argc == 1)
	{
		print_usage();
		return (0);
	}
	input_data = malloc(sizeof(t_input_data));
	if (!(input_data->args = parse_args(argc, argv)))
	{
		free(input_data);
		return (0);
	}
	if (!(input_data->players = parse_players(input_data->args)))
	{
		ft_lstdel(&input_data->args, args_deleter);
		free(input_data);
		return (0);
	}
	return (input_data);
}

void 		print_usage()
{
	ft_putendl("Usage: ./corewar [-dump N | -vis] [-n N] <champion.cor> <...>");
	ft_putendl("-dump N\t: Dumps memory after N cycles then exits");
	ft_putendl("-vis\t: Ncurses output mode");
	ft_putendl("-n N\t: Sets number N to champion");
}

t_list 		*parse_players(t_list *args)
{
	t_list		*players;

	if (!(players = get_players(args)))
		return (0);
	init_numbers(players, args);
	ft_lst_sort(&players, nbr_cmp);
	return (players);
}

t_list			*get_players(t_list *args)
{
	t_list		*players;
	t_arg		*arg;
	t_player	*player;

	players = 0;
	while (args)
	{
		arg = lst_get_arg(args);
		if (!ft_strcmp(arg->flag, "player"))
		{
			if ((player = get_player(arg->value)))
				lst_add_player(&players, player);
			else
			{
				free_players(&players);
				return (0);
			}
		}
		args = args->next;
	}
	return (players);
}

void init_numbers(t_list *players, t_list *args)
{
	t_list		*players_cpy;
	t_player	*player;
	unsigned	player_idx;
	int 		player_number;

	players_cpy = players;
	player_idx = 0;
	while (players)
	{
		player = lst_get_player(players);
		player_idx++;
		player_number = get_player_number(args, players_cpy, player_idx);
		init_player_number(player, player_number, player_idx);
		players = players->next;
	}
}

int 	get_player_number(t_list *args, t_list *players, unsigned player_idx)
{
	int 	player_number;

	if ((player_number = get_number_from_args(args, player_idx)) == 0)
		player_number = player_idx;
	if (number_exists(players, player_number))
		player_number = player_idx;
	while (number_exists(players, player_number))
		++player_number;
	return (player_number);
}

void	init_player_number(t_player *player, int player_number, unsigned player_idx)
{
	player->player_num = player_number;
	player_number = -player_idx;
	player_number = swap_uint32(player_number);
	ft_memcpy(player->player_code, (uint8_t *)&player_number, 4);
}

int 	get_number_from_args(t_list *args, unsigned player_idx)
{
	t_arg	*curr;
	t_arg	*prev;

	prev = 0;
	while (args)
	{
		curr = lst_get_arg(args);
		if (!ft_strcmp(curr->flag, "player"))
			--player_idx;
		if (player_idx == 0)
			if (prev && !ft_strcmp(prev->flag, "-n"))
				return (ft_atoi(prev->value));
		prev = curr;
		args = args->next;
	}
	return (0);
}

int 		number_exists(t_list *players, int number)
{
	t_player	*player;

	if (number == 0)
		return (1);
	while (players)
	{
		player = lst_get_player(players);
		if (player->player_num == number)
			return (1);
		players = players->next;
	}
	return (0);
}

int 			nbr_cmp(void *a, void *b)
{
	t_player	*player1;
	t_player	*player2;

	player1 = *(t_player **)a;
	player2 = *(t_player **)b;

	return (player1->player_num - player2->player_num);
}
