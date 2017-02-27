/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 11:52:32 by nahmed-m          #+#    #+#             */
/*   Updated: 2017/02/27 01:02:26 by nahmed-m         ###   ########.fr       */
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
		ft_printf("TINY :  0x%X\n", tmp);
		while (tmp)
		{
		ft_printf("\t0x%X - 0x%X : %d octets", tmp->data, tmp->data + tmp->size, tmp->size);
			if ((tmp->free & FLAG_PAGE) != 0)
		ft_printf("   HEAD OF PAGE");
			if ((tmp->free & FLAG_FREE) != 0)
		ft_printf("   FREE");
				ft_printf("\n");
				size += tmp->size;
			tmp = tmp->next;
		}
	ft_printf("\n");
	}
	return (size);
}

static size_t	show_small_heap(void)
{
	t_heap		*tmp;
	t_heap		*new;
	size_t		size;
	
	new = (t_heap*)(tmp + 413696);
	size = 0;
	tmp = g_memory.heap_small;
	if (tmp)
	{
		printf("SMALL : 0x%X\n", tmp);
		printf("SMALL : 0x%X\n", new);
		while (tmp)
		{
				ft_printf("\t0x%X - 0x%X : %d octets", tmp->data, tmp->data + tmp->size, tmp->size);
		if ((tmp->free & FLAG_PAGE) != 0)
		ft_printf("   HEAD OF PAGE");
			if ((tmp->free & FLAG_FREE) != 0)
		ft_printf("   FREE");
//			ft_printf("%s", tmp->data);
				ft_printf("\n");
				size += tmp->size;
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
		ft_printf("BIG :   0x%X\n", tmp);
		while (tmp)
		{
				ft_printf("\t0x%X - 0x%X : %d octets", tmp->data, tmp->data + tmp->size, tmp->size);
			if ((tmp->free & FLAG_PAGE) != 0)
		ft_printf("   HEAD OF PAGE %d ", tmp->size);
			ft_printf("%s", tmp->data);
				ft_printf("\n");
				size += tmp->size;
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
