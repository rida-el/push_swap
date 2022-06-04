/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_node_bottom.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-maza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:30:21 by rel-maza          #+#    #+#             */
/*   Updated: 2022/06/04 15:30:30 by rel-maza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_node_bottom(t_stack *stack, t_node *elem)
{
	if (!stack_is_empty(stack))
	{
		elem->above = stack->bottom;
		stack->bottom->bellow = elem;
	}
	else
		stack->top = elem;
	stack->bottom = elem;
	stack->size++;
}
