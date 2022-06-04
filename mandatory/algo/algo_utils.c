/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-maza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 15:49:12 by rel-maza          #+#    #+#             */
/*   Updated: 2022/05/29 15:49:16 by rel-maza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*bubble_sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (arr);
}

int	*get_sorted_array_from_stack(t_stack *a, int *prev_arr)
{
	int		i;
	int		*tmp;
	t_node	*head;

	tmp = prev_arr;
	if (a->size == 0)
		return (0);
	prev_arr = ft_calloc(sizeof(int), a->size);
	i = 0;
	head = a->top;
	while (head)
	{
		prev_arr[i] = head->num;
		head = head->bellow;
		i++;
	}
	prev_arr = bubble_sort_array(prev_arr, a->size);
	free(tmp);
	return (prev_arr);
}

int	get_p1_ind(t_stack *stack, int divisor)
{
	int	p1_ind;
	int	size;

	size = calculate_stack_size(stack);
	if (size <= 110)
		p1_ind = size / 3;
	else if (size <= 190)
		p1_ind = size / 4;
	else if (size <= 300)
		p1_ind = size / 5;
	else if (size <= 430)
		p1_ind = size / 6;
	else
		p1_ind = size / divisor;
	return (p1_ind);
}

int	get_biggest_number_in_stack(t_stack *stack)
{
	int		current;
	t_node	*node;

	node = stack->top;
	current = node->num;
	while (node)
	{
		if (node->num > current)
			current = node->num;
		node = node->bellow;
	}
	return (current);
}

int	get_index_biggest_number(t_stack *stack, int biggest_num)
{
	int		i;
	t_node	*node;

	i = 0;
	node = stack->top;
	while (node)
	{
		if (node->num == biggest_num)
			return (i);
		node = node->bellow;
		i++;
	}
	return (-1);
}
