/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/27 21:10:32 by jhille        #+#    #+#                 */
/*   Updated: 2022/01/13 12:45:23 by zaiba         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "sorting/sorting.h"

int	check_sorted(t_list *stack1)
{
	t_list	*iter;
	int		value;

	iter = stack1;
	value = -2147483648;
	while (iter)
	{
		if (value < *(int *)iter->content)
			value = *(int *)iter->content;
		else
			break ;
		iter = iter->next;
	}
	if (iter)
		return (0);
	else
		return (1);
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = input_conversion(argc, argv);
	stack_b = 0;
	if (!check_sorted(stack_a))
		select_algo(&stack_a, &stack_b, argc - 1);
	ft_lstclear(&stack_a, &free);
	return (0);
}
