/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-maza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:26:00 by rel-maza          #+#    #+#             */
/*   Updated: 2022/06/04 15:26:03 by rel-maza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rrb(t_stack *b, int flag)
{
	t_node	*node;

	if (stack_is_empty(b) || b->size == 1)
		return ;
	node = new_node(b->bottom->num);
	push_node_top(b, node);
	pop_node_bottom(b);
	if (flag)
		ft_putstr_fd("rrb\n", 1);
}
