/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   insert_push_chunk.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 15:20:18 by jhille        #+#    #+#                 */
/*   Updated: 2021/12/15 15:34:03 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "sorting.h"

void	scan_chunk(t_list **stack_a, int *h_index, int min, int max)
{
	int		i;
	int		value;
	t_list	*iter;

	i = 0;
	iter = *stack_a;
	while (iter)
	{
		value = *(int *)iter->content;
		if (value >= min && value <= max)
		{
			if (h_index[0] == -1)
				h_index[0] = i;
			else
				h_index[1] = i;
		}
		i++;
		iter = iter->next;
	}
}

int	select_node(t_list **stack_a, int *h_index, int size)
{
	int	moves[2];
	int	node_val;

	node_val = node_value(*stack_a, h_index[0]);
	moves[0] = get_moves(stack_a, size, node_val);
	if (h_index[1] == -1)
		return (moves[0]);
	node_val = node_value(*stack_a, h_index[1]);
	moves[1] = get_moves(stack_a, size, node_val);
	if (ft_abs(moves[0]) < ft_abs(moves[1]))
		return (moves[0]);
	else
		return (moves[1]);
}

void	push_chunk_b(t_list **stack_a, t_list **stack_b, int min, int max)
{
	int	h_index[2];
	int	moves;
	int	size;

	while (1)
	{
		h_index[0] = -1;
		h_index[1] = -1;
		size = ft_lstsize(*stack_a);
		scan_chunk(stack_a, h_index, min, max);
		if (h_index[0] == -1)
			break ;
		else
		{
			moves = select_node(stack_a, h_index, size);
			move_to_top(stack_a, 'a', moves);
			pb(stack_a, stack_b);
		}
	}
}

void	push_chunk_a(t_list **stack_a, t_list **stack_b, int b_size)
{
	int	b_max;
	int	moves;

	b_max = find_max(*stack_b);
	moves = get_moves(stack_b, b_size, b_max);
	move_to_top(stack_b, 'b', moves);
	pa(stack_a, stack_b);
}
