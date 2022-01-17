/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate_operations.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/01 12:41:23 by jhille        #+#    #+#                 */
/*   Updated: 2021/12/15 15:27:01 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static int	rotate(t_list **stack)
{
	t_list	*new_first;

	if (!*stack || !(*stack)->next)
		return (0);
	new_first = (*stack)->next;
	(*stack)->next = 0;
	ft_lstadd_back(&new_first, *stack);
	*stack = new_first;
	return (1);
}

void	ra(t_list **stack_a)
{
	if (!rotate(stack_a))
		return ;
	if (write(1, "ra\n", 3) == -1)
		error_exit(WRITE_F);
}

void	rb(t_list **stack_b)
{
	if (!rotate(stack_b))
		return ;
	if (write(1, "rb\n", 3) == -1)
		error_exit(WRITE_F);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	if (!rotate(stack_a) && !rotate(stack_b))
		return ;
	if (write(1, "rr\n", 3) == -1)
		error_exit(WRITE_F);
}
