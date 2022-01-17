/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap_operations.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/30 15:25:30 by jhille        #+#    #+#                 */
/*   Updated: 2021/11/30 17:48:09 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static int	swap(t_list **stack)
{
	t_list	*temp;

	if (!*stack || !(*stack)->next)
		return (0);
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
	return (1);
}

void	sa(t_list **stack_a)
{
	if (!swap(stack_a))
		return ;
	if (write(1, "sa\n", 3) == -1)
		error_exit(WRITE_F);
}

void	sb(t_list **stack_b)
{
	if (!swap(stack_b))
		return ;
	if (write(1, "sb\n", 3) == -1)
		error_exit(WRITE_F);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	if (!swap(stack_a) && !swap(stack_b))
		return ;
	if (write(1, "ss\n", 3) == -1)
		error_exit(WRITE_F);
}
