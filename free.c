/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <nahmed-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 01:28:32 by nahmed-m          #+#    #+#             */
/*   Updated: 2017/03/02 02:58:53 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void free(void *ptr)
{
	t_heap *tmp;

	pthread_mutex_lock(&g_mutex.mutex_free);
	if (ptr == NULL)
	{
		pthread_mutex_unlock(&g_mutex.mutex_free);
		return ;
	}
	tmp = (t_heap*)((char*)ptr - BLOCK_SIZE);
	if (!tmp->data)
	{
		return ;
		pthread_mutex_unlock(&g_mutex.mutex_free);
	}
	if ((tmp->free & FLAG_FREE) == 0)
		tmp->free = tmp->free | FLAG_FREE;
	// add free handler here
	pthread_mutex_unlock(&g_mutex.mutex_free);
}

