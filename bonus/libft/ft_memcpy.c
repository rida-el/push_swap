/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhalid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:35:34 by mkhalid           #+#    #+#             */
/*   Updated: 2021/11/12 20:02:41 by mkhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char	*newsrc;
	char		*newdst;

	if (!dst && ! src)
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
