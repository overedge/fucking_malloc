
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
	while(i<1024)
	{
	addr = (char*)malloc(1024);
	addr[0] = 42;
	i++;
	}
//	show_alloc_mem();
	return(0);
}
