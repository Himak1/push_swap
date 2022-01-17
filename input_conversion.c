/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_conversion.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/29 12:31:05 by jhille        #+#    #+#                 */
/*   Updated: 2021/12/16 12:24:01 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "error_exit.h"

static void	check_if_negative(char *arg_str, int *negative, int *i)
{
	if (arg_str[*i] == '-')
	{
		*negative = 1;
		*i += 1;
		if (!arg_str[*i])
			error_exit(BAD_ARG);
	}
}

static int	convert_int(char *arg_str)
{
	int	i;
	int	negative;
	int	ret;

	i = 0;
	negative = 0;
	check_if_negative(arg_str, &negative, &i);
	if ((ft_strlen(arg_str) > 10 && negative == 0)
		|| (ft_strlen(arg_str) > 11 && negative == 1))
		error_exit(INT_OVERFLOW);
	if (arg_str[i] == '0' && arg_str[i + 1])
		error_exit(BAD_ARG);
	while (arg_str[i])
	{
		if (!ft_isdigit(arg_str[i]))
			error_exit(BAD_ARG);
		i++;
	}
	ret = ft_atoi(arg_str);
	if ((negative == 1 && ret > 0) || (negative == 0 && ret < 0))
		error_exit(INT_OVERFLOW);
	return (ret);
}

void	find_duplicate(t_list *stack1, int new_node)
{
	while (stack1)
	{
		if (*(int *)stack1->content == new_node)
			error_exit(DUPL_NUM);
		stack1 = stack1->next;
	}
}

t_list	*input_conversion(int argc, char *argv[])
{
	int		*value;
	t_list	*stack1;
	t_list	*temp;

	argc--;
	stack1 = 0;
	while (argc != 0)
	{
		value = malloc(sizeof(int));
		if (!value)
			error_exit(MALLOC_F);
		*value = convert_int(argv[argc]);
		temp = ft_lstnew(value);
		if (!temp)
			error_exit(MALLOC_F);
		find_duplicate(stack1, *(int *)temp->content);
		if (stack1)
			ft_lstadd_front(&stack1, temp);
		else
			stack1 = temp;
		argc--;
	}
	return (stack1);
}
