/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <nahmed-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 16:19:30 by nahmed-m          #+#    #+#             */
/*   Updated: 2017/03/12 21:15:51 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void			*realloc_handler(int s1, int s2, t_heap *tmp, size_t size)
{
	t_heap		*new;

	if (!tmp->data)
	{
		pthread_mutex_unlock(&g_mutex.mutex_realloc);
		return (NULL);
	}
	if (s1 == s2 && s1 != BIG)
	{
		tmp->size = size;
		pthread_mutex_unlock(&g_mutex.mutex_realloc);
		return (tmp->data);
	}
	else
	{
		new = malloc(size);
		if (new)
		{
			if (size >= tmp->size)
				ft_memcpy(new, tmp->data, tmp->size);
		}
		free(tmp->data);
		pthread_mutex_unlock(&g_mutex.mutex_realloc);
		return(new);
	}
}

void				*realloc(void *ptr, size_t size)
{
	t_heap		*tmp;
	int			size_category;
	int			size_category2;

	if (pthread_mutex_lock(&g_mutex.mutex_realloc) == EINVAL)
	{
		pthread_mutex_init(&g_mutex.mutex_realloc, NULL);
		pthread_mutex_lock(&g_mutex.mutex_realloc);
	}
	if (ptr == NULL)
	{
		pthread_mutex_unlock(&g_mutex.mutex_realloc);
		return (malloc(size));
	}
	tmp = (t_heap*)((char*)ptr - BLOCK_SIZE);
	size_category = get_block_category(size);
	size_category2 = get_block_category(tmp->size);
	if (size == 0 && ptr)
	{
		free(ptr);
		pthread_mutex_unlock(&g_mutex.mutex_realloc);
		return (NULL);
	}
	return (realloc_handler(size_category, size_category2, tmp, size));
}
