/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenjair <obenjair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 18:50:31 by obenjair          #+#    #+#             */
/*   Updated: 2022/07/04 19:06:32 by obenjair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../inc/push_swap.h"
#include "../libft/inc/libft.h"

void	ft_pb(t_stack *stack, int index)
/*  Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.*/
{
	int	i;

	if(stack->size_a == 0)
		return;
	stack->size_b++;
	i = stack->size_b;
	while (i > 0)
	{
		stack->b[i] = stack->b[i - 1];
			--i;
	}
	stack->b[0] = stack->a[0];
	i = -1;
	stack->size_a--;
	while (i < stack->size_a)
	{
		stack->a[i] = stack->a[i + 1];
			++i;
	}
	if (index == 0)
		ft_printf("pb\n");
}

void	pa(t_stack *stack, int index)
/* Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.*/
{
	int	i;

	if (stack->size_b == 0)
		return;
	stack->size_a++;
	i = stack->size_a;
	while (i > 0)
    {
		stack->a[i] = stack->a[i - 1];
            --i;
    }
	stack->a[0] = stack->b[0];
	i = -1;
	stack->size_b--;
	while (i < stack->size_b)
    {
		stack->b[i] = stack->b[i + 1];
            ++i;
    }
	if (index == 0)
		write(1, "pa\n", 3);
}
