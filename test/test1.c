#include <stdio.h>
#include <stdlib.h>
int main()
{
	int		i;
	char	*addr;
	i=0;
	while(i<600)
	{
	//	printf("%X\n", addr);
	addr = (char*)malloc(104);
	ft_strcpy(addr, "toto", 4);
//		free(addr)
	i++;;
	}
	show_alloc_mem();
	return(0);
}
