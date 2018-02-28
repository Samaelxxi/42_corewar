/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 06:06:00 by vpaladii          #+#    #+#             */
/*   Updated: 2017/11/19 06:06:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

# include "libft.h"

typedef struct	s_color
{
	char		*color_val;
	char		*color_str;
}				t_color;

t_color			g_colors[] =
{
	{"\x1B[0m", "eoc"},
	{"\x1B[31m", "red"},
	{"\x1B[32m", "green"},
	{"\x1B[33m", "yellow"},
	{"\x1B[34m", "blue"},
	{"\x1B[35m", "magenta"},
	{"\x1B[36m", "cyan"},
	{"\x1B[37m", "white"},
	{NULL, NULL}
};

#endif
