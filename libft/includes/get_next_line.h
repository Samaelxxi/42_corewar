/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 15:37:35 by vpaladii          #+#    #+#             */
/*   Updated: 2017/11/24 21:34:28 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 64

# include <unistd.h>
# include <fcntl.h>
# include "libft.h"

typedef struct		s_line
{
	int				fd;
	int				r_bytes;
	char			*line;
	size_t			line_buf_size;
	size_t			line_size;
	struct s_line	*next;
}					t_line;

int					get_next_line(const int fd, char **line);

#endif
