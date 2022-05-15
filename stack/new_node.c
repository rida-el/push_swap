#include "../push_swap.h"

t_node	*new_node(int data)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->num = data;
	new->above = NULL;
	new->bellow = NULL;
	return (new);
}