#include "../push_swap.h"

/* a funciton to check if stack empty or not */
int	stack_is_empty(t_stack *stack)
{
	return (stack->top == NULL && stack->bottom == NULL);
}
