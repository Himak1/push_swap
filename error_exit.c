/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_exit.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/27 21:18:07 by jhille        #+#    #+#                 */
/*   Updated: 2022/01/13 12:46:44 by zaiba         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "error_exit.h"
#include <unistd.h>

void	error_exit(int error_code)
{
	if (error_code == MALLOC_F)
		write(1, "ERROR\nMemory allocation failed\n", 31);
	else if (error_code == BAD_ARG)
		write(1, "ERROR\nNon-numeric character as argument\n", 41);
	else if (error_code == INT_OVERFLOW)
		write(1, "ERROR\nArgument is too big or small for an int\n", 46);
	else if (error_code == WRITE_F)
		write(1, "ERROR\nWrite() call failed\n", 26);
	else if (error_code == DUPL_NUM)
		write(1, "ERROR\nDuplicate numbers found\n", 30);
	exit(-1);
}
