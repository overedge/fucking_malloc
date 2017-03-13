/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <nahmed-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 01:28:32 by nahmed-m          #+#    #+#             */
/*   Updated: 2017/03/12 21:15:53 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void	free_handler_big(t_heap *ptr, t_heap *tmp, size_t size, int cat)
{
	t_heap			*father;

	if (!tmp)
		return ;
	if (tmp == ptr)
	{
		g_memory.heap_big = tmp->next;
		if (munmap(tmp, get_zone_size(size, cat)) < 0)
			g_memory.heap_big = tmp;
	}
	else
	{
		while (tmp->next != ptr)
			tmp = tmp->next;
		father = tmp;
		tmp = tmp->next;
		father->next = tmp->next;
		if (munmap(tmp, get_zone_size(size, cat)) < 0)
			father->next = ptr;
	}
}

static void	free_handler(t_heap *ptr, int size_category, size_t size)
{
	t_heap		*begin_list;

	begin_list = get_list_category(size_category);
	if (size_category == BIG)
		free_handler_big(ptr, begin_list, size, size_category);
}

void		free(void *ptr)
{
	t_heap *tmp;

	if (pthread_mutex_lock(&g_mutex.mutex_free) == EINVAL)
	{
		pthread_mutex_init(&g_mutex.mutex_free, NULL);
		pthread_mutex_lock(&g_mutex.mutex_free);
	}
	if (ptr == NULL)
	{
		pthread_mutex_unlock(&g_mutex.mutex_free);
		return ;
	}
	tmp = (t_heap*)((char*)ptr - BLOCK_SIZE);
	if (!tmp->data)
	{
		pthread_mutex_unlock(&g_mutex.mutex_free);
		return ;
	}
	if (get_block_category(tmp->size) != BIG && (tmp->free & FLAG_FREE) == 0)
		tmp->free = tmp->free | FLAG_FREE;
	free_handler(tmp, get_block_category(tmp->size), tmp->size);
	show_actions();
	pthread_mutex_unlock(&g_mutex.mutex_free);
}
