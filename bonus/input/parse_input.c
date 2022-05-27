#include "../push_swap.h"

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