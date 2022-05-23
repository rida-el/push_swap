#include "../push_swap.h"

int *bubble_sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while(i < size - 1)
	{
		j = i + 1;
		while(j < size)
		{
			if(arr[i] > arr[j])
				{
					tmp = arr[i];
					arr[i] = arr[j];
					arr[j] = tmp;
				}
			j++;
		}
		i++;
	}
	return arr;
}

int	*get_sorted_array_from_stack(t_stack *a)
{
	int		i;
	int		*arr;
	t_node	*head;

	if(a->size == 0)
		return (0);
	arr = ft_calloc(sizeof(int), a->size);
	i = 0;
	head = a->top;
	while(head){
		arr[i] = head->num;
		head = head->bellow;
		i++;
	}
	arr = bubble_sort_array(arr, a->size);

	return (arr);
}

int	calculate_stack_size(t_stack *stack)
{
	int		i;
	t_node	*node;

	i = 1;
	node = stack->top;
	while(node->bellow)
	{
		node = node->bellow;
		i++;
	}
	return (i);
}

void	print_stack(t_stack *stack)
{
	t_node	*node;

	if(stack_is_empty(stack))
		return ;

	node = stack->top;
	while(node->bellow)
	{
		ft_putnbr_fd(node->num, 1);
		ft_putstr_fd(" | ", 1);
		node = node->bellow;
	}
	ft_putnbr_fd(node->num, 1);
	ft_putchar_fd('\n', 1);
}

int		get_p1_ind(t_stack *stack, int divisor)
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
	while(node)
	{
		if(node->num > current)
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
	while(node)
	{
		if(node->num == biggest_num)
			return(i);
		node = node->bellow;
		i++;
	}
	return (-1);
}

void	return_nodes_to_a(t_stack *a, t_stack *b, int flag)
{
	int	biggest_num;
	int	ind_biggest_num;
	
	while(!stack_is_empty(b))
	{
		biggest_num = get_biggest_number_in_stack(b);
		ind_biggest_num = get_index_biggest_number(b, biggest_num);
		if(ind_biggest_num == -1)
			return ;
		while(b->top->num != get_biggest_number_in_stack(b))
		{
			if(ind_biggest_num >= calculate_stack_size(b) / 2)
				rrb(b, flag);
			else
				rb(b, flag);
		}
		pa(a, b, flag);
	}
}


int	handle_num_less_than_vp1(t_stack *a, t_stack *b, t_utils *utils, int *pb_count)
{
	pb(a, b, 1);
	(*pb_count)++;
	if( !stack_is_empty(b) && b->top->num <= utils->v_p2)
	{
		if(a->top->num > utils->v_p1)
			rr(a, b, 1);
		else
			rb(b, 1);
	}
	if(*pb_count == utils->ind_p1 + 1)
	{
		// FREEING
		// FREE the previous pointer utils->arr was on !
		utils->arr = get_sorted_array_from_stack(a);
		if(!utils->arr)
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
	while(a->size > 1)
	{
		if(a->top->num <= utils->v_p1){
			if(handle_num_less_than_vp1(a, b, utils, &pb_count) == -1)
				break ;
		}
		else
		{
			if(a->size == 1)
				break ;
			ra(a, 1);
		}
	}
}


void	push_swap(t_stack *a, t_stack *b)
{
	t_utils *utils;

	utils = malloc(sizeof(t_utils));
	if (!utils)
		return ;
	utils->arr = get_sorted_array_from_stack(a);
	if(!utils->arr)
		return ;
	utils->ind_p1 = get_p1_ind(a, try_all_divisors(a, b));	
	utils->ind_p2 = utils->ind_p1 / 2;
	utils->v_p1 = utils->arr[utils->ind_p1];
	utils->v_p2 = utils->arr[utils->ind_p2];
	send_nodes_to_b(a, b, utils);
	return_nodes_to_a(a, b, 1);
	// FREEING
	// free(utils);// free utils->arr
	free_utils(utils);
}