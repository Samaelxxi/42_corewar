/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 15:37:19 by vpaladii          #+#    #+#             */
/*   Updated: 2017/11/02 15:37:22 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		cut_and_return(t_line *temp_line, char **line, size_t idx)
{
	char	*new_line;
	char	*temp;
	int		last;

	if (line)
	{
		last = (temp_line->r_bytes == 0 &&
				temp_line->line_size == idx + 1) ? 1 : 0;
		if (!(new_line = ft_strsub(temp_line->line, 0, idx + last)))
			return (-1);
		*line = new_line;
		temp_line->line_size -= (idx + 1);
		temp_line->line_buf_size = (((temp_line->line_size) /
									BUFF_SIZE) + 1) * BUFF_SIZE;
		if (!(temp = ft_strnew(temp_line->line_buf_size)))
			return (-1);
		ft_strncpy(temp, (temp_line->line + idx + 1), temp_line->line_size);
		free(temp_line->line);
		temp_line->line = temp;
		return (1);
	}
	else
		return (-1);
}

static t_line	*find_fd(int fd, t_line **t_lines)
{
	t_line	*temp_line;
	t_line	*prev;

	prev = NULL;
	temp_line = *t_lines;
	while (temp_line != NULL)
	{
		if (temp_line->fd == fd)
			return (temp_line);
		prev = temp_line;
		temp_line = temp_line->next;
	}
	if (!(temp_line = (t_line*)malloc(sizeof(t_line))) ||
		!(temp_line->line = ft_strnew(BUFF_SIZE)))
		return (NULL);
	temp_line->fd = fd;
	temp_line->r_bytes = 1;
	temp_line->line_buf_size = BUFF_SIZE;
	temp_line->line_size = 0;
	temp_line->next = NULL;
	if (prev)
		prev->next = temp_line;
	else
		*t_lines = temp_line;
	return (temp_line);
}

static void		delete_temp_line(int fd, t_line **t_lines)
{
	t_line	*temp_line;
	t_line	*prev;

	prev = NULL;
	temp_line = *t_lines;
	while (temp_line != NULL)
	{
		if (temp_line->fd == fd)
		{
			free(temp_line->line);
			if (prev)
				prev->next = temp_line->next;
			else
				*t_lines = temp_line->next;
			free(temp_line);
			break ;
		}
		prev = temp_line;
		temp_line = temp_line->next;
	}
}

int				read_to_temp_line(t_line *temp_line, int fd, t_line **t_lines)
{
	char			*temp;

	if (temp_line->line_size + BUFF_SIZE > temp_line->line_buf_size)
	{
		temp_line->line_buf_size += BUFF_SIZE;
		temp = ft_strnew(temp_line->line_buf_size);
		ft_strncpy(temp, temp_line->line, temp_line->line_size);
		free(temp_line->line);
		temp_line->line = temp;
	}
	if (temp_line->r_bytes > 0)
	{
		temp_line->r_bytes = read(fd, (temp_line->line +
									temp_line->line_size), BUFF_SIZE);
		if (temp_line->r_bytes == -1)
		{
			delete_temp_line(fd, t_lines);
			return (-1);
		}
		temp_line->line_size += temp_line->r_bytes;
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_line	*t_lines;
	t_line			*temp_line;
	size_t			idx;

	if (fd < 0 || (temp_line = find_fd(fd, &t_lines)) == NULL)
		return (-1);
	while (1)
	{
		idx = 0;
		if (temp_line->line_size == 0 && temp_line->r_bytes == 0)
		{
			delete_temp_line(fd, &t_lines);
			return (0);
		}
		while (idx < temp_line->line_size)
		{
			if (temp_line->line[idx] == '\n' ||
				(temp_line->r_bytes == 0 && temp_line->line_size == idx + 1))
				return (cut_and_return(temp_line, line, idx));
			idx++;
		}
		if (read_to_temp_line(temp_line, fd, &t_lines) == -1)
			return (-1);
	}
}
