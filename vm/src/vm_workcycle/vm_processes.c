/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_processes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 20:25:00 by vpaladii          #+#    #+#             */
/*   Updated: 2018/02/17 20:25:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_process	*create_new_process(unsigned pc, t_player *player)
{
	t_process *process;

	process = ft_memalloc(sizeof(t_process));

	process->pc = pc;
	ft_memcpy(process->player_code, player->player_code, 4);
	ft_memcpy(process->registers[1], player->player_code, 4);

	return (process);
}

t_process	*clone_process(unsigned pc, t_process *process)
{
	t_process *new_process;

	new_process = ft_memalloc(sizeof(t_process));
	ft_memcpy(new_process, process, sizeof(t_process));
	ft_memset(&(new_process->comm), 0, sizeof(t_proc_command));
	new_process->pc = pc;

	return (new_process);
}

int		process_still_alive(t_process *proc, t_list *processes)
{
	while (processes)
	{
		if (proc == lst_get_process(processes))
			return (1);
		processes = processes->next;
	}
	return (0);
}
