#include "../push_swap.h"

void	sb(t_stack *b, int flag)
{
	int	tmp;

	if (stack_is_empty(b) || b->size == 1)
		return ;
	tmp = b->top->num;
	b->top->num = b->top->bellow->num;
	b->top->bellow->num = tmp;
	if (flag)
		ft_putstr_fd("sb\n", 1);
}
