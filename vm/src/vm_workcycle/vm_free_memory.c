/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_free_memory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlogin <xlogin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 13:46:00 by xlogin            #+#    #+#             */
/*   Updated: 2018/02/15 13:46:00 by xlogin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		player_deleter(void *content, size_t size)
{
	t_player *player;

	if (content && size)
	{
		player = *((t_player**)(content));
		free(player->bytecode->code);
		free(player->bytecode);
		free(player);
		free(content);
	}
}

void		process_deleter(void *content, size_t size)
{
	t_process *process;

	if (content && size)
	{
		process = *((t_process**)(content));
		free(process);
		free(content);
	}
}

void		args_deleter(void *content, size_t size)
{
	t_arg *arg;

	if (content && size)
	{
		arg = *((t_arg**)(content));
		free(arg);
		free(content);
	}
}

void		free_data(t_vm *vm, t_input_data *data)
{
	if (vm->processes)
		ft_lstdel(&(vm->processes), double_deleter);
	ft_lstdel(&(vm->players), player_deleter);
	if (data->args)
		ft_lstdel(&(data->args), args_deleter);
	free(data);
	free(vm);
}

void 		free_bytecode(t_bytecode *bytecode)
{
	if (bytecode)
	{
		if (bytecode->code)
			free(bytecode->code);
		free(bytecode);
	}
}

void		free_players(t_list **players)
{
	ft_lstdel(players, player_deleter);
}
