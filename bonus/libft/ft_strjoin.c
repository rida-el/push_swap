/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhalid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 17:44:13 by mkhalid           #+#    #+#             */
/*   Updated: 2021/11/13 13:25:53 by mkhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1l;
	int		s2l;
	char	*join;

	if (!s1)
		return (0);
	s1l = ft_strlen(s1);
	s2l = ft_strlen(s2);
	join = malloc(sizeof(char) * (s1l + s2l + 1));
	if (!join)
		return (0);
	ft_strlcpy(join, s1, s1l + 1);
	ft_strlcat(join + s1l, s2, s2l + 1);
	free((void *)s1);
	return (join);
}
