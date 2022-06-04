/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_node_top.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-maza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:29:18 by rel-maza          #+#    #+#             */
/*   Updated: 2022/06/04 15:29:51 by rel-maza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
