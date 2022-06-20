/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-maza <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 19:10:41 by rel-maza           #+#    #+#             */
/*   Updated: 2021/11/12 20:01:53 by rel-maza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t i;
	unsigned char *s1c;
	unsigned char *s2c;

	s1c = (unsigned char *)s1;
	s2c = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (s1c[i] != s2c[i])
			return (s1c[i] - s2c[i]);
		i++;
	}
	return (0);
}
