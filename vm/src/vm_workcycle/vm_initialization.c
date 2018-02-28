/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_initialization.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlogin <xlogin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 16:45:00 by xlogin            #+#    #+#             */
/*   Updated: 2018/02/14 16:45:00 by xlogin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_initialization.h"

t_vm		*init_vm(t_input_data *data)
{
	t_vm *vm;

	vm = ft_memalloc(sizeof(t_vm));
	init_vm_values(vm, data);
	write_champions_on_field(vm);
	init_champion_processes(vm);
	choose_vm_mode(vm, data->args);

	return (vm);
}

void		init_vm_values(t_vm *vm, t_input_data *data)
{
	vm->cycles_to_die = CYCLE_TO_DIE;
	vm->players = data->players;
	vm->total_players = ft_lstlen(vm->players);
	vm->last_player = get_last_player(vm->players);
}

t_player	*get_last_player(t_list *players)
{
	while (players->next != NULL)
		players = players->next;
	return (lst_get_player(players));
}

void		write_champions_on_field(t_vm *vm)
{
	t_list *players;
	t_player *player;
	unsigned player_num;

	players = vm->players;
	player_num = 1;
	while (players != NULL)
	{
		player = lst_get_player(players);
		write_champion_on_field(vm, player, player_num);
		player_num++;
		players = players->next;
	}
}

void		write_champion_on_field(t_vm *vm, t_player *player, unsigned player_num)
{
	unsigned shift;

	shift = CALC_INIT_CHAMP_SHIFT(vm->total_players, player_num);
	write_bytecode_on_field(vm, shift, player->bytecode);
}


void		init_champion_processes(t_vm *vm)
{
	t_list *players;
	unsigned player_num;

	players = vm->players;
	player_num = 1;
	while (players)
	{
		add_champion_process(vm, lst_get_player(players), player_num);
		players = players->next;
		player_num++;
	}
}

void		add_champion_process(t_vm *vm, t_player *player, unsigned player_num)
{
	t_process *process;
	unsigned pc;

	pc = CALC_INIT_CHAMP_SHIFT(vm->total_players, player_num);
	process = create_new_process(pc, player);
	load_command_to_process(process, vm);
	lst_add_process(&(vm->processes), process);
}

int 		is_mode(t_arg *arg)
{
	if (!ft_strcmp(arg->flag, "-dump") || !ft_strcmp(arg->flag, "-vis"))
		return (1);
	return (0);
}

void		set_vm_mode(t_vm *vm, t_arg *arg)
{
	if (arg->value)
	{
		vm->vm_mode.mode = DUMP_MODE;
		vm->vm_mode.arg = ft_atoi(arg->value);
		if (vm->vm_mode.arg <= 0)
			vm->vm_mode.arg = 2147483647;
	}
	else
	{
		vm->vm_mode.mode = VIS_MODE;
		vm->vm_mode.arg = 0;
	}
}

void		choose_vm_mode(t_vm *vm, t_list *args)
{
	t_arg	*arg;

	vm->vm_mode.mode = NO_MODE;
	while (args)
	{
		arg = lst_get_arg(args);
		if (is_mode(arg))
			set_vm_mode(vm, arg);
		args = args->next;
	}
}
