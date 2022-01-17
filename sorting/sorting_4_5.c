/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorting_4_5.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/01 17:48:52 by jhille        #+#    #+#                 */
/*   Updated: 2021/12/12 17:20:52 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "sorting.h"

void	sorting_4(t_list **stack_a, t_list **stack_b)
{
	int	moves;

	moves = get_moves(stack_a, 4, find_min(*stack_a));
	move_to_top(stack_a, 'a', moves);
	pb(stack_a, stack_b);
	sorting_3(stack_a);
	pa(stack_a, stack_b);
}

void	sorting_5(t_list **stack_a, t_list **stack_b)
{
	int	moves;

	moves = get_moves(stack_a, 5, find_min(*stack_a));
	move_to_top(stack_a, 'a', moves);
	pb(stack_a, stack_b);
	moves = get_moves(stack_a, 4, find_min(*stack_a));
	move_to_top(stack_a, 'a', moves);
	pb(stack_a, stack_b);
	sorting_3(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}
