#include "../push_swap.h"

void	ss(t_stack *a, t_stack *b, int flag)
{
	sa(a, 0);
	sb(b, 0);
	if (flag)
		ft_putstr_fd("ss\n", 1);
}
