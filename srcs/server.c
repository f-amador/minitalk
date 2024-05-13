#include "../include/minitalk.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd , &c, 1);
}

void	ft_putstr(char *str)
{
	if (!str)
		return ;
	while (*str)
		write(1, str++, 1);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		ft_putnbr(-n);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar_fd(n + '0', 1);
}

void ft_sig_handle(int sig)
{
	int i;
	char c;

	i = 0;
	c = 0;
	printf("%d\n", (sig >> 1 & 1));

}

int main(void)
{
	pid_t	pid;
	struct sigaction sa;

	sa.sa_handler = ft_sig_handle;
	sa.sa_flags = 0;
	pid = getpid();
	ft_putnbr(pid);
	if (sigaction(SIGUSR1, &sa, NULL) || sigaction(SIGUSR2, &sa, NULL))
	{
		printf("closing server...\n");
		exit(0);
	}
	while (1)
	{
		printf("waiting for signal!\n");
		usleep(500000000);
	}
}
