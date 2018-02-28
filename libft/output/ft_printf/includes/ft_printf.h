/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 11:53:00 by vpaladii          #+#    #+#             */
/*   Updated: 2017/11/14 11:53:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include "specifier.h"
# include "print_funcs.h"
# include "define_type.h"

int		ft_printf(const char *format, ...);
void	printf_process_color(const char **format, int *is_color, int *printed);
void	print_char(t_spec *spec, int *printed, char chr);

#endif
