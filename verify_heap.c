/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_heap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 10:14:11 by nahmed-m          #+#    #+#             */
/*   Updated: 2017/02/26 22:34:17 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

extern t_memory g_memory;
#include <stdio.h>
t_heap	*verify_heap(size_t size, int size_category)
{
	t_heap		*tmp;
	t_heap		*new;
	int			compt;

	compt = 0;
	tmp = get_list_category(size_category);
	if (!tmp)
		return (NULL);
	while (tmp)
	{
		if (compt > get_block_size(size, size_category) || (tmp->free & FLAG_PAGE) != 0)
			compt = 0;
		compt += tmp->size + BLOCK_SIZE;
		if ((compt + size + BLOCK_SIZE< get_block_size(size, size_category) && tmp->next == NULL))
		{
		ft_printf("toto\n");
		new = (t_heap*)(tmp->data + tmp->size);
		new->size = size;
		new->free = 0;
		new->next = NULL;
		tmp->next = new;
		return (new);
		}
		tmp = tmp->next;
	}
	ft_printf("A LA CULOTTE\n");
	return (NULL);
}

