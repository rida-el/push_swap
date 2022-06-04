/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-maza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:25:01 by rel-maza          #+#    #+#             */
/*   Updated: 2022/06/04 15:25:11 by rel-maza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rb(t_stack *b, int flag)
{
	t_node	*node;

	if (stack_is_empty(b) || b->size == 1)
		return ;
	node = new_node(b->top->num);
	push_node_bottom(b, node);
	pop_node_top(b);
	if (flag)
		ft_putstr_fd("rb\n", 1);
}
