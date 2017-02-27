int main()
{
	int		i;
	char	*addr;
	i=0;
	while(i<1024)
	{
//	if (i == 394)
//		addr = (char*)malloc(120);
//	else
	addr = (char*)malloc(4072);
	int		y = 0;
	//			printf("SEGV\n");
	while (y < 4071)
	{
//	ft_printf("ICI %D," , y);
	addr[y] = 42;
	y++;
	}
	addr[y] = '\0';
	y = 0;
	i++;
///	ft_printf("%s", addr);
	}
	show_alloc_mem();
	//printf("SEGVS\n");
	return(0);
}
