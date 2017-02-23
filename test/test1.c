int main()
{
	int		i;
	char	*addr;
	i=0;
	while(i<1024)
	{
	addr = (char*)malloc(1024);
	int		y = 0;
	while (y < 1024)
	{
//	ft_printf("ICI %D," , y);
	addr[y] = 42;
	y++;
	}
	addr[y] = '\0';
	y = 0;
	i++;
//		show_alloc_mem();
///	ft_printf("%s", addr);
	}
	show_alloc_mem();
	return(0);
}
