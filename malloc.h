/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 16:59:56 by nahmed-m          #+#    #+#             */
/*   Updated: 2017/03/12 17:11:53 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include "libft/includes/libft.h"
# include <stdlib.h>
# include <sys/mman.h>
# include <unistd.h>
# include <pthread.h>
# include <errno.h>


# define FLAG1 PROT_READ | PROT_WRITE
# define FLAG2 MAP_ANON | MAP_PRIVATE

typedef struct		s_heap {
	size_t			size;
	unsigned char	free;
	struct s_heap	*next;
	void			*data;
}					t_heap;


typedef struct		s_memory {
	t_heap			*heap_tiny;
	t_heap			*heap_small;
	t_heap			*heap_big;
}					t_memory;

typedef struct		s_thread {
	pthread_mutex_t mutex_malloc;
	pthread_mutex_t mutex_free;
	pthread_mutex_t mutex_realloc;
	pthread_mutex_t mutex_show;
}					t_thread;


# define BIG 3
# define SMALL 2
# define TINY 1

# define BLOCK_SIZE sizeof(t_heap)

# define TINY_SIZE 160
# define SMALL_SIZE 1056


# define FLAG_FREE 1
# define FLAG_PAGE 2

t_memory			g_memory;
t_thread			g_mutex;

/*
** Function of project
*/
void				free(void *ptr);
void				*malloc(size_t size);
void				*realloc(void *ptr, size_t size);
void				show_alloc_mem(void);
/*
** Function and declation of memory management
*/
int					get_block_category(size_t size);
size_t				get_block_size(int size_category);
size_t				get_zone_size(size_t size, int size_category);
t_heap				*get_list_category(int size_category);
t_heap				*get_last_of_list(t_heap *begin);
t_heap				*verify_heap(size_t size, int size_category);
t_heap				*extend_heap(size_t size, int size_category);
/*
** Bonus
*/
void				show_actions(void);
#endif
