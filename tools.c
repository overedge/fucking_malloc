/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 17:38:51 by nahmed-m          #+#    #+#             */
/*   Updated: 2017/03/01 02:04:22 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int		get_block_category(size_t size)
{
	if (size + BLOCK_SIZE > SMALL_SIZE)
		return (BIG);
	else if (size + BLOCK_SIZE > TINY_SIZE && size + BLOCK_SIZE <= SMALL_SIZE)
		return (SMALL);
	else
		return (TINY);
}

size_t	get_block_size(int size_category)
{
	if (size_category == SMALL)
		return (1024);
	else if (size_category == TINY)
		return (128);
	else
		printf("EROOOOOOOOOOOOOOR\n");
		return (1);
}

size_t	get_zone_size(size_t size, int size_category)
{
	if (size_category == BIG)
		return (size + BLOCK_SIZE);
	else if (size_category == SMALL)
		return (getpagesize() * 26);
	else
		return (getpagesize() * 4);
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
