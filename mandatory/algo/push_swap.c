/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-maza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 15:49:42 by rel-maza          #+#    #+#             */
/*   Updated: 2022/05/29 15:49:50 by rel-maza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	calculate_stack_size(t_stack *stack)
{
	int		i;
	t_node	*node;

	i = 1;
	node = stack->top;
	while (node->bellow)
	{
		node = node->bellow;
		i++;
	}
	return (i);
}

void	return_nodes_to_a(t_stack *a, t_stack *b, int flag)
{
	int	biggest_num;
	int	ind_biggest_num;

	while (!stack_is_empty(b))
	{
		biggest_num = get_biggest_number_in_stack(b);
		ind_biggest_num = get_index_biggest_number(b, biggest_num);
		if (ind_biggest_num == -1)
			return ;
		while (b->top->num != get_biggest_number_in_stack(b))
		{
			if (ind_biggest_num >= calculate_stack_size(b) / 2)
				rrb(b, flag);
			else
				rb(b, flag);
		}
		pa(a, b, flag);
	}
}

int	handle_num_less_than_vp1(t_stack *a,
		t_stack *b, t_utils *utils, int *pb_count)
{
	pb(a, b, 1);
	(*pb_count)++;
	if (!stack_is_empty(b) && b->top->num <= utils->v_p2)
	{
		if (a->top->num > utils->v_p1)
			rr(a, b, 1);
		else
			rb(b, 1);
	}
	if (*pb_count == utils->ind_p1 + 1)
	{
		utils->arr = get_sorted_array_from_stack(a, utils->arr);
		if (!utils->arr)
			return (-1);
		utils->ind_p1 = get_p1_ind(a, try_all_divisors(a, b));
		utils->ind_p2 = utils->ind_p1 / 2;
		utils->v_p1 = utils->arr[utils->ind_p1];
		utils->v_p2 = utils->arr[utils->ind_p2];
		*pb_count = 0;
	}
	return (0);
}

void	send_nodes_to_b(t_stack *a, t_stack *b, t_utils *utils)
{
	int	pb_count;

	pb_count = 0;
	while (a->size > 1)
	{
		if (a->top->num <= utils->v_p1)
		{
			if (handle_num_less_than_vp1(a, b, utils, &pb_count) == -1)
				break ;
		}
		else
		{
			if (a->size == 1)
				break ;
			ra(a, 1);
		}
	}
}

void	push_swap(t_stack *a, t_stack *b)
{
	t_utils	*utils;

	if (a->size <= 5)
	{
		sort_5(a, b);
		return ;
	}
	utils = malloc(sizeof(t_utils));
	if (!utils)
		return ;
	utils->arr = malloc(sizeof(int) * 1);
	utils->arr = get_sorted_array_from_stack(a, utils->arr);
	if (!utils->arr)
		return ;
	utils->ind_p1 = get_p1_ind(a, try_all_divisors(a, b));
	utils->ind_p2 = utils->ind_p1 / 2;
	utils->v_p1 = utils->arr[utils->ind_p1];
	utils->v_p2 = utils->arr[utils->ind_p2];
	send_nodes_to_b(a, b, utils);
	return_nodes_to_a(a, b, 1);
	free_utils(utils);
}
