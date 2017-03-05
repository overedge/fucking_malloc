/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_heap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 10:14:11 by nahmed-m          #+#    #+#             */
/*   Updated: 2017/03/02 01:23:34 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"


static t_heap	*verify_heap_big(size_t size, t_heap *tmp)
{
	while (tmp != NULL)
	{
		if ((tmp->free & FLAG_FREE) != 0 && size <= tmp->size)
		{
				tmp->free = (tmp->free & ~FLAG_FREE);
				
				// PEUT ETRE RAJOUTER UN FREE SUR le RESTE
				return (tmp);
		}
		tmp = tmp->next;
	}
	return (NULL);
}

t_heap			*verify_heap(size_t size, int size_category)
{
	t_heap		*tmp;
	t_heap		*new;
	int			compt;

	compt = 0;
	tmp = get_list_category(size_category);
	if (!tmp)
		return (NULL);
	if (size_category == BIG)
		return (verify_heap_big(size, tmp));
	while (tmp != NULL)
	{
		if ((tmp->free & FLAG_PAGE) != 0)
			compt = 0;
		compt += get_block_size(size_category);
		if ((tmp->next == NULL && compt + get_block_size(size_category) <= get_zone_size(size, size_category)) || ((tmp->free & FLAG_FREE) != 0 && size <= tmp->size))
		{
			if ((tmp->free & FLAG_FREE) != 0 && size <= tmp->size)
			{
				tmp->free = (tmp->free & ~FLAG_FREE);
				return (tmp);
			}
			else
			{
				new = (t_heap*)((char*)tmp + get_block_size(size_category));
				new->size = size;
				new->free = 0;
				new->next = NULL;
				new->data = (void*)((char*)new + BLOCK_SIZE);
				tmp->next = new;
			}
			return (new);
		}
		tmp = tmp->next;
	}
	return (NULL);
}

