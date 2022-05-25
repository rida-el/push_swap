#include "push_swap.h"

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
		write(0, "ERROR\n", 6);
		exit(1);
	}
	free(str);
	return (split);
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
	push_swap(a, b);
	free_stack(a);
	free_stack(b);
}
