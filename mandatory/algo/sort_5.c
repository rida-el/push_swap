/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-maza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 15:50:36 by rel-maza          #+#    #+#             */
/*   Updated: 2022/05/29 15:50:38 by rel-maza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	do_moves_sort_5(t_stack *a, t_stack *b, int stack_max, int stack_min)
{
	int	pushed_already;

	pushed_already = 0;
	while (1)
	{
		if (a->top->num == stack_min || a->top->num == stack_max)
		{
			pb(a, b, 1);
			pushed_already++;
			if (pushed_already == 2)
				break ;
		}
		else
			ra(a, 1);
	}
	sort_3(a);
	while (!stack_is_empty(b))
	{
		pa(a, b, 1);
		if (a->top->num > a->top->bellow->num)
			ra(a, 1);
	}
}

void	sort_5(t_stack *a, t_stack *b)
{
	int		stack_min;
	int		stack_max;
	t_node	*tmp;

	if (a->size <= 3)
	{
		sort_3(a);
		return ;
	}
	stack_min = 2147483647;
	stack_max = -2147483648;
	tmp = a->top;
	while (tmp)
	{
		if (tmp->num > stack_max)
			stack_max = tmp->num;
		if (tmp->num < stack_min)
			stack_min = tmp->num;
		tmp = tmp->bellow;
	}
	do_moves_sort_5(a, b, stack_max, stack_min);
}
