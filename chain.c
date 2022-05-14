#include "chain.h"
#include <time.h>

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

int main()
{
	printf("%s", create_hash());
}