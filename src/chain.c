#include "chain.h"
#include <time.h>
#include "get_next_chain.h"

char    *create_hash()
{
	char	*base;
	char	*ret;
	int		i;
	int		tut;

	base = "0123456789abcdefghij";
	i = strlen(base) + i;
	ret = malloc(20);
	srand(time(NULL));
	while (--i > 0)
	{
		tut = rand() % 20;
		ret[i - 1] = base[tut];
	}
	return (ret);
}
/*
product	*readmainchain(product *mainchain)
{
	int		mainfd;
	char	*chain;

	mainfd = open("chain", O_RDONLY);
	while (1);
	{
		chain = get_next_chain(mainfd);
		if (!chain)
			break;
	}
	close(mainfd);
}
*/
int main()
{
	char	*hash;
	
	hash = malloc(20);
	hash = create_hash();
	printf("%s\n", hash);
	return (0);
}