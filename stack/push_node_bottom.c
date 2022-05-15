#include "../push_swap.h"

void	push_node_bottom(t_stack *stack, t_node *elem)
{
	if (!stack_is_empty(stack))
	{
		elem->above = stack->bottom;
		stack->bottom->bellow = elem;
	}
	else
		stack->top = elem;
	stack->bottom = elem;
	stack->size++;
}
