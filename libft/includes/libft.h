/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 16:11:47 by vpaladii          #+#    #+#             */
/*   Updated: 2017/10/23 16:11:50 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <string.h>
# include <wchar.h>
# include "string.h"
# include "output.h"
# include "other.h"
# include "libft_structs.h"
# include "fcntl.h"

# define HEX_BASE "0123456789abcdef"
# define ABS(x)  ( ( (x) < 0) ? -(x) : (x) )
# define MAX(x, y) (((x) > (y)) ? (x) : (y))
# define MIN(x, y) (((x) < (y)) ? (x) : (y))

#endif
