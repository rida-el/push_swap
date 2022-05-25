#include "../push_swap.h"

void	push_node_top(t_stack *stack, t_node *node)
{
	if (!stack_is_empty(stack))
	{
		node->bellow = stack->top;
		stack->top->above = node;
	}
	else
	{
		stack->bottom = node;
	}
	stack->top = node;
	stack->size++;
}
