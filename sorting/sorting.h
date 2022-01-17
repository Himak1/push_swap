/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorting.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/01 16:06:12 by jhille        #+#    #+#                 */
/*   Updated: 2021/12/16 17:07:13 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTING_H
# define SORTING_H
# define MAX_INT 2147483647
# define MIN_INT -2147483648
# include "../libft/libft.h"

void	print_lst(void *content);//remove this!

void	select_algo(t_list **stack_a, t_list **stack_b, int argc);

void	sorting_3(t_list **stack_a);
void	sorting_4(t_list **stack_a, t_list **stack_b);
void	sorting_5(t_list **stack_a, t_list **stack_b);
void	sorting_6(t_list **stack_a, t_list **stack_b);

void	insert_standardize(t_list **stack);
void	insertion_sort(t_list **stack_a, t_list **stack_b, int chunks);
void	scan_chunk(t_list **stack_a, int *h_index, int min, int max);
int		select_node(t_list **stack_a, int *h_index, int size);
void	push_chunk_b(t_list **stack_a, t_list **stack_b, int min, int max);
void	push_chunk_a(t_list **stack_a, t_list **stack_b, int b_size);

int		get_moves(t_list **stack, int size, int value);
void	move_to_top(t_list **stack, char type, int moves);

int		find_max(t_list	*stack);
int		find_min(t_list *stack);

t_list	*node_index(t_list *stack, int index);
int		node_value(t_list *stack, int index);

int		ft_abs(int num);
#endif