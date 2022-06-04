/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-maza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:26:51 by rel-maza          #+#    #+#             */
/*   Updated: 2022/06/04 15:26:52 by rel-maza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sb(t_stack *b, int flag)
{
	int	tmp;

	if (stack_is_empty(b) || b->size == 1)
		return ;
	tmp = b->top->num;
	b->top->num = b->top->bellow->num;
	b->top->bellow->num = tmp;
	if (flag)
		ft_putstr_fd("sb\n", 1);
}
