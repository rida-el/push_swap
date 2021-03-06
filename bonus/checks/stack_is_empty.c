/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_is_empty.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-maza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 16:00:10 by rel-maza          #+#    #+#             */
/*   Updated: 2022/06/04 16:00:19 by rel-maza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	stack_is_empty(t_stack *stack)
{
	return (stack->top == NULL && stack->bottom == NULL);
}
