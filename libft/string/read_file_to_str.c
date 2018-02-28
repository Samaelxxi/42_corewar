/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_to_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlogin <xlogin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 16:29:00 by xlogin            #+#    #+#             */
/*   Updated: 2018/02/14 16:29:00 by xlogin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		count_message_size(t_list *lst)
{
	size_t len;

	len = 0;
	while (lst)
	{
		len += lst->content_size;
		lst = lst->next;
	}
	return (len);
}

void		write_message_to_str(t_list *lst, char *res)
{
	size_t written;

	written = 0;
	while (lst)
	{
		ft_memcpy(res + written, (char*)(lst->content), lst->content_size);
		written += lst->content_size;
		lst = lst->next;
	}
}

size_t		list_to_str(t_list *lst, char **input_message)
{
	char	*res;
	size_t	len;

	len = count_message_size(lst);
	res = ft_strnew(len);
	write_message_to_str(lst, res);
	*input_message = res;
	return (len);
}

ssize_t		read_file_to_str(int fd, char **input_message)
{
	t_list	*lst;
	char	buf[65];
	size_t	readen;
	size_t	len;

	(void)fd;
	lst = NULL;
	while ((readen = read(fd, buf, 64)) > 0)
	{
		buf[readen] = '\0';
		ft_lstappend(&lst, ft_lstnew(buf, readen));
	}
	len = list_to_str(lst, input_message);
	ft_lstdel(&lst, content_deleter);
	return (len);
}
