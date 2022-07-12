/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenjair <obenjair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 18:43:22 by obenjair          #+#    #+#             */
/*   Updated: 2022/07/03 02:43:42 by obenjair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "../inc/push_swap.h"
#include "../libft/inc/libft.h"

void	push_swap(char **argv)
{
	t_stack	stack;
	int			size;
	int			i;

	i = -1;
	size = strlen_2(argv); // count the size of numbers in our input
	stack.a = malloc(size * sizeof(int)); // allocate a memory of stack A
	if (!stack.a)
		return ;
	stack.size_a = size;
	stack.b = malloc(size * sizeof(int)); // allocate memory to stack B
	if (!stack.b)
	{
		free(stack.a);
		return ;
	}
	stack.size_b = 0; // stack B is empty
	while (i < size)
	{
		stack.a[i] = atoi_2(argv[i], stack.a);
		++i;  // ft_ps_atoi : to check if there are just numbers in our stack nothing else
	}
	check_if_repeat(stack.a, size); // check if there are the same numbers in the stack if YES return ERROR
	sort(&stack, size); // start sorting our numbers in the stack a
	free(stack.a);
	free(stack.b);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		argv++;
		if (argc == 2)
			argv = ft_split(*argv, ' ');
		push_swap(argv);
		return (0);
	}
	return (0);
}