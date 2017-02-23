/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 17:38:51 by nahmed-m          #+#    #+#             */
/*   Updated: 2017/02/21 15:14:35 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

extern t_memory g_memory;

int		get_block_category(size_t size)
{
	if (size + BLOCK_SIZE >= SMALL_SIZE)
		return (BIG);
	if (size + BLOCK_SIZE > 128 && size + BLOCK_SIZE < 4096)
		return (SMALL);
	return (TINY);
}

int		get_block_size(size_t size, int size_category)
{
	if (size_category == BIG)
		return (((size + BLOCK_SIZE) / getpagesize() + 1) * getpagesize());
	else if (size_category == SMALL)
		return (((SMALL_SIZE + BLOCK_SIZE) * 100 / getpagesize() + 1) * getpagesize()); 
	else
		return (((TINY_SIZE + BLOCK_SIZE) * 100 / getpagesize() + 1) * getpagesize());
}

t_heap	*get_list_category(int size_category)
{
	if (size_category == BIG)
		return (g_memory.heap_big);
	else if (size_category == SMALL)
		return (g_memory.heap_small);
	else
		return (g_memory.heap_tiny);
}

t_heap	*get_last_of_list(t_heap *begin)
{
	while (begin->next != NULL)
		begin = begin->next;
	return (begin);
}
