#include "../push_swap.h"

void	print_stack(t_stack *stack)
{
	t_node	*node;

	if (stack_is_empty(stack))
		return ;
	node = stack->top;
	while (node->bellow)
	{
		ft_putnbr_fd(node->num, 1);
		ft_putstr_fd(" | ", 1);
		node = node->bellow;
	}
	ft_putnbr_fd(node->num, 1);
	ft_putchar_fd('\n', 1);
}