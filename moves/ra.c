#include "../push_swap.h"

void	ra(t_stack *a)
{
	t_node	*node;

	if(stack_is_empty(a) || a->size == 1)
		return ;
	node = new_node(a->top->num);
	push_node_bottom(a, node);
	pop_node_top(a);
}