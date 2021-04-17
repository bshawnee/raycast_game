#include "../headers/parser.h"
#include <errno.h>

void	error(const char *msg)
{
	ft_putendl_fd((char*)msg, 2);
	exit(errno);
}
