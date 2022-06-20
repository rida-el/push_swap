/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-maza <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:14:56 by rel-maza           #+#    #+#             */
/*   Updated: 2021/11/12 20:04:44 by rel-maza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t size;
	unsigned int i;

	if (!s)
		return;
	size = ft_strlen(s);
	i = 0;
	while (i < size)
	{
		f(i, &s[i]);
		i++;
	}
}
