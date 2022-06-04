/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-maza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:23:20 by rel-maza          #+#    #+#             */
/*   Updated: 2022/06/04 15:23:24 by rel-maza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_stack *a, t_stack *b, int flag)
{
	t_node	*node;

	if (stack_is_empty(b))
		return ;
	node = new_node(b->top->num);
	push_node_top(a, node);
	pop_node_top(b);
	if (flag)
		ft_putstr_fd("pa\n", 1);
}
