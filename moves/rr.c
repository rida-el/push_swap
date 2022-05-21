#include "../push_swap.h"

void	rr(t_stack *a, t_stack *b, int flag)
{
	ra(a, 0);
	rb(b, 0);
	if(flag)
		ft_putstr_fd("rr\n", 1);
}