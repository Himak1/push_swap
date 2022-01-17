/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   insert_sort.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/09 16:52:18 by jhille        #+#    #+#                 */
/*   Updated: 2021/12/16 17:07:42 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "sorting.h"

static void	get_chunks(int *chunk_min, int *chunk_max,
						t_list *stack_a, int chunks)
{
	int	max;
	int	min;
	int	range;
	int	i;

	i = 0;
	max = find_max(stack_a);
	min = find_min(stack_a);
	range = (max - min) / chunks;
	while (i < chunks)
	{
		chunk_min[i] = min + (range * i);
		chunk_max[i] = (min + (range * (i + 1)) - 1);
		i++;
	}
	chunk_max[i - 1] = max;
}

void	malloc_chunk_values(int **cmax, int **cmin, int chunks)
{
	*cmax = malloc(chunks * sizeof(int));
	*cmin = malloc(chunks * sizeof(int));
	if (*cmax == NULL || *cmin == NULL)
		error_exit(MALLOC_F);
}

void	insertion_sort(t_list **stack_a, t_list **stack_b, int chunks)
{
	int	*chunk_max;
	int	*chunk_min;
	int	b_size;
	int	i;

	i = 0;
	malloc_chunk_values(&chunk_max, &chunk_min, chunks);
	insert_standardize(stack_a);
	get_chunks(chunk_min, chunk_max, *stack_a, chunks);
	while (i < chunks)
	{
		push_chunk_b(stack_a, stack_b, chunk_min[i], chunk_max[i]);
		i++;
	}
	b_size = ft_lstsize(*stack_b);
	while (*stack_b)
	{
		push_chunk_a(stack_a, stack_b, b_size);
		b_size--;
	}
	free(chunk_max);
	free(chunk_min);
}
