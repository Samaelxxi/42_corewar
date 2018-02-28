/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_funcs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 15:40:00 by vpaladii          #+#    #+#             */
/*   Updated: 2017/11/15 15:40:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERAL_FUNCS_H
# define GENERAL_FUNCS_H

# include "libft.h"
# include "specifier.h"
# include <stdarg.h>

void		printf_process_width(char **line, int width, char *flags,
									int prec);
void		printf_process_decimal_precision(char **line, int precision);
intmax_t	get_int_arg(t_spec *spec, va_list ap);
uintmax_t	get_uns_arg(t_spec *spec, va_list ap);

#endif
