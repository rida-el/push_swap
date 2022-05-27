#include "../push_swap.h"

int ft_strlent(char *s)
{
	if (!s)
		return (0);
	int i;
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char *ft_line_join(char *s1, char *s2)
{
	int i = 0;
	int j = 0;
	char *result = NULL;
	int l = 0;
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		s1[0] = 0;
	}
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

char *get_line(int fd)
{
	char *line = NULL;
	char buffer[2];
	int a;
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

char *get_next_line(int fd)
{

	char *result = NULL;

	if (fd < 0)
		return (NULL);

	result = get_line(fd);
	return (result);
}

// int main()
// {
// 	char *res;
// 	res = get_next_line(0);
// 	while (res)
// 	{
// 		printf("Line : %s",res);
// 		res = get_next_line(0);
// 	}
// 	return(0);
// }