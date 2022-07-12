/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenjair <obenjair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 19:37:50 by obenjair          #+#    #+#             */
/*   Updated: 2022/07/04 19:09:32 by obenjair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "../inc/push_swap.h"
#include "../libft/inc/libft.h"

void	sa(t_stack *stack, int index)
/* Swap the first 2 elements at the top of stack a. 
	Do nothing if there is only one or no elements.*/
{
	int	temp;

    temp = 0;
	if (stack->size_a == 0 || stack->size_a == 1)
		return ;
	temp = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = temp;
	if (index == 0)
		write(1, "sa\n", 3);
}

void	sb(t_stack *stack, int index)
/* Swap the first 2 elements at the top of stack b. 
	Do nothing if there is only one or no elements.*/
{
	int	temp;

    temp = 0;
	if (stack->size_b == 0 || stack->size_b == 1)
		return ;
	temp = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = temp;
	if (index == 0)
		write(1, "sb\n", 3);
}

void	ss(t_stack *stack, int index)
/* sa and sb at the same time. */
{
	int	temp;

    temp = 0;
	if (stack->size_a == 0 || stack->size_a == 1 || (stack->size_b == 0 || stack->size_b == 1))
		return ;
	temp = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = temp;
	temp = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = temp;
	if (index == 0)
		write(1, "ss\n", 3);
}
