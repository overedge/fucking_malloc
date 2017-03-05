/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <nahmed-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 17:13:00 by nahmed-m          #+#    #+#             */
/*   Updated: 2017/03/01 23:28:11 by nahmed-m         ###   ########.fr       */
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
strcpy(addr, "BONJOURS12345678");
print(addr);
//free(NULL);

//free((void *)addr + 5);

addr = realloc((void *)addr, 10);
print(addr);
show_alloc_mem();
}
