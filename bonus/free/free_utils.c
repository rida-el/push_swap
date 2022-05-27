#include "../push_swap.h"

void	free_utils(t_utils *utils)
{
	free(utils->arr);
	free(utils);
}
