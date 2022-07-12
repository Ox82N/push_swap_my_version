/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenjair <obenjair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 19:33:06 by obenjair          #+#    #+#             */
/*   Updated: 2022/07/04 19:08:39 by obenjair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "../inc/push_swap.h"
#include "../libft/inc/libft.h"

void	ra(t_stack *stack, int index)
/*  Shift up all elements of stack a by 1.
The first element becomes the last one.*/
{
	int	temp;
	int	i;

    i = 0;
	if (stack->size_a == 0 || stack->size_a == 1)
		return ;
	temp = stack->a[i];
	i++;
	while (i < stack->size_a)
	{
		stack->a[i - 1] = stack->a[i];
			i++;
	}
	stack->a[i - 1] = temp;
	if (index == 0)
		write(1, "ra\n", 3);
}

void	rb(t_stack *stack, int index)
/* Shift up all elements of stack b by 1. 
The first element becomes the last one.*/
{
	int	temp;
	int	i;

    i = 0;
	if (stack->size_b == 0 || stack->size_b == 1)
		return ;
	temp = stack->b[i];
	i++;
	while (i < stack->size_b)
	{
		stack->b[i - 1] = stack->b[i];
			i++;
	}
	stack->b[i - 1] = temp;
	if (index == 0)
		write(1, "rb\n", 3);
}

void	rr(t_stack *stack, int index)
/* ra and rb at the same time.*/
{
	int	temp;
	int	i;

    i = 0;
	if (stack->size_a == 0 || stack->size_a == 1 || (stack->size_b == 0 || stack->size_b == 1))
		return ;
	temp = stack->a[i];
	while (i < stack->size_a)
	{
		stack->a[i - 1] = stack->a[i];
			++i;
	}
	stack->a[i - 1] = temp;
	i = 0;
	temp = stack->b[i];
	while (i < stack->size_b)
	{
		stack->b[i - 1] = stack->b[i];
			++i;
	}
	stack->b[i - 1] = temp;
	if (index == 0)
		write(1, "rr\n", 3);
}
