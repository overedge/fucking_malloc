/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <nahmed-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 01:28:32 by nahmed-m          #+#    #+#             */
/*   Updated: 2017/03/06 12:08:21 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void	free_handler_big(t_heap *ptr, t_heap *tmp)
{
	static		int	i = 1;
	t_heap			*father;
	if (!tmp)
		return ;
	if (tmp == ptr && tmp->next == NULL)
	{
		ft_printf("test s\n");
		g_memory.heap_big = NULL;
		munmap(tmp, tmp->size + BLOCK_SIZE);
	}
	else if (tmp == ptr)
	{
		ft_printf("WESG\n");
		father = g_memory.heap_big;
		while (father != NULL)
		{
			ft_printf("0x%X size : %d \n ", father, father->size);
			father = father->next;
		}
		ft_printf("_-------------------------_ ON RETIRE\n");
		g_memory.heap_big = tmp->next;
		father = g_memory.heap_big;
		while (father != NULL)
		{
			ft_printf("0x%X size : %d \n ", father, father->size);
			father = father->next;
		}
	}
	else
	{
		show_alloc_mem();
		ft_printf("LE PTR ============== 0x%X\n", ptr);
		ft_printf("test\n");
		while (tmp->next != ptr)
			tmp = tmp->next;
		father = tmp;
		tmp = tmp->next;
		father->next = tmp->next;
		munmap(tmp, tmp->size + BLOCK_SIZE);
		ft_printf("test\n");
	}
}

static void	free_handler(t_heap *ptr, int size_category)
{
	t_heap		*begin_list;

	begin_list = get_list_category(size_category);
	if (size_category == BIG)
	{
		free_handler_big(ptr, begin_list);
		return ;
	}
}

void		free(void *ptr)
{
	t_heap *tmp;

	ft_printf("FREE\n");
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
	if ((tmp->free & FLAG_FREE) == 0)
		tmp->free = tmp->free | FLAG_FREE;
	free_handler(tmp, get_block_category(tmp->size));
	show_actions();
	pthread_mutex_unlock(&g_mutex.mutex_free);
}
