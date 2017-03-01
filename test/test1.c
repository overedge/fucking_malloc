
void	ft_remplis(int i, char *addr)
{
	int		y = 0;
		while (y < i)
		{
			addr[y] = 42;
			y++;
		}
		addr[y] = '\0';
}

int main()
{
	int		i;
	char	*addr;
	i=0;
	while(i<50)
	{
	addr = (char*)malloc(1000);
	ft_remplis(999, addr);
	//free(addr);
	addr = (char*)malloc(10);
	//ft_remplis(9, addr);
	free(addr);
	addr = (char*)malloc(100);
//	ft_remplis(99, addr);
	free(addr);
	addr = (char*)malloc(545);
//	ft_remplis(544, addr);
	free(addr);
	i++;
	}
	show_alloc_mem();
	return(0);
}
