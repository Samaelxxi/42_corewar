/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 10:39:00 by vpaladii          #+#    #+#             */
/*   Updated: 2017/12/19 10:39:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_STRUCTS_H
# define LIBFT_STRUCTS_H

# include <stdlib.h>
# include "libft.h"

typedef struct			s_point
{
	int					x;
	int					y;
}						t_point;

/*
** Linked List
*/

typedef struct			s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}						t_list;

t_list					*ft_lstnew(void const *content, size_t content_size);
void					ft_lstdelone(t_list **alst, void (*del)(void *,
										size_t));
void					ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void					ft_lstadd(t_list **alst, t_list *new_elem);
void					ft_lstappend(t_list **alst, t_list *new_node);
void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list					*ft_lst_copy(t_list *lst);
void					ft_lstremove(t_list **lst, t_list *elem,
									void del(void *, size_t));
void					ft_lst_reverse(t_list **begin_list);
int						ft_lstlen(t_list *lst);
void					ft_list_remove_if(t_list **begin_list,
			int (*check)(t_list*), void (*del)(void *, size_t));
void					ft_lst_sort(t_list **begin_list, int (*cmp)());


void					dummy_deleter(void *d, size_t s);
void					content_deleter(void *content, size_t size);
void					double_deleter(void *ptr, size_t size);
/*
**  Circular double linked link
*/

typedef struct			s_cdll
{
	struct s_cdll		*next;
	struct s_cdll		*prev;
	void				*data;
}						t_cdll;

t_cdll					*new_cdll_elem(void *data, size_t datasize);
void					cdll_add(t_cdll **lst, t_cdll *elem);
void					cdll_append(t_cdll **lst, t_cdll *elem);
void					cdll_delete_elem(t_cdll **elem,
										void (*del)(t_cdll *elem));

/*
**  Queue
*/

typedef struct			s_queue
{
	t_list				*head;
	t_list				*tail;
	size_t				data_size;
}						t_queue;

void					enqueue(t_queue *queue, void *data);
void					*dequeue(t_queue *queue);
t_queue					*init_queue(size_t data_size);
void					del_queue(t_queue **queue, void (*del)(void *data,
																size_t s));

#endif
