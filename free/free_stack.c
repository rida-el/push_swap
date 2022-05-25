#include "../push_swap.h"

void	free_stack(t_stack *stack)
{
	t_node	*tmp;

	while (stack->top)
	{
		tmp = stack->top;
		stack->top = stack->top->bellow;
		free(tmp);
	}
	free(stack);
}
