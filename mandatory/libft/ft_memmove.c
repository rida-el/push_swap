/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-maza <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 09:36:51 by rel-maza           #+#    #+#             */
/*   Updated: 2021/11/12 20:03:07 by rel-maza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void *ft_memmove(void *dst, const void *src, size_t len)
{
	char *s;
	char *d;

	if (!dst && !src)
		return (dst);
	s = (char *)src;
	d = (char *)dst;
	if (s < d)
	{
		while (len--)
			d[len] = s[len];
	}
	else
		ft_memcpy(d, s, len);
	return (dst);
}
