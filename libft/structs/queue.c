/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 10:53:00 by vpaladii          #+#    #+#             */
/*   Updated: 2017/12/19 10:53:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../includes/libft_structs.h"

t_queue		*init_queue(size_t data_size)
{
	t_queue *queue;

	queue = malloc(sizeof(t_queue));
	queue->head = NULL;
	queue->tail = NULL;
	queue->data_size = data_size;
	return (queue);
}

void		enqueue(t_queue *queue, void *data)
{
	t_list *new_elem;

	if (!queue)
		return ;
	new_elem = ft_lstnew(data, queue->data_size);
	if (!queue->head)
	{
		queue->head = new_elem;
		queue->tail = new_elem;
	}
	else
	{
		queue->tail->next = new_elem;
		queue->tail = new_elem;
	}
}

void		*dequeue(t_queue *queue)
{
	void	*res;
	t_list	*temp;

	if (!queue || !queue->head)
		return (NULL);
	if (queue->head != queue->tail)
	{
		temp = queue->head;
		res = temp->content;
		queue->head = queue->head->next;
		free(temp);
		return (res);
	}
	else
	{
		res = queue->head->content;
		free(queue->head);
		queue->head = NULL;
		queue->tail = NULL;
		return (res);
	}
}

void		del_queue(t_queue **queue, void (*del)(void *data, size_t s))
{
	ft_lstdel(&((*queue)->head), del);
	free(*queue);
	*queue = NULL;
}
