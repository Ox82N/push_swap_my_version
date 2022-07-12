/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenjair <obenjair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 20:34:21 by obenjair          #+#    #+#             */
/*   Updated: 2022/07/04 16:40:46 by obenjair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "../inc/push_swap.h"
#include "../libft/inc/libft.h"

void	quick_sort_3(t_stack *stack, int lenght)
{
	if (lenght == 3 && stack->size_a == 3)
		sort_3(stack);
	else if (lenght == 2)
	{
		if (stack->a[0] > stack->a[1])
			sa(stack, 0);
	}
	else if (lenght == 3)
	{
		while (lenght != 3 || !(stack->a[0] < stack->a[1] && stack->a[1] < stack->a[2]))
		{
			if (lenght == 3 && stack->a[0] > stack->a[1] && stack->a[2])
				sa(stack, 0);
			else if (lenght == 3 && !(stack->a[2] > stack->a[0]
					&& stack->a[2] > stack->a[1]))
				lenght = push(stack, lenght, 0);
			else if (stack->a[0] > stack->a[1])
				sa(stack, 0);
			else if (lenght++)
				pa(stack, 0);
		}
	}
}

int	sort_b(t_stack *s, int len)
{
	if (len == 1)
		pa(s, 0);
	else if (len == 2)
	{
		if (s->b[0] < s->b[1])
			sb(s, 0);
		while (len--)
			pa(s, 0);
	}
	else if (len == 3)
	{
		while (len || !(s->a[0] < s->a[1] && s->a[1] < s->a[2]))
		{
			if (len == 1 && s->a[0] > s->a[1])
				sa(s, 0);
			else if (len == 1 || (len >= 2 && s->b[0] > s->b[1])
				|| (len == 3 && s->b[0] > s->b[2]))
				len = push(s, len, 1);
			else
				sb(s, 0);
		}
	}
	return (0);
}

int	get_mediane(int *pivot, int *stack, int size)
{
	int		*tmp_stack;
	int		i;

	tmp_stack = (int *)malloc(size * sizeof(int));
	if (!tmp_stack)
		return (0);
	i = 0;
	while (i < size)
	{
		tmp_stack[i] = stack[i];
		i++;
	}
	sort_temp(tmp_stack, size);
	*pivot = tmp_stack[size / 2];
	free(tmp_stack);
	return (1);
}

int	quick_sort_a(t_stack *stack, int len, int cnt)
{
	int	pivot;
	int	items;

	if (check_if_sorted(stack->a, len, UP) == 1)
		return (1);
	items = len;
	if (len <= 3)
	{
		quick_sort_3(stack, len);
		return (1);
	}
	if (!cnt && !get_mediane(&pivot, stack->a, len))
		return (0);
	while (len != items / 2 + items % 2)
	{
		if (stack->a[0] < pivot && (len--))
			pb(stack, 0);
		else if (++cnt)
			ra(stack, 0);
	}
	while (items / 2 + items % 2 != stack->size_a && cnt--)
		rra(stack, 0);
	return (quick_sort_a(stack, items / 2 + items % 2, 0)
		&& quick_sort_b(stack, items / 2, 0));
	return (1);
}

int	quick_sort_b(t_stack *stack, int len, int cnt)
{
	int	pivot;
	int	items;

	if (!cnt && check_if_sorted(stack->b, len, DOWN) == 1)
		while (len--)
			pa(stack, 0);
	if (len <= 3)
	{
		sort_b(stack, len);
		return (1);
	}
	items = len;
	if (!get_mediane(&pivot, stack->b, len))
		return (0);
	while (len != items / 2)
	{
		if (stack->b[0] >= pivot && len--)
		    pa(stack, 0);
		else if (++cnt)
			rb(stack, 0);
	}
	while (items / 2 != stack->size_b && cnt--)
		rrb(stack, 0);
	return (quick_sort_a(stack, items / 2 + items % 2, 0)
		&& quick_sort_b(stack, items / 2, 0));
}
