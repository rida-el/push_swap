/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-maza <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:45:19 by rel-maza           #+#    #+#             */
/*   Updated: 2021/11/12 20:07:27 by rel-maza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char *ret;
	size_t size;
	unsigned int i;

	if (!s)
		return (0);
	size = ft_strlen(s);
	ret = malloc(sizeof(char) * (size + 1));
	if (!ret)
		return (0);
	i = 0;
	while (i < size)
	{
		ret[i] = f(i, s[i]);
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
