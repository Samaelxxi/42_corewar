/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdubinki <vdubinki@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 10:49:00 by vdubinki          #+#    #+#             */
/*   Updated: 2018/02/23 10:49:00 by vdubinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

void		free_player(t_player *player)
{
	free(player->bytecode->code);
	free(player->bytecode);
	free(player);
}
