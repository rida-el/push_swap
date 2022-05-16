#include "../push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	if(stack_is_empty(b))
		return ;
	push_node_top(a, b->top);
	pop_node_top(b);
}