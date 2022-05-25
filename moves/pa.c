#include "../push_swap.h"

void	pa(t_stack *a, t_stack *b, int flag)
{
	t_node	*node;

	if (stack_is_empty(b))
		return ;
	node = new_node(b->top->num);
	push_node_top(a, node);
	pop_node_top(b);
	if (flag)
		ft_putstr_fd("pa\n", 1);
}
