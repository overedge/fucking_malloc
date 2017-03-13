/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <nahmed-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 16:47:06 by nahmed-m          #+#    #+#             */
/*   Updated: 2017/03/12 21:21:03 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define M (1024 * 1024)

void print(char *s)

{

write(1, s, strlen(s));

}

int main()
{
char *addr1;
char *addr3;
addr1 = (char*)malloc(16*M);
strcpy(addr1, "Bonjours\n");
print(addr1);
addr3 = (char*)realloc(addr1, 128*M);
addr3[127*M] = 42;
print(addr3);
return (0);
}
