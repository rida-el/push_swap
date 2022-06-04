/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_node_bottom.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-maza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 15:37:22 by rel-maza          #+#    #+#             */
/*   Updated: 2022/05/29 15:37:23 by rel-maza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pop_node_bottom(t_stack *stack)
{
	t_node	*tmp;

	if (stack_is_empty(stack))
		return ;
	tmp = stack->bottom;
	stack->bottom = stack->bottom->above;
	if (stack->size == 1)
	{
		stack->top = NULL;
		stack->bottom = NULL;
	}
	else
		stack->bottom->bellow = NULL;
	stack->size--;
	free(tmp);
}
