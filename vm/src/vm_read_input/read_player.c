/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdubinki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 10:17:39 by vdubinki          #+#    #+#             */
/*   Updated: 2018/02/14 10:17:41 by vdubinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "vm_structs.h"

t_bytecode	*read_player(char *filename)
{
	t_bytecode	*bytecode;
	int			fd;
	char		*tmp;

	if (!filename)
		return (0);
	if ((fd = open(filename, O_RDONLY)) == -1)
		return (0);
	if (!(bytecode = malloc(sizeof(t_bytecode))))
		return (0);
	bytecode->size = read_file_to_str(fd, &tmp);
	bytecode->code = (uint8_t *)tmp;
	return (bytecode);
}
