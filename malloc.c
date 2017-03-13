/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 16:46:01 by nahmed-m          #+#    #+#             */
/*   Updated: 2017/03/12 21:16:57 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void			*malloc(size_t size)
{
	t_heap		*tmp;
	int			size_category;

	if (pthread_mutex_lock(&g_mutex.mutex_malloc) == EINVAL)
	{
		pthread_mutex_init(&g_mutex.mutex_malloc, NULL);
		pthread_mutex_lock(&g_mutex.mutex_malloc);
	}
	if (size == 0)
	{
		pthread_mutex_unlock(&g_mutex.mutex_malloc);
		return (NULL);
	}
	size_category = get_block_category(size);
	if ((tmp = verify_heap(size, size_category)) == NULL)
	{
		if ((tmp = extend_heap(size, size_category)) == NULL)
		{
				pthread_mutex_unlock(&g_mutex.mutex_malloc);
				return (NULL);
		}
	}
	show_actions();
	pthread_mutex_unlock(&g_mutex.mutex_malloc);
	return (tmp->data);
}

