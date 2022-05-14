#include "signal.h"
#include "stdio.h"
#include "string.h"

unsigned char	g_gelen = 0;
char	*msaj;

char	*stradd(char *s1, char s2)
{
	unsigned int	i;
	unsigned int	j;
	char			*s3;

	if (!s1)
	{
		s1 = malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	s3 = malloc(ft_strlen(s1) + 2);
	if (!s3)
		return (NULL);
	i = -1;
	while (s1[++i] != 0)
		s3[i] = s1[i];
	s3[i++] = s2;
	s3[i] = 0;
	free(s1);
	return (s3);
}

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
		bit = 0;
		msaj = stradd(msaj, g_gelen);
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
