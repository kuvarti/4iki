#include "signal.h"
#include "stdio.h"

unsigned char	g_gelen = 0;

void	birsinyal(int sig, siginfo_t *si, void *undelete)
{
	static int	bit = 0;

	if (bit == 0)
		g_gelen = 0;
	g_gelen <<= 1;
	if (sig == SIGUSR2)
		g_gelen += 1;
	bit++;
	if (bit == 8)
	{
		printf("%c", g_gelen);
		bit = 0;
		kill(si->si_pid, SIGUSR1);
		undelete = "error verme";
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	sg;

	pid = getpid();
	sg.sa_flags = SA_SIGINFO;
	sg.sa_sigaction = birsinyal;
	sigaction(SIGUSR1, &sg, NULL);
	sigaction(SIGUSR2, &sg, NULL);
	printf("pid : %d\n", pid);
	while (1)
		;
}
