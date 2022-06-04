/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-maza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 16:32:46 by rel-maza          #+#    #+#             */
/*   Updated: 2022/06/04 16:33:17 by rel-maza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_strlent(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_line_join(char *s1, char *s2)
{
	int		i;
	int		j;
	int		l;
	char	*result;

	i = 0;
	j = 0;
	result = NULL;
	if (!s1)
		s1 = (char *)ft_calloc(1, sizeof(char));
	l = ft_strlent(s1) + ft_strlent(s2);
	result = (char *)malloc(sizeof(char) * (l + 1));
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[j])
		result[i++] = s2[j++];
	result[i] = 0;
	free(s1);
	return (result);
}

char	*get_line(int fd)
{
	int		a;
	char	*line;
	char	buffer[2];

	line = 0;
	buffer[1] = 0;
	while (1)
	{
		a = read(fd, buffer, 1);
		if (a == -1)
			return (NULL);
		if (a == 0)
			return (line);
		if (buffer[0] == '\n')
		{
			line = ft_line_join(line, buffer);
			return (line);
		}
		if (buffer[0] == '\0')
			return (line);
		line = ft_line_join(line, buffer);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char	*result;

	result = 0;
	if (fd < 0)
		return (NULL);
	result = get_line(fd);
	return (result);
}
