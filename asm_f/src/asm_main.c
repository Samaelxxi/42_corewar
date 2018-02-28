/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 13:46:00 by vgnylyan          #+#    #+#             */
/*   Updated: 2018/02/15 13:46:00 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		main(int argc, char **argv)
{
	int								fd;
	t_file_of_tokens				file_of_tokens;
	t_champion						champion;
	t_champ_commands				parsed_commands;

	ft_memset(&(file_of_tokens), 0, sizeof(t_file_of_tokens));
	ft_memset(&(champion), 0, sizeof(t_champion));
	ft_memset(&(parsed_commands), 0, sizeof(t_champ_commands));
	fd = open_file(argc, argv);
	split_file_into_tokens(&file_of_tokens, fd);
	close(fd);
	if (parse_all_tokens(&file_of_tokens, &parsed_commands))
	{
		free_all_memory(&file_of_tokens, &champion, &parsed_commands);
		return (1);
	}
	create_champion_code(&champion, &parsed_commands);
	fd = create_newfile(argv[argc - 1]);
	write_champ_to_file(fd, &champion);
	close (fd);

	free_all_memory(&file_of_tokens, &champion, &parsed_commands);
	return (0);
}

void		write_champ_to_file(int fd, t_champion *champion)
{
	write(fd, champion->magic_value, MAGIC_VALUE_SIZE);
	write(fd, champion->champ_name, PROG_NAME_LENGTH + PADDING_AFTER_PROG_NAME_SIZE);
	write(fd, champion->size_champ, CODE_SIZE);
	write(fd, champion->champ_desc, COMMENT_LENGTH + PADDING_AFTER_COMMENT_SIZE);
	write(fd, (champion->bytecode)->code, (champion->bytecode)->size);
}


