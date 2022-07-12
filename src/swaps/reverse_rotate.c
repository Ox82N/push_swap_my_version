/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenjair <obenjair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 18:59:12 by obenjair          #+#    #+#             */
/*   Updated: 2022/07/04 19:16:27 by obenjair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "../inc/push_swap.h"
#include "../libft/inc/libft.h"

void	rra(t_stack *stack, int index)
/* Shift down all elements of stack a by 1.
The last element becomes the first one.*/
{
	int	temp;
	int	i;

	if (stack->size_a == 0 || stack->size_a == 1)
		return ;
	i = stack->size_a - 1;
	temp = stack->a[i];
	while (i)
	{
		stack->a[i] = stack->a[i - 1];
			i--;
	}
	stack->a[i] = temp;
	if (index == 0)
		write(1, "rra\n", 4);
}

void	rrb(t_stack *stack, int index)
/* Shift down all elements of stack b by 1. 
   The last element becomes the first one*/
{
	int	temp;
	int	i;

	if (stack->size_b == 0 || stack->size_b == 1)
		return ;
	i = stack->size_b - 1;
	temp = stack->b[i];
	while (i)
	{
		stack->b[i] = stack->b[i - 1];
			i--;
	}
	stack->b[i] = temp;
	if (index == 0)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack *stack, int index)
/* rra and rrb at the same time.*/
{
	int	temp;
	int	i;

	if ((stack->size_a == 0 || stack->size_a == 1) || (stack->size_b == 0 || stack->size_b == 1))
		return ;
	i = stack->size_a - 1;
	temp = stack->a[i];
	while (i)
	{
		stack->a[i] = stack->a[i - 1];
			i--;
	}
	stack->a[i] = temp;
	i = stack->size_b - 1;
	temp = stack->b[i];
	while (i)
	{
		stack->b[i] = stack->b[i - 1];
			i--;
	}
	stack->b[i] = temp;
	if (index == 0)
		write(1, "rrr\n", 4);
}