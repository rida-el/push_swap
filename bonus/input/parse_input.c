#include "../push_swap.h"

int is_space(char c)
{
	return (c >= 9 && c <= 13) || c == 32;
}

int is_all_spaces(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!is_space(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_one_sign(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if((str[i] == '-' || str[i] == '+') && !ft_isdigit(str[i+1]))
			return(1);
		i++;
	}
	return (0);
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
		if (argv[i][0] == '\0' || is_all_spaces(argv[i]) || is_one_sign(argv[i]))
			exit_error(1);
		str = ft_strjoin(str, argv[i]);
		str = ft_strjoin(str, " ");
		i++;
	}
	split = ft_split(str, ' ');
	if (!is_invalid_input(split))
		exit_error(1);
	free(str);
	return (split);
}