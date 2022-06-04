/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-maza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 15:34:36 by rel-maza          #+#    #+#             */
/*   Updated: 2022/05/29 15:34:48 by rel-maza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pb(t_stack *a, t_stack *b, int flag)
{
	t_node	*node;

	if (stack_is_empty(a))
		return ;
	node = new_node(a->top->num);
	push_node_top(b, node);
	pop_node_top(a);
	if (flag)
		ft_putstr_fd("pb\n", 1);
}
