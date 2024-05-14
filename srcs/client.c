#include "../include/minitalk.h"

int	ft_atoi(char *str)
{
	long	res;
	int	i;

	res = 0;
	i = 0;
	if (!(str[i] >= '0' && str[i] <= '9'))
		exit(write(2, "INVALID PID", 11));
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		if (res > INT_MAX)
			exit(write(2, "INVALID PID", 11));
		i++;
	}
	return (res);
}

void	ft_sendsig(char *str, pid_t pid)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 7;
		while (j >= 0)
		{
			if(str[i] >> j & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			j--;
			usleep(300);
		}
		i++;
	}
}

int	main(int ac, char *av[])
{
	pid_t	pid;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		ft_sendsig(av[2], pid);
	}
}
