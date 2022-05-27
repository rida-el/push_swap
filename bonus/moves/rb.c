#include "../push_swap.h"

void	rb(t_stack *b, int flag)
{
	t_node	*node;

	if (stack_is_empty(b) || b->size == 1)
		return ;
	node = new_node(b->top->num);
	push_node_bottom(b, node);
	pop_node_top(b);
	if (flag)
		ft_putstr_fd("rb\n", 1);
}