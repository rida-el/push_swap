/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-maza <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 12:58:18 by rel-maza           #+#    #+#             */
/*   Updated: 2021/11/12 19:55:34 by rel-maza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_calloc(size_t count, size_t size)
{
	void *ret;

	ret = malloc(size * count);
	if (ret == NULL)
		return (NULL);
	ft_bzero(ret, size * count);
	return (ret);
}
