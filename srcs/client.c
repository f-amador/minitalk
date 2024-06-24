/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruda-si <bruda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:36:44 by framador          #+#    #+#             */
/*   Updated: 2024/05/27 15:05:14 by bruda-si         ###   ########.fr       */
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

static void	ft_sendlen(char *str, pid_t pid)
{
	int	i;
	int	len;

	len = 0;
	i = 31;
	while (*(str++))
		len++;
	while (i >= 0)
	{
		if (len >> i & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
		usleep(100);
	}
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
			usleep(100);
		}
		i++;
	}
	i = 7;
	while (i >= 0)
	{
		kill(pid, SIGUSR2);
		i--;
		usleep(100);
	}
}

static void	ft_sighandler(int sig)
{
	(void)sig;
	write(1, "Message delivered successfully\n", 31);
	exit(0);
}

int	main(int ac, char *av[])
{
	pid_t				pid;
	struct sigaction	sa;

	sa.sa_handler = ft_sighandler;
	sa.sa_flags = 0;
	if (sigaction(SIGUSR1, &sa, NULL) || sigaction(SIGUSR2, &sa, NULL))
	{
		write(1, "closing server...\n", 18);
		exit(0);
	}
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (pid < 1 || !(av[2][0]))
			exit(write(2, "INVALID PID\n", 12));
		ft_sendlen(av[2], pid);
		ft_sendsig(av[2], pid);
		while (1)
		{
		}
	}
	else
		return (write(2, "Error! Use: ./client PID str\n", 29));
}
