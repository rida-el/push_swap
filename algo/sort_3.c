#include "../push_swap.h"

void	sort_3(t_stack *a)
{	
	sort_2(a);
	if (a->bottom->num < a->top->num)
		rra(a, 1);
	else if (a->top->bellow->num > a->bottom->num)
	{
		rra(a, 1);
		sa(a, 1);
	}
}
