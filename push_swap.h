#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include "./libft/libft.h"

typedef struct s_node
{
	int num;
	struct s_node *above;
	struct s_node *bellow;
} t_node;

typedef struct s_stack
{
	t_node *top;
	t_node *bottom;
	int size;
} t_stack;

/* --- INPUT functions --- */
int check_individual_input(char *input);
int check_invalid_input(char **split);
char **parse_input(char **argv);

/* --- CHECK functions ---*/
int stack_is_empty(t_stack *stack);

/* --- MOVES functions --- */
void sa(t_stack *b, int flag);
void sb(t_stack *b, int flag);
void ss(t_stack *a, t_stack *b, int flag);

void pa(t_stack *a, t_stack *b, int flag);
void pb(t_stack *a, t_stack *b, int flag);

void ra(t_stack *a, int flag);
void rb(t_stack *b, int flag);
void rr(t_stack *a, t_stack *b, int flag);

void rra(t_stack *a, int flag);
void rrb(t_stack *b, int flag);
void rrr(t_stack *a, t_stack *b, int flag);

/* --- STACK functions --- */
t_stack *stack_init(void);
t_node *new_node(int data);

void push_node_bottom(t_stack *stack, t_node *elem);
void push_node_top(t_stack *stack, t_node *node);

void pop_node_bottom(t_stack *stack);
void pop_node_top(t_stack *stack);

/* --- Algo functions --- */
void push_swap(t_stack *a, t_stack *b);
int *bubble_sort_array(int *arr, int size);
int *get_sorted_array_from_stack(t_stack *a);
int calculate_stack_size(t_stack *stack);
void print_stack(t_stack *stack);
int get_p1_ind(t_stack *stack, int divisor);
int get_biggest_number_in_stack(t_stack *stack);
int get_index_biggest_number(t_stack *stack, int biggest_num);
int get_optimal_divisor(t_stack *a, t_stack *b);


#endif