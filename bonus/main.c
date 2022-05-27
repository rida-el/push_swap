#include "../push_swap.h"

int	is_valid_individual_input(char *input)
{
	int		i;
	long	num;

	i = 1;
	if (!(ft_isdigit(input[0]) || input[0] == '+' || input[0] == '-' ))
		return (0);
	while (input[i])
	{
		if (!ft_isdigit(input[i]))
			return (0);
		i++;
	}
	if (i > 11)
		return (0);
	num = ft_atoi_long(input);
	if (num > 2147483647 || num < -2147483648)
		return (0);
	return (1);
}

int	is_invalid_input(char **split)
{
	int	i;
	int	j;

	i = 0;
	while (split[i])
	{
		if (!is_valid_individual_input(split[i]))
			return (0);
		j = i + 1;
		while (split[j])
		{
			if (ft_atoi_long(split[i]) == ft_atoi_long(split[j]))
				return (0);
			j++;
		}
		i++;
	}
	if (split[0] == 0)
		return (0);
	return (1);
}

char	**parse_input(char **argv)
{
	int		i;
	char	*str;
	char	**split;

	str = ft_strdup("");
	i = 1;
	while (argv[i])
	{
		str = ft_strjoin(str, argv[i]);
		str = ft_strjoin(str, " ");
		i++;
	}
	split = ft_split(str, ' ');
	if (!is_invalid_input(split))
	{
		write(2, "ERROR\n", 6);
		exit(1);
	}
	free(str);
	return (split);
}

void	execute_instructions(t_stack *a, t_stack *b)
{
	char	*instruction;

	instruction = get_next_line(0);
	while (instruction)
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
		instruction = get_next_line(0);
	}
}

void	print_stack(t_stack *stack)
{
	t_node	*node;

	if (stack_is_empty(stack))
		return ;
	node = stack->top;
	while (node->bellow)
	{
		ft_putnbr_fd(node->num, 1);
		ft_putstr_fd(" | ", 1);
		node = node->bellow;
	}
	ft_putnbr_fd(node->num, 1);
	ft_putchar_fd('\n', 1);
}

int	stack_is_sorted(t_stack *stack)
{
	t_node	*node;

	node = stack->top;
	while (node && node->bellow)
	{
		if (node->num > node->bellow->num)
			return (0);
		node = node->bellow;
	}
	return (1);
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
