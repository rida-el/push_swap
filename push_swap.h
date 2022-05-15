#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include "./libft/libft.h"

typedef struct s_node {
	int	num;
	struct s_node *above;
	struct s_node *bellow;
} t_node;

typedef struct s_stack {
	t_node	*top;
	t_node *bottom;
	int size;
} t_stack;


/* --- INPUT functions --- */
int 	check_individual_input(char *input);
int		check_invalid_input(char **split);
char	**parse_input(char **argv);


/* --- CHECK fucntions ---*/
int	stack_is_empty(t_stack *stack);


/* --- STACK functions --- */
t_stack	*stack_init(void);
t_node	*new_node(int data);
void	push_node_bottom(t_stack *stack, t_node *elem);
#endif