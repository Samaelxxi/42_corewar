/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_comment_champion.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 15:15:00 by vgnylyan          #+#    #+#             */
/*   Updated: 2018/02/18 15:15:00 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		save_comment_or_name(char **object, char *line,
									int *nbr_line, int fd)
{
	char		*copy_line;

	if (starts_with(line, COMMENT_CMD_STRING) == 1)
		copy_line = ft_strtrim_start(line + 8);
	else
		copy_line = ft_strtrim_start(line + 5);
	free(line);
	if (*copy_line != '\"')
		lex_error(*nbr_line, "Missing start character (\")");
	else
		put_comment_or_name_on_struct(object, copy_line, nbr_line, fd);
}

void		put_comment_or_name_on_struct(char **object,
						char *line, int *nbr_line, int fd)
{
	if (count_chars(line + 1, '\"'))
	{
		if (check_comment_or_name(ft_strchr(line + 1, '\"') + 1) == 0)
			lex_error(*nbr_line, "Invalid character after end symbol (\")");
		*object = ft_strtrim_end(line + 1);
		*ft_strchr(*object, '\"') = '\0';
		ft_strdel(&line);
	}
	else
	{
		*object = ft_strdup(line + 1);
		ft_strdel(&line);
		join_comment_or_name_to_each_other(object, line, nbr_line, fd);
	}
}

void		join_comment_or_name_to_each_other(char **object,
							char *line, int *nbr_line, int fd)
{
	char		*trim_line;

	while (get_next_line(fd, &line) != 0)
	{
		*nbr_line = *nbr_line + 1;
		join_comment_or_name_together(object, line);
		if (ft_strchr(line, '\"'))
			break ;
		ft_strdel(&line);
	}
	if (!ft_strchr(*object, '\"'))
		lex_error(*nbr_line, "Missing end symbol (\")");
	*ft_strchr(*object, '\"') = '\0';
	trim_line = ft_strtrim_free(line);
	if (check_comment_or_name(ft_strchr(trim_line, '\"') + 1) == 0)
		if (*(ft_strchr(trim_line, '\"') + 1) != '\0')
			lex_error(*nbr_line, "Invalid character after end symbol (\")");
	ft_strdel(&trim_line);
}

void		join_comment_or_name_together(char **object, char *str2)
{
	size_t		size_str1;
	char		*buff;

	size_str1 = ft_strlen(*object);
	*object = (char*)realloc((void*)*object, size_str1 + 2);
	(*object)[size_str1] = '\n';
	(*object)[size_str1 + 1] = '\0';
	buff = ft_strjoin(*object, str2);
	ft_strdel(object);
	*object = buff;
}

int			check_comment_or_name(char *line)
{
	char		*trim_line;

	trim_line = ft_strtrim(line);
	if (*trim_line == '#' || *trim_line == '\0')
	{
		ft_strdel(&trim_line);
		return (1);
	}
	ft_strdel(&trim_line);
	return (0);
}
