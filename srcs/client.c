/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framador <framador@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:36:44 by framador          #+#    #+#             */
/*   Updated: 2024/05/15 18:08:47 by framador         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static int	ft_atoi(char *str)
{
	int		i;
	long	res;

	res = 0;
	i = 0;
	if (!(str[i] > '0' && str[i] <= '9'))
		return (-1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		if (res > INT_MAX)
			return (-1);
		i++;
	}
	if (str[i])
		exit(write(2, "INVALID PID\n", 12));
	return (res);
}

static void	ft_sendsig(char *str, pid_t pid)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 7;
		while (j >= 0)
		{
			if (str[i] >> j & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			j--;
			usleep(50);
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
		if (pid < 1)
			exit(write(2, "INVALID PID\n", 12));
		ft_sendsig(av[2], pid);
	}
	else
		return (write(2, "Error! Use: ./client PID str\n", 29));
}
