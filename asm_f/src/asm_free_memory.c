/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_free_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <omakovsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 11:47:00 by omakovsk          #+#    #+#             */
/*   Updated: 2018/02/23 11:47:00 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		free_all_memory(t_file_of_tokens *all_tokens, t_champion *champion,
						t_champ_commands *command)
{
	free_file_of_tokens(all_tokens);
	free_champion(champion);
	free_champ_command(command);
	return (1);
}

void	free_file_of_tokens(t_file_of_tokens *all_tokens)
{
	free(all_tokens->champ_name);
	free(all_tokens->champ_desc);
	if (all_tokens->lines)
		ft_lstdel(&(all_tokens->lines), line_deleter);
}

void	free_champion(t_champion *champion)
{
	if (champion->champ_desc)
		free(champion->champ_desc);
	if (champion->champ_name)
		free(champion->champ_name);
	if (champion->magic_value)
		free(champion->magic_value);
	if (champion->size_champ)
		free(champion->size_champ);
	if (champion->bytecode && champion->bytecode->code)
		free(champion->bytecode->code);
	if (champion->bytecode)
		free(champion->bytecode);
}

void	free_champ_command(t_champ_commands *command)
{
	if (command->commands)
		ft_lstdel(&(command->commands), command_deleter);
}
