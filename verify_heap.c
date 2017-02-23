/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_heap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 10:14:11 by nahmed-m          #+#    #+#             */
/*   Updated: 2017/02/23 15:07:53 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

extern t_memory g_memory;
#include <stdio.h>
t_heap	*verify_heap(size_t size, int size_category)
{
	t_heap		*tmp;
	t_heap		*new;
	size_t		compt;

	compt = 0;
	tmp = get_list_category(size_category);
	while (tmp != NULL)
	{
		compt += tmp->size + BLOCK_SIZE;
	//	if (compt >= (size_t)get_block_size(size, size_category)  && tmp->next == NULL && (tmp->free & FLAG_PAGE) == 0)
	//	{
	//		show_alloc_mem();
	//		ft_printf("get_block_size = %d\n", get_block_size(size, size_category));
	//		printf("tmp->data == %s\n", tmp->data);
	//		printf("tmp->free == %d\n", tmp->free);
	//			exit(1);
	//		return (NULL);
		

	//	}
		if (compt >= (size_t)get_block_size(size, size_category))
		{
			ft_printf("NOP\n");
			exit(1);
		}
		if (compt >= (size_t)get_block_size(size, size_category))
			compt = 0;
		if ((tmp->next == NULL || (tmp->free & FLAG_FREE) != 0) && size + BLOCK_SIZE < (size_t)get_block_size(size, size_category) - compt)
		{
			if ((tmp->free & FLAG_FREE) != 0)
			{
				new = tmp;
				new->free &= ~(FLAG_FREE);
				if ((mmap(new->data, new->size, FLAG1, FLAG2, -1, 0)) == MAP_FAILED)
							return (NULL);
			}
			else
			{
				new = (t_heap*)(tmp->data + tmp->size);
				new->size = 1024;
				new->free = 0;
				new->next = NULL;
				tmp->next = new;
			}
			return (new);
		}
		tmp = tmp->next;
	}
	return (NULL);
}

