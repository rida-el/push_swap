#include "../push_swap.h"

void	exit_error(int status)
{
	write(2, "ERROR\n", 6);
	exit(status);
}
