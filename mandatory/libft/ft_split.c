/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhalid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:11:12 by mkhalid           #+#    #+#             */
/*   Updated: 2021/11/13 17:26:36 by mkhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	split_counter(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && c != str[i])
			i++;
		if (c == 0)
		{
			count++;
			break ;
		}
		while (c && c == str[i])
			i++;
		count++;
	}
	return (count);
}

static int	word_counter(char *str, char c)
{
	int	count;

	count = 0;
	while (*str && c != *str)
	{
		count++;
		str++;
	}
	return (count);
}

static void	free_res(char **result, int size)
{
	while (size--)
		free(result[size]);
	free(result);
}

static char	*create_word(char *str, char c, char **word)
{
	int	wcount;
	int	j;

	wcount = word_counter(str, c);
	*word = malloc(sizeof(char) * (wcount + 1));
	j = 0;
	if (*word == 0)
		return (0);
	(*word)[wcount] = 0;
	while (j < wcount)
		(*word)[j++] = *str++;
	while (c == *str)
		str++;
	return (str);
}

char	**ft_split(char const *str, char c)
{
	char	**result;
	int		spcount;
	int		i;

	if (str == 0)
		return (NULL);
	while (c && *str && c == (char)*str)
		str++;
	spcount = split_counter((char *)str, c);
	result = malloc(sizeof(char *) * (spcount + 1));
	if (!result)
		return (0);
	result[spcount] = 0;
	i = 0;
	while (i < spcount)
	{
		str = create_word((char *)str, c, result + i);
		if (str == 0)
		{
			free_res(result, i);
			return (0);
		}
		i++;
	}
	return (result);
}
