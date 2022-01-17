/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move_to_top.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/08 18:26:55 by jhille        #+#    #+#                 */
/*   Updated: 2021/12/12 00:50:55 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "sorting.h"

int	get_moves(t_list **stack, int size, int value)
{
	int		i;
	t_list	*iter;

	i = 0;
	iter = *stack;
	while (iter)
	{
		if (*(int *)iter->content == value)
			break ;
		iter = iter->next;
		i++;
	}
	if (i <= size / 2)
		return (i);
	else
		return ((size - i) * -1);
}

void	move_to_top(t_list **stack, char type, int moves)
{
	while (moves != 0)
	{
		if (moves > 0)
		{
			if (type == 'a')
				ra(stack);
			else
				rb(stack);
			moves--;
		}
		else
		{
			if (type == 'a')
				rra(stack);
			else
				rrb(stack);
			moves++;
		}
	}
}
