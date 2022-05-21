#include "../push_swap.h"

void	rrr(t_stack *a, t_stack *b, int flag)
{
	rra(a, 0);
	rrb(b, 0);
	if(flag)
		ft_putstr_fd("rrr\n", 1);
}