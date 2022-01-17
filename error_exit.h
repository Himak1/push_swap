/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_exit.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhille <jhille@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/27 21:19:29 by jhille        #+#    #+#                 */
/*   Updated: 2022/01/13 12:50:43 by zaiba         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_EXIT_H
# define ERROR_EXIT_H
# include <stdlib.h>
# define MALLOC_F -1
# define BAD_ARG -2
# define INT_OVERFLOW -3
# define WRITE_F -4
# define DUPL_NUM -5

void	error_exit(int error_code);
#endif