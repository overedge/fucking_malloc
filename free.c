/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <nahmed-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 01:28:32 by nahmed-m          #+#    #+#             */
/*   Updated: 2017/03/01 01:36:11 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void free(void *ptr)
{
	t_heap *tmp;

	if (ptr == NULL)
		return ;
	tmp = (t_heap*)((char*)ptr - BLOCK_SIZE);
	if ((tmp->free & FLAG_FREE) == 0)
		tmp->free = tmp->free | FLAG_FREE;
}

