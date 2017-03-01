/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 16:46:01 by nahmed-m          #+#    #+#             */
/*   Updated: 2017/03/01 01:28:29 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void			*malloc(size_t size)
{
	t_heap		*tmp;
	int			size_category;
	if (size == 0)
		return (NULL);
	size_category = get_block_category(size);
	if ((tmp = verify_heap(size, size_category)) == NULL)
	{
		if ((tmp = extend_heap(size, size_category)) == NULL)
				return (NULL);
	}
	return (tmp->data);
}

