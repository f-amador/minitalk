/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framador <framador@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:42:22 by framador          #+#    #+#             */
/*   Updated: 2024/05/15 17:59:23 by framador         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static int	g_bits;

void	ft_receivelen(int *len, int sig)
{
	*len = (*len << 1) + (sig >> 1 & 1);
}

void	ft_resetstr(char *str, int *len, int *j, pid_t pid)
{
	g_bits = 0;
	*len = 0;
	*j = 0;
	ft_putstr(str);
	free(str);
	kill(pid, SIGUSR1);
}

static void	ft_allocstr(char **str, int len)
{
	*str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		exit (1);
	(*str)[len] = 0;
}

static void	ft_sig_handle(int sig, siginfo_t *info, void *context)
{
	static int	i;
	static int	j;
	static int	len;
	static char	c;
	static char	*str;

	(void)context;
	if (g_bits++ < 32)
		ft_receivelen(&len, sig);
	else
	{
		if (g_bits == 33)
			ft_allocstr(&str, len);
		i++;
		c = (c << 1) + (sig >> 1 & 1);
		if (i == 8)
		{
			str[j++] = c;
			if (!c)
				ft_resetstr(str, &len, &j, info->si_pid);
			c = 0;
			i = 0;
		}
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	sa.sa_sigaction = ft_sig_handle;
	sa.sa_flags = SA_SIGINFO;
	pid = getpid();
	ft_putnbr(pid);
	write(1, "\n", 1);
	if (sigaction(SIGUSR1, &sa, NULL) || sigaction(SIGUSR2, &sa, NULL))
	{
		ft_putstr("closing server...\n");
		exit(0);
	}
	while (1)
	{
	}
}
