/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_is_empty.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-maza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:20:19 by rel-maza          #+#    #+#             */
/*   Updated: 2022/06/04 15:20:29 by rel-maza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* a funciton to check if stack empty or not */
int	stack_is_empty(t_stack *stack)
{
	return (stack->top == NULL && stack->bottom == NULL);
}
