/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   insert_standardize.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/14 16:54:31 by jhille        #+#    #+#                 */
/*   Updated: 2021/12/17 19:01:55 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"
#include "../error_exit.h"
#include <stdlib.h>

static int	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
	return (1);
}

// in quicksort() size == max index

static void	quicksort(int *arr, int start, int size)
{
	int	i;
	int	j;

	if (start >= size)
		return ;
	i = start;
	j = start - 1;
	while (i < size)
	{
		if (arr[i] < arr[size])
		{
			j++;
			swap(&arr[i], &arr[j]);
		}
		i++;
	}
	swap(&arr[j + 1], &arr[size]);
	quicksort(arr, 0, j);
	quicksort(arr, j + 1, size);
}

static int	*copy_and_sort(t_list **stack, int size)
{
	t_list	*iter;
	int		*copy;
	int		i;

	i = 0;
	copy = malloc(size * sizeof(int));
	if (!copy)
		error_exit(MALLOC_F);
	iter = *stack;
	while (iter)
	{
		copy[i] = *(int *)iter->content;
		iter = iter->next;
		i++;
	}
	quicksort(copy, 0, size - 1);
	return (copy);
}

t_list	*value_to_index(int value, int *sorted)
{
	int		i;
	int		*content;
	t_list	*new_node;

	i = 0;
	while (sorted[i] != value)
		i++;
	content = malloc(sizeof(int *));
	if (!content)
		error_exit(MALLOC_F);
	*content = i;
	new_node = ft_lstnew(content);
	if (!new_node)
		error_exit(MALLOC_F);
	return (new_node);
}

void	insert_standardize(t_list **stack)
{
	t_list	*std;
	t_list	*iter;
	int		*sorted;

	iter = *stack;
	sorted = copy_and_sort(stack, ft_lstsize(*stack));
	std = value_to_index(*(int *)iter->content, sorted);
	while (iter->next)
	{
		iter = iter->next;
		ft_lstadd_back(&std, value_to_index(*(int *)iter->content, sorted));
	}
	ft_lstclear(stack, free);
	*stack = std;
	free(sorted);
}
