/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_is_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-maza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:31:35 by rel-maza          #+#    #+#             */
/*   Updated: 2022/06/04 15:31:50 by rel-maza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	stack_is_sorted(t_stack *stack)
{
	t_node	*node;

	node = stack->top;
	while (node && node->bellow)
	{
		if (node->num > node->bellow->num)
			return (0);
		node = node->bellow;
	}
	return (1);
}
