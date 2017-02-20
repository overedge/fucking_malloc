/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_heap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 10:14:11 by nahmed-m          #+#    #+#             */
/*   Updated: 2017/02/20 12:07:22 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

extern t_memory g_memory;

t_heap	*verify_heap_big(size_t size, int size_category)
{


	return (NULL);
}


#include <stdio.h>
t_heap	*verify_heap(size_t size, int size_category)
{
	t_heap		*tmp;
	t_heap		*new;
	size_t		compt;

	compt = 0;
	tmp = get_list_category(size_category);
	if (size_category == BIG)
		return (verify_heap_big(size, size_category));
	while (tmp)
	{
		compt += tmp->size + BLOCK_SIZE;
		if (compt >= getpagesize()  && tmp->next == NULL)
			return (NULL);
		if (compt >= getpagesize())
		{
			compt = 0;
			ft_printf("PAGE NEXT\n");
		}
		if ((tmp->next == NULL || tmp->free == 1) && size + BLOCK_SIZE < (size_t)getpagesize - compt)
		{
			if (tmp->free == 1)
				new = tmp;
			else
			{
				new = (t_heap*)(tmp->data + tmp->size);
				new->size = size;
			}
			new->free = 0;
			new->next = NULL;
			tmp->next = new;
			return (new);
		}
		tmp = tmp->next;
	}
	return (NULL);
}

