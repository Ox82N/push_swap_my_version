 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenjair <obenjair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 18:45:03 by obenjair          #+#    #+#             */
/*   Updated: 2022/07/03 17:41:50 by obenjair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct stacks
{
    int *a;
    int *b;
    int size_a;
    int size_b;
}   t_stack;

# define UP 0
# define DOWN 1

//swaps
void	pb(t_stack *stack, int index);
void	pa(t_stack *stack, int index);
void	rra(t_stack *stack, int index);
void	rrb(t_stack *stack, int index);
void	rrr(t_stack *stack, int index);
void	ra(t_stack *stack, int index);
void	rb(t_stack *stack, int index);
void	rr(t_stack *stack, int index);
void	sa(t_stack *stack, int index);
void	sb(t_stack *stack, int index);
void	ss(t_stack *stack, int index);

// main
void	push_swap(char **argv);

//utils
void	error(int *stack);
int	atoi_2(char *str, int *stack) ;
int	strlen_2(char **argv);
int	check_if_sorted(int *stack, int size, int index);
void	check_if_repeat(int *stack, int size);

//sort
void	sort_temp(int *temp_stack, int size);
void	sort_3(t_stack *stack);
int	sort(t_stack *stack, int size);
int	push(t_stack *stack, int lenght, int operation);


//quick_sort
void	quick_sort_3(t_stack *stack, int lenght);
int	sort_b(t_stack *s, int len);
int	get_mediane(int *pivot, int *stack, int size);
int	quick_sort_a(t_stack *stack, int len, int cnt);
int	quick_sort_b(t_stack *stack, int len, int cnt);
#endif