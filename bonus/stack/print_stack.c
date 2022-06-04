/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-maza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:30:06 by rel-maza          #+#    #+#             */
/*   Updated: 2022/06/04 15:30:08 by rel-maza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_stack(t_stack *stack)
{
	t_node	*node;

	if (stack_is_empty(stack))
		return ;
	node = stack->top;
	while (node->bellow)
	{
		ft_putnbr_fd(node->num, 1);
		ft_putstr_fd(" | ", 1);
		node = node->bellow;
	}
	ft_putnbr_fd(node->num, 1);
	ft_putchar_fd('\n', 1);
}
