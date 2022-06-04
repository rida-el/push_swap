/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divisor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-maza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 15:49:22 by rel-maza          #+#    #+#             */
/*   Updated: 2022/05/29 15:49:23 by rel-maza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*copy_stack(t_stack *stack)
{
	t_node	*tmp_top;
	t_stack	*copy;

	if (!stack)
		return (0);
	copy = stack_init();
	tmp_top = stack->top;
	while (tmp_top)
	{
		push_node_bottom(copy, new_node(tmp_top->num));
		tmp_top = tmp_top->bellow;
	}
	return (copy);
}

int	get_optimal_divisor(t_divisor *div)
{
	int	i;
	int	min;
	int	min_instructions;

	i = 0;
	min = 0;
	min_instructions = 2147483647;
	while (i < 7)
	{
		if (div->instructions_count[i] < min_instructions
			&& div->instructions_count[i] > 0)
		{
			min_instructions = div->instructions_count[i];
			min = i + 4;
		}
		i++;
	}
	free(div);
	return (min);
}
