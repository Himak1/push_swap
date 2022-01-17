/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lst_2nd_to_last.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/01 12:36:28 by jhille        #+#    #+#                 */
/*   Updated: 2021/12/01 13:22:23 by jhille        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

t_list	*lst_2nd_to_last(t_list *lst)
{
	t_list	*i;

	i = lst;
	while (i && i->next->next)
	{
		i = i->next;
	}
	return (i);
}
