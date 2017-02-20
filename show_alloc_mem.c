/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 11:52:32 by nahmed-m          #+#    #+#             */
/*   Updated: 2017/02/20 12:02:58 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

extern t_memory g_memory;

static size_t	show_tiny_heap(void)
{
	t_heap		*tmp;
	size_t		size;

	size = 0;
	tmp = g_memory.heap_tiny;
	if (tmp)
	{
		ft_printf("TINY :\n");
		while (tmp)
		{
			if (tmp->free == 0)
			{
				ft_printf("\tSIZE : %d, 0x%X\n", tmp->size, tmp->data);
//				if (tmp->next != NULL)
//					ft_printf("\t\t\t\tDECAL : %d\n", tmp->next->data - tmp->data);
				size += tmp->size;
			}
			tmp = tmp->next;
		}
	ft_printf("\n");
	}
	return (size);
}

static size_t	show_small_heap(void)
{
	t_heap		*tmp;
	size_t		size;

	size = 0;
	tmp = g_memory.heap_small;
	if (tmp)
	{
		ft_printf("SMALL :\n");
		while (tmp)
		{
			if (tmp->free == 0)
			{
				ft_printf("\tSIZE : %d, 0x%X\n", tmp->size, tmp->data);
				size += tmp->size;
			}
			tmp = tmp->next;
		}
	ft_printf("\n");
	}
	return (size);
}

static size_t	show_big_heap(void)
{
	t_heap		*tmp;
	size_t		size;

	size = 0;
	tmp = g_memory.heap_big;
	if (tmp)
	{
		ft_printf("BIG :\n");
		while (tmp)
		{
			if (tmp->free == 0)
			{
				ft_printf("\tSIZE : %d, 0x%X\n", tmp->size, tmp->data);
				size += tmp->size;
			}
			tmp = tmp->next;
		}
	ft_printf("\n");
	}
	return (size);
}

void			show_alloc_mem()
{
	size_t		size;

	size = 0;
	size += show_tiny_heap();
	size += show_small_heap();
	size += show_big_heap();
	ft_printf("Size: %d octect(s)\n", size);
	if (BONUS_SHOW_SIZE)
	{
		ft_printf("\033[1;31m----------BONUS HUMAN READABLE-----------\033[m\n");
		ft_printf("💾\t\033[1;34m KB :\033[m \033[1;32m%d KB\033[m\t\n", size / 1024);
		ft_printf("📼\t\033[1;34m MB :\033[m \033[1;32m%d MB\033[m\n", size / 1024 / 1024);
		ft_printf("📱\t\033[1;34m GB :\033[m \033[1;32m%d GB\033[m\n", size / 1024 / 1024 / 1024);
		ft_printf("\033[1;31m----------------------------------------\033[m\n");
	}
}
