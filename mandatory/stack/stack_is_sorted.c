#include "../push_swap.h"

int	stack_is_sorted(t_stack *stack)
{
	t_node	*node;

	node = stack->top;
	while (node && node->bellow)
	{
		if (node->num > node->bellow->num)
			return (0);
		node = node->bellow;
	}
	return (1);
}