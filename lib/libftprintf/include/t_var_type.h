/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   t_var_type.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:22:42 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 14:22:42 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_VAR_TYPE_H
# define T_VAR_TYPE_H

typedef enum	e_var_type {
	UNDEFINED = 0,
	CHAR = 1,
	STRING = 2,
	POINTER = 3,
	INT = 4,
	UNSIGNED = 5,
	HEX_LOW = 6,
	HEX_UP = 7,
	PERCENTAGE = 8,
	N = 9,
}				t_var_type;

#endif
