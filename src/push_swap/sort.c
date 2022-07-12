/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenjair <obenjair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 20:23:11 by obenjair          #+#    #+#             */
/*   Updated: 2022/07/11 18:55:21 by obenjair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "../inc/push_swap.h"
#include "../libft/inc/libft.h"

void	sort_temp(int *temp_stack, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (temp_stack[i] > temp_stack[j])
			{
				temp = temp_stack[i];
				temp_stack[i] = temp_stack[j];
				temp_stack[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void	sort_3(t_stack *stack)  // of we have just 3 numbers in our stack
{
	if (stack->a[0] > stack->a[1] && stack->a[0] < stack->a[2] && stack->a[1] < stack->a[2])
		sa(stack, 0);
	if (stack->a[0] > stack->a[1] && stack->a[0] > stack->a[2] && stack->a[1] < stack->a[2])
	 	ra(stack, 0);
	if (stack->a[0] < stack->a[1] && stack->a[0] > stack->a[2] && stack->a[1] > stack->a[2])
		rra(stack, 0);
	if (stack->a[0] > stack->a[1] && stack->a[0] > stack->a[2] && stack->a[1] > stack->a[2])
	{
		sa(stack, 0);
		rra(stack, 0);
	}
	if (stack->a[0] < stack->a[1] && stack->a[0] < stack->a[2] && stack->a[1] > stack->a[2])
	{
		sa(stack, 0);
		ra(stack, 0);
	}
}

int	sort(t_stack *stack, int size)
{
	if(check_if_sorted(stack->a, stack->size_a, UP) == 0)
	{
		if (size == 2) // just 2 numbers in the stack
			sa(stack, 0);
		else if (size == 3) // just 3 numbers in the stack
			sort_3(stack);
		else
			quick_sort_a(stack, size, 0);  //more than 3 numbers in the stack
	}
	return (0);
}

int	ft_push(t_stack *stack, int lenght, int operation)
{
	if (operation == 0)
		ft_pb(stack, 0);
	else
		ft_pa(stack, 0);
	lenght--;
	return (lenght);
}