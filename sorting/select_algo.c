/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   select_algo.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/08 14:51:53 by jhille        #+#    #+#                 */
/*   Updated: 2021/12/14 16:38:10 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "sorting.h"

void	select_algo(t_list **stack_a, t_list **stack_b, int stack_size)
{
	if (stack_size == 2)
		sa(stack_a);
	else if (stack_size == 3)
		sorting_3(stack_a);
	else if (stack_size == 4)
		sorting_4(stack_a, stack_b);
	else if (stack_size == 5)
		sorting_5(stack_a, stack_b);
	else if (stack_size == 500)
		insertion_sort(stack_a, stack_b, 15);
	else
		insertion_sort(stack_a, stack_b, 7);
}
