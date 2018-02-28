/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 14:25:00 by vpaladii          #+#    #+#             */
/*   Updated: 2017/11/14 14:25:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPECIFIER_H
# define SPECIFIER_H

# include <stdlib.h>
# include "libft.h"
# include <stdarg.h>

# define MAX_FLAGS_NUM 5

# define FLAGS "#0-+ "
# define LEN_MODS "hljz"
# define MODS_COMPARE "-HhlKzj"
# define SPECIFIERS "sSpdDioOuUxXcCn%br"
# define POSS_CHARS "0123456789sSpidDoOuUxXcCblhzjn#+-. *r"

typedef struct	s_spec
{
	char		*flags;
	int			min_width;
	int			precision;
	char		len_mod;
	char		specifier;
}				t_spec;

t_spec			*printf_process_specifier(const char **format, va_list ap);
void			printf_free_specifier(t_spec *spec);
void			printf_parse_flags(char *spec_str, t_spec *specifier);
void			printf_parse_width(char *spec_str, t_spec *specifier,
									va_list ap);
void			printf_parse_precision(char *spec_str, t_spec *specifier,
										va_list ap);
void			printf_parse_mods(char *spec_str, t_spec *specifier);
void			printf_parse_specifier(char *spec_str, t_spec *specifier);
void			printf_parse_asterisks(char *spec_str, t_spec *specifier,
								va_list ap);

#endif
