#include "../push_swap.h"

t_stack *copy_stack(t_stack *stack)
{
	t_node *tmp_top;
	t_stack *copy;

	if (!stack)
		return (0);
	copy = stack_init();
	tmp_top = stack->top;
	while (tmp_top)
	{
		push_node_bottom(copy, new_node(tmp_top->num));
		tmp_top = tmp_top->bellow;
	}
	// free(tmp_top);
	return (copy);
}

int get_optimal_divisor(int *instructions_count)
{
	int i;
	int min;
	int min_instructions;

	i = 0;
	min = 0;
	min_instructions = 2147483647;
	while (i < 7)
	{
		if (instructions_count[i] < min_instructions && instructions_count[i] > 0)
		{
			min_instructions = instructions_count[i];
			min = i + 4;
		}
		i++;
	}
	return (min);
}

void reset_utils(t_utils *utils, t_stack *tmp_a, int optimal_divisor)
{
	if (!utils)

		if (!utils)
			return;
	utils->arr = get_sorted_array_from_stack(tmp_a);
	if (!utils->arr)
		return;
	utils->ind_p1 = get_p1_ind(tmp_a, optimal_divisor);
	utils->ind_p2 = utils->ind_p1 / 2;
	utils->v_p1 = utils->arr[utils->ind_p1];
	utils->v_p2 = utils->arr[utils->ind_p2];
}

void push_back_to_tmp_a(t_stack *tmp_a, t_stack *tmp_b, int *instructions_count, int optimal_divisor)
{
	int biggest_num;
	int ind_biggest_num;

	while (!stack_is_empty(tmp_b))
	{
		biggest_num = get_biggest_number_in_stack(tmp_b);
		ind_biggest_num = get_index_biggest_number(tmp_b, biggest_num);
		if (ind_biggest_num == -1)
		{
			ft_putstr_fd("Biggest not found in stack !\n", 1);
			break;
		}
		while (tmp_b->top->num != get_biggest_number_in_stack(tmp_b))
		{
			if (ind_biggest_num >= calculate_stack_size(tmp_b) / 2)
				rrb(tmp_b, 0);
			else
				rb(tmp_b, 0);
			(instructions_count[optimal_divisor - 4])++;
		}
		pa(tmp_a, tmp_b, 0);
		(instructions_count[optimal_divisor - 4])++;
	}
}

void test(t_stack *tmp_a, t_stack *tmp_b, t_divisor *div, t_utils *utils)
{
	pb(tmp_a, tmp_b, 0);
	(div->instructions_count[div->optimal_divisor - 4])++;
	utils->pb_count++;
	if (!stack_is_empty(tmp_b) && tmp_b->top->num <= utils->v_p2)
	{
		if (tmp_a->top->num > utils->v_p1)
			rr(tmp_a, tmp_b, 0);
		else
			rb(tmp_b, 0);
		(div->instructions_count[div->optimal_divisor - 4])++;
	}
	if (utils->pb_count == utils->ind_p1 + 1)
	{
		reset_utils(utils, tmp_a, div->optimal_divisor);
		utils->pb_count = 0;
	}
}

void some_func(t_stack *tmp_a, t_stack *tmp_b, t_divisor *div, t_utils *utils)
{
	// int pb_count;

	utils->pb_count = 0;
	while (tmp_a->size > 1)
	{
		if (tmp_a->top->num <= utils->v_p1)
		{
			test(tmp_a, tmp_b, div, utils);
		}
		else
		{
			if (tmp_a->size == 1)
				break;
			ra(tmp_a, 0);
			(div->instructions_count[div->optimal_divisor - 4])++;
		}
	}
}

int try_all_divisors(t_stack *aaaa, t_stack *bbbb)
{

	t_utils *utils;
	t_stack *tmp_a;
	t_stack *tmp_b;
	t_divisor *div;

	div = malloc(sizeof(t_divisor));
	utils = malloc(sizeof(t_utils));
	if (!utils || !div)
		return (0);
	div->optimal_divisor = 3;
	while (++(div->optimal_divisor) <= 10)
	{
		tmp_a = copy_stack(aaaa);
		tmp_b = copy_stack(bbbb);
		div->instructions_count[div->optimal_divisor - 4] = 0;
		reset_utils(utils, tmp_a, div->optimal_divisor);
		some_func(tmp_a, tmp_b, div, utils);
		push_back_to_tmp_a(tmp_a, tmp_b, div->instructions_count, div->optimal_divisor);
		free(tmp_a);
		free(tmp_b);
	}
	return (get_optimal_divisor(div->instructions_count));
}