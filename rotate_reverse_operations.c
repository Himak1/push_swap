/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate_reverse_operations.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/30 17:49:16 by jhille        #+#    #+#                 */
/*   Updated: 2021/12/01 13:30:51 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static int	rotate_reverse(t_list **stack)
{
	t_list	*new_first;
	t_list	*new_last;

	if (!*stack || !(*stack)->next)
		return (0);
	new_first = ft_lstlast(*stack);
	new_last = lst_2nd_to_last(*stack);
	new_last->next = 0;
	ft_lstadd_front(stack, new_first);
	return (1);
}

void	rra(t_list **stack_a)
{
	if (!rotate_reverse(stack_a))
		return ;
	if (write(1, "rra\n", 4) == -1)
		error_exit(WRITE_F);
}

void	rrb(t_list **stack_b)
{
	if (!rotate_reverse(stack_b))
		return ;
	if (write(1, "rrb\n", 4) == -1)
		error_exit(WRITE_F);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	if (!rotate_reverse(stack_a) && !rotate_reverse(stack_b))
		return ;
	if (write(1, "rrr\n", 4) == -1)
		error_exit(WRITE_F);
}
