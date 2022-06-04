/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-maza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 15:35:59 by rel-maza          #+#    #+#             */
/*   Updated: 2022/05/29 15:36:01 by rel-maza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stack *a, int flag)
{
	int	tmp;

	if (stack_is_empty(a) || a->size == 1)
		return ;
	tmp = a->top->num;
	a->top->num = a->top->bellow->num;
	a->top->bellow->num = tmp;
	if (flag)
		ft_putstr_fd("sa\n", 1);
}
