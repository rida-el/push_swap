#include <stdio.h>
#include "libft/libft.h"

typedef struct s_stack_elm {
	int	num;
	struct s_stack_elm *next;
	struct s_stack_elm *previous;
} t_stack_elm;

typedef struct s_stack {
	t_stack_elm	*top;
	t_stack_elm *bottom;
	int size;
} t_stack;

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
		{
			write(0, "ERROR\n", 6);
			exit(1);
		}
		j = i + 1;
		while(split[j])
		{
			if(ft_atoi_long(split[i]) == ft_atoi_long(split[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

char	**parse_input(char **argv)
{
	int i;
	int	j;
	char *str;
	char **split;
	t_stack a;

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
	return (split);
}

int main(int argc, char **argv)
{
	char	**split;
	// parse input
	split = parse_input(argv);
	// create_stack(split);
}