#include "push_swap.h"

int check_individual_input(char *input)
{
	int		i;
	long	num;

	i = 1;
	if(!(ft_isdigit(input[0]) || input[0] == '+' || input[0] == '-'))
		return (0);
	while(input[i])
	{
		if(!ft_isdigit(input[i]))
			return (0);
		i++;
	}
	if(i > 11)
		return (0);
	num = ft_atoi_long(input);
	if(num > 2147483647 || num  < -2147483648)
		return (0);
	return (1);
}

int	check_invalid_input(char **split)
{
	int i;
	int j;

	i = 0;
	while(split[i])
	{
		if(!check_individual_input(split[i]))
			return (1);
		j = i + 1;
		while(split[j])
		{
			if(ft_atoi_long(split[i]) == ft_atoi_long(split[j]))
				return (1);
			j++;
		}
		i++;
	}
	if(split[0] == 0) // to eliminate the case where the binay is ran like: ./a.out ""
		return (1);
	return (0);
}

char	**parse_input(char **argv)
{
	int i;
	int	j;
	char *str;
	char **split;
	// t_stack a;

	str = ft_strdup("");
	i = 1;
	while(argv[i])
	{
		str = ft_strjoin(str, argv[i]);
		str = ft_strjoin(str, " ");
		i++;
	}
	split = ft_split(str, ' ');
	if(check_invalid_input(split))
	{
		write(0, "ERROR\n", 6);
		exit(1);
	}
	free(str);
	return (split);
}

int main(int argc, char **argv)
{
	int 	i;
	t_node	*elm;
	char	**split;
	t_stack	*a;
	t_stack	*b;

	// parse input
	split = parse_input(argv);
	a = stack_init();
	b = stack_init();
	i = 0;
	while(split[i])
	{
		elm = new_node(ft_atoi(split[i]));
		push_node_bottom(a, elm);
		i++;
	}
	push_swap(a, b);

// TEST ZONE 
	// while(a->top)
	// {
	// 	printf("%d\n", a->top->num);
	// 	a->top = a->top->bellow;
	// }
	// i = 0;
	// t_stack *b;
	// b = stack_init();
	// while(split[i])
	// {
	// 	elm = new_node(ft_atoi(split[i]));
	// 	push_node_bottom(b, elm);
	// 	i++;
	// }
	

	// while(a->top)
	// {
	// 	printf("%d -- ", a->top->num);
	// 	a->top = a->top->bellow;

	// }
	// printf("\n");
	// while(b->top)
	// {
	// 	printf("%d -- ", b->top->num);
	// 	b->top = b->top->bellow;
	// }
	// while(1);

}