#include "../push_swap.h"

void	pop_node_top(t_stack *stack)
{
	t_node	*tmp;

	if (stack_is_empty(stack))
		return ;
	tmp = stack->top;
	stack->top = stack->top->bellow;
	if (stack->size == 1)
	{
		stack->top = NULL;
		stack->bottom = NULL;
	}
	else
		stack->top->above = NULL;
	stack->size--;
	free(tmp);
}
