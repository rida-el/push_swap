#include "../push_swap.h"

void	rra(t_stack *a)
{
	t_node	*node;

	if(stack_is_empty(a) || a->size == 1)
		return ;
	node = new_node(a->bottom->num);
	push_node_top(a, node);
	pop_node_bottom(a);
}