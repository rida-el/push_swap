/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-maza <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:51:54 by rel-maza           #+#    #+#             */
/*   Updated: 2021/11/13 13:14:55 by rel-maza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	int size;
	char *ret;
	unsigned int slen;

	if (!s)
		return (NULL);
	slen = (unsigned int)ft_strlen(s);
	if (start >= slen)
		size = 0;
	else
		size = min(slen - start, len);
	ret = malloc((size + 1) * sizeof(char));
	if (!ret)
		return (0);
	ft_strlcpy(ret, s + start, size + 1);
	return (ret);
}
