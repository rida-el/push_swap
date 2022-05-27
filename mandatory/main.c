#include "push_swap.h"


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
	if(stack_is_sorted(a))
		exit(0);
	push_swap(a, b);
	free_stack(a);
	free_stack(b);
}
