/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_node_top.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-maza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:31:09 by rel-maza          #+#    #+#             */
/*   Updated: 2022/06/04 15:31:10 by rel-maza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_node_top(t_stack *stack, t_node *node)
{
	if (!stack_is_empty(stack))
	{
		node->bellow = stack->top;
		stack->top->above = node;
	}
	else
	{
		stack->bottom = node;
	}
	stack->top = node;
	stack->size++;
}
