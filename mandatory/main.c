/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-maza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 15:32:29 by rel-maza          #+#    #+#             */
/*   Updated: 2022/05/29 15:32:37 by rel-maza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	char	**split;
	t_node	*elm;
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		exit(0);
	i = -1;
	split = parse_input(argv);
	a = stack_init();
	b = stack_init();
	while (split[++i])
	{
		if (split[i][0] == '\0')
			exit_error(1);
		elm = new_node(ft_atoi(split[i]));
		push_node_bottom(a, elm);
		free(split[i]);
	}
	if (stack_is_sorted(a))
		exit(0);
	push_swap(a, b);
	free_stack(a);
	free_stack(b);
}
