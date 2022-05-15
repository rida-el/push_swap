/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhalid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:36:54 by mkhalid           #+#    #+#             */
/*   Updated: 2021/11/08 15:10:27 by mkhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	is_from_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	int		end;
	char	*ret;

	if (!s1)
		return (0);
	i = 0;
	while (s1[i] && is_from_set(s1[i], set))
		i++;
	start = i;
	i = ft_strlen(s1) - 1;
	while (i > start && is_from_set(s1[i], set))
		i--;
	end = i;
	ret = malloc ((end - start + 1 + 1) * sizeof(char));
	if (!ret)
		return (0);
	i = 0;
	while (start <= end)
		ret[i++] = s1[start++];
	ret[i] = '\0';
	return (ret);
}
