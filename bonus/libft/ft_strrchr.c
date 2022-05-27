/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhalid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:13:00 by mkhalid           #+#    #+#             */
/*   Updated: 2021/11/12 20:08:47 by mkhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	cc;
	char	*ss;

	ss = (char *)s + ft_strlen((char *)s);
	cc = (char)c;
	if (cc == '\0')
		return (ss);
	while (ss >= s)
	{
		if (*ss == cc)
			return (ss);
		ss--;
	}
	return (0);
}
