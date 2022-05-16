#include "../push_swap.h"

/* sa: swap a - swap the first 2 elements at the top of stack a. 
 * (do nothing if there is only one or no elements). */
void	sa(t_stack *a)
{
	int	tmp;

	if (stack_is_empty(a) || a->size == 1)
		return ;
	tmp = a->top->num;
	a->top->num = a->top->bellow->num;
	a->top->bellow->num = tmp;
}
