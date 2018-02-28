/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_signed_decimal.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 15:27:00 by vpaladii          #+#    #+#             */
/*   Updated: 2017/11/15 15:27:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_SIGNED_DECIMAL_H
# define PRINT_SIGNED_DECIMAL_H

# include "libft.h"
# include <stdarg.h>
# include <inttypes.h>
# include "specifier.h"
# include "general_funcs.h"

void		printf_signed(t_spec *spec, va_list ap, int *printed);
char		*signed_itoa(intmax_t num);

#endif
