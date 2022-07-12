/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenjair <obenjair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 20:12:51 by obenjair          #+#    #+#             */
/*   Updated: 2022/07/03 18:57:41 by obenjair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "../inc/push_swap.h"
#include "../libft/inc/libft.h"

void	error(int *stack) // in case there is an Error(some arguments aren’t integers,
							// some arguments are bigger than an integer and/or there are duplicates.)
{
	free(stack);
    write(1, "Error\n", 7);
	exit (1);
}

int	atoi_2(char *str, int *stack) 
{
	int i;
	int ishara;
	int res;

	i = 0;
	res = 0;
	ishara = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if(str[i] == '+' || str[i] == '-')
	{
		if(str[i] == '-')
		{
			ishara = -1;
		}
		i++;
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			error(stack);
		res = (str[i] - '0') + (res * 10);
		i++;
	}
	if ((res > 2147483648 && ishara == -1) || (res > 2147483647 && ishara == 1))
		error(stack);
	return (res * ishara);
}

int	strlen_2(char **argv) // count how many arguments are there in our input
{
	int	count;

	count = 0;
	while (*argv != '\0')
	{
		argv++;
		count++;
	}
	return (count);
}

int	check_if_sorted(int *stack, int size, int index) // to check if our numbers are already sorted
{
	int	i;

	if (index == UP)
	{
		i = 1;
		while (i < size)
		{
			if (stack[i - 1] > stack[i])
				return (0);
			i++;
		}
		return (1);
	}
	else
	{
		i = 1;
		while (i < size)
		{
			if (stack[i - 1] < stack[i])
				return (0);
			i++;
		}
		return (1);
	}
}

void	check_if_repeat(int *stack, int size) // to check if there are the same nmbers in our stack
{												// if YES return ERROR
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < size)
	{
		while (j < size)
		{
			if (stack[i] == stack[j])
				error(stack);
			j++;
		}
		i++;
		j = i + 1;
	}
}
