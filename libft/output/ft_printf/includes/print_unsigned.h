/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 12:33:00 by vpaladii          #+#    #+#             */
/*   Updated: 2017/11/17 12:33:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_UNSIGNED_H
# define PRINT_UNSIGNED_H

# define BASE "0123456789abcdef"

# include "libft.h"
# include <stdarg.h>
# include <inttypes.h>
# include "specifier.h"
# include "general_funcs.h"

void	printf_unsigned(t_spec *spec, va_list ap, int *printed);
char	*unsigned_itoa(uintmax_t num, int base);

#endif
