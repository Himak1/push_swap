/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorting_3.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/01 15:11:25 by jhille        #+#    #+#                 */
/*   Updated: 2021/12/15 13:16:03 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "sorting.h"

void	sorting_3(t_list **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = node_value(*stack_a, 0);
	b = node_value(*stack_a, 1);
	c = node_value(*stack_a, 2);
	if (a > b && b < c && a > c)
		ra(stack_a);
	else if (a < b && a < c && b > c)
	{
		rra(stack_a);
		sa(stack_a);
	}
	else if (a > b && b > c)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (a < b && b > c)
		rra(stack_a);
	else if (a > b && b < c)
		sa(stack_a);
}
