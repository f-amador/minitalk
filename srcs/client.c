#include "../include/minitalk.h"

int	ft_atoi(char *str)
{
	long	res;
	int	i;

	res = 0;
	i = 0;
	if (!(str[i] >= '0' && str[i] <= '9'))
		exit(write(2, "Wrong pid", 9));
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		if (res > INT_MAX)
			exit(write(2, "Wrong pid", 9));
		i++;
	}
	return (res);
}

void	ft_senddig(char *str, pid_t pid)
{
	int	i;
	int	j;
	while (str[i])
	{
		j = 0;
		while (j < 8)
		{
			if(str[i] >> j & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			j++;
		}
	}

	i = 0;
}

int	main(int ac, char *av[])
{
	if (ac == 3)
	{
	
	}
}
