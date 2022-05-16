#include "../push_swap.h"

/* sb: swap b - swap the first 2 elements at the top of stack b. 
 * (do nothing if there is only one or no elements). */
void	sb(t_stack *b)
{
	int	tmp;

	if (stack_is_empty(b) || b->size == 1)
		return ;
	tmp = b->top->num;
	b->top->num = b->top->bellow->num;
	b->top->bellow->num = tmp;
}