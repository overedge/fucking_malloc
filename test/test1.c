int main()
{
	int		i;
	char	*addr;
	i=0;
	while(i<6)
	{
	addr = (char*)malloc(1024);
	int		y = 0;
	//			printf("SEGV\n");
	while (y < 1023)
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
