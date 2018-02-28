/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_initialization.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <omakovsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 13:08:00 by omakovsk          #+#    #+#             */
/*   Updated: 2018/02/18 13:08:00 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void				init_champ_commands(t_file_of_tokens *header, t_champ_commands **champ_cmd)
{
	(*champ_cmd)->champ_name = header->champ_name;
	(*champ_cmd)->champ_desc = header->champ_desc;
}

t_parsing_error		*init_error_struct(int type_error, t_token *token)
{
	t_parsing_error *err;

	if (!(err = ft_memalloc(sizeof(t_parsing_error))))
		return (NULL);
	err->error_code = type_error;
	err->error_token = token;
	return (err);
}
