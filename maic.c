/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maic.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <nahmed-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 01:52:01 by nahmed-m          #+#    #+#             */
/*   Updated: 2017/03/06 09:33:35 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "malloc.h"
#include <errno.h>
pthread_mutex_t lock;

void	test(int mutex)
{
	printf("THREAD  : %d\n", mutex);
	if (pthread_mutex_lock(&lock) == EINVAL)
	{
		pthread_mutex_init (&lock, NULL);
		pthread_mutex_lock(&lock);
	}

	printf("HELLO JE SUIS LE THREAD  : %d JATTEND\n", mutex);
	sleep(1);
	pthread_mutex_unlock(&lock);
}

void	*start_thread_1(void * rien)
{
	while(1)
	test(1);
	return (NULL);
}


void	*start_thread_2(void * rien)
{
	while(1)
	test(2);
	return (NULL);
}

int main(void)
{
	pthread_t un;
	pthread_t deux;

	pthread_create (&un, NULL, start_thread_1, NULL);
	pthread_create (&deux, NULL, start_thread_2, NULL);
	sleep(2200);
}
