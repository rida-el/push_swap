#include "../push_swap.h"

void	exec_one_instruction(t_stack *a, t_stack *b, char *instruction)
{
		if (ft_strncmp(instruction, "pa", 2) == 0)
			pa(a, b, 0);
		if (ft_strncmp(instruction, "pb", 2) == 0)
			pb(a, b, 0);
		if (ft_strncmp(instruction, "ra", 2) == 0)
			ra(a, 0);
		if (ft_strncmp(instruction, "rb", 2) == 0)
			rb(b, 0);
		if (ft_strncmp(instruction, "rr", 2) == 0)
			rr(a, b, 0);
		if (ft_strncmp(instruction, "rra", 3) == 0)
			rra(a, 0);
		if (ft_strncmp(instruction, "rrb", 3) == 0)
			rrb(b, 0);
		if (ft_strncmp(instruction, "rrr", 3) == 0)
			rrr(a, b, 0);
		if (ft_strncmp(instruction, "sa", 2) == 0)
			sa(a, 0);
		if (ft_strncmp(instruction, "sb", 2) == 0)
			sb(b, 0);
		if (ft_strncmp(instruction, "ss", 2) == 0)
			ss(a, b, 0);
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
	execute_instructions(a, b);
	if (stack_is_sorted(a) && stack_is_empty(b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(a);
	free_stack(b);
}
