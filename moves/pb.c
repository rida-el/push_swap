#include "../push_swap.h"

void	pb(t_stack *a, t_stack *b)
{
	if(stack_is_empty(a))
		return ;
	push_node_top(b, a->top);
	pop_node_top(a);
}