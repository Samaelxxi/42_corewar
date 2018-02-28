/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_concat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 19:24:00 by vpaladii          #+#    #+#             */
/*   Updated: 2017/11/29 19:24:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*path_concat(char *dirname, char *filename)
{
	char *fullpath;

	fullpath = ft_strnew(ft_strlen(dirname) + 1 + ft_strlen(filename));
	ft_strcpy(fullpath, dirname);
	ft_strcat(fullpath, "/");
	ft_strcat(fullpath, filename);
	return (fullpath);
}
