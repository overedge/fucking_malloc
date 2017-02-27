/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_heap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 10:14:11 by nahmed-m          #+#    #+#             */
/*   Updated: 2017/02/27 01:02:25 by nahmed-m         ###   ########.fr       */
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
		compt += tmp->size + BLOCK_SIZE;

		if (compt + size + BLOCK_SIZE > get_block_size(size, size_category))
		compt = 0;
		if ((compt + size + BLOCK_SIZE <= get_block_size(size, size_category) && tmp->next == NULL) && compt != 0)

		{
	if ((tmp->free & FLAG_PAGE) != 0)
		ft_printf("PAGE\n");
		ft_printf("%d get_block_size = %d\n", compt, get_block_size(size, size_category));
		ft_printf("toto\n");
		new = (t_heap*)(tmp->data + tmp->size);
		new->size = size;
		new->free = 0;
		new->next = NULL;
		tmp->next = new;
		ft_printf("size = %d NEW = 0x%X new->data = 0x%X\n", size,new,new->data);
		return (new);
		}
		tmp = tmp->next;
	}
	ft_printf("A LA CULOTTE\n");
	return (NULL);
}

