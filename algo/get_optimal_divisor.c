#include "../push_swap.h"

t_stack	*copy_stack(t_stack *stack)
{
	t_node	*tmp_top;
	t_stack	*copy;

	if(!stack)
		return (0);
	copy = stack_init();
	tmp_top = stack->top;
	while(tmp_top)
	{
		push_node_bottom(copy, new_node(tmp_top->num));
		tmp_top = tmp_top->bellow;
	}
	//free(tmp_top);
	return (copy);
}

int	get_optimal_divisor(int *instructions_count)
{
	int	i;
	int	min;
	int	min_instructions;

	i = 0;
	min = 0;
	min_instructions = 2147483647;
	while (i < 7)
	{
		if(instructions_count[i] < min_instructions && instructions_count[i] > 0)
		{
			min_instructions = instructions_count[i];
			min = i + 4;
		}
		i++;
	}
	return (min);
}

int try_all_divisors(t_stack *aaaa, t_stack *bbbb)
{
	int v_p1;
	int v_p2;
	int ind_p1;
	int ind_p2;
	int *arr;
	int pb_count;
	int biggest_num;
	int ind_biggest_num;
	int p_pv2;

	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int optimal_divisor;
	int instructions_count[7];


	optimal_divisor = 3;
	while (++optimal_divisor <= 10)
	{
		tmp_a = copy_stack(aaaa);
		tmp_b = copy_stack(bbbb);

		instructions_count[optimal_divisor - 4] = 0;
		arr = get_sorted_array_from_stack(tmp_a);
		ind_p1 = get_p1_ind(tmp_a, optimal_divisor);
		ind_p2 = ind_p1 / 2;
		v_p1 = arr[ind_p1];
		v_p2 = arr[ind_p2];
		p_pv2 = arr[0];

		pb_count = 0;
		while (tmp_a->size > 1)
		{
			if (tmp_a->top->num <= v_p1)
			{
				pb(tmp_a, tmp_b, 0);
				(instructions_count[optimal_divisor - 4])++;
				pb_count++;
				if (!stack_is_empty(tmp_b) && tmp_b->top->num <= v_p2)
				{
					if(tmp_a->top->num > v_p1)
						rr(tmp_a, tmp_b, 0);
					else
						rb(tmp_b, 0);
					(instructions_count[optimal_divisor - 4])++;
				}

				if (pb_count == ind_p1 + 1)
				{
					arr = get_sorted_array_from_stack(tmp_a);
					if (!arr)
						break;
					ind_p1 = get_p1_ind(tmp_a, optimal_divisor);
					ind_p2 = ind_p1 / 2;
					p_pv2 = v_p1;
					v_p1 = arr[ind_p1];
					v_p2 = arr[ind_p2];
					pb_count = 0;
				}
			}
			else
			{
				if (tmp_a->size == 1)
					break;
				ra(tmp_a, 0);
				(instructions_count[optimal_divisor - 4])++;
			}
		}

		while (!stack_is_empty(tmp_b))
		{
			biggest_num = get_biggest_number_in_stack(tmp_b);
			ind_biggest_num = get_index_biggest_number(tmp_b, biggest_num);
			if (ind_biggest_num == -1)
			{
				ft_putstr_fd("Biggest not found in stack !\n", 1);
				break ;
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
		free(tmp_a);
		free(tmp_b);
	}


	return (get_optimal_divisor(instructions_count));
}