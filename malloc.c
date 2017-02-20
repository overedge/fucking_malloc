/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 16:46:01 by nahmed-m          #+#    #+#             */
/*   Updated: 2017/02/20 12:07:23 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_memory		g_memory;

void			*malloc(size_t size)
{
	t_heap	*tmp;
	int		size_category;
	if (size == 0)
		return (NULL);
	size = ALIGN8(size);
	size_category = get_block_category(size);
	if (size_category == BIG)
		ft_printf("BIG\n");
	else if (size_category == SMALL)
		ft_printf("SMALL\n");
	else if (size_category == TINY)
		ft_printf("TINY\n");
	if ((tmp = verify_heap(size, size_category)) == NULL)
	{
		if ((tmp = extend_heap(size, size_category)) == NULL)
				return (NULL);
	}
	return ((void*)tmp->data);
}

void free(void *ptr)
{
	t_heap *tmp;

	if (ptr == NULL)
		return ;
	tmp = ptr - sizeof(t_heap);
	munmap(tmp->data, tmp->size);
	tmp->free = 1;
}

void	*realloc(void *ptr, size_t size)
{
	return (NULL);
}



