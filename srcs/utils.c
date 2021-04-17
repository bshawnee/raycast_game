#include "../headers/main.h"

void	error(const char *msg)
{
	printf("%s\n", msg);
	exit(errno);
}
