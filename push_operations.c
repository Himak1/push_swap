/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_operations.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/30 13:03:10 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/30 17:28:52 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

// takes first node from stack1 and assigns as first node for stack2

static int	push(t_list **stack1, t_list **stack2)
{
	t_list	*temp;

	if (!(*stack1))
		return (0);
	temp = (*stack1)->next;
	ft_lstadd_front(stack2, *stack1);
	*stack1 = temp;
	return (1);
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	if (!push(stack_b, stack_a))
		return ;
	if (write(1, "pa\n", 3) == -1)
		error_exit(WRITE_F);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	if (!push(stack_a, stack_b))
		return ;
	if (write(1, "pb\n", 3) == -1)
		error_exit(WRITE_F);
}
