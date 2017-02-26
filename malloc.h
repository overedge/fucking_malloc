/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 16:59:56 by nahmed-m          #+#    #+#             */
/*   Updated: 2017/02/26 02:43:00 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include "libft/includes/libft.h"
# include <stdlib.h>
# include <sys/mman.h>
# include <unistd.h>

# define FLAG1 PROT_READ | PROT_WRITE
# define FLAG2 MAP_ANON | MAP_PRIVATE
# define BONUS_SHOW_SIZE 1
static int z;
typedef struct		s_heap {
	size_t			size;
	unsigned char	free;
	struct s_heap	*next;
	char			data[];
}					t_heap;


typedef struct		s_memory {
	t_heap			*heap_tiny;
	t_heap			*heap_small;
	t_heap			*heap_big;
}					t_memory;

# define BIG 3
# define SMALL 2
# define TINY 1

# define TINY_SIZE 128
# define SMALL_SIZE 4096

# define BLOCK_SIZE sizeof(t_heap)

# define FLAG_FREE 1
# define FLAG_PAGE 2

/*
** Function of project
*/
void				free(void *ptr);
void				*malloc(size_t size);
/*void				*realloc(void *ptr, size_t size);*/
void				show_alloc_mem(void);
/*
** Function and declation of memory management
*/
int					get_block_category(size_t size);
int					get_block_size(size_t size, int size_category);
t_heap				*get_list_category(int size_category);
t_heap				*get_last_of_list(t_heap *begin);
t_heap				*verify_heap(size_t size, int size_category);
t_heap				*extend_heap(size_t size, int size_category);

#endif
