/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-maza <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:35:34 by rel-maza           #+#    #+#             */
/*   Updated: 2021/11/12 20:02:41 by rel-maza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memcpy(void *dst, const void *src, size_t n)
{
	const char *newsrc;
	char *newdst;

	if (!dst && !src)
		return (dst);
	newsrc = (const char *)src;
	newdst = (char *)dst;
	while (n--)
	{
		*newdst = *newsrc;
		newsrc++;
		newdst++;
	}
	return (dst);
}
