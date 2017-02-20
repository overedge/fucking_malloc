/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 17:38:51 by nahmed-m          #+#    #+#             */
/*   Updated: 2017/02/20 12:07:22 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

extern t_memory g_memory;

int		get_block_category(size_t size)
{
	int		size_page;

	size_page = getpagesize();
	if (size + BLOCK_SIZE >= size_page)
		return (BIG);
	if (size + BLOCK_SIZE > 128 && size + BLOCK_SIZE < 512)
		return (SMALL);
	return (TINY);
}

int		get_block_size(size_t size, int size_category)
{
	if (size_category == BIG)
		return (-1);
	else if (size_category == SMALL)
		return (SMALL_SIZE * 100 / getpagesize());
	else
		return (TINY_SIZE * 100 / getpagesize());
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
