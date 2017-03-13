/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <nahmed-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 17:13:00 by nahmed-m          #+#    #+#             */
/*   Updated: 2017/03/12 21:23:48 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void print(char *s)

{

write(1, s, strlen(s));

}

int main()

{

char *addr;

addr = malloc(16);

free(NULL);

free((void *)addr + 5);

if (realloc((void *)addr + 5, 10) == NULL)

print("Bonjours\n");

}
