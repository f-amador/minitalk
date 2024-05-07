#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void ft_sig_handle(int sig)
{
	printf("%d\n", (sig >> 1 & 1));

}

int main(void)
{
	pid_t	pid;
	struct sigaction sa;

	sa.sa_handler = ft_sig_handle;
	sa.sa_flags = 0;
	pid = getpid();
	printf("%d\n", pid);
	if (sigaction(SIGUSR1, &sa, NULL) || sigaction(SIGUSR2, &sa, NULL))
	{
		printf("closing server...\n");
		exit (0);
	}
	while (1)
	{
		printf("waiting for signal!\n");
		usleep(500000000);
	}
}
