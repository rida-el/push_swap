/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-maza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 15:40:22 by rel-maza          #+#    #+#             */
/*   Updated: 2022/05/29 15:42:02 by rel-maza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
