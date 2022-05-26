#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef struct s_node
{
	int				num;
	struct s_node	*above;
	struct s_node	*bellow;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
}	t_stack;

typedef struct s_utils
{
	int	v_p1;
	int	v_p2;
	int	ind_p1;
	int	ind_p2;
	int	*arr;
	int	pb_count;
}	t_utils;

typedef struct s_divisor
{
	int	instructions_count[7];
	int	optimal_divisor;
}	t_divisor;

int		is_valid_individual_input(char *input);
int		is_invalid_input(char **split);
char	**parse_input(char **argv);

int		stack_is_empty(t_stack *stack);

void	sa(t_stack *b, int flag);
void	sb(t_stack *b, int flag);
void	ss(t_stack *a, t_stack *b, int flag);

void	pa(t_stack *a, t_stack *b, int flag);
void	pb(t_stack *a, t_stack *b, int flag);

void	ra(t_stack *a, int flag);
void	rb(t_stack *b, int flag);
void	rr(t_stack *a, t_stack *b, int flag);

void	rra(t_stack *a, int flag);
void	rrb(t_stack *b, int flag);
void	rrr(t_stack *a, t_stack *b, int flag);

t_stack	*stack_init(void);
t_node	*new_node(int data);

void	push_node_bottom(t_stack *stack, t_node *elem);
void	push_node_top(t_stack *stack, t_node *node);

void	pop_node_bottom(t_stack *stack);
void	pop_node_top(t_stack *stack);

void	free_stack(t_stack *stack);
void	free_split(char **split);
void	free_utils(t_utils *utils);

void	push_swap(t_stack *a, t_stack *b);
int		*bubble_sort_array(int *arr, int size);
int		*get_sorted_array_from_stack(t_stack *a, int *prev_arr);
int		calculate_stack_size(t_stack *stack);
int		get_p1_ind(t_stack *stack, int divisor);
int		get_biggest_number_in_stack(t_stack *stack);
int		get_index_biggest_number(t_stack *stack, int biggest_num);
void	send_nodes_to_b(t_stack *a, t_stack *b, t_utils *utils);
int		handle_num_less_than_vp1(t_stack *a,
			t_stack *b, t_utils *utils, int *pb_count);
void	return_nodes_to_a(t_stack *a, t_stack *b, int flag);

t_stack	*copy_stack(t_stack *stack);
int		try_all_divisors(t_stack *a, t_stack *b);
int		get_optimal_divisor(t_divisor *div);
void	reset_utils(t_utils *utils, t_stack *tmp_a, int optimal_divisor);
void	push_back_to_tmp_a(t_stack *tmp_a,
			t_stack *tmp_b, int *instructions_count, int optimal_divisor);
void	test(t_stack *tmp_a, t_stack *tmp_b, t_divisor *div, t_utils *utils);
void	some_func(t_stack *tmp_a, t_stack *tmp_b,
			t_divisor *div, t_utils *utils);

void	sort_5(t_stack *a, t_stack *b);
void	do_moves_sort_5(t_stack *a, t_stack *b, int stack_max, int stack_min);
void	sort_3(t_stack *a);
void	sort_2(t_stack *a);

#endif
