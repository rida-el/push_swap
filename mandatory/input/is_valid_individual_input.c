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
