#include "../push_swap.h"

void	pb(t_stack *a, t_stack *b)
{
	t_node	*node;

	if(stack_is_empty(a))
		return ;
	node = new_node(a->top->num);
	push_node_top(b, node);
	pop_node_top(a);
}