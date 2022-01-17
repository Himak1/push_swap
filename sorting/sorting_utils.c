/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorting_utils.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/01 15:29:12 by jhille        #+#    #+#                 */
/*   Updated: 2021/12/10 15:11:10 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

t_list	*node_index(t_list *stack, int index)
{
	int	i;

	i = 0;
	while (stack && i != index)
	{
		stack = stack->next;
		i++;
	}
	return (stack);
}

int	node_value(t_list *stack, int index)
{
	t_list	*node;

	node = node_index(stack, index);
	return (*(int *)node->content);
}

int	find_min(t_list *stack)
{
	int	min;

	min = 2147483647;
	while (stack)
	{
		if (min > *(int *)stack->content)
			min = *(int *)stack->content;
		stack = stack->next;
	}
	return (min);
}

int	find_max(t_list	*stack)
{
	int	max;

	max = -2147483648;
	while (stack)
	{
		if (max < *(int *)stack->content)
			max = *(int *)stack->content;
		stack = stack->next;
	}
	return (max);
}

int	ft_abs(int num)
{
	if (num < 0)
		return (num * -1);
	else
		return (num);
}
