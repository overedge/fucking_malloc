/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_management.c                                :+:      :+:    :+:   */
/*                                                  `  +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 14:42:42 by nahmed-m          #+#    #+#             */
/*   Updated: 2017/02/23 14:36:34 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

#include <stdio.h>
extern t_memory g_memory;
t_heap	*extend_heap(size_t size, int size_category)
{
	printf("EXTEND HEAP\n");
	t_heap		*tmp;
	t_heap		*new;

	tmp = get_list_category(size_category);
	if ((new = mmap(0, get_block_size(size, size_category), FLAG1, FLAG2, -1, 0)) == MAP_FAILED)
		return (NULL);
	new->size = size;
	new->free = 2;
	new->next = NULL;
	if (!tmp)
	{
		if (size_category == BIG)
			g_memory.heap_big = new;
		else if (size_category == SMALL)
			g_memory.heap_small = new;
		else
			g_memory.heap_tiny = new;
	}
	else
	{
		tmp = get_last_of_list(tmp);
		tmp->next = new;
	}
	return (new);
}
