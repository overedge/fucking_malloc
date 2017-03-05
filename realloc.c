/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <nahmed-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 16:19:30 by nahmed-m          #+#    #+#             */
/*   Updated: 2017/03/01 23:29:53 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void				*realloc(void *ptr, size_t size)
{
	t_heap		*tmp;
	t_heap		*new;
	int			size_category;
	int			size_category2;
	
	tmp = (t_heap*)((char*)ptr - BLOCK_SIZE);
	if (ptr == NULL)
		return(malloc(size));
	if (size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}
	//if (!tmp->data)
	//	return (NULL);
		new = malloc(size);
		free(ptr);
		if (new)
		{
		//	if (size >= tmp->size)
		//		ft_memcpy(new, tmp->data, tmp->size);
		//	else
				ft_memcpy(tmp->data, tmp->data, 10);
		}
		else
			return (NULL);
		return(new);
	size_category = get_block_category(size);
	size_category2 = get_block_category(tmp->size);
//	if (tmp->next != NULL && (size_category == BIG || size_category2 == BIG)
//	{
//	}
	if (size_category == size_category2 )
	{
		tmp->size = size;
		return (tmp->data);
	}
	return (NULL);
}
