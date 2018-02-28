/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdubinki <vdubinki@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 09:53:00 by vdubinki          #+#    #+#             */
/*   Updated: 2018/02/23 09:53:00 by vdubinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

int 	main(int argc, char **argv)
{
	t_player	*player;

	if (!check_args(argc, argv))
		return (0);
	if (!(player = get_player(argv[1])))
		return (0);
	disassemble(player, argv[1]);
	free_player(player);
	return (0);
}
