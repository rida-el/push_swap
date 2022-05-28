#include "../push_swap.h"

void	exec_one_instruction(t_stack *a, t_stack *b, char *instruction)
{
	// printf("%s", instruction);
		if (ft_strcmp(instruction, "pa\n") == 0)
			pa(a, b, 0);
		else if (ft_strcmp(instruction, "pb\n") == 0)
			pb(a, b, 0);
		else if (ft_strcmp(instruction, "ra\n") == 0)
			ra(a, 0);
		else if (ft_strcmp(instruction, "rb\n") == 0)
			rb(b, 0);
		else if (ft_strcmp(instruction, "rr\n") == 0)
			rr(a, b, 0);
		else if (ft_strcmp(instruction, "rra\n") == 0)
			rra(a, 0);
		else if (ft_strcmp(instruction, "rrb\n") == 0)
			rrb(b, 0);
		else if (ft_strcmp(instruction, "rrr\n") == 0)
			rrr(a, b, 0);
		else if (ft_strcmp(instruction, "sa\n") == 0)
			sa(a, 0);
		else if (ft_strcmp(instruction, "sb\n") == 0)
			sb(b, 0);
		else if (ft_strcmp(instruction, "ss\n") == 0)
			ss(a, b, 0);
		else
			exit_error(1);
}

void	execute_instructions(t_stack *a, t_stack *b)
{
	char	*instruction;

	instruction = get_next_line(0);
	while (instruction)
	{
		exec_one_instruction(a, b, instruction);
		instruction = get_next_line(0);
	}
}


int	main(int argc, char **argv)
{
	int		i;
	char	**split;
	t_node	*elm;
	t_stack	*a;
	t_stack	*b;

	i = 0;
	(void)argc;
	split = parse_input(argv);
	a = stack_init();
	b = stack_init();
	while (split[i])
	{
		elm = new_node(ft_atoi(split[i]));
		push_node_bottom(a, elm);
		free(split[i]);
		i++;
	}
	print_stack(a);
	execute_instructions(a, b);
	if (stack_is_sorted(a) && stack_is_empty(b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	
	print_stack(a);

	free_stack(a);
	free_stack(b);
}
